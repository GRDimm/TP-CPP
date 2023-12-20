#!/bin/bash

set -e

OUT=$(./3.1.test)
EXPECTED="Triplet: 42; ; 3
1.5"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
