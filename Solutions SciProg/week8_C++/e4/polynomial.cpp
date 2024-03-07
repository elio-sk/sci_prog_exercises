#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;


class Polynomial
{
private:
	int n; 		
	double* a;  

public:
	
	Polynomial(int n) { // constructor without vector of coefficients a
		assert(n >= 0);
		this->n = n;
		a = new double[n + 1]; // new allocates memory 
		
		for (int i = 0; i <= n; i++)
			a[i] = 0; // initialize all coefficients = zero
	}

	
		Polynomial(int n, double* a) { // constructor
		assert(n >= 0);
		this->n = n;
		this->a = new double[n + 1];

		for (int i = 0; i <= n; i++)
			this->a[i] = a[i];
	}

	~Polynomial() {
		delete[] a;
	}
	

    
	Polynomial(const Polynomial &p) { // copy constructor
		n = p.n;
		a = new double[n + 1];
		for (int i = 0; i <= n; i++)
			a[i] = p.a[i];
	}


	Polynomial& operator=(const Polynomial &p) { 	// assignment operator
		if (this != &p) {
			delete[] a;
			n = p.n;
			a = new double[n + 1];
			for (int i = 0; i <= n; i++)
				a[i] = p.a[i];
		}
		return *this;
	}

	int degree() const {
		return n;
	}

	int getCoefficient(int i) const {
		return a[i];
	}
};


ostream &operator<<(ostream &os, const Polynomial &p) { // overload the << operator to print a polynomial p to the screen via the syntax cout << p.

	int nonzero_counter = 0;

	for (int i = p.degree(); i >= 0; i--) {
		if (p.getCoefficient(i) != 0) {
			nonzero_counter++;
			if (i == 0)
				os << p.getCoefficient(i);
			else if (i == 1)
				os << p.getCoefficient(i) << "x";
			else
				os << p.getCoefficient(i) << "x^" << i;
			if (i > 0)
				os << " + ";
		}
	}


	if (nonzero_counter == 0) 	// if all coefficients are zero, print 0
		os << "0";
		
	return os;
}

int main(){
	Polynomial p1(5, new double[6]{ 3, 1, 7, 2, 7, 9 });
	cout << "p1: " << p1 << endl;

	Polynomial p2(p1);
	cout << "p2: " << p2 << endl;

	Polynomial p3(3);
	cout << "p3: " << p3 << endl;


	return 0;
}
