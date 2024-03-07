
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;





class Fraction {
private:
	int num; 
	int den; 

public:
	
	Fraction(int c, int d){  // constructor
		assert(d != 0);
		if (d < 0) {
			num = -c;
			den = abs(d);
		}
		else {
			num = c;
			den = d;
		}
		cout << "Fraction created: " << num << "/" << den << endl;
	}

	// standard constructor (without parameters)
	Fraction() {
		num = 0;
		den = 1;
		cout << "Fraction created: " << num << "/" << den << endl;
	}

	
	Fraction(const Fraction& f) { // copy constructor
		num = f.num;
		den = f.den;
		cout << "Copy constructor called" << endl;
	}

	
	Fraction& operator=(const Fraction& f) { 
		if (this != &f) {
			num = f.num;
			den = f.den;
			cout << "Assignment operator called" << endl;
		}
		else
		{
			cout << "Assignment to itself" << endl;
		}
		return *this;
	}

	
	~Fraction() {
		cout << "Fraction destructor called for " << num << "/" << den << endl; // destructor
	}

	void setNum(int c) {
		num = c;
	}

	void setDen(int d) {
		den = d;
	}

	int getNum() {
		return num;
	}

	int getDen() {
		return den;
	}

	void print() {
		cout << num << "/" << den << endl;
	}
};

int main() {
	Fraction f1; // calling standard constructor
	Fraction f2(1, 2); // calling constructor with parameters
	Fraction f3(3, -4); // calling constructor: we want the fraction to be constructed as -3/4
	Fraction f4(f1); // using copy constructor
	Fraction f5 = f1; // using assignment operator

	cout << "f1: ";
	f1.print();
	cout << "f2: ";
	f2.print();
	cout << "f3: ";
	f3.print();
	cout << "f4: ";
	f4.print();
	cout << "f5: ";
	f5.print();

	f1.setNum(17);
	f1.setDen(55);
	cout << "f1: ";
	f1.print();
	cout << "The numerator of f1 is " << f1.getNum() << " and the denominator is " << f1.getDen() << "." << endl;

	return 0;
}
