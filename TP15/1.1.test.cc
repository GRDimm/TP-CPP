#include "1.1.h"
#include "main_utils.h"
#include <iostream>
#include <sstream>
using namespace std;

string PrintStudents(const vector<Student>& students) {
  stringstream ss;
  for (const Student& s : students) {
    ss << s.name << ": N°" << s.number << ", " << s.grade << "/20\n";
  }
  return ss.str();
}

int main() {
  vector<Student> students = {
    {"Mr.Right", 123123, 4.0},
    {"Zizou", 466, 14.0},
    {"Paul", 11111121, 19.5},
    {"Lazy", 975844, 0.0},
  };
  CHECK_EQ(PrintStudents(students),
           "Mr.Right: N°123123, 4/20\n"
           "Zizou: N°466, 14/20\n"
           "Paul: N°11111121, 19.5/20\n"
           "Lazy: N°975844, 0/20\n");

  SortStudentsByName(&students);
  CHECK_EQ(PrintStudents(students),
           "Lazy: N°975844, 0/20\n"
           "Mr.Right: N°123123, 4/20\n"
           "Paul: N°11111121, 19.5/20\n"
           "Zizou: N°466, 14/20\n");

  SortStudentsByNumberModulo(&students, 1000000000);
  CHECK_EQ(PrintStudents(students),
           "Zizou: N°466, 14/20\n"
           "Mr.Right: N°123123, 4/20\n"
           "Lazy: N°975844, 0/20\n"
           "Paul: N°11111121, 19.5/20\n");

  SortStudentsByNumberModulo(&students, 10);
  CHECK_EQ(PrintStudents(students),
           "Paul: N°11111121, 19.5/20\n"
           "Mr.Right: N°123123, 4/20\n"
           "Lazy: N°975844, 0/20\n"
           "Zizou: N°466, 14/20\n");

  SortStudentsByNumberModulo(&students, 4);
  CHECK_EQ(PrintStudents(students),
           "Lazy: N°975844, 0/20\n"
           "Paul: N°11111121, 19.5/20\n"
           "Zizou: N°466, 14/20\n"
           "Mr.Right: N°123123, 4/20\n");

  ApplyFunctionToStudents(
      [](Student* s) {
        s->grade = std::min(20.0, 2.0 * s->grade);
      }, &students);
  CHECK_EQ(PrintStudents(students),
           "Lazy: N°975844, 0/20\n"
           "Paul: N°11111121, 20/20\n"
           "Zizou: N°466, 20/20\n"
           "Mr.Right: N°123123, 8/20\n");

  cout << "SUCCESS! You passed all tests.\n";
}
