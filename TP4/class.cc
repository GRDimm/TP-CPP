#include "class.h"
#include <string>
using namespace std;

Class::Class(string name, int N) : name(name), N(N) {
    students = new Student*[N];
    for (int i = 0; i < N; i++) {
        students[i] = nullptr;
    }
}

string Class::Name() const {
    return name;
}

int Class::MaxNumberOfStudents() const {
    return N;
}

int Class::NumStudents() const {
    int s = 0;
    for (int i = 0; i < N; i++) {
        if(students[i] != nullptr){
            s++;
        }
    }
    return s;
}

int Class::AddStudent(Student* student){
    for (int i = 0; i < N; i++) {
        if(students[i] == nullptr){
            students[i] = student;
            return i;
        }
    }
    return -1;
}

Student* Class::GetStudent(int student_index) const {
    return students[student_index];
}