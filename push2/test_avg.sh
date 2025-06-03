#!/bin/bash

total=0
runs=100

for i in $(seq 1 $runs); do
    ops=$(./push_swap $(shuf -i 1-500 -n 500) | wc -l)
    echo "Run $i: $ops operations"
    total=$((total + ops))
done

echo "Average operations over $runs runs: $((total / runs))"
