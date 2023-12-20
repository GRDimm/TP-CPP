#!/bin/bash

function die {
  echo "ERROR: $@"
  exit 1
}

function check_file {
  [[ -f "$1" ]] || die "File '$1' not found"
}

check_file "1.2.bin"

echo "Hello
World
This is
a
simple
text
file" > 1.2.test

function CHECK_EQ() {
  OUT="$($1)"
  if [[ "$OUT" = "$2" ]]; then
    echo "OK"
  else
    die "FAILED! When running '$1', expected output:
'$2'
And got, instead:
'$OUT'"
  fi
}

CHECK_EQ "./1.2.bin 1.2.test 1" "Hello"
CHECK_EQ "./1.2.bin 1.2.test 0" ""
CHECK_EQ "./1.2.bin 1.2.test 2" "Hello
World"
CHECK_EQ "./1.2.bin 1.2.test 4" "Hello
World
This is
a"

echo "SUCCESS! You solved the exercise."
