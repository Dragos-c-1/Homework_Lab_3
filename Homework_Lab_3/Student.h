#pragma once
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int grade;

public:
    static int instanceCount;

    Student(std::string n, int g) : name(n), grade(g) {
        instanceCount++;
    }

    Student(const Student& other) : name(other.name), grade(other.grade) {
        instanceCount++;
    }

    ~Student() {
        instanceCount--;
    }

    std::string getName() const { return name; }
    int getGrade() const { return grade; }

    void display() const {
        std::cout << "Nume: " << name << ", Nota: " << grade << "\n";
    }
};
