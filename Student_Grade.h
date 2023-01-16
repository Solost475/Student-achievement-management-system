#include <string>
#include <iostream>

#pragma once
using namespace std;

class Student_Grade {

public:
    string id, name;
    int chinese, english, math, sum;

    void output() {
        cout << "id name chinese math english:\n";
        cout << id << " " << name << " " << chinese << " " << math << " " << english << endl;
    }

    void student_grade_change() {
        int x;
        cout << "1.chinese grade" << endl;
        cout << "2.math grade" << endl;
        cout << "3.english grade" << endl;
        cin >> x;
        cout << "Please enter the grade you want to modify\n";
        switch (x) {
            case 1:
                cin >> chinese;
                break;
            case 2:
                cin >> math;
                break;
            case 3:
                cin >> english;
                break;
        }
        sum = chinese + math + english;
    }
};

vector<Student_Grade> student_Grade;
