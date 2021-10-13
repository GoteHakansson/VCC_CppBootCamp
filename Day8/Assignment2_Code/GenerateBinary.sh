#!/bin/bash
echo "Hello World"
mkdir ./tmp
cd ./tmp
git init
git remote add -f origin https://github.com/GoteHakansson/VCC_CppBootcamp.git
git pull origin main
cd ./Day1/Assigment1_Code
g++ posnumbers.cpp -o posnumbers
./posnumbers