#include <iostream>
using namespace std;

template <typename SomeClass>
class Track : public SomeClass {
 public:
  Track() : SomeClass(), s() {
    cerr << "Default-Constructing @" << this << endl;
  }

  Track(const SomeClass& obj) : SomeClass(obj), s(obj) {
    cerr << "Copy-Constructing @" << this << endl;
  }

  ~Track() {
    cerr << "Destructing @" << this << endl;
  }

  const SomeClass& Get() const {
    return s;
  }

  SomeClass* Mutable() {
    return &s;
  }

 private:
  SomeClass s;
};
