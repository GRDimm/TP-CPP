#include "3.1.h"
#include <string>
#include <iostream>
using std::cout;

typedef std::string SomeClass;

int main() {
  const double x = 3.0;
  SomeClass my_class;
  Triplet<int, SomeClass, double> t(42, my_class, x);
  cout << "Triplet: " << t.first << "; " << t.second << "; " << t.third << "\n";
  t.third /= 2.0;
  cout << t.third << "\n";
}
