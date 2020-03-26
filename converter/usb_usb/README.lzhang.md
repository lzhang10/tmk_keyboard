git submodule init
git submodule update
nix-shell
make -f Makefile.leonardo
sleep 3 && make -f Makefile.leonardo program

After programming, use boot magic LSHIFT-RSHIFT plus 0-3 to select the active layer:
0: default querty
1: magic keyboard
2: kinesis adv2
3: magic keyboard for VNC under MacOS

To set default layer, press SPACE+number while plugging the keyboard.

use `sudo hid_listen` to see debug messages.
