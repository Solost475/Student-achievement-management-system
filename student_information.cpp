#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;

class Student_Grade {

public:
    string id;
    int chinese, english, math, sum;
    Student_Grade(string ID)
    {
        id = ID;
        cout << "Please enter the grade of Chinese math English:\n";
        cin >> chinese >> math >> english;
        cout << "Enter successfully\n";
        sum = chinese + math + english;
    }
    void Student_grade_change()
    {
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

class Student_Information {
public:
    void input()
    {
        cout << "name gender id major phone address age class:\n";
        cin >> name >> gender >> id >> major >> phone >> address >> age >> classes;
        Student_Grade stu(id);
        student_Grade.push_back(id);
    }
    void output()
    {
        cout << "name:" << name << endl;
        cout << "gender:" << gender << endl;
        cout << "id:" << id << endl;
        cout << "major:" << major << endl;
        cout << "phone:" << phone << endl;
        cout << "address:" << address << endl;
        cout << "age:" << age << endl;
        cout << "class:" << classes << endl;
    }

    void output_all()
    {
        cout << name << " " << gender << " " << id << " " << major << " " << phone << " " << address << " " << age << " " << classes << endl;
    }

    void change()
    {
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

class Teacher_Information {

public:
    void input()
    {
        cout << "name gender id major phone address age class:\n";
        cin >> name >> gender >> id >> major >> phone >> address >> age >> classes;
    }
    void output()
    {
        cout << "name:" << name << endl;
        cout << "gender:" << gender << endl;
        cout << "id:" << id << endl;
        cout << "major:" << major << endl;
        cout << "phone:" << phone << endl;
        cout << "address:" << address << endl;
        cout << "age:" << age << endl;
        cout << "class:" << classes << endl;
    }

    void change()
    {
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
vector<Teacher_Information> teacher_information;
void Student_input()
{
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

void Student_add()
{
    Student_Information stu;
    stu.input();
    student_information.push_back(stu);
    cout << "Student information added successfully!\n";
    system("pause");
}

void Student_delete()
{
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

void Student_find()
{
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

void Student_change()
{
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

void Student_sort()
{
    cout << "Please enter the information you want to rank according to:\n";
    int x;
    cout << "1.sum\n";
    cout << "2.math\n";
    cout << "3.english\n";
    cout << "4.chinese\n";
    cin >> x;
    switch (x) {
    case 1:
        sort(student_Grade.begin(), student_Grade.end(), [&](Student_Grade& a, Student_Grade& b) { return a.sum > b.sum; });
        break;
    case 2:
        sort(student_Grade.begin(), student_Grade.end(), [&](Student_Grade& a, Student_Grade& b) { return a.math > b.math; });
        break;
    case 3:
        sort(student_Grade.begin(), student_Grade.end(), [&](Student_Grade& a, Student_Grade& b) { return a.english > b.english; });
        break;
    case 4:
        sort(student_Grade.begin(), student_Grade.end(), [&](Student_Grade& a, Student_Grade& b) { return a.chinese > b.chinese; });
        break;
    }
    cout << "Sort success!\n";
    system("pause");
}

void Student_qualified()
{
    int c1 = 0, c2 = 0, c3 = 0, n = student_Grade.size();
    for (auto x : student_Grade) {
        if (x.chinese < 60)
            c1++;
        if (x.math < 60)
            c2++;
        if (x.english < 60)
            c3++;
    }
    cout << "Chinese pass rate:" << c1 / n * 100 << "%\n";
    cout << "Math pass rate:" << c2 / n * 100 << "%\n";
    cout << "English pass rate:" << c3 / n * 100 << "%\n";
    system("pause");
}

void Student_information()
{
    cout << "Please enter your student id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_information.begin(); i != student_information.end(); i++) {
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

void Student_information_All()
{
    cout << "name gender id major phone address age classes:\n";
    for (auto i = student_information.begin(); i != student_information.end(); i++) {
        i->output_all();
    }
    system("pause");
}

void Student_grade_change()
{
    cout << "Please enter your student id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = student_Grade.begin(); i != student_Grade.end(); i++) {
        if (i->id == id) {
            f = 1;
            i->Student_grade_change();
            break;
        }
    }
    if (f == 0) {
        cout << "Failed to find the student information\n";
    }
    system("pause");
}

void Teacher_add()
{
    Teacher_Information teacher;
    teacher.input();
    teacher_information.push_back(teacher);
    cout << "Teacher information added successfully!\n";
    system("pause");
}

void Teacher_change()
{
    cout << "Please enter your teacher id\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = teacher_information.begin(); i != teacher_information.end(); i++) {
        if (i->id == id) {
            f = 1;
            i->change();
            cout << "Succeeded in modifying the information!\n";
        }
    }
    if (f == 0) {
        cout << "Failed to find the teacher information\n";
    }
    system("pause");
}

void Teacher_find()
{
    cout << "Please enter the id of the teacher you are looking for\n";
    string id;
    cin >> id;
    int f = 0;
    for (auto i = teacher_information.begin(); i != teacher_information.end(); i++) {
        if (i->id == id) {
            f = 1;
            cout << "The queried teacher information has been found\n";
            i->output();
        }
    }
    if (f == 0) {
        cout << "Failed to find the teacher information\n";
    }
    system("pause");
}

void menu()
{

    cout << "*===============================================================================================*" << endl;
    cout << "**&&&&&&&&&&&&&&& welcome to use the student information management system &&&&&&&&&&&&&&&&&&&&**" << endl;
    cout << "**                        0: exit                                                              **" << endl;
    cout << "**                        1: Input student information                                         **" << endl;
    cout << "**                        2: Add student information                                           **" << endl;
    cout << "**                        3: Delete student information                                        **" << endl;
    cout << "**                        4: Find student information                                          **" << endl;
    cout << "**                        5: Modify student information                                        **" << endl;
    cout << "**                        6: student achievement ranking                                       **" << endl;
    cout << "**                        7: students queried                                                  **" << endl;
    cout << "**                        8: Display student information                                       **" << endl;
    cout << "**                        9: Add teacher information                                           **" << endl;
    cout << "**                        10: Modify teacher information                                       **" << endl;
    cout << "**                        11: Find teacher information                                         **" << endl;
    cout << "**                        12: Display all the student information                              **" << endl;
    cout << "**                        13: Modify student grade                                             **" << endl;
    cout << "**&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&**" << endl;
    cout << "*===============================================================================================*" << endl;

    Student_Information stu;
    int x;
    cin >> x;
    system("cls");
    switch (x) {
    case 0:
        exit(0);
        break;
    case 1:
        Student_input();
        break;
    case 2:
        Student_add();
        break;
    case 3:
        Student_delete();
        break;
    case 4:
        Student_find();
        break;
    case 5:
        Student_change();
        break;
    case 6:
        Student_sort();
        break;
    case 7:
        Student_qualified();
        break;
    case 8:
        Student_information();
        break;
    case 9:
        Teacher_add();
        break;
    case 10:
        Teacher_change();
        break;
    case 11:
        Teacher_find();
        break;
    case 12:
        Student_information_All();
        break;
    case 13:
        Student_grade_change();
        break;
    default:
        printf("Invalid input!\n");
        system("pause");
    }
}
int main()
{
    while (1) {
        menu();
    }
    return 0;
}