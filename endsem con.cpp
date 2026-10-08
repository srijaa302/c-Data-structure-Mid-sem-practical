#include <iostream>
using namespace std;

class Student {
    string name;
    int registerNumber;

public:
    Student(string n, int r) {
        name = n;
        registerNumber = r;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Register Number: " << registerNumber << endl;
    }
};
int main() {

    Student student1("srii", 101);
    Student student2("Prii", 102);


    student1.display();
    cout << endl;
    student2.display();

    return 0;
}
