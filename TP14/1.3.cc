#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char *argv[]){

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