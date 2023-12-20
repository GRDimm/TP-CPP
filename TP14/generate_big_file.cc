#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <number of lines (100K per line)>" << endl;
    return 1;
  }
  istringstream is(argv[1]);
  int num_lines = 0;
  is >> num_lines;
  for (int l = 0; l < num_lines; ++l) {
    for (int c = 0; c < 100000; ++c) cout << char(random() % 96 + 32);
    cout << endl;
  }
}
