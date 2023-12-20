#include <iostream>
#include "3.2.cc"

using namespace std;

int main(int argc, char** argv){
    argc += 1; //Sinon error unused param
    char* str = argv[1];
    Strip(str);
    cout << str << endl;
}