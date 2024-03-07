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
    
        Matrix(){
            n = 0;
            type = 'F';
            a = vector<double>(0); 
            cout << "Matrix created: " << n << "x" << n << " " << type << endl;
        }
    

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

        double& operator()(int i, int j){
    
            assert(i >= 0 && i < n);
            assert(j >= 0 && j < n);
            
            // if type is 'F'
            if (type == 'F'){
                assert(i >= 0 && i < n);
                assert(j >= 0 && j < n);
                return a[i*n + j];
            }

            else if (type == 'L'){
                assert(i >= 0 && i < n);
                assert(j >= 0 && j < n);
                return a[(i*(i+1))/2 + j];
            }

            else {
                assert(i >= 0 && i < n);
                assert(j >= 0 && j < n);
                assert(i <= j);
                    return a[j*(j+1)/2 + i];
            }
        }

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
        
        //Trace of a matrix
        double trace(){
            double trace = 0;
            if (type == 'F'){
                for (int i = 0; i < n; i++){
                    trace += a[i*n + i];
                }
            }
            else if (type == 'L'){
                for (int i = 0; i < n; i++){
                    trace += a[(i*(i+1))/2 + i];
                }
            }
            else if (type == 'U'){
                for (int i = 0; i < n; i++){
                    trace += a[i*(i+1)/2 + i];
                }
            }
            return trace;
        }

 
        bool isDiagonal(){
            if (type == 'F'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i != j && a[i*n + j] != 0){
                            return false;
                        }
                    }
                }
            }
            else if (type == 'L'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i != j && a[(i*(i+1))/2 + j] != 0){
                            return false;
                        }
                    }
                }
            }
            else if (type == 'U'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i != j && a[j*(j+1)/2 + i] != 0){
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        bool isSymmetric()
        {
            
            if (isDiagonal()){ // if diagonal is true
                return true;
            }

            else{
                // three cases: type is F, type is L or type is U
                if (type == 'F'){
                    for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                            if (i != j && a[i*n + j] != a[j*n + i]){
                                return false;
                            }
                        }
                    }
                }
                else if (type == 'L'){
                    for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                            if (i != j && a[(i*(i+1))/2 + j] != a[(j*(j+1))/2 + i]){
                                return false;
                            }
                        }
                    }
                }
                else if (type == 'U'){
                    for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                            if (i != j && a[j*(j+1)/2 + i] != a[i*(i+1)/2 + j]){
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }

    
        bool isSkewSymmetric(){
            if (type == 'F'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i != j && a[i*n + j] != -a[j*n + i]){
                            return false;
                        }
                    }
                }
            }

            // if the type is L and all the elements are 0, then return true. otherwise, return false.
            else if (type == 'L'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (a[(i*(i+1))/2 + j] != 0){
                            return false;
                        }
                    }
                }
            }

            // if the type is U and all the elements are 0, then return true. otherwise, return false.
            else if (type == 'U'){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (a[j*(j+1)/2 + i] != 0){
                            return false;
                        }
                    }
                }
            }
            return true;
        }    
};

int main(){
    Matrix m1(3, 'F', 2);
    m1(0,0) = 4.0;
    m1(1,1) = 5.0;
    m1(2,2) = 6.0;

    Matrix m2(3, 'F', 2);
    m2(1,0) = 1.0;
    m2(0,1) = 3.0;

    Matrix m3(3, 'F', 2);
    m3(1,0) = 3.0;
    m3(0,1) = 3.0;
    m3(2,2) = 9.0;
    m3(2,0) = 4.0;
    m3(0,2) = 4.0;

    cout << endl << "Matrix 1" << endl;
    m1.print();
    cout << endl << "Matrix 2" << endl;
    m2.print();


    cout << endl << "Trace of Matrix 1: " << m1.trace() << endl;
    cout << endl << "Trace of Matrix 2: " << m2.trace() << endl;


    cout << endl << "Is Matrix 1 diagonal? " << m1.isDiagonal() << endl;
    cout << endl << "Is Matrix 2 diagonal? " << m2.isDiagonal() << endl;


    cout << endl << "Is Matrix 1 symmetric? " << m1.isSymmetric() << endl;
    cout << endl << "Is Matrix 2 symmetric? " << m2.isSymmetric() << endl;

    cout << endl << "Is Matrix 1 skew-symmetric? " << m1.isSkewSymmetric() << endl;
    cout << endl << "Is Matrix 2 skew-symmetric? " << m2.isSkewSymmetric() << endl;


}

