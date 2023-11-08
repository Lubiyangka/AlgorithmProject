#include <bits/stdc++.h>

using namespace std;
struct Student {
    int id[6];
    string name;
    int grade;
};

Student student[5];

void input(int n) {
    bool isFirst = true;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int j = 0;
        while (true) {
            char t;
            scanf("%c", &t);
            if (isFirst) {
                isFirst = false;
                continue;
            }
            if (t == '\n') {
                break;
            }
            if (t == ' ') {
                cnt++;
                continue;
            }
            if (cnt == 0) {
                student[i].id[j] = t - '0';
                j++;
            } else if (cnt == 1) {
                student[i].name.push_back(t);
            } else {
                student[i].grade = student[i].grade * 10 + (t - '0');
            }
        }
    }
}

void output(int n) {
    for (int i = 0; i < n; i++) {
        for (int j: student[i].id) {
            cout << j;
        }
        cout << " " << student[i].name << " " << student[i].grade << "\n";
    }
}

bool isBigger(int index) {
    int x = 0, y = 0;
    for (int i = 0; i < 6; i++) {
        x = x * 10 + student[index].id[i];
        y = y * 10 + student[index + 1].id[i];
    }
    return x > y;
}

bool sortById(const Student &x, const Student &y) {
    for (int i = 0; i < 6; ++i) {
        if (x.id[i] != y.id[i]) {
            return x.id[i] < y.id[i];
        }
    }
    return false;
}

bool compareByName(const Student &x, const Student &y) {
    if (x.name != y.name) {
        return x.name < y.name;
    } else {
        return sortById(x, y);
    }
}

bool compareByGrade(const Student &x, const Student &y) {
    if (x.grade != y.grade) {
        return x.grade < y.grade;
    } else {
        return sortById(x, y);
    }
}

void swapStudent(Student &x, Student &y){
    Student temp;
    temp = x;
    x = y;
    y = temp;
}

void sortTest(int n, int order) {
    if (order == 1) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (isBigger(j)) {
                    swapStudent(student[j], student[j + 1]);
                }
            }
        }
    } else if (order == 2) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if(!compareByName(student[j], student[j + 1])){
                    swapStudent(student[j], student[j + 1]);
                }
            }
        }
//        sort(student, student + n, compareByName);
    } else {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if(!compareByGrade(student[j], student[j + 1])){
                    swapStudent(student[j], student[j + 1]);
                }
            }
        }
//        sort(student, student + n, compareByGrade);
    }
}

int main() {
    int N = 0;
    int c = 0;
    cin >> N >> c;
    input(N);
    sortTest(N, c);
    output(N);
}
