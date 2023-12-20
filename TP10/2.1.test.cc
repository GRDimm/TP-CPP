#include "2.1.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

int main() {
  Shape* square = StraightSquare::Create(-3.4, -2.5, 9.5);
  CHECK_NEAR(square->Area(), 9.5 * 9.5, 1e-12); 
  cout << square->Name() << endl;
  cout << square->Description() << endl;

  // Clean up! We must delete the objects that our program allocated.
  delete square;
}
