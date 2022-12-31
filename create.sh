#!/usr/bin/env bash

mkdir $1

echo "# Creates a binary target
add_executable($1 $1.cpp)" > $1/CMakeLists.txt

cp template/template.cpp $1/$1.cpp

touch $1/readme.md

echo "# $1" > $1/readme.md