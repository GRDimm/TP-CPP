
#include "2.1.h"
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// This function, which you must implement, should do the following:
// - Construct N instances of MyObj, with seed=0...N-1.
// - Sort them by Value()
// - Return the "median" value, i.e. the Value() of the N/2-th MyObj in the
//   sorted list.
// - [IMPORTANT!] Destroy all instances of MyObj before returning.
int ComputeMedianMyObj(int N) {
    vector<unique_ptr<MyObj>> objects;

    for(int i = 0; i < N; i++) {
        objects.push_back(unique_ptr<MyObj>(new MyObj(i)));
    }

    sort(objects.begin(), objects.end(), [](const unique_ptr<MyObj> &a, const unique_ptr<MyObj> &b) {
        return a->Value() < b->Value();
    });

    return objects[N / 2]->Value();
}
