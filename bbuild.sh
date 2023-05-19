#!/usr/bin/env bash

source format.sh $1

rm -rf build
cmake -S . -B build -D TARGET_GROUP=$1
cmake --build build

if [[ $2 == "run" ]]; then
  echo "Will run the application now..."
  ./build/$1/$(basename "$1")
fi