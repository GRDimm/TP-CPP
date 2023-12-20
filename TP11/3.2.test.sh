#!/bin/bash

set -e

OUT=$(./3.2.test)
EXPECTED="42
int(42)
42
Hello World!"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
