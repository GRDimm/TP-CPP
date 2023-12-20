#include <iostream>
using namespace std;

template <typename SomeClass>

class Track : public SomeClass {
 public:
  Track() : SomeClass() {
    cerr << "Default-Constructing @" << this << endl;
  }

  Track(const SomeClass& obj) : SomeClass(obj) {
    cerr << "Copy-Constructing @" << this << endl;
  }

  ~Track() {
    cerr << "Destructing @" << this << endl;
  }
};