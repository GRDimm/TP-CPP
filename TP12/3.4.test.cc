#include "3.4.h"
#include <string>
#include <iostream>
#include "main_utils.h"
using std::cout;
using std::endl;
using std::string;

class MyDouble {
 public:
  MyDouble() : x_() {}
  MyDouble(double x) : x_(x) {}
  bool operator<(const MyDouble& other) const { return x_ < other.x_; }
 private:
  const double x_;
};

class MyString {
 public:
  MyString() : x_() {}
  MyString(const char* x) : x_(x) {}
  bool operator<(const MyString& other) const { return x_ < other.x_; }
 private:
  const string x_;
};

int main() {
  Triplet<MyDouble, MyString, MyDouble> a(1, "Hello", 4.3);
  Triplet<MyDouble, MyString, MyDouble> b;
  Triplet<MyDouble, MyString, MyDouble> c(2, "Hello", 4.3);
  Triplet<MyDouble, MyString, MyDouble> d(1, "Hello!", 4.3);
  Triplet<MyDouble, MyString, MyDouble> e(-1, "ZZZ", 9e99);
  Triplet<MyDouble, MyString, MyDouble> f(1, "Hella", 9e99);
  Triplet<MyDouble, MyString, MyDouble> g(1, "Hello", 4.300000001);
  Triplet<MyDouble, MyString, MyDouble> h(1, "Hello", 4.299999999);

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
