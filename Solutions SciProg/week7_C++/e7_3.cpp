#include <iostream>
#include <cmath>
using namespace std;

string int2roman(int n) {
     string s = "";
    while (n > 0) {
        if (n >= 1000) {
            s += "M";
            n -= 1000;
        } else if (n >= 900) {
            s += "CM";
            n -= 900;
        } else if (n >= 500) {
            s += "D";
            n -= 500;
        } else if (n >= 400) {
            s += "CD";
            n -= 400;
        } else if (n >= 100) {
            s += "C";
            n -= 100;
        } else if (n >= 90) {
            s += "XC";
            n -= 90;
        } else if (n >= 50) {
            s += "L";
            n -= 50;
        } else if (n >= 40) {
            s += "XL";
            n -= 40;
        } else if (n >= 10) {
            s += "X";
            n -= 10;
        } else if (n >= 9) {
            s += "IX";
            n -= 9;
        } else if (n >= 5) {
            s += "V";
            n -= 5;
        } else if (n >= 4) {
            s += "IV";
            n -= 4;
        } else if (n >= 1) {
            s += "I";
            n -= 1;
        }
    }
    return s;
}

int roman2int(string s){
    int n = 0;
    while (s.size() > 0) {
        if (s[0] == 'M') {
            n += 1000;
            s.erase(0, 1);
        } else if (s[0] == 'D') {
            n += 500;
            s.erase(0, 1);
        } else if (s[0] == 'C') {
            if (s[1] == 'M') {
                n += 900;
                s.erase(0, 2);
            } else if (s[1] == 'D') {
                n += 400;
                s.erase(0, 2);
            } else {
                n += 100;
                s.erase(0, 1);
            }
        } else if (s[0] == 'L') {
            n += 50;
            s.erase(0, 1);
        } else if (s[0] == 'X') {
            if (s[1] == 'C') {
                n += 90;
                s.erase(0, 2);
            } else if (s[1] == 'L') {
                n += 40;
                s.erase(0, 2);
            } else {
                n += 10;
                s.erase(0, 1);
            }
        } else if (s[0] == 'V') {
            n += 5;
            s.erase(0, 1);
        } else if (s[0] == 'I') {
            if (s[1] == 'X') {
                n += 9;
                s.erase(0, 2);
            } else if (s[1] == 'V') {
                n += 4;
                s.erase(0, 2);
            } else {
                n += 1;
                s.erase(0, 1);
            }
        }
    }
    return n;
}

int main(){
    int n=77;
    cout << "Integer to roman" << endl;
    string r=int2roman(n);
    cout << r << endl;

    string ss = "X";
    cout << "Roman to integer" << endl;
    int k = roman2int(ss);
    cout << k << endl;

    return 0;
}
