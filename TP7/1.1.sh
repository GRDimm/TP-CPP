#!/bin/bash

function die {
  echo "ERROR: $@" > /dev/stderr
  exit 1
}

[[ -s "1.1.txt" ]] || die "'1.1.txt' not found"

awk '' || die "awk n'est pas installé sur votre système!"

OUT=$(awk '{print $1}' 'RS=,' 1.1.txt | awk '{print $1}' | sort)
echo "${OUT}"
MD5=$(echo "$OUT" | cksum)
if [[ "${MD5% *}" = 1829760181 ]]; then
  echo "Correct!"
else
  echo "Wrong"
fi
