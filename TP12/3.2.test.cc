#include "3.2.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Youpla {
 public:
  Youpla() : x_("NONE") { cout << "Constructing Youpla by default" << endl; }
  Youpla(const Youpla& youpla) : x_(youpla.x_) {
    cout << "Constructing Youpla by copy" << endl;
  }
  Youpla(const string& x) : x_(x) {
    cout << "Constructing Youpla from a string" << endl;
  }

  Youpla& operator=(const Youpla& youpla) {
    x_ = youpla.x_;
    return *this;
  }

 private:
  string x_;
};

int main() {
  Triplet<Youpla, int, Youpla> t;
  t.first = Youpla("Hop");
}
