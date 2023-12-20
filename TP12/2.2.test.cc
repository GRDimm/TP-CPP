#include "2.2.h"
#include <iostream>
#include <string>
using std::string;
using std::cerr;
using std::endl;

struct ABC {
  int a;
  double b;
  int c;
};

int main() {
  Track<string> s;
  cerr << s.Get() << endl;
  *s.Mutable() += "Hello";
  *s.Mutable() += "World";
  cerr << s.Get() << endl;
  const Track<string> t = string("yop");
  cerr << t.Get() << endl;
}
