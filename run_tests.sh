#!/bin/bash

# File to store the counter
COUNTER_FILE="$HOME/.miniRT_counter"

# Initialize counter if it doesn't exist
if [ ! -f "$COUNTER_FILE" ]; then
    echo 1 > "$COUNTER_FILE"
fi

# Read current counter and increment
temp_01=$(cat "$COUNTER_FILE")
next_counter=$((temp_01 + 1))

# Pad temp_01 with leading zero (e.g., 01, 02)
temp_01=$(printf "%02d" "$temp_01")

# Run the miniRT command
./miniRT "scenes/test${temp_01}*"

# Save the incremented counter
echo "$next_counter" > "$COUNTER_FILE"
