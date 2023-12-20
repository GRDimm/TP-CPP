#include <iostream>

void CountingSort(const int n, const int* values, int* sortedArray) {
    int max_value = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    std::vector<int> count(max_value + 1, 0);
    for (int i = 0; i < n; i++) {
        count[values[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_value; i++) {
        while (count[i] > 0) {
            sortedArray[index] = i;
            index++;
            count[i]--;
        }
    }
}

int HIndex(int num_articles, const int* num_citations) {

    int sorted_citations[num_articles];
    CountingSort(num_articles, num_citations, sorted_citations);

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




