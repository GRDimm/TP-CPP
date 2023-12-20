#include "4.1.h"
#include "main_utils.h"
#include <ctime>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  CardinalityCounter<long long> cc;

  // Basic checks
  CHECK_EQ(0, cc.NumOccurences(123));
  CHECK_EQ(0, cc.NumOccurences(123));
  CHECK_EQ(0, cc.NumOccurences(0));
  CHECK_EQ(0, cc.NumOccurences(-1));
  cc.Add(1);
  cc.Add(123);
  cc.Add(1234567890123456L);
  cc.Add(123);
  cc.Add(123);
  cc.Add(1234567890123456L);
  CHECK_EQ(1, cc.NumOccurences(1));
  CHECK_EQ(3, cc.NumOccurences(123));
  CHECK_EQ(2, cc.NumOccurences(1234567890123456L));
  CHECK_EQ(1, cc.NumOccurences(1));
  CHECK_EQ(3, cc.NumOccurences(123));
  CHECK_EQ(2, cc.NumOccurences(1234567890123456L));
  CHECK_EQ(0, cc.NumOccurences(-1));
  CHECK_EQ(0, cc.NumOccurences(0));
  cout << "Basic tests PASSED" << endl;

  // Check that cardinalities above 1000000 are supported.
  for (int i = 0; i < 1000001; ++i) cc.Add(456);
  CHECK_EQ(1000001, cc.NumOccurences(456));
  cout << "Large cardinality test PASSED" << endl;

  // Complexity check: it should all be in constant time.
  // Inserting 100000 elements, 100 times each. Should all take less
  // than a second.
  // 1) Prepare the elements to insert.
  const int kNumElements = 100000;
  const int kCardinality = 100;
  vector<int> elements;
  {
    unordered_set<int> element_set;
    while (element_set.size() < kNumElements) element_set.insert(random());
    elements.insert(elements.begin(), element_set.begin(), element_set.end());
  }
  // 2) Perform the repeated insertions.
  CardinalityCounter<int> c2;
  clock_t c0 = clock();
  for (int i = 0; i < kCardinality; ++i) {
    for (const int e : elements) {
      c2.Add(e); 
    }
  }
  clock_t c1 = clock();
  // 3) Check that all cardinalities are correct.
  for (const int e : elements) CHECK_EQ(kCardinality, c2.NumOccurences(e));
  cout << "Stress test PASSED" << endl;
  // 4) Check that the time it took to insert all elements wasn't too long.
  cout << "Checking that your code is fast enough...\n";
  CHECK_LT(double(c1 - c0) / CLOCKS_PER_SEC, 1.0);
  cout << "Speed test PASSED" << endl;
}
