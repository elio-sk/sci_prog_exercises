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


	Polynomial(int n, double* a) { 	// constructor
		assert(n >= 0);
		this->n = n;
		this->a = new double[n + 1];
		for (int i = 0; i <= n; i++)
			this->a[i] = a[i];
	}

	~Polynomial() {
		delete[] a;
	}


	Polynomial(const Polynomial &p) { 	// copy constructor
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


	const double& operator[](int i) const { 	// Accessing the coefficients of the polynomial via [] - const object
		assert(i >= 0 && i <= n);
		return a[i];
	}

	
	double& operator[](int i) {    
		assert(i >= 0 && i <= n); // Accessing the coefficients of the polynomial via [] - normal object
		return a[i];
	}
};


ostream &operator<<(ostream &os, const Polynomial &p) { // overload the PRINT operator to print a polynomial

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


	if (nonzero_counter == 0) 	//  print 0 if all coefficients are zero
		os << "0";
		
	return os;
}

int main(){
	Polynomial p1(3, new double[4]{ 1, 1, 1, 1 });
	cout << "p1: " << p1 << endl;

	p1[2] = 2;

	cout << "p1: " << p1 << endl;

	return 0;
}
