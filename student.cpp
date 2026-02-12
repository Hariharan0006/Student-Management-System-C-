#include "Student.h"
#include <sstream>

Student::Student() {}

Student::Student(int r, std::string n, std::string d, float m) {
    roll = r;
    name = n;
    department = d;
    marks = m;
}

std::string Student::toFileString() const {
    std::ostringstream oss;
    oss << roll << "|" << name << "|" << department << "|" << marks;
    return oss.str();
}
