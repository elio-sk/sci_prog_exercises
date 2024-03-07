#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

class Matrix
{
    private:
        int n;
        char type;
        double value;
        vector<double> a;

    public:
        Matrix(){     // Standard constructor, which creates a 0x0 matrix with type 'F'   
            n = 0;
            type = 'F';
            a = vector<double>(0); //  Initialize a to a vector of length 0
            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }
    

    //Constructor, which gets n and type as input parameters and allocates the corresponding matrix with all entries initialized with 0.
        Matrix(int n, char type){
            this->n = n;
            this->type = type;

        
            assert(type == 'F' || type == 'U' || type == 'L'); // Assert that the type is either 'F', 'U' or 'L'

        
            if (type == 'F'){ // If the type is 'F', then the matrix is a square matrix with nxn entries initialized with 0
                a = vector<double>(n*n); // Initialize a to a vector of length n*n
                for (int i = 0; i < n*n; i++){
                    a[i] = 0;
                }
            }

            // If the type is 'U' or 'L', then the matrix is a square matrix with nxn entries initialized with 0
            else if (type == 'L' || type == 'U'){
                a = vector<double>((n*(n+1))/2); //  Initialize a to a vector of length n*(n+1)/2
                for (int i = 0; i < (n*(n+1))/2; i++){
                    a[i] = 0;
                }
            }

            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }

    // Constructor, which gets n and type as input parameters and allocates the corresponding matrix with all entries initialized with the value v.
        Matrix(int n, char type, double value){
            this->n = n;
            this->type = type;
            this->value = value;

            
            assert(type == 'F' || type == 'U' || type == 'L'); // assert type is either F, U or L

            
            if (type == 'F'){ // if type is 'F', then the matrix is a square matrix with nxn entries initialized with value
                a = vector<double>(n*n);
                for (int i = 0; i < n*n; i++)
                {
                    a[i] = value;
                }
            }

           
            else if (type == 'L' || type == 'U'){  // if type is 'L' or 'U', then the matrix is a square matrix with nxn entries initialized with value
                a = vector<double>((n*(n+1))/2);
                for (int i = 0; i < (n*(n+1))/2; i++)
                {
                    a[i] = value;
                }
            }
            
            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }

        double& operator()(int i, int j){
    
            assert(i >= 0 && i < n);// assert that i is between 0 and n-1
            assert(j >= 0 && j < n);// assert that j is between 0 and n-1
            
            // if type is 'F'
            if (type == 'F'){
                assert(i >= 0 && i < n); 
                assert(j >= 0 && j < n);
                return a[i*n + j];
            }

            // if type is 'L'
            else if (type == 'L'){ 
                assert(i >= 0 && i < n);
                assert(j >= 0 && j < n);
                return a[(i*(i+1))/2 + j];
            }

            // if type is 'U'
            else {
                assert(i >= 0 && i < n);
                assert(j >= 0 && j < n);
                assert(i <= j);
                    return a[j*(j+1)/2 + i];
            }
        }

 
        void print(){ // Prints the matrix
            
            // if type = F
            if (type == 'F'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        printf("%f ", a[i*n + j]);
                    }
                    printf("\n");
                }
            }

            // if type == L

            else if (type == 'L'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i >= j){
                            printf("%f ", a[(i*(i+1))/2 + j]);
                        }
                        else{
               
                            printf("0.000000 "); // print 0 as double type
                        }
                    }
                    printf("\n");
                }
            }

            // if type == U
            else if (type == 'U'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i <= j){
                            printf("%f ", a[j*(j+1)/2 + i]);
                        }
                        else{
                          
                            printf("0.000000 ");
                        }
                    }
                    printf("\n");
                }
            }
        }
        
};

// testing the functions
int main(){
    Matrix m1(3, 'F');
    Matrix m2(3, 'L');
    Matrix m3(3, 'U');
    Matrix m4(3, 'F', 2);
    Matrix m5(3, 'L', 2);
    Matrix m6(3, 'U', 2);
    m6(0,2) = 25.0;

    // printing
    cout << endl << "Matrix 1" << endl;
    m1.print();
    cout << endl << "Matrix 2" << endl;
    m2.print();
    cout << endl << "Matrix 3" << endl;
    m3.print();
    cout << endl << "Matrix 4" << endl;
    m4.print();
    cout << endl << "Matrix 5" << endl;
    m5.print();
    cout << endl << "Matrix 6" << endl;
    m6.print();
    cout << endl;

    

    cout << m1(0,2) << endl;
    cout << m2(0,2) << endl;
    cout << m3(0,2) << endl;
    cout << m4(0,2) << endl;
    cout << m5(0,2) << endl;
    cout << m6(0,2) << endl;

    return 0;
}

