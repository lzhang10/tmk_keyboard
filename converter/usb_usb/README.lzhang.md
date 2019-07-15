git submodule init
git submodule update
nix-shell
make -f Makefile.leonardo
sleep 3 && make -f Makefile.leonardo program
