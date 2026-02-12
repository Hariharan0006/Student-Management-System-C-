#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include "Student.h"

class FileHandler {
public:
    static std::vector<Student> loadStudents();
    static void saveStudents(const std::vector<Student>& students);
};

#endif
