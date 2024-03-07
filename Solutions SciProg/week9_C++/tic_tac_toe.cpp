#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

class Matrix
{
private:
	int n; 					
	double* vector;  		
	char type;				// 

public:
	
	// constructor: Matrix 0x0
	Matrix()
	{
        n = 0;
        type = 'F';
        vector = new double[0]; 		// Allocating a vector of length 0 with values of type double
       
    }
	
	// constructor with all entries 0
	Matrix(int n) 
	{
		assert(n >= 0);
		this->n = n;
		vector = new double[n*n]; 			// "New" allocates memoryof type double
		
		for (int i = 0; i <= n*n; i++)
			vector[i] = 0;					// Set all coefficients to zero
		this->type = 'F';
	}

	// Constructor which sets all entries a given value
	Matrix(int n, char type, double value) 
	{
		assert(n >= 0);
		this->n = n;
		this->type = type;
		
		vector = new double[n*n]; 			
		
		if (type == 'F')		
		{
			for (int i = 0; i < n*n; i++)
			this->vector[i] = value;
		}
		
		if (type == 'U' || type == 'L')			
		{
			for (int i = 0; i < n*(n+1)/2; i++)
			this->vector[i] = value;
		}
		
	}
	
	
	~Matrix() 
	{
		delete[] vector;
	}
	
    // Copy constructor
	Matrix(const Matrix &M) 
	{
		n = M.n;
		vector = new double[n*n];
		for (int i = 0; i <= n*n; i++)
			vector[i] = M.vector[i];
	}

	// Assignment operator
	Matrix& operator=(const Matrix &M) 
	{
		if (this != &M) 
		{
			delete[] vector;
			n = M.n;
			vector = new double[n + 1];
			for (int i = 0; i <= n; i++)
				vector[i] = M.vector[i];
		}
		return *this;
	}
	

	int dimension() const 
	{
		return n;
	}
	
	// Returns type of the matrix
	char diag() const 
	{
		return type;
	}


	// Sets an entry of the matrix
	
	void setCoefficient(int i, int j, double value) const		// "value" is the value of the component we want to change
	{
		assert(i > 0 && i <= n);
        assert(j > 0 && j <= n);
        
        // If type is 'F'
        if (type == 'F')
			{
            vector[i-1 + (j-1)*n]=value;
        	}

        // If type is 'L': The vector fills from the upper-left corner by rows
        else if (type == 'L')
			{
            if (i >= j)
				{
                vector[(i*(i-1))/2 + j-1]=value;
            	}
        	}

        // If type is 'U': The vector fills from the upper-left corner by columns
        else if (type == 'U')
			{
            if(i<=j)
				{
                vector[j*(j-1)/2 + i-1]=value;
            	}
            }
            
		else
			{
            cout << "Error: type not recognized. " << endl;
        	}
	}
	
	
	// Returns a specified entry of the matrix: Depending of the type, we define where there must be zeros.
	
	double getCoefficient(int i, int j) const 
	{
	
		assert(i > 0 && i <= n);
        assert(j > 0 && j <= n);
        
        // If type is 'F'
        if (type == 'F')
			{
            return vector[i-1 + (j-1)*n];
        	}

        // If type is 'L': The vector fills from the upper-left corner by rows
        else if (type == 'L')
			{
            if (i >= j)
				{
                return vector[(i*(i-1))/2 + j-1];
            	}
            else
				{
                return 0;
            	}
        	}

        // If type is 'U': The vector fills from the upper-left corner by columns
        else if (type == 'U')
			{
            if(i<=j)
				{
                return vector[j*(j-1)/2 + i-1];
            	}
            else 
				{
                return 0.0;
            	}
        	}
            
		else
			{
            cout << "Error: type not recognized. " << endl;
            return 0; 
        	}
	}
	
	
};


		       
// Overload the << operator to print a Matrix M to the screen via the syntax ''cout << M''
ostream &operator<<(ostream &os, const Matrix &M) 
{
	os << "\n";
	for (int i = 1; i<=M.dimension(); i++) 			// We move over all the coefficients of the matrix
	{
		for (int j = 1; j<=M.dimension(); j++)
		{
			os << M.getCoefficient(i,j) << "\t";
		}
		os << "\n";
	}
	
	return os;
}



int main()
{
	Matrix M=Matrix(3);	
	printf("Here we have THE BOARD:\n");
	cout << M << endl;
	int flag;	
	
	for (int k=0; k<9; k++)
	{
		int player=k%2+1;
		printf("Player %d, introduce the coordinates to place your token: ",player);
		
		int i,j;
		scanf("%d %d", &i, &j);
		if (M.getCoefficient(i,j)!=0)
		{
			flag=1;
			cout << "Play in an empty spot!" << endl;
			break;
		}
		
		M.setCoefficient(i,j,player);
		cout << M << endl;
		
		// Winning condition?
		flag=0;
		for (int l=1;l<3;l++)
		{
			// Controlling columns:
			if (M.getCoefficient(1,l)==player && M.getCoefficient(2,l)==player && M.getCoefficient(3,l)==player)
			{
				flag=1;
			}
			// Controlling rows:
			if (M.getCoefficient(l,1)==player && M.getCoefficient(l,2)==player && M.getCoefficient(l,3)==player)
			{
				flag=1;
			}
			// Controlling diagonals:
			if (M.getCoefficient(1,1)==player && M.getCoefficient(2,2)==player && M.getCoefficient(3,3)==player)
			{
				flag=1;
			}
			if (M.getCoefficient(1,3)==player && M.getCoefficient(2,2)==player && M.getCoefficient(3,1)==player)
			{
				flag=1;
			}
		}
		
		if (flag==1)
		{
			printf("PLAYER %d WINS !!!\n\n",player);
			break;
		}
	}
	
	if (flag!=1)
	{
		printf("THIS IS A TIE !!!");
	}	
	
}
