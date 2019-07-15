git submodule init
git submodule update
nix-shell
make -f Makefile.magic-linux
sleep 3 && make -f Makefile.magic-linux program
