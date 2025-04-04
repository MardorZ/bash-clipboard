#!/bin/bash

set -e  # Exit on error

echo "🧪 Running clipboard tests..."

TEST_INPUT="test_input.txt"
TEST_OUTPUT="test_output.txt"
CLIPBOARD_CMD="./bash-clipboard"
TMP_FILE="/tmp/clipboard_buffer"

# Create test file
echo "Hello, clipboard world!" > "$TEST_INPUT"

# Run copy
cat "$TEST_INPUT" | $CLIPBOARD_CMD -c

# Check if temp file exists
if [[ ! -f $TMP_FILE ]]; then
    echo "❌ Clipboard temp file not found!"
    exit 1
fi

# Run paste
$CLIPBOARD_CMD -p > "$TEST_OUTPUT"

# Compare input and output
if diff "$TEST_INPUT" "$TEST_OUTPUT" > /dev/null; then
    echo "✅ Clipboard copy/paste test passed!"
else
    echo "❌ Clipboard copy/paste test failed!"
    exit 1
fi

# Clean up
rm -f "$TEST_INPUT" "$TEST_OUTPUT"

echo "🎉 All tests passed."
