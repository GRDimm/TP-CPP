#include "3.3.h"
#include <string>
#include <iostream>
#include "main_utils.h"
using std::cout;
using std::endl;
using std::string;

int main() {
  const Triplet<int, string, double> a(1, "Hello", 4.3);
  Triplet<int, string, double> b;
  b.first = 1;
  const Triplet<int, string, double> c(2, "Hello", 4.3);
  const Triplet<int, string, double> d(1, "Hello!", 4.3);
  const Triplet<int, string, double> e(-1, "ZZZ", 9e99);
  const Triplet<int, string, double> f(1, "Hella", 9e99);
  const Triplet<int, string, double> g(1, "Hello", 4.300000001);
  const Triplet<int, string, double> h(1, "Hello", 4.299999999);

  CHECK(!(a < a));
  CHECK(b < a);
  CHECK(!(a < b));
  CHECK(a < c);
  CHECK(!(c < a));
  CHECK(a < d);
  CHECK(!(d < a));
  CHECK(e < a);
  CHECK(!(a < e));
  CHECK(f < a);
  CHECK(!(a < f));
  CHECK(a < g);
  CHECK(!(g < a));
  CHECK(h < a);
  CHECK(!(a < h));

  cout << "SUCCESS! All tests passed." << endl;
}
