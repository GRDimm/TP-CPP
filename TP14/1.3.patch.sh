#!/bin/bash

function die {
  echo "ERROR: $@"
  exit 1
}

function check_file {
  [[ -f "$1" ]] || die "File '$1' not found"
}

check_file "1.3.cc"

echo "#include <sys/resource.h>" > 1.3.patched.cc
echo "#include <iostream>" >> 1.3.patched.cc
awk '{print $0} /int  *main *\(/ {
  print "  // Limit the memory to 32MB."
  print "  rlimit lim;"
  print "  lim.rlim_cur = 32<<20;"
  print "  lim.rlim_max = lim.rlim_cur;"
  print "  if (setrlimit(RLIMIT_AS, &lim) != 0) {"
  print "    std::cerr << \"WARNING: This test limits the amount of memory to 32MB.\\n\""
  print "              << \"So if the test fails with an error involving std::bad_alloc,\""
  print "              << \" you are probably using too much memory!\\n\" << endl;"
  print "    return 1;"
  print "  }"
}' 1.3.cc >> 1.3.patched.cc
