#include "4.4.h"
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

string GetMostFrequent(const CardinalityCounter<string>& c) {
  return c.MostFrequent();
}

int main() {
  // Reproduce the tests of 1.1, and add basic tests for "MostFrequent".
  CardinalityCounter<long long> counter;

  // Basic checks
  CHECK_EQ(0, counter.NumOccurences(123));
  CHECK_EQ(0, counter.NumOccurences(123));
  CHECK_EQ(0, counter.NumOccurences(0));
  CHECK_EQ(0, counter.NumOccurences(-1));

  counter.Add(1);
  CHECK_EQ(1, counter.MostFrequent());
  counter.Add(123);
  counter.Add(1234567890123456L);
  counter.Add(123);
  CHECK_EQ(123, counter.MostFrequent());
  counter.Add(123);
  counter.Add(1234567890123456L);
  CHECK_EQ(123, counter.MostFrequent());

  CHECK_EQ(1, counter.NumOccurences(1));
  CHECK_EQ(3, counter.NumOccurences(123));
  CHECK_EQ(2, counter.NumOccurences(1234567890123456L));
  CHECK_EQ(1, counter.NumOccurences(1));
  CHECK_EQ(3, counter.NumOccurences(123));
  CHECK_EQ(2, counter.NumOccurences(1234567890123456L));
  CHECK_EQ(0, counter.NumOccurences(-1));
  CHECK_EQ(0, counter.NumOccurences(0));
  CHECK_EQ(3, counter.Size());

  counter.Remove(789);
  counter.Remove(789);
  counter.Remove(123);
  counter.Remove(123);
  CHECK_EQ(3, counter.Size());

  CHECK_EQ(1, counter.NumOccurences(123));
  CHECK_EQ(1234567890123456L, counter.MostFrequent());
  CHECK_EQ(2, counter.NumOccurences(1234567890123456L));
  CHECK_EQ(1, counter.NumOccurences(1));
  counter.Remove(1234567890123456L);
  counter.Add(1);
  CHECK_EQ(1, counter.MostFrequent());
  counter.Remove(123);
  CHECK_EQ(2, counter.Size());
  counter.Remove(1);
  counter.Remove(1);
  CHECK_EQ(1, counter.Size());
  CHECK_EQ(0, counter.NumOccurences(1));
  counter.Remove(1);
  counter.Remove(1);
  counter.Remove(1);
  counter.Remove(1);
  CHECK_EQ(1, counter.Size());
  CHECK_EQ(0, counter.NumOccurences(1));
  CHECK_EQ(1234567890123456L, counter.MostFrequent());
  counter.Add(1);
  counter.Add(1);
  CHECK_EQ(2, counter.NumOccurences(1));
  CHECK_EQ(1, counter.MostFrequent());
  CHECK_EQ(2, counter.Size());
  counter.Add(123);
  CHECK_EQ(3, counter.Size());

  // Check that cardinalities above 1000000 are supported.
  for (int i = 0; i < 1000001; ++i) counter.Add(456);
  CHECK_EQ(1000001, counter.NumOccurences(456));
  CHECK_EQ(456, counter.MostFrequent());
  CHECK_EQ(4, counter.Size());
  for (int i = 0; i < 1000000; ++i) {
    CHECK_EQ(1000001 - i, counter.NumOccurences(456));
    counter.Remove(456);
  }
  CHECK_EQ(1, counter.NumOccurences(456));
  CHECK_EQ(4, counter.Size());
  counter.Remove(456);
  CHECK_EQ(0, counter.NumOccurences(456));
  CHECK_EQ(3, counter.Size());
  counter.Remove(456);
  CHECK_EQ(0, counter.NumOccurences(456));
  CHECK_EQ(3, counter.Size());
  counter.Add(456);
  CHECK_EQ(4, counter.Size());

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
  int s = 0;
  for (int i = 0; i < kCardinality; ++i) {
    for (const int e : elements) {
      counter2.Add(e); 
      s += counter2.MostFrequent();
    }
  }
  CHECK_NE(s, 0);
  clock_t c1 = clock();
  // 3) Check that all cardinalities are correct.
  for (const int e : elements) CHECK_EQ(kCardinality, counter2.NumOccurences(e));
  // 4) Check that the time it took to insert all elements wasn't too long.
  double dt = double(c1 - c0) / CLOCKS_PER_SEC;
  cout << "Checking that your code is fast enough: " << dt << " s" << endl;
  CHECK_LT(dt, 5.0);

  // Now the 1.2 tests.
  CHECK_EQ(kNumElements, counter2.Size());
  CHECK_EQ(4, counter.Size());
  // Tests the 'const' bit.
  CHECK_EQ(0, GetSize(CardinalityCounter<string>()));
  CHECK_EQ(0, GetNumOccurences(CardinalityCounter<string>(), "Hello"));

  // Check MostFrequent()'s constness, and use strings.
  CardinalityCounter<string> cs;
  cs.Add("Hello");
  CHECK_EQ("Hello", GetMostFrequent(cs));

  // Performance tests for the MostFrequent() call.
  // Scenario 1): alternating bests. This doesn't stress the memory much.
  CardinalityCounter<int> counter3;
  const int kRepeat = 10000000;
  c0 = clock();
  for (int i = 0; i < kRepeat; ++i) {
    counter3.Add(123);
    CHECK_EQ(123, counter3.MostFrequent());
    counter3.Add(456);
    counter3.Add(456);
    CHECK_EQ(456, counter3.MostFrequent());
    counter3.Add(123);
  }
  c1 = clock();
  dt = double(c1 - c0) / CLOCKS_PER_SEC;
  cout << "Checking that your code is fast enough: " << dt << " s" << endl;
  CHECK_LT(dt, 3.0);
  // Scenario 2): many different elements. Let's say this was already covered
  // in the first performance test above.

  // Performance and correctness test:
  // add/remove elements at random. Remove() should
  // run in amortized constat time, since we have 1/N probability that
  // it picks the most frequent element.
  {
    const int kNumElements = 1000;
    vector<int> elements;
    {
      unordered_set<int> element_set;
      while (element_set.size() < kNumElements) element_set.insert(random());
      elements.insert(elements.begin(), element_set.begin(), element_set.end());
    }
    const int kRepeat = 10000000;
    CardinalityCounter<int> counter4;
    c0 = clock();
    for (int i = 0; i < kRepeat; ++i) {
      const int r = random();
      const int e = elements[(r >> 1) % elements.size()];
      if (r & 1) counter4.Add(e); else counter4.Remove(e);
    }
    c1 = clock();
    const int size = counter4.Size();
    CHECK_GT(size, 3 * kNumElements / 4);
    CHECK_LE(size, kNumElements);
    const int most_frequent = counter4.MostFrequent();
    const int occurences = counter4.NumOccurences(most_frequent);
    CHECK_LT(occurences, 5 * sqrt(kRepeat / kNumElements));
    CHECK_GT(occurences, sqrt(kRepeat / kNumElements));
    dt = double(c1 - c0) / CLOCKS_PER_SEC;
    cout << "Checking that your code is fast enough: " << dt << " s" << endl;
    CHECK_LT(dt, 3.0);
  }

  cout << "SUCCESS!" << endl;
}
