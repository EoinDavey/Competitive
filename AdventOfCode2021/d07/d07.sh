#!/bin/bash

inpstr=$(cat /dev/stdin)
IFS=","
inp=()
for i in $inpstr; do
    inp+=($i)
done;

mx=0
for i in ${inp[@]}; do
    if (($i > $mx)); then
        mx=$i
    fi;
done;

part_a() {
    bst=$((1000*1000*1000))
    for((pos=0;pos<=$mx;pos++)); do
        sm=0
        for x in ${inp[@]}; do
            if (($x > $pos)); then
                ((sm+=x-pos))
            else
                ((sm+=pos-x))
            fi;
        done;
        if (($sm < $bst)); then
            bst=$sm
        fi;
    done;
    echo "Part A: $bst"
}

part_b() {
    bst=$((1000*1000*1000))
    for((pos=0;pos<=$mx;pos++)); do
        sm=0
        for x in ${inp[@]}; do
            let d=pos-x
            if ((d < 0)); then
                ((d=-d))
            fi
            ((sm+=(d*(d+1))/2))
        done;
        if (($sm < $bst)); then
            bst=$sm
        fi;
    done;
    echo "Part B: $bst"
}

part_a
part_b
