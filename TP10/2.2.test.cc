#include "2.2.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

int main() {
  Shape* circle = Circle::Create(-3.4, -2.5, 9.5);
  CHECK_NEAR(circle->Area(), 283.528736986, 1e-8); 
  cout << circle->Name() << endl;
  cout << circle->Description() << endl;

  // Clean up! We must delete the objects that our program allocated.
  delete circle;
}
