#include "student.h"
#include <string.h>

Student::Student(const char* name, int birthday) : birthday(birthday){
    strncpy(this->name, name, 127);
    this->name[127] = '\0';
}

const char* Student::Name() const {
    return name;
}

int Student::Birthday(){
    return birthday % 10000;
}