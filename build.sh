#!/bin/sh -e

cd $(dirname $0)

mkdir -p build
cd build
/bin/echo -e "\x1b[31;1m## running cmake  ##\x1b[0m"
if [ $1 = "DBG" ]
then
	cmake -DCMAKE_BUILD_TYPE:STRING=Debug ..
else
	cmake ..
fi
/bin/echo -e "\x1b[31;1m## running make   ##\x1b[0m"
make -j 3
/bin/echo -e "\x1b[31;1m## running tests  ##\x1b[0m"
./src/tests/run-tests
/bin/echo -e "\x1b[31;1m## build succeded ##\x1b[0m"

