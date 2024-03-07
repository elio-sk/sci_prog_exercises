#include "name.hpp"

int main()
{
	Name n1("Elio", "Skenderaj");
	cout << " First name is " << n1.getFirstname() << " and surname is " << n1.getSurname() << "." << endl;
    cout << "The full name is: ";
    n1.printName();
    cout << endl << endl;

    
	Name n2("Matthew David Wilburn", "White");
	cout << " First name is " << n2.getFirstname() << " and surname is " << n2.getSurname() << "." << endl;
    cout << "The full name is: ";
    n2.printName();
    cout << endl << endl;
    
	return 0;
}

