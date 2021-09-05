rm -rf bin
mkdir bin
mkdir bin/obj
make build
cd test
./build.sh
./game
