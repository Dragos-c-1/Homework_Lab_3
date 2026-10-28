#include <iostream>
#include <limits>

#include "Rectangle.h"
#include "Student.h"
#include "StudentGroup.h"

using namespace std;

int Student::instanceCount = 0;

int main() {
    StudentGroup group;
    int choice = -1;

    while (choice != 0) {
        cout << "\n=========== MENIU ===========\n";
        cout << "1. Testare Rectangle (T.3.1)\n";
        cout << "2. Adaugare Student nou\n";
        cout << "3. Afisare toti studentii\n";
        cout << "4. Sortare studenti (T.3.2)\n";
        cout << "5. Cautare student dupa nume (T.3.3)\n";
        cout << "6. Afisare studenti cu nota maxima (T.3.4)\n";
        cout << "7. Verificare numar de instante Student active (T.3.7)\n";
        cout << "0. Iesire\n";
        cout << "=============================\n";
        cout << "Alege o optiune: ";

        cin >> choice;

        switch (choice) {
        case 1: {
            double w1, h1, w2, h2;
            cout << "Introduceti latimea si lungimea primului dreptunghi (ex: 4 5): ";
            cin >> w1 >> h1;
            cout << "Introduceti latimea si lungimea celui de-al doilea dreptunghi: ";
            cin >> w2 >> h2;

            Rectangle r1(w1, h1);
            Rectangle r2(w2, h2);

            cout << "\nRezultate comparatie:\n";
            r1.compareArea(r2);
            r1.comparePerimeter(r2);
            break;
        }
        case 2: {
            string name;
            int grade;
            cout << "Introduceti numele studentului: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Introduceti nota: ";
            cin >> grade;

            group.addStudent(Student(name, grade));
            break;
        }
        case 3:
            cout << "\n--- Lista Studenti ---\n";
            group.displayAll();
            break;
        case 4:
            group.sortStudents();
            cout << "\n--- Lista Sortata ---\n";
            group.displayAll();
            break;
        case 5: {
            string searchName;
            cout << "Introduceti numele pe care il cautati: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, searchName);
            group.searchStudent(searchName);
            break;
        }
        case 6:
            group.displayStudentsWithMaxGrade();
            break;
        case 7:
            cout << "Numar instante curente de Student: " << Student::instanceCount << "\n";
            break;
        case 0:
            cout << "Iesire din program.\n";
            break;
        default:
            cout << "Optiune invalida. Reincercati.\n";
        }
    }

    return 0;
}