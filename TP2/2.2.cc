#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long FactorielleMod2(int n){
    long long produit = 1;

    for(int i=1; i <= n; i++){
        produit *= i;
        produit = produit % MOD;
    }

    return produit;

}
