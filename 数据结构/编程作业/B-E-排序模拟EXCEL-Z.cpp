#include <bits/stdc++.h>

using namespace std;
struct Student {
    string id;
    string name;
    int grade;
};

Student student[100];

bool compareById(Student &x, Student &y) {
    return x.id < y.id;
}

bool compareByName(Student &x, Student &y) {
    if (x.name == y.name) {
        return x.id < y.id;
    } else {
        return x.name < y.name;
    }
}

bool compareByGrade(Student &x, Student &y) {
    if (x.grade == y.grade) {
        return x.id < y.id;
    } else {
        return x.grade < y.grade;
    }
}

int main() {
    int N = 0;
    int c = 0;
    cin >> N >> c;
    for (int i = 0; i < N; i++) {
        cin >> student[i].id >> student[i].name >> student[i].grade;
    }
    if (c == 1) {
        sort(student, student + N, compareById);
    } else if (c == 2) {
        sort(student, student + N, compareByName);
    } else {
        sort(student, student + N, compareByGrade);
    }
    for (int i = 0; i < N; i++) {
        cout << student[i].id << " " << student[i].name << " " << student[i].grade << endl;
    }
}
