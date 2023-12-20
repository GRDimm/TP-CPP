#include <iostream>
#include "1.4.cc"

int HIndex(int num_articles, const int* num_citations) {

    int* sorted_citations = SortRev(num_articles, num_citations);

    int h = 0;
    for (int i = 0; i < num_articles; i++) {
        if (sorted_citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break;
        }
    }

    return h;
}







