#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "student.h"

using namespace std;

class Class {

    private:
        string name;
        int N;
        Student** students; 
    public:
        string Name() const;
        int MaxNumberOfStudents() const;
        int NumStudents() const;
        int AddStudent(Student* student);
        Student* GetStudent(int student_index) const;
        Class(string name, int N);
};

#endif