#!/bin/bash

function die {
  echo "ERROR: $@"
  exit 1
}

function check_file {
  [[ -f "$1" ]] || die "File '$1' not found"
}

# 100MB memory limit.
ulimit -v 100000
if ./1.1.test; then
  echo "Your code passed the correctness tests!"
else
  echo "FAILED: Your code failed the correctness tests."
  exit 1
fi

check_file 1.1.o

for fail in 1.1.fail{1,2,3}.cc; do
  check_file "$fail"
  if g++ -std=c++11 1.1.o $fail > /dev/null 2>&1; then
    echo "FAILED: you didn't make all functions of class 'Sequence' abstract (i.e. pure virtual)"
    exit 1
  fi
done
echo "SUCCESS! You solved the exercise."
