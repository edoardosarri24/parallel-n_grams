#!/bin/bash

mkdir -p data
if [ ! -f "data/input.txt" ]; then
    echo "downloading dataset..."
    cd exec/download_inpu_script/
    uv run main.py
    cd ../../
fi