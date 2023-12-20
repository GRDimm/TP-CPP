#include "3.3.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
  Print(123);
  cout << endl;
  Print(456L);
  cout << endl;
  Print(789U);
  cout << endl;
  Print(111222333444555UL);
  cout << endl;
  Print((short)42);
  cout << endl;
  const string s = "Hello World!";
  Print(s);
  cout << endl;
}
