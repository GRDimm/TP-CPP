#include <iostream>

using namespace std;

template <typename T>
void Print(T x){cout << x;}

void Print(int x){cout << "int(" << x << ")";}
void Print(unsigned int x){cout << "unsigned int(" << x << ")";}
void Print(long x){cout << "long(" << x << ")";}
void Print(unsigned long x){cout << "unsigned long(" << x << ")";}

