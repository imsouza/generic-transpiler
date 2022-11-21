#!/bin/sh
make
./bin/scopeParser < ./test/input.g | ./bin/genericParser