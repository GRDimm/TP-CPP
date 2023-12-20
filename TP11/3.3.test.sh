#!/bin/bash

set -e

OUT=$(./3.3.test)
EXPECTED="int(123)
long(456)
unsigned int(789)
unsigned long(111222333444555)
42
Hello World!"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
