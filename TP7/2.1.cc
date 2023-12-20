#include <iostream>

using namespace std;

class A {
 public:
  A() : x_(0) {
    cout << "Constructing A() @" << this << endl;
  }
  A(int x) {
    x_ = x;
    cout << "Constructing A(" << x << ") @" << this << endl;
  }

  ~A() {
    cout << "~A(): x = " << x_ << ", @" << this << endl;
  }

 private:
  int x_;
};

int main() {
  cout << "Starting" << endl;
  A a = 123;
  {
    A a;
    A* aa = new A(456);
  }
  for (int i = 0; i < 2; i++) {
    A a(i);
  }

    cout << "checkpoint1" << endl;

  A* a_ptr[3] = {NULL, NULL, NULL};

    cout << "checkpoint2" << endl;

  for (int i = 0; i < 3; i++) {
    a_ptr[i] = new A(i);
  }
    cout << "checkpoint3" << endl;
  for (int i = 0; i < 3; i++) {
    delete a_ptr[i];
  }
cout << "checkpoint4" << endl;
  A yop[2];

  // Where is the memory leak ??
}