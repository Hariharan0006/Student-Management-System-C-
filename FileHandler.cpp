#include "FileHandler.h"
#include <fstream>
#include <sstream>

std::vector<Student> FileHandler::loadStudents() {
    std::vector<Student> students;
    std::ifstream file("students.txt");

    if (!file) return students;

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        int roll;
        std::string name, dept;
        float marks;

        getline(ss, token, '|');
        roll = std::stoi(token);

        getline(ss, name, '|');
        getline(ss, dept, '|');

        getline(ss, token);
        marks = std::stof(token);

        students.push_back(Student(roll, name, dept, marks));
    }

    file.close();
    return students;
}

void FileHandler::saveStudents(const std::vector<Student>& students) {
    std::ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.toFileString() << std::endl;
    }

    file.close();
}
