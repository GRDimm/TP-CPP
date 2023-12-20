#include <iostream>
using namespace std;

template <typename A, typename B, typename C>

class Triplet {
    public:
        Triplet() : first(), second(), third(){}
        Triplet(const A& a, const B& b, const C& c) : first(a), second(b), third(c){}
        A first;
        B second;
        C third;
        bool operator<(const Triplet& t) const {
            if (this->first < t.first) {
                return true;
            } else if (!(t.first < this->first) && this->second < t.second) {
                return true;
            } else if (!(t.first < this->first) && !(t.second < this->second) && this->third < t.third) {
                return true;
            }
            return false;
        }
};