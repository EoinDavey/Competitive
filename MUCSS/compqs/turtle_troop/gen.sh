#!/bin/bash
rm -r input/* output/*
for i in {1..10}; do python3 generators/gen.py > input/input0$i.txt; done;
for i in {10..20}; do python3 generators/gen.py > input/input$i.txt; done;

for i in input/*.txt; do python3 solutions/soln.py < $i > ${i//input/output}; done;

zip -r hackerrank.zip input/ output/
