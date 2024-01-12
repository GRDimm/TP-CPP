#include <functional>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

struct Student {
    string name;   // Eg. "John Smith"
    int number;    // Identification number, eg. "12345678"
    double grade;  // Global grade over 20.0, eg. 15.5.
};

void SortStudentsByName(vector<Student>* students){
    std::sort(students->begin(), students->end(),
        [](const Student a, const Student b) {
            return a.name < b.name;
    });
}

// Sorts students by their identification number modulo M: 0 before 1.
void SortStudentsByNumberModulo(vector<Student>* students, int M){
    std::sort(students->begin(), students->end(),
        [M](const Student a, const Student b) {
            return (a.number % M) < (b.number % M);
    });
}

// Applies the given function to each student inside the vector.
void ApplyFunctionToStudents(std::function<void(Student*)> fun, vector<Student>* students){
    for (Student& student : *students) {
        fun(&student);
    }
}
