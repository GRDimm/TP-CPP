#include "3.1.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
  Print(42);
  cout << endl;
  Print(123L);
  cout << endl;
  Print(3.1);
  cout << endl;
  Print('a');
  cout << endl;
  Print("Hello World!");
  cout << endl;
  const string s = "Hello World!";
  Print(s);
  cout << endl;
}
