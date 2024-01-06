#include <iostream>

using namespace std;

int ys, ye, ds, de;
int cnt;

bool isDate(int year, int month, int date);

bool isLeapYear(int y);

int main() {
    cin >> ys;
    cin >> ye;
    ds = ys % 10000;
    de = ye % 10000;
    ys /= 10000;
    ye /= 10000;
    for (int i = ys; i <= ye; i++) {
        int temp = i;
        int t[4];
        int month = 0, date = 0;
        for (int &j: t) {
            j = temp % 10;
            temp /= 10;
        }
        month = t[0] * 10 + t[1];
        date = t[2] * 10 + t[3];
        if (ys == ye) {
            if((month < ds / 100 || (month == ds / 100 && date < ds % 100))||(month > de / 100 || (month == de / 100 && date > de % 100))){
                continue;
            }
        } else {
            if (i == ys && (month < ds / 100 || (month == ds / 100 && date < ds % 100))) {
                continue;
            }
            if (i == ye && (month > de / 100 || (month == de / 100 && date > de % 100))) {
                continue;
            }
        }
        if (isDate(i, month, date)) {
//            cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
}

bool isDate(int year, int month, int date) {
    int d = 30;
    if (month > 0 && month < 13) {
        if (month == 2) {
            if (isLeapYear(year)) {
                d -= 1;
            } else {
                d -= 2;
            }
        } else {
            if (month != 4 && month != 6 && month != 9 && month != 11) {
                d++;
            }
        }
        if (date > 0 && date <= d) {
            return true;
        }
    }
    return false;
}

bool isLeapYear(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return true;
    }
    return false;
}