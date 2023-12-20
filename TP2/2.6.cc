#include <iostream>
using namespace std;

long Pgcd(long a, long b){

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    return Pgcd(b, a % b);
}
