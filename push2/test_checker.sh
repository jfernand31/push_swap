#!/bin/bash

failures=0
tests=100

for ((i=1; i<=tests; i++)); do
    INPUT=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
    OUTPUT=$(echo $INPUT | xargs ./push_swap)
    RESULT=$(echo "$OUTPUT" | ./checker_linux $INPUT)

    if [ "$RESULT" != "OK" ]; then
        echo "Test $i failed!"
        failures=$((failures+1))
    fi
done

echo "$failures out of $tests tests failed."
