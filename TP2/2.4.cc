#include <iostream>
using namespace std;

long FiboRec(int n){
    if(n == 0 || n == 1){
        return 1;
    }else{
        return FiboRec(n-1) + FiboRec(n-2);
    }
}
