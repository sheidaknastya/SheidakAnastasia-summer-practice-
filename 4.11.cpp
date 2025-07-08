#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdio> 

using namespace std;

struct Student {
    string surname;
    string name;
    string group;
};

struct Grade {
    string surname;
    int marks[5];
};


bool hasScholarship(const Grade& g) {
    for (int i = 0; i < 5; ++i) {
        if (g.marks[i] < 4) return false;
    }
    return true;
}

int main() {
    vector<Student> students;
    vector<Grade> grades;

    ifstream finF("students.txt");
    ifstream finG("grades.txt");

    if (!finF || !finG) {
        cout << "Один из файлов не найден.\n";
        return 1;
    }


    Student s;
    while (finF >> s.surname >> s.name >> s.group) {
        students.push_back(s);
    }

    Grade g;
    while (finG >> g.surname >> g.marks[0] >> g.marks[1] >> g.marks[2] >> g.marks[3] >> g.marks[4]) {
        grades.push_back(g);
    }

    finF.close();
    finG.close();


    rename("scholarship.txt", "scholarship.bak");

    ofstream fout("scholarship.txt");
    fout << left << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(10) << "Группа" << "\n";
    fout << "----------------------------------------\n";

    for (const auto& st : students) {
        for (const auto& gr : grades) {
            if (st.surname == gr.surname && hasScholarship(gr)) {
                fout << setw(15) << st.surname << setw(15) << st.name << setw(10) << st.group << "\n";
            }
        }
    }

    fout.close();

    remove("scholarship.bak");

    cout << "Ведомость сохранена в 'scholarship.txt'\n";
    return 0;
}
