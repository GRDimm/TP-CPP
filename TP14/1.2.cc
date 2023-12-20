#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){

    if(argc == 3){

        ifstream ifs (argv[1], ifstream::in);
        int count = 0;
        int N = atoi(argv[2]);
        string line;

        while(getline (ifs, line) && count < N){
            cout << line << endl;
            count++;
        }

    }

    return 0;
}