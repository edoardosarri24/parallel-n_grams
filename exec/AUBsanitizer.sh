#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: Missing argument. Usage: $0 [seq|par]"
    exit 1
fi

MODE=$1

if [[ "$MODE" != "seq" && "$MODE" != "par" ]]; then
    echo "Error: Invalid argument '$MODE'. Usage: $0 [seq|par]"
    exit 1
fi

echo "building (ASan + UBSan)..."
rm -rf build
# RelWithDebInfo gives us optimizations (-O2/-O3) AND debug symbols (-g)
# This is ideal for sanitizers: run fast enough to test, but give line numbers on error.
cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo -DENABLE_AUBSAN=ON
cmake --build build

echo "executing ($MODE)..."
if [ "$MODE" == "par" ]; then
    ./build/parallel/parallel_trigrams
else
    ./build/sequential/sequential_trigrams
fi