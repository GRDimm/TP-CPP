#include <cstdlib>
#include <iostream>
#include <vector>
#include "3.4.h"

using namespace std;

#define CHECK(x) do {\
  if (!(x)) {\
    cerr << "ERROR in " __FILE__ ":" << __LINE__\
         << ": CHECK condition violated: " #x << std::endl;\
    exit (1);\
  }\
} while(0)

int main() {
  srand(0);
  cout << "Basic tests...\n";
  Array a;
  CHECK(a.size() == 0);
  a.push_back(3);
  a.push_back(2);
  a.push_back(1);
  a.push_back(0);
  a.push_back(-1);
  CHECK(a.size() == 5);
  CHECK(a[0] == 3);
  CHECK(a[1] == 2);
  CHECK(a[2] == 1);
  CHECK(a[3] == 0);
  CHECK(a[4] == -1);
  a[4] = 3;
  a.pop_back();
  a.pop_back();
  CHECK(a.size() == 3);
  a[1] = -2;
  CHECK(a[0] == 3);
  CHECK(a[1] == -2);
  CHECK(a[2] == 1);

  cout << "PASSED!\n===================================================\n";
  cout << "Checking for memory leaks (if this takes more than ~10 second, you probably have a memory leak)...\n";
  time_t t = time(0);
  int s = 0;
  for (int i = 0; i < 1000000; ++i) {
    Array a;
    for (int j = 0; j < 1000; ++j) a.push_back(j);
    s += a.size();
  }
  cout << "This took " << time(0) - t << " seconds. [debug:" << s << "]\n";
  cout << "PASSED! No memory leaks in the simple scenario (growing only)\n";
  cout << "===================================================\n";
  cout << "Checking that the memory usage does not explode (if this takes more than ~10 second, your code is probably wrong)...\n";
  t = time(0);
  s = 0;
  for (int size : {1, 10, 1000, 1000000}) {
    const int times = (1<<28) / sizeof(int) / size;  // 256MB.
    for (int i = 0; i < times; ++i) {
      Array a;
      for (int j = 0; j < size; ++j) a.push_back(j);
      s += a.size();
    }
  }
  cout << "This took " << time(0) - t << " seconds. [debug:" << s << "]\n";
  cout << "PASSED!\n===================================================\n";
  cout << "Now testing a complex case, with arrays growing/shrinking at random...\n";
  const int total = 100000000;
  int capacity_values[] = {100, 10000, 1000000, 10000000};
  int num = 0;
  vector<int> capacities;
  for (int capacity : capacity_values) {
    const int num_a = total / capacity;
    for (int j = 0; j < num_a; ++j) capacities.push_back(capacity);
    num += num_a;
  }
  Array* arrays = new Array[num];
  t = time(0);
  int num_ops = 1<<24;
  vector<int> sizes(num, 0);
  for (int i = 0; i < num_ops; ++i) {
    const int x = rand() % num;
    Array* a = &arrays[x];
    const bool remove = rand() % 2 == 0;
    int max_num = capacities[x];
    while (max_num >= capacities[x]) max_num = 1 << (rand() % 31);
    int num = rand() % max_num;
    if (remove) {
      num = std::min(num, sizes[x]);
      sizes[x] -= num;
      while (num--) a->pop_back();
    } else {
      num = std::min(num, capacities[x] - sizes[x]);
      sizes[x] += num;
      while (num--) a->push_back(num);
    }
    CHECK(a->size() == sizes[x]);
  }
  cout << "This took " << time(0) - t << " seconds.\n";
  cout << "PASSED!\n";
  delete[] arrays;
}
