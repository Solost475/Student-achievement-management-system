#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Student_Information.h"
#include "Teacher_Information.h"
#include "File_manipulation.h"

using namespace std;

void menu() {
    cout << "*===============================================================================================*" << endl;
    cout << "**&&&&&&&&&&&&&&& welcome to use the student information management system &&&&&&&&&&&&&&&&&&&&**" << endl;
    cout << "**                        0: exit                                                              **" << endl;
    cout << "**                        1: Input student information                                         **" << endl;
    cout << "**                        2: Add student information                                           **" << endl;
    cout << "**                        3: Delete student information                                        **" << endl;
    cout << "**                        4: Find student information                                          **" << endl;
    cout << "**                        5: Modify student information                                        **" << endl;
    cout << "**                        6: student achievement ranking                                       **" << endl;
    cout << "**                        7: show students queried                                             **" << endl;
    cout << "**                        8: Display student information                                       **" << endl;
    cout << "**                        9: Display all the student information                               **" << endl;
    cout << "**                        10: Modify student grade                                             **" << endl;
    cout << "**                        11: Display student grade                                            **" << endl;
    cout << "**                        12: Input teacher information                                        **" << endl;
    cout << "**                        13: Add teacher information                                          **" << endl;
    cout << "**                        14: Delete teacher information                                       **" << endl;
    cout << "**                        15: Find teacher information                                         **" << endl;
    cout << "**                        16: Modify teacher information                                       **" << endl;
    cout << "**                        17: Display all the teacher information                              **" << endl;
    cout << "**                        18: Save data                                                        **" << endl;
    cout << "**&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&**" << endl;
    cout << "*===============================================================================================*" << endl;

    Student_Information stu;
    int x;
    cin >> x;
    system("cls");
    switch (x) {
        case 0:
            exit(0);
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
            Student_information_All();
            break;
        case 10:
            Student_grade_change();
            break;
        case 11:
            Student_grade_display();
            break;
        case 12:
            Teacher_input();
            break;
        case 13:
            Teacher_add();
            break;
        case 14:
            Teacher_delete();
            break;
        case 15:
            Teacher_find();
            break;
        case 16:
            Teacher_change();
            break;
        case 17:
            Teacher_information_All();
            break;
        case 18:
            Save_data();
            break;
        default:
            printf("Invalid input!\n");
            system("pause");
    }

}

int main() {
    cout << "If there is no initial data, proceed and the file is automatically created\n";
    Read_data();
    while (true) {
        menu();
    }
}