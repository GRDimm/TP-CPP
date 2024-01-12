#include <functional>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Student {
  string name;   // Eg. "John Smith"
  int number;    // Identification number, eg. "12345678"
  double grade;  // Global grade over 20.0, eg. 15.5.
};

// Sorts students by name, lexicographically: "Aab" before "Ac".
void SortStudentsByName(vector<Student>* students);

// Sorts students by their identification number modulo M: 0 before 1.
void SortStudentsByNumberModulo(vector<Student>* students, int M);

// Applies the given function to each student inside the vector.
void ApplyFunctionToStudents(std::function<void(Student*)> fun,
                             vector<Student>* students);
