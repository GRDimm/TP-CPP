#include "main_utils.h"
#include "1.2.h"
#include <limits>

int main() {
  {
    FibonacciSequence* fibo = new FibonacciSequence;
    ShiftSequence fibo_10(fibo, 10);
    CHECK_EQ(89, fibo_10.Value());
  }

  {
    Sequence* fibo = new FibonacciSequence;
    ShiftSequence fibo0(fibo, 0);
    CHECK_EQ(1, fibo0.Value());
    fibo0.Next();
    CHECK_EQ(1, fibo0.Value());
    fibo0.Next();
    CHECK_EQ(2, fibo0.Value());
  }

  {
    // Triple composition. Whoooo, how fun.
    Sequence* fibo = new FibonacciSequence;
    Sequence* fibo1 = new ShiftSequence(fibo, 10);
    Sequence* fibo2 = new ShiftSequence(fibo1, 20);
    ShiftSequence fibo3(fibo2, 30);
    CHECK_EQ(2504730781961.0, fibo3.Value());
  }

  // Verify that there are no memory leaks.
  double s = 0.0;
  const int times = 10000000;
  for (int i = 0; i < times; ++i) {
    FibonacciSequence* fibo = new FibonacciSequence;
    ShiftSequence fibo_s(fibo, i % 2);
    s += fibo_s.Value();
  }
  CHECK_EQ(times, s);

  // Verify that FibonacciSequence is copy-constructible.
  FibonacciSequence s1;
  s1.Next();
  s1.Next();
  cout << "S1 val : " << s1.Value() << endl;
  FibonacciSequence s2 = s1;
  cout << "S2 start val : " << s2.Value() << endl;
  s2.Next();
  s2.Next();

  cout << "S2 end val : " << s2.Value() << endl;
  cout << "S1 val : " << s1.Value() << endl;

  FibonacciSequence s3(s2);
  cout << "S2 end val : " << s2.Value() << endl;
  cout << "S1 val : " << s1.Value() << endl;

  FibonacciSequence s4(s1);
  cout << "S2 end val : " << s2.Value() << endl;
  cout << "S1 val : " << s1.Value() << endl;
  CHECK_EQ(14.0, s1.Value() + s2.Value() + s3.Value() + s4.Value());
}
