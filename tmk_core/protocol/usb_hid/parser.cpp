#include "parser.h"
#include "usb_hid.h"

#include "debug.h"


void KBDReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf)
{
  dprintf("input %d:", hid->GetAddress());
    for (uint8_t i = 0; i < len; i++) {
        dprintf(" %02X", buf[i]);
    }
    dprint("\r\n");

    // ignore Cherry 0101010101010101 bug report
    // https://geekhack.org/index.php?topic=69169.msg2638223#msg2638223
    // if (buf[1] == 0x01) {
    //    dprint("Cherry bug: ignored\r\n");
    //    return;
    // }

    // Apple USB Magic keyboard (Model A1644) (buf[1] == 0x01) has mods byte in buf[1] while buf[0] is 0x01:
    // input 1: 01 00 00 00 00 00 00 00 00 00
    // buf[9] on magic keyboard:
    // 0x01: media eject key pressed
    // 0x02: fn key pressed
    // we store buf[9] in buf[1] (reserved byte)

    if (buf[0] == 0x01 && len == 10) {
      uint8_t t = buf[0];
      buf[0] = buf[1];
      buf[1] = buf[9];
    }
    ::memcpy(&report, buf, sizeof(report_keyboard_t));
    time_stamp = millis();
}
