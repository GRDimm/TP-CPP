#include <iostream>
using namespace std;

double FiboIter(int n){
    double Fn_1 = 1;
    double Fn = 1;

    for(int i=0; i < n; i++){
        double temp = Fn;
        Fn = Fn_1 + Fn;
        Fn_1 = temp;
    }
    
    return Fn_1;

}

