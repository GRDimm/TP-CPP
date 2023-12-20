#!/bin/bash

set -e

OUT=$(./3.2.test)
EXPECTED="Constructing Youpla by default
Constructing Youpla by default
Constructing Youpla from a string"

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
