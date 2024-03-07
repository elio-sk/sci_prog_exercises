#ifndef _NAME_
#define _NAME_

#include <iostream>
#include <string>

using namespace std;

class Name
{
private:
    string firstname;
    string surname;

public:
    Name(string firstname, string surname)
    {
        this->firstname = firstname;
        this->surname = surname;
    }

    void setFullName(string fullname)
    {
        int pos = fullname.find_last_of(" "); // find the last space

        if (pos != string::npos) // if there is a space
        {
            firstname = fullname.substr(0, pos); // firstname is the first part of the string up to the last space (substring)
            surname = fullname.substr(pos + 1, fullname.length()); // surname is the second part of the string after the last space (substring)
        }
        else
        {
            firstname = fullname;  // if there is no space, firstname is the fullname
            surname = " ";
        }
    }

    string getFirstname()
    {
        return firstname;
    }

    string getSurname()
    {
        return surname;
    }

    void setFirstname(string firstname)
    {
        this->firstname = firstname;
    }

    void setSurname(string surname)
    {
        this->surname = surname;
    }

// Method printName().
// When having multiple first names, only the first one is printed. Other first names are printed as initials with a dot.

    void printName()
    {
        if (firstname.find(" ") != string::npos) // if there is a space
        {
            cout << firstname.substr(0, firstname.find_first_of(" ")+2) << ". " << surname; // it is +2 because we want to print 1 space and first letter of the next name
        }
        else
        {
            cout << firstname << " " << surname; // if there is only 1 first name, print it normally
        }
    }

};

int main();

#endif
