#!/bin/bash

set -e

OUT=$(./2.2.test 2>&1 | sed 's/ @.*/ @.../')
EXPECTED="Default-Constructing @...

HelloWorld
Copy-Constructing @...
yop
Destructing @...
Destructing @..."

if [[ "$OUT" = "$EXPECTED" ]]; then
  echo "SUCCESS"
else
  echo "FAILED: Expected: '$EXPECTED', and instead, got '$OUT'"
  exit 1
fi
