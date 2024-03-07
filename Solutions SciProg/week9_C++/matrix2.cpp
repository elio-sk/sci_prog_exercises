#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;


// Definition of vector classfrom the lecture notes
using std::vector;
using std::cout;
using std::ostream;

class Vector {
    
    private:
        vector<double> coeff;

    public:
        Vector(int dim=0, double init=0);
        int size() const;
        const double& operator()(int k) const;
        double& operator()(int k);
        double norm() const;

        };

Vector::Vector(int dim, double init) : coeff(dim,init) {}   
        
int Vector::size() const {return coeff.size();}
        
const double& Vector::operator()(int k) const{
    assert(k>=0 && k<size());
    return coeff[k];
    }
            
double& Vector::operator()(int k) {
    assert(k>=0 && k<size());
    return coeff[k];
    }

double Vector::norm() const {
    double sum = 0;
    for (int j=0; j<size(); ++j) {
        sum = sum + coeff[j]*coeff[j];
        }
    return sqrt(sum);
    }

ostream& operator<<(ostream& output, const Vector& x) {
    output << "\n";
    if (x.size()==0) {
        output << " empty vector";
        }
    else {
            for (int j=0; j<x.size(); ++j) {
            output << " " << x(j);
            }
        }
    output << "\n";
    return output;
    }


//Definition of matrix class from the lecture notes

class Matrix
{
    private:
        int n;
        char type;
        double value;
        vector<double> a;

    public:
        // constructor 
        Matrix(){
            n = 0;
            type = 'F';
            a = vector<double>(0);
            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }

        // constructor 
        Matrix(int n, char type){
            this->n = n;
            this->type = type;

            assert(type == 'F' || type == 'U' || type == 'L');

            if (type == 'F'){
                a = vector<double>(n*n); 
                for (int i = 0; i < n*n; i++){
                    a[i] = 0;
                }
            }

            else if (type == 'L' || type == 'U'){
                a = vector<double>((n*(n+1))/2);
                for (int i = 0; i < (n*(n+1))/2; i++){
                    a[i] = 0;
                }
            }

            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }

        // constructor 
        Matrix(int n, char type, double value){
            this->n = n;
            this->type = type;
            this->value = value;

            assert(type == 'F' || type == 'U' || type == 'L');

            if (type == 'F'){
                a = vector<double>(n*n);
                for (int i = 0; i < n*n; i++)
                {
                    a[i] = value;
                }
            }

            else if (type == 'L' || type == 'U'){
                a = vector<double>((n*(n+1))/2);
                for (int i = 0; i < (n*(n+1))/2; i++)
                {
                    a[i] = value;
                }
            }
            
            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }

        //Accessing elements of the matrix
        double& operator()(int i, int j){
    
            assert(i >= 0 && i < n);
            assert(j >= 0 && j < n);
            
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

        // print function
        void print(){
            if (type == 'F'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        printf("%f ", a[i*n + j]);
                    }
                    printf("\n");
                }
            }

            else if (type == 'L'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i >= j){
                            printf("%f ", a[(i*(i+1))/2 + j]);
                        }
                        else{
                            printf("0.000000 ");
                        }
                    }
                    printf("\n");
                }
            }

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
        
        // overload the operator | for matrix multiplication

        Vector operator|(const Vector& b){
            
            assert(n == b.size() && "Dimensions do not match");
            
            Vector x(n);
            
            if (type == 'U'){

                // solve the system Ux = b by backward substitution


                for (int i = n-1; i >= 0; i--){
                    double sum = 0;
                    for (int j = n-1; j > i; j--){
                        sum = sum + a[i*(i+1)/2 + j]*x(j); // 
                    }
                    x(i) = (b(i) - sum)/a[i*(i+1)/2 + i]; // 
                }

                // print the vector x
                cout << "The solution to the system Ux = b is: " << endl;
                for (int i = 0; i < n; i++){
                    cout << x(i) << endl;
                }
            }
            else {
                cout << "The | operator was defined only for upper triangular matrices " << endl;
            }
            return x;
        }
};


int main(){

    Matrix U(4,'U',5);
    cout << endl;
    cout << "U = " << endl;
    U.print();
    cout << endl;
    
    Vector b(4, 0.0);
    b(0) = 3.0;
    b(1) = 4.0;
    b(2) = 2.0;
    b(3) = -2.0;
    cout << "b = " << endl;
    for (int i = 0; i < 3; i++){
        cout << b(i) << endl;
    }
    cout << endl;
    U|b;
    cout << endl;
    return 0;
}
