#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

class StudentGroup {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
        std::cout << "Student adaugat cu succes!\n";
    }

    void sortStudents() {
        if (students.empty()) {
            std::cout << "Lista este goala!\n";
            return;
        }
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.getGrade() == b.getGrade()) {
                return a.getName() < b.getName();
            }
            return a.getGrade() > b.getGrade();
            });
        std::cout << "Studentii au fost sortati!\n";
    }

    void displayAll() const {
        if (students.empty()) {
            std::cout << "Nu exista studenti in lista.\n";
            return;
        }
        for (const auto& student : students) {
            student.display();
        }
    }

    void searchStudent(const std::string& searchName) const {
        auto it = std::find_if(students.begin(), students.end(), [&searchName](const Student& s) {
            return s.getName() == searchName;
            });

        if (it != students.end()) {
            std::cout << "Student gasit: ";
            it->display();
        }
        else {
            std::cout << "Studentul '" << searchName << "' nu a fost gasit.\n";
        }
    }

    void displayStudentsWithMaxGrade() const {
        if (students.empty()) {
            std::cout << "Lista este goala!\n";
            return;
        }

        auto maxIt = std::max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getGrade() < b.getGrade();
            });

        int maxGrade = maxIt->getGrade();

        std::cout << "Studenti cu nota maxima (" << maxGrade << "):\n";
        for (const auto& student : students) {
            if (student.getGrade() == maxGrade) {
                student.display();
            }
        }
    }
};