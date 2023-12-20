#!/bin/bash

set -e

OUT=$(./1.3.test)
EXPECTED="(1, 2, R51:G68:B85)
(1, 2, R51:G68:B85)
(1, 2, R51:G68:B85)
(1, 2)"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
