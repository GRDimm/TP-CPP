#include <iostream>
using namespace std;

const long MOD = 1000000007;

long FactorielleMod(int n){
    if(n == 0){
        return 1;
    }else{
        return n*FactorielleMod(n-1) % MOD;
    }
    
}
