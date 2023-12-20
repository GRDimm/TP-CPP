#ifndef IO_H
#define IO_H

#include "student.h"
#include "class.h"

using namespace std;

void PrintStudent(const Student& student);
void PrintClass(const Class& Cl);
Student* EnterStudent();
Class* EnterClass();

#endif