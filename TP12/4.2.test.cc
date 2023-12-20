#include "4.2.h"
#include "main_utils.h"
#include <ctime>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetSize(const CardinalityCounter<string>& c) {
  return c.Size();
}

int GetNumOccurences(const CardinalityCounter<string>& c, const string& s) {
  return c.NumOccurences(s);
}

int main() {
  // Reproduce the tests of 1.1...
  CardinalityCounter<long long> counter;

  // Basic checks
  CHECK_EQ(0, counter.NumOccurences(123));
  CHECK_EQ(0, counter.NumOccurences(123));
  CHECK_EQ(0, counter.NumOccurences(0));
  CHECK_EQ(0, counter.NumOccurences(-1));
  counter.Add(1);
  counter.Add(123);
  counter.Add(1234567890123456L);
  counter.Add(123);
  counter.Add(123);
  counter.Add(1234567890123456L);
  CHECK_EQ(1, counter.NumOccurences(1));
  CHECK_EQ(3, counter.NumOccurences(123));
  CHECK_EQ(2, counter.NumOccurences(1234567890123456L));
  CHECK_EQ(1, counter.NumOccurences(1));
  CHECK_EQ(3, counter.NumOccurences(123));
  CHECK_EQ(2, counter.NumOccurences(1234567890123456L));
  CHECK_EQ(0, counter.NumOccurences(-1));
  CHECK_EQ(0, counter.NumOccurences(0));

  // Check that cardinalities above 1000000 are supported.
  for (int i = 0; i < 1000001; ++i) counter.Add(456);
  CHECK_EQ(1000001, counter.NumOccurences(456));

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
  CardinalityCounter<int> counter2;
  clock_t c0 = clock();
  for (int i = 0; i < kCardinality; ++i) {
    for (const int e : elements) {
      counter2.Add(e); 
    }
  }
  clock_t c1 = clock();
  // 3) Check that all cardinalities are correct.
  for (const int e : elements) CHECK_EQ(kCardinality, counter2.NumOccurences(e));
  // 4) Check that the time it took to insert all elements wasn't too long.
  cout << "Checking that your code is fast enough...\n";
  CHECK_LT(double(c1 - c0) / CLOCKS_PER_SEC, 1.0);

  // Now the 1.2 tests.
  CHECK_EQ(kNumElements, counter2.Size());
  CHECK_EQ(4, counter.Size());
  // Tests the 'const' bit.
  CHECK_EQ(0, GetSize(CardinalityCounter<string>()));
  CHECK_EQ(0, GetNumOccurences(CardinalityCounter<string>(), "Hello"));

  cout << "SUCCESS!" << endl;
}
