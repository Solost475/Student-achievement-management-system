#include "Student_Information.h"
#include <vector>

#pragma once
using namespace std;

class Teacher_Information : public Student_Information {
public:
    vector<string> classes;

    void input() override {
        cout << "name gender id major phone address age class:\n";
        string class1;
        cin >> name >> gender >> id >> major >> phone >> address >> age >> class1;
        Teacher_Information::classes.push_back(class1);
    }

    void output() override {
        cout << "name:" << name << endl;
        cout << "gender:" << gender << endl;
        cout << "id:" << id << endl;
        cout << "major:" << major << endl;
        cout << "phone:" << phone << endl;
        cout << "address:" << address << endl;
        cout << "age:" << age << endl;
        cout << "class: ";
        for (const auto& x: Teacher_Information::classes) {
            cout << x << " ";
        }
        cout << endl;
    }

    void output_all() override {
        cout << name << " " << gender << " " << id << " " << major << " " << phone << " " << address << " " << age
             << " ";
        for (const auto& x: Teacher_Information::classes) {
            cout << x << ", ";
        }
        cout << endl;
    }

    virtual void class_delete() {
        int j = 1, x;
        for (auto & classe : Teacher_Information::classes) {
            cout << j << " " << classe << endl;
            j++;
        }
        cout << "Please enter delete classes:\n";
        cin >> x;
        j = 1;
        for (auto i = Teacher_Information::classes.begin(); i != Teacher_Information::classes.end(); i++) {
            if (x == j) {
                Teacher_Information::classes.erase(i);
                cout << "successfully delete class!\n";
                break;
            }
            j++;
        }
    }

    void change() override {
        int x;
        cout << "Please enter the information number you want to modify:\n";
        cout << "1.name" << endl;
        cout << "2.gender" << endl;
        cout << "3.id" << endl;
        cout << "4.major" << endl;
        cout << "5.phone" << endl;
        cout << "6.address" << endl;
        cout << "7.age" << endl;
        cout << "8.add class" << endl;
        cout << "9.delete class" << endl;
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
            case 8: {
                cout << "Please enter your modified classes:\n";
                string class1;
                cin >> class1;
                Teacher_Information::classes.push_back(class1);
                break;
            }
            case 9: {
                cout << "Please enter delete classes:\n";
                class_delete();
                break;
            }
        }
    }
};

vector<Teacher_Information> teacher_information;


void Teacher_input() {
    Teacher_Information teacher;
    cout << "Please enter the number of teacher information you want to enter:\n";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        teacher.input();
        teacher_information.push_back(teacher);
    }
    cout << "Teacher information added successfully!\n";
    system("pause");
}

void Teacher_add() {
    Teacher_Information teacher;
    teacher.input();
    teacher_information.push_back(teacher);
    cout << "Teacher information added successfully!\n";
    system("pause");
}

void Teacher_delete() {
    cout << "Please enter your teacher id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = teacher_information.begin(); i != teacher_information.end(); i++) {
        if (i->id == id) {
            f = 1;
            cout << "The information of the teacher to be deleted has been queried\n";
            teacher_information.erase(i);
        }
    }
    if (f == 0) {
        cout << "Failed to delete the teacher information\n";
    }
    system("pause");
}

void Teacher_find() {
    cout << "Please enter the id of the teacher you are looking for\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto & i : teacher_information) {
        if (i.id == id) {
            f = 1;
            cout << "The queried teacher information has been found\n";
            i.output();
        }
    }
    if (f == 0) {
        cout << "Failed to find the teacher information\n";
    }
    system("pause");
}

void Teacher_change() {
    cout << "Please enter your teacher id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto & i : teacher_information) {
        if (i.id == id) {
            f = 1;
            i.change();
            cout << "Succeeded in modifying the information!\n";
        }
    }
    if (f == 0) {
        cout << "Failed to find the teacher information\n";
    }
    system("pause");
}

void Teacher_information_All() {
    cout << "name gender id major phone address age classes:\n";
    for (auto & i : teacher_information) {
        i.output_all();
    }
    system("pause");
}
