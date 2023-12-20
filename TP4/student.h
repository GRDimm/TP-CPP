#ifndef STUDENT_H
#define STUDENT_H


class Student {
    private:
        char name[128];
        int birthday;
    public:
        Student(const char* name, int birthday);

        const char * Name() const;
        int Birthday();
};

#endif