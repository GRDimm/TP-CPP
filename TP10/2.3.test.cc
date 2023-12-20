#include "2.3.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

int main() {
  Shape* square = StraightSquare::Create(-3.4, -2.5, 0.95);
  CHECK_NEAR(square->Perimeter(), 3.8, 1e-12); 
  cout << "Test 1/4 PASSED: StraightSquare::Perimeter() correctly implemented.\n";

  Shape* circle = Circle::Create(-3.4, -2.5, 0.95);
  CHECK_NEAR(circle->Perimeter(), 5.96902604165, 1e-8); 
  cout << "Test 2/4 PASSED: Circle::Perimeter() correctly implemented.\n";
  CHECK_EQ(square->Description(), "Square: area=0.902500, perimeter=3.800000");
  CHECK_EQ(circle->Description(), "Circle: area=2.835287, perimeter=5.969026");
  cout << "Test 3/4 PASSED: Description() correctly implemented.\n";

  delete square;
  delete circle;
  cout << "Test 4/4 PASSED: Destruction works.\n";
  cout << "SUCCESS: all tests passed.\n";
}
