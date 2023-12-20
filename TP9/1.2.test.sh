#!/bin/bash

set -e

OUT=$(./1.2.test)
EXPECTED="(4, 3, R255:G53:B128)
INVALID
(0, 0, R0:G0:B0)
INVALID"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
