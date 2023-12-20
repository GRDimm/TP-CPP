#!/bin/bash

function die {
  echo "ERROR: $@"
  exit 1
}

function check_file {
  [[ -f "$1" ]] || die "File '$1' not found"
}

check_file "1.1.bin"

echo "Hello
World
This is
a
simple
text
file" > 1.1.test

N=$(./1.1.bin 1.1.test)
[[ "$N" = 7 ]] || die "Expected 7 lines for file '1.1.test', got '$N'"

echo -n "" > 1.1.test

N=$(./1.1.bin 1.1.test)
[[ "$N" = 0 ]] || die "Expected 0 lines for file '1.1.test', got '$N'"

echo "" > 1.1.test

N=$(./1.1.bin 1.1.test)
[[ "$N" = 1 ]] || die "Expected 1 lines for file '1.1.test', got '$N'"

echo "SUCCESS! You solved the exercise."
