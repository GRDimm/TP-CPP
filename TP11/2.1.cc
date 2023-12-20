#include "2.1.h"
#include <iostream>
#include <cmath>
#include <regex>

using namespace std;
using std::exception;

bool checkPattern(const char* str) {
    std::regex pattern("0|(-?[1-9][0-9]*)");
    return std::regex_match(str, pattern);
}

int ParseInt(const char* str){
    int s = 0;
    int i = 0;
    int mult = 1;
    int length = 0;
    bool currentOverflow = false;
    bool lookOverflow = true;
    const char* M = "2147483647";
    const char* m = "-2147483648";

    if(str == nullptr){
        throw NullPtrException();
    }

    if(str[0] == '\0'){
        throw EmptyStrException();
    }

    if(!checkPattern(str)){
        throw BadFormatException(str);
    }

    if(str[0] == '-'){
        i++;
        mult = -1;
    }

    while(str[i]){

        if(lookOverflow){
            if(mult == 1){
                if(str[i] < M[i]){
                    lookOverflow = false;
                }else if(str[i] > M[i]){
                    currentOverflow = true;
                }
            }else{
                if(str[i] < m[i]){
                    lookOverflow = false;
                }else if(str[i] > m[i]){
                    currentOverflow = true;
                }
            }
        }


        s *= 10;
        s += (str[i] - '0');
        i++;
        length++;

        if((length > 10) || (length == 10 && currentOverflow) ){
            throw OverflowException(str);
        } 

    }

    return s*mult;
}
