#include "main_utils.h"
#include "1.3.h"
#include <limits>
#include <iostream>
using namespace std;

double GetSequenceValueAfterFiveSteps(Sequence* seq) {
  for (int i = 0; i < 5; ++i) {
    seq->Next();
  }
  return seq->Value();
}

int main() {
  FibonacciSequence* fibo = new FibonacciSequence;
  CHECK_EQ(0, fibo->Step());
  fibo->Next();
  CHECK_EQ(1, fibo->Step());
  fibo->Next();
  CHECK_EQ(2, fibo->Step());
  CHECK_EQ(2, fibo->Step());
  CHECK_EQ(2, fibo->Step());

  ShiftSequence seq(fibo, 10);
  CHECK_EQ(seq.Step(), 0);
  seq.Next();
  CHECK_EQ(seq.Step(), 1);
  seq.Next();
  CHECK_EQ(2, seq.Step());
  CHECK_EQ(2, seq.Step());
  CHECK_EQ(2, seq.Step());

  cout << "SUCCESS!\n";
}
