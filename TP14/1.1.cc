#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    if(argc == 2){

        ifstream ifs (argv[1], ifstream::in);
        int count = 0;
        string name;

        while(getline (ifs, name)){
            count++;
        }

        cout << count << endl;
    }

    return 0;
}