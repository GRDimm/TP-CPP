#include <iostream>

using namespace std;

void Strip(char* str) {
    char* dest = str;

    while (*str) {
        if (*str != ' ') {
            *dest = *str;
            dest++;
        }
        str++;
    }

    *dest = '\0';
}
