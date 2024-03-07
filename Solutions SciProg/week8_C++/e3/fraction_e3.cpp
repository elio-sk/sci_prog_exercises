
#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;


class Fraction
{
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
	}


	Fraction() { 	// standard constructor (without parameters)
		num = 0;
		den = 1;
	}


	Fraction(const Fraction& f) { 	// copy constructor
		num = f.num;
		den = f.den;
		cout << "Copy constructor called" << endl;
	}


	Fraction& operator=(const Fraction& f) { 	// assignment operator
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


	~Fraction() { 	// destructor
		cout << "Fraction destructor called for " << num << "/" << den << endl;
	}

	void setNum(int c) {
		num = c;
	}

	void setDen(int d) {
		den = d;
	}

	int getNum() const {
		return num;
	}

	int getDen() const {
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
	}
};

const Fraction operator+(const Fraction &f1, const Fraction &f2)
{
	Fraction f3(f1.getNum() * f2.getDen() + f2.getNum() * f1.getDen(), f1.getDen() * f2.getDen());
	f3.reduce();
	return f3;
}

const Fraction operator-(const Fraction &f1, const Fraction &f2)
{
	Fraction f3(f1.getNum() * f2.getDen() - f2.getNum() * f1.getDen(), f1.getDen() * f2.getDen());
	f3.reduce();
	return f3;
}

const Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	Fraction f3(f1.getNum() * f2.getNum(), f1.getDen() * f2.getDen());
	f3.reduce();
	return f3;
}

const Fraction operator/(const Fraction &f1, const Fraction &f2)
{
	assert(f2.getNum() != 0);
	Fraction f3(f1.getNum() * f2.getDen(), f1.getDen() * f2.getNum());
	f3.reduce();
	return f3;
}

ostream &operator<<(ostream &os, const Fraction &f)
{
	os << f.getNum() << "/" << f.getDen();
	return os;
}

int main()
{
	Fraction f1(2, 3);
	cout << "f1: ";
	f1.print();

	Fraction f2(6, 7);
	cout << "f2: ";
	f2.print();

	cout << "f1 + f2 = " << f1 + f2 << endl;
	cout << "f1 - f2 = " << f1 - f2 << endl;
	cout << "f1 * f2 = " << f1 * f2 << endl;
	cout << "f1 / f2 = " << f1 / f2 << endl;

	return 0;
}
