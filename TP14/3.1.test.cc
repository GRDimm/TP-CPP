#include "3.1.h"
#include "main_utils.h"
#include <iostream>
using namespace std;

int main() {
  {
    HatFactory factory;
    CHECK_EQ(0, Hat::NumHatsGlobal());
    Hat* h1 = factory.NewHat();
    CHECK_EQ(1, Hat::NumHatsGlobal());
    Hat* h2 = factory.NewHat();
    CHECK_EQ(2, Hat::NumHatsGlobal());
    CHECK(h1 != h2);
    Hat* h3 = factory.NewHat();
    CHECK_EQ(3, Hat::NumHatsGlobal());
    CHECK(h3 != h1);
    CHECK(h3 != h2);
  }
  CHECK_EQ(0, Hat::NumHatsGlobal());

  cout << "SUCCESS! You passed the tests.\n";
}
