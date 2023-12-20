#include <iostream>
#include <vector>
using namespace std;

int* SortRev(const int n, const int* values){
    int* sortedArray = new int[n];
    copy(values, values + n, sortedArray);
    sort(sortedArray, sortedArray + n, greater<int>());
    return sortedArray;
}