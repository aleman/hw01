#!/bin/bash

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"

g++ *cpp -o notify || exit 1
./notify "input=test-a.1.txt" | diff - test-a.out.txt || exit 1
