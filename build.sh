#!/bin/sh -e

cd $(dirname $0)

mkdir -p build
cd build
/bin/echo -e "\x1b[31m## running cmake  ##\x1b[0m"
cmake ..
/bin/echo -e "\x1b[31m## running make   ##\x1b[0m"
make -j 3
/bin/echo -e "\x1b[31m## running tests  ##\x1b[0m"
./src/tests/run-tests
/bin/echo -e "\x1b[31m## build succeded ##\x1b[0m"

