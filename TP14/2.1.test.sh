#!/bin/bash

if grep delete 2.1.cc > /dev/null; then
  echo "FAILED: You used the forbidden keyword 'delete' in your code!"
  exit 1
else
  echo "SUCCESS!"
fi
