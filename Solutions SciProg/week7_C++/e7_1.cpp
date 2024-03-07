#include <iostream>
#include <cmath>
using namespace std;

string dec2bin(int n) {
    string s = "";
    while (n > 0) {
        s = (n % 2 == 0 ? "0" : "1") + s;
        n /= 2;
    }
    return s;
}

int bin2dec(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        n += (s[i] - '0') * pow(2, s.size() - i - 1);
    }
    return n;
}

int main(){
    int n=77;
    cout << "Decimal to binary" << endl;
    string s = dec2bin(n);
    cout << dec2bin(n) << endl;

    string s1 = "10101";
    cout << "Binary to decimal" << endl;
    int k = bin2dec(s1);
    cout << bin2dec(s1) << endl;

    return 0;
}
