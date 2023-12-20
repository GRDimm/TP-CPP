#include "3.2.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
  Print(42L);
  cout << endl;
  Print(42);
  cout << endl;
  Print(42U);
  cout << endl;
  const string s = "Hello World!";
  Print(s);
  cout << endl;
}
