#include "main_utils.h"
#include "1.1.h"
#include <limits>

double GetSequenceValueAfterFiveSteps(Sequence* seq) {
  for (int i = 0; i < 5; ++i) {
    seq->Next();
  }
  return seq->Value();
}

int main() {
  FibonacciSequence fibo;
  CHECK_EQ(8, GetSequenceValueAfterFiveSteps(&fibo));
  CHECK_EQ(89, GetSequenceValueAfterFiveSteps(&fibo));
  cout << "Test #1 PASSED: FibonacciSequence, simple" << endl;
  // Harder: verify that the sequence is not bothered by integer overflows.
  for (int i = 0; i < 500; ++i) {
    fibo.Next();
  }
  CHECK_NEAR(fibo.Value(), 2.774592228930568e+106, 1e-9);
  cout << "Test #2 PASSED: FibonacciSequence, no-integer-overflow" << endl;

  FactorialModXSequence factmod(97);
  CHECK_EQ(1, factmod.Value());
  CHECK_EQ(1, factmod.Value());
  factmod.Next();
  CHECK_EQ(1, factmod.Value());
  factmod.Next();
  CHECK_EQ(2, factmod.Value());
  CHECK_EQ(93, GetSequenceValueAfterFiveSteps(&factmod));
  cout << "Test #3 PASSED: FactorialModXSequence, simple" << endl;

  // Slightly harder: when the factorial overflows.
  {
    FactorialModXSequence factmod(97);
    CHECK_EQ(23, GetSequenceValueAfterFiveSteps(&factmod));
    CHECK_EQ(30, GetSequenceValueAfterFiveSteps(&factmod));
    // Note: 15! and 20! overflow an int, but not a long long.
    CHECK_EQ(53, GetSequenceValueAfterFiveSteps(&factmod));
    CHECK_EQ(90, GetSequenceValueAfterFiveSteps(&factmod));
    cout << "Test #4 PASSED: FactorialModXSequence, no-int-overflow" << endl;
    // 25! overflows a long long.
    CHECK_EQ(15, GetSequenceValueAfterFiveSteps(&factmod));
    cout << "Test #5 PASSED: FactorialModXSequence, no-long-long-overflow" << endl;
  }

  // Performance check: it should be super fast to get the 1000000-th term of
  // either sequence.
  {
    clock_t c0 = clock();
    FibonacciSequence fibo;
    FactorialModXSequence factmod(97);
    double s = 0;
    for (int i = 0; i < 1000000; ++i) {
      fibo.Next();
      factmod.Next();
      s += factmod.Value() ? fibo.Value() * factmod.Value() : 0;
    }
    CHECK_EQ(fibo.Value(), std::numeric_limits<double>::infinity());
    CHECK_EQ(factmod.Value(), 0);
    CHECK_NEAR(s, 1.20392e+22, 1e17);
    clock_t c1 = clock();
    cout << "Test #6 PASSED: both sequence; performance. Time: "
         << double(c1-c0) / CLOCKS_PER_SEC << " s" << endl;
  }

  // Even harder: modulo^2 overflows an integer.
  {
    clock_t c0 = clock();
    FactorialModXSequence factmod(1000000007);
    for (int i = 0; i < 25; ++i) {
      factmod.Next();
    }
    CHECK_EQ(factmod.Value(), 440732388);
    int s = 0;
    for (int i = 25; i < 100000000; ++i) {
      factmod.Next();
      s += int(factmod.Value());
    }

    cout << "TEST" << endl;
    cout << "Value : " << factmod.Value() << endl;
    factmod.Next();
    cout << "Value : " << factmod.Value() << endl;
    CHECK_EQ(factmod.Value(), 927880474);
    CHECK_EQ(s, 748849251);
    clock_t c1 = clock();
    cout << "Test #7 PASSED: FactorialModXSequence: no-large-modulo-overflow. Time: "
         << double(c1-c0) / CLOCKS_PER_SEC << " s" << endl;
  }

  // Performance check, harder: should be O(1) in memory.
  {
    clock_t c0 = clock();
    double s1 = 0;
    int s2 = 0;
    for (int i = 0; i < 1000; ++i) {
      FibonacciSequence* fibo = new FibonacciSequence;
      for (int k = 0; k < 100000; ++k) { fibo->Next(); s1 += fibo->Value(); }
      FactorialModXSequence* factmod = new FactorialModXSequence(1000000007);
      for (int k = 0; k < 100000; ++k) { factmod->Next(); s2 += int(factmod->Value()); }
    }
    CHECK_EQ(s1, std::numeric_limits<double>::infinity());
    CHECK_EQ(s2, 1730433568);
    clock_t c1 = clock();
    cout << "Test #8 PASSED: Performance and Space. Time: "
         << double(c1-c0) / CLOCKS_PER_SEC << " s" << endl;
  }
}
