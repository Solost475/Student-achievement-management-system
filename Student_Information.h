#include <iostream>
#include <vector>
#include "Student_Grade.h"

#pragma once
using namespace std;

class Student_Information {
public:
    virtual void input() {
        cout << "id name gender major phone address age class:\n";
        cin >> id >> name >> gender >> major >> phone >> address >> age >> classes;
        Student_Grade stu;
        cout << "Please enter the grade Chinese math English:\n";
        cin >> stu.chinese >> stu.math >> stu.english;
        stu.sum = stu.chinese + stu.math + stu.english;
        cout << "Enter successfully\n";
        stu.id = id;
        stu.name = name;
        student_Grade.push_back(stu);
    }

    virtual void output() {
        cout << "name:" << name << endl;
        cout << "gender:" << gender << endl;
        cout << "id:" << id << endl;
        cout << "major:" << major << endl;
        cout << "phone:" << phone << endl;
        cout << "address:" << address << endl;
        cout << "age:" << age << endl;
        cout << "class:" << classes << endl;
    }

    virtual void output_all() {
        //name gender id major phone address age classes
        cout << name << " " << gender << " " << id << " " << major << " " << phone << " " << address << " " << age
             << " " << classes << endl;
    }

    virtual void change() {
        int x;
        cout << "Please enter the information number you want to modify:\n";
        cout << "1.name" << endl;
        cout << "2.gender" << endl;
        cout << "3.id" << endl;
        cout << "4.major" << endl;
        cout << "5.phone" << endl;
        cout << "6.address" << endl;
        cout << "7.age" << endl;
        cout << "8.class" << endl;
        cin >> x;
        switch (x) {
            case 1:
                cout << "Please enter your modified name:\n";
                cin >> name;
                break;
            case 2:
                cout << "Please enter your modified gender:\n";
                cin >> gender;
                break;
            case 3:
                cout << "Please enter your modified id:\n";
                cin >> id;
                break;
            case 4:
                cout << "Please enter your modified major:\n";
                cin >> major;
                break;
            case 5:
                cout << "Please enter your modified phone:\n";
                cin >> phone;
                break;
            case 6:
                cout << "Please enter your modified address:\n";
                cin >> address;
                break;
            case 7:
                cout << "Please enter your modified age:\n";
                cin >> age;
                break;
            case 8:
                cout << "Please enter your modified classes:\n";
                cin >> classes;
                break;
        }
    }

    string name, gender, id, major, phone, address, age, classes;
};

vector<Student_Information> student_information;

void Student_input() {
    Student_Information stu;
    cout << "Please enter the number of student information you want to enter:\n";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        stu.input();
        student_information.push_back(stu);
    }
    cout << "Student information added successfully!\n";
    system("pause");
}

void Student_add() {
    Student_Information stu;
    stu.input();
    student_information.push_back(stu);
    cout << "Student information added successfully!\n";
    system("pause");
}

void Student_delete() {
    cout << "Please enter your student id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_information.begin(); i != student_information.end(); i++) {
        if (i->id == id) {
            f = 1;
            cout << "The information of the student to be deleted has been queried\n";
            student_information.erase(i);
        }
    }
    if (f == 0) {
        cout << "Failed to delete the student information\n";
    }
    system("pause");
}

void Student_find() {
    cout << "Please enter the id of the student you are looking for\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_information.begin(); i != student_information.end(); i++) {
        if (i->id == id) {
            f = 1;
            cout << "The queried student information has been found\n";
            i->output();
        }
    }
    if (f == 0) {
        cout << "Failed to find the student information\n";
    }
    system("pause");
}

void Student_change() {
    cout << "Please enter your student id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_information.begin(); i != student_information.end(); i++) {
        if (i->id == id) {
            f = 1;
            i->change();
            cout << "Succeeded in modifying the information!\n";
        }
    }
    if (f == 0) {
        cout << "Failed to find the student information\n";
    }
    system("pause");
}

void Student_grade_display() {
    cout << "id name sum chinese math english\n";
    for (auto x: student_Grade) {
        cout << x.id << " " << x.name << " " << x.sum << " " << x.chinese << " " << x.math << " " << x.english << endl;
    }
    system("pause");
}

void Student_sort() {
    cout << "Please enter the information you want to rank according to:\n";
    int x;
    cout << "1.sum\n";
    cout << "2.math\n";
    cout << "3.english\n";
    cout << "4.chinese\n";
    cin >> x;
    switch (x) {
        case 1:
            sort(student_Grade.begin(), student_Grade.end(),
                 [&](Student_Grade &a, Student_Grade &b) { return a.sum > b.sum; });
            break;
        case 2:
            sort(student_Grade.begin(), student_Grade.end(),
                 [&](Student_Grade &a, Student_Grade &b) { return a.math > b.math; });
            break;
        case 3:
            sort(student_Grade.begin(), student_Grade.end(),
                 [&](Student_Grade &a, Student_Grade &b) { return a.english > b.english; });
            break;
        case 4:
            sort(student_Grade.begin(), student_Grade.end(),
                 [&](Student_Grade &a, Student_Grade &b) { return a.chinese > b.chinese; });
            break;
    }
    cout << "Sort success!\n";
    Student_grade_display();
    system("pause");
}

void Student_qualified() {
    int c1 = 0, c2 = 0, c3 = 0, n = student_Grade.size();
    for (auto x: student_Grade) {
        if (x.chinese >= 60)
            c1++;
        if (x.math >= 60)
            c2++;
        if (x.english >= 60)
            c3++;
    }
    cout << "Chinese pass rate:" << c1 / n * 100 << "%\n";
    cout << "Math pass rate:" << c2 / n * 100 << "%\n";
    cout << "English pass rate:" << c3 / n * 100 << "%\n";
    system("pause");
}

void Student_information() {
    cout << "Please enter your student id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_Grade.begin(); i != student_Grade.end(); i++) {
        if (i->id == id) {
            f = 1;
            i->output();
            break;
        }
    }
    if (f == 0) {
        cout << "Failed to find the student information\n";
    }
    system("pause");
}

void Student_information_All() {
    cout << "name gender id major phone address age classes:\n";
    for (auto i = student_information.begin(); i != student_information.end(); i++) {
        i->output_all();
    }
    system("pause");
}

void Student_grade_change() {
    cout << "Please enter your student id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_Grade.begin(); i != student_Grade.end(); i++) {
        if (i->id == id) {
            f = 1;
            int x;
            system("cls");
            cout << "1.change grade\n2.delete grade\n";
            cin >> x;
            if (x == 1)
                i->student_grade_change();
            else {
                student_Grade.erase(i);
                cout << "Deleted successfully!\n";
            }
            break;
        }
    }
    if (f == 0) {
        cout << "Failed to find the student information\n";
    }
    system("pause");
}