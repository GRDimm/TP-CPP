#include <iostream>
using namespace std;

template <typename A, typename B, typename C>

class Triplet {
    public:
        Triplet(const A& a, const B& b, const C& c) : first(a), second(b), third(c){}
        A first;
        B second;
        C third;
};