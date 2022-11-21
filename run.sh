#!/bin/sh

echo "\nCompiling...\n"
make
echo "\nDone!\n"
./bin/scopeParser < ./test/input.g | ./bin/genericParser