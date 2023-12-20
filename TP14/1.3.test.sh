#!/bin/bash

function die {
  echo "ERROR: $@"
  exit 1
}

function check_file {
  [[ -f "$1" ]] || die "File '$1' not found"
}

check_file "1.3.bin"

echo "Hello
World
This is

a
simple
text

file" > 1.3.test

function CHECK_FILE() {
  CONTENTS="$(cat $1)"
  if [[ "$CONTENTS" = "$2" ]]; then
    echo "OK"
  else
    die "FAILED! When inspecting file '$1', expected contents:
'$2'
And got, instead:
'$CONTENTS'"
  fi
}

./1.3.bin 1.3.test 5
CHECK_FILE "1.3.test" "a
simple
text

file"

./1.3.bin 1.3.test 5
CHECK_FILE "1.3.test" "a
simple
text

file"

./1.3.bin 1.3.test 2
CHECK_FILE "1.3.test" "
file"

./1.3.bin 1.3.test 1
CHECK_FILE "1.3.test" "file"

./1.3.bin 1.3.test 1
CHECK_FILE "1.3.test" "file"

./1.3.bin 1.3.test 0
CHECK_FILE "1.3.test" ""

./generate_big_file 1000 > big
tail -n 5 big > small5

./1.3.bin big 5 || die "FAILED!"
diff big small5 > /dev/null || die "FAILED last test! Maybe your file I/O got stopped because you were using too much RAM?"
echo "OK"

echo "SUCCESS! You solved the exercise."
