#!/bin/bash

set -e

OUT=$(./1.1.test)
EXPECTED="(4, 3)
INVALID
(0, 0)
INVALID"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
