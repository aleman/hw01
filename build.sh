#!/bin/bash

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"

$CXX -std=c++11 *cpp -o notify || exit 1
./notify "input=test-a.1.txt" | diff - test-a.out.txt || exit 1
