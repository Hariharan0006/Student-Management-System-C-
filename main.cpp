#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "FileHandler.h"

using namespace std;

void showMenu() {
    cout << "\n====================================\n";
    cout << "   STUDENT MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Student> students = FileHandler::loadStudents();
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name, dept;
            float marks;

            cout << "Enter Roll: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter Marks: ";
            cin >> marks;

            students.push_back(Student(roll, name, dept, marks));
            FileHandler::saveStudents(students);
            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            for (const auto& s : students) {
                cout << "\nRoll: " << s.roll
                     << "\nName: " << s.name
                     << "\nDepartment: " << s.department
                     << "\nMarks: " << s.marks << "\n";
            }
        }

        else if (choice == 3) {
            int roll;
            cout << "Enter Roll to Search: ";
            cin >> roll;

            bool found = false;
            for (const auto& s : students) {
                if (s.roll == roll) {
                    cout << "Found: " << s.name << " | "
                         << s.department << " | "
                         << s.marks << endl;
                    found = true;
                }
            }

            if (!found) cout << "Student Not Found!\n";
        }

        else if (choice == 4) {
            int roll;
            cout << "Enter Roll to Update: ";
            cin >> roll;

            for (auto& s : students) {
                if (s.roll == roll) {
                    cin.ignore();
                    cout << "Enter New Name: ";
                    getline(cin, s.name);
                    cout << "Enter New Department: ";
                    getline(cin, s.department);
                    cout << "Enter New Marks: ";
                    cin >> s.marks;

                    FileHandler::saveStudents(students);
                    cout << "Updated Successfully!\n";
                    break;
                }
            }
        }

        else if (choice == 5) {
            int roll;
            cout << "Enter Roll to Delete: ";
            cin >> roll;

            students.erase(
                remove_if(students.begin(), students.end(),
                [roll](Student s) { return s.roll == roll; }),
                students.end());

            FileHandler::saveStudents(students);
            cout << "Deleted Successfully!\n";
        }

    } while (choice != 6);

    cout << "Exiting Program...\n";
    return 0;
}
