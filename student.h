#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    int roll;
    std::string name;
    std::string department;
    float marks;

    Student();
    Student(int r, std::string n, std::string d, float m);

    std::string toFileString() const;
};

#endif
