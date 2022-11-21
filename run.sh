#!/bin/sh

echo "\nCompiling...\n"
make
echo "\nDone!\n"
./bin/scopeParser < ./test/input.g | ./bin/genericParser >./test/output.cpp
echo "\nOutput: ./test/output.cpp\n"