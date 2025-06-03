#!/bin/bash

failures=0
tests=100

for ((i=1; i<=tests; i++)); do
    # Generate numbers 1 to 500, shuffle and remove duplicates
    INPUT=$(jot 500 1 500 | sort -R | awk '!seen[$0]++' | tr '\n' ' ')
    
    # Run push_swap and check the result
    OUTPUT=$(echo $INPUT | xargs ./push_swap)
    RESULT=$(echo "$OUTPUT" | ./checker_Mac $INPUT)

    if [ "$RESULT" != "OK" ]; then
        echo "Test $i failed!"
        failures=$((failures+1))
    fi
done

echo "$failures out of $tests tests failed."
