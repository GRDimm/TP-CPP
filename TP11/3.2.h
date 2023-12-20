#include <iostream>

using namespace std;

template <typename T>
void Print(T x){cout << x;}

void Print(int x){cout << "int(" << x << ")";}
