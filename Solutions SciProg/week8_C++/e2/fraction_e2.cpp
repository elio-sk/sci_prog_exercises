
#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

class Fraction {
private:
	int num; 
	int den; 

public:

	Fraction(int c, int d){ 	// constructor
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


	Fraction() { 	// standard constructor (without parameters)
		num = 0;
		den = 1;
		cout << "Fraction created: " << num << "/" << den << endl;
	}

	
	Fraction(const Fraction& f) { // copy constructor
		num = f.num;
		den = f.den;
		cout << "Copy constructor called" << endl;
	}

	
	Fraction& operator=(const Fraction& f) { // assignment operator
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

	
	~Fraction() { // destructor
		cout << "Fraction destructor called for " << num << "/" << den << endl;
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

	void reduce(){
		int gcd = 1;
		int a = abs(num);
		int b = abs(den);
		while (b != 0) {
			int r = a % b;
			a = b;
			b = r;
		}
		gcd = a;
		num /= gcd;
		den /= gcd;
		cout << "Fraction reduced to " << num << "/" << den << endl;
	}
};

int main() {
	Fraction f1(21, 9);
	Fraction f2(35, -210);

	cout << "f1 before reduction: ";
	f1.print();
	f1.reduce();
	cout << "f1 after reduction: ";
	f1.print();
	
	cout << "f2 before reduction: ";
	f2.print();
	f2.reduce();
	cout << "f2 after reduction: ";
	f2.print();

	return 0;
}
