#!/bin/bash

set -e

OUT=$(./3.1.test)
EXPECTED="42
123
3.1
a
Hello World!
Hello World!"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
