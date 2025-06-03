#!/bin/bash

total=0
runs=100

for i in $(seq 1 $runs); do
    # Generate numbers 1 to 500 and shuffle
    input=$(jot 500 1 500 | sort -R | tr '\n' ' ')

    # Count push_swap operations
    ops=$(./push_swap $input | wc -l)

    echo "Run $i: $ops operations"
    total=$((total + ops))
done

echo "Average operations over $runs runs: $((total / runs))"
