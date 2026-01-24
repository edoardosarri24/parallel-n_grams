#!/bin/bash

mkdir -p data
if [ ! -f "data/input.txt" ]; then
    echo "downloading dataset..."
    curl -O https://downloads.wortschatz-leipzig.de/corpora/eng_news_2024_1M.tar.gz
    tar -xf eng_news_2024_1M.tar.gz
    mkdir -p sequential/data
    mv eng_news_2024_1M/eng_news_2024_1M-sentences.txt data/input.txt
    rm eng_news_2024_1M.tar.gz
    rm -rf eng_news_2024_1M
fi