git submodule init
git submodule update
nix-shell
make -f Makefile.leonardo
sleep 3 && make -f Makefile.leonardo program

After programming, use boot magic LSHIFT-RSHIFT plus 0-3 to pick the default layer:
0: default querty
1: magic keyboard
2: kinesis adv2
3: magic keyboard for VNC under MacOS
