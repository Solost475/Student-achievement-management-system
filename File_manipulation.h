#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Student_Grade.h"
#include "Student_Information.h"
#include "Teacher_Information.h"


#pragma once
using namespace std;

void op(string local) {
    ifstream read;
    read.open(local, ios::in);
    ofstream write;
    write.open("1.txt", ios::out | ios::trunc);
    vector<string> q;
    string s;
    while (getline(read, s)) {
        int n = s.size();
        if (n == 0) continue;
        q.push_back(s);
    }
    int n = q.size();
    for (int i = 0; i < n; i++) {
        write << q[i];
        if (i != n - 1) {
            write << endl;
        }
    }
    read.close();
    write.close();
}

void Read_data() {
    // op("student_Grade_file.txt");
    // op("student_information_file.txt");
    // op("teacher_information_file.txt");
    ifstream student_Grade_file, student_information_file, teacher_information_file;
    student_Grade_file.open("student_Grade_file.txt", ios::in);
    if (!student_Grade_file) {
        cout << "fail to open the student_Grade_file.txt" << endl;
        system("pause");
        return;
    }
    while (student_Grade_file.peek() != EOF) {
        string id, name;
        int chinese, math, english, sum;
        //student_Grade_file << x.id << " " << x.name << " " << x.chinese << " " << x.math << " " << x.english << " " << x.sum << endl;
        student_Grade_file >> id >> name >> chinese >> math >> english >> sum;
        Student_Grade stu;
        stu.id = id, stu.name = name, stu.chinese = chinese, stu.math = math, stu.english = english, stu.sum = sum;
        student_Grade.push_back(stu);
    }
    student_Grade.pop_back();
    student_Grade_file.close();
    // string name, gender, id, major, phone, address, age, classes;

    student_information_file.open("student_information_file.txt", ios::in);
    if (!student_information_file) {
        cout << "fail to open the student_information_file.txt" << endl;
        system("pause");
        return;
    }
    while (student_information_file.peek() != EOF) {
        Student_Information stu;
        student_information_file >> stu.name >> stu.gender >> stu.id >> stu.major >> stu.phone >> stu.address >> stu.age
                                 >> stu.classes;
        student_information.push_back(stu);
    }
    student_information_file.close();

    teacher_information_file.open("teacher_information_file.txt", ios::in);
    if (!teacher_information_file) {
        cout << "fail to open the teacher_information_file.txt" << endl;
        system("pause");
        return;
    }
    while (teacher_information_file.peek() != EOF) {
        Teacher_Information teacher;
        string class1;
        teacher_information_file >> teacher.name >> teacher.gender >> teacher.id >> teacher.major >> teacher.phone
                                 >> teacher.address >> teacher.age;
        while (teacher_information_file >> class1) {
            if (teacher_information_file.get() == '\n') break;
            teacher.Teacher_Information::classes.push_back(class1);
        }
        teacher_information.push_back(teacher);
    }
    teacher_information_file.close();
}

void Save_data() {
    ofstream student_Grade_file, student_information_file, teacher_information_file;
    student_Grade_file.open("student_Grade_file.txt", ios::out);
    for (auto x: student_Grade) {
        //student_Grade_file >> id >> name >> chinese >> math >> english >> sum;
        student_Grade_file << x.id << " " << x.name << " " << x.chinese << " " << x.math << " " << x.english << " "
                           << x.sum << endl;
    }
    student_Grade_file.close();
    // string name, gender, id, major, phone, address, age, classes;

    student_information_file.open("student_information_file.txt", ios::out);
    for (auto x: student_information) {
        //student_information_file >> stu.name >> stu.gender >> stu.id >> stu.major >> stu.phone >> stu.address >> stu.age >> stu.classes;
        student_information_file << x.name << " " << x.gender << " " << x.id << " " << x.major << " " << x.phone << " "
                                 << x.address << " " << x.age << " " << x.classes << endl;
    }
    student_information_file.close();

    teacher_information_file.open("teacher_information_file.txt", ios::out);
    string class1;
    for (auto x: teacher_information) {
        teacher_information_file << x.name << " " << x.gender << " " << x.id << " " << x.major << " " << x.phone << " "
                                 << x.address << " " << x.age << " ";
        for (auto y: x.Teacher_Information::classes) {
            teacher_information_file << y << " ";
        }
        teacher_information_file << endl;
    }
    teacher_information_file.close();

    student_Grade.clear();
    student_information.clear();
    teacher_information.clear();
    Read_data();
}
