#include <sys/resource.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char *argv[]){
  // Limit the memory to 32MB.
  rlimit lim;
  lim.rlim_cur = 32<<20;
  lim.rlim_max = lim.rlim_cur;
  if (setrlimit(RLIMIT_AS, &lim) != 0) {
    std::cerr << "WARNING: This test limits the amount of memory to 32MB.\n"
              << "So if the test fails with an error involving std::bad_alloc,"
              << " you are probably using too much memory!\n" << endl;
    return 1;
  }

    if(argc == 3){

        ifstream ifs (argv[1], ifstream::in);
        string line;
        int N = atoi(argv[2]);
        queue<string> lines;

        while (getline(ifs, line)) {
            if (lines.size() >= N) {
                lines.pop();
            }
            lines.push(line);
        }

        ifs.close();

         ofstream ofs(argv[1]);

        while (!lines.empty()) {
            ofs << lines.front() << endl;
            lines.pop();
        }

        ofs.close();
        }

    return 0;
}
