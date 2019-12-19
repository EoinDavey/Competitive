#!/bin/bash
rm -r input/* output/*
for i in {1..2}; do python3 generators/genrand.py 1000 > input/input0$i.txt; done;
for i in {3..4}; do python3 generators/genrand.py 100000 > input/input0$i.txt; done;
for i in {5..9}; do python3 generators/genhard.py 100000 > input/input0$i.txt; done;
for i in {10..15}; do python3 generators/genhard.py 100000 > input/input$i.txt; done;

g++ -std=gnu++11 -x c++ --static -O2 -o soln.out solutions/soln.cpp

for i in input/*.txt; do ./soln.out < $i > ${i//input/output}; done;

rm soln.out

zip -r hackerrank.zip input/ output/
