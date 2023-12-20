#include "2.1.h"
#include <string>
using std::string;

struct ABC {
  int a;
  double b;
  int c;
};

int main() {
  {
    Track<string> s;
    Track<string> t = string("yop");
  }
  ABC abc = {123, 45.67, 89};
  Track<ABC>* on_heap = new Track<ABC>(abc);
  Track<ABC>* on_heap_def = new Track<ABC>;
  Track<ABC> def;
  delete on_heap;
  delete on_heap_def;
}
