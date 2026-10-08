#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> students;
    int choice;
    string name;

do {
cout << "1.Add a student\n";
cout << "2.Serve the first student\n";
cout << "3.Display waiting students\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1:
cout << "Enter student name: ";
cin >> name;
students.push(name);
cout << name << " has joined the queue.\n";
break;

case 2:
if (students.empty()) {
cout << "Queue is empty. No student to serve.\n";
} else {
cout << "Serving student: " << students.front() << endl;
students.pop();
}
break;

case 3:
if (students.empty()) {
cout << "Queue is empty. No students are waiting.\n";
} else {
queue<string> temp = students;
cout << "Students waiting:\n";
while (!temp.empty()) {
cout << temp.front() << endl;
temp.pop();
}
}
break;

default:
cout << "Invalid choice. Try again.\n";
}
} while (choice != 4);
return 0;
}

