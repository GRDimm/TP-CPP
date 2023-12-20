#include "2.1.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

static int num_live_myobj_instances;

MyObj::MyObj(int seed) : value_((seed + 12987124) * 1000000007) {
  ++num_live_myobj_instances;
}

MyObj::~MyObj() {
  --num_live_myobj_instances;
}

int main() {
  num_live_myobj_instances = 0;
  CHECK_EQ(391330525, ComputeMedianMyObj(10));
  // If this CHECK fails, it means that ComputeMedianMyObj() didn't properly
  // destruct all the MyObj instances that it has constructed.
  CHECK_EQ(0, num_live_myobj_instances);

  CHECK_EQ(11886, ComputeMedianMyObj(1000000));
  CHECK_EQ(0, num_live_myobj_instances);

  cout << "You passed the .cc test.\n";
}
