#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
	cout << "Input a string: ";
    string s;
    cin >> s;
    if (isPalindrome(s)) {
        cout << "Yes it is a palindrome" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
//you can do instead of if else the ? and : to check right away
