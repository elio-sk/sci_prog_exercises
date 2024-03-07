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
    
    // Accessing the elements of the matrix
        double& operator()(int i, int j){
    
            assert(i >= 0 && i < n);
            assert(j >= 0 && j < n);
            
            
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
                            // print 0 as double type
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

    // Row sum norm
        double rowSumNorm(){
            double max = 0;

            // if matrix is L, U, or F
            if (type == 'F')
            {
                for (int i = 0; i < n; i++){
                    double sum = 0;
                    for (int j = 0; j < n; j++){
                        sum += abs(a[i*n + j]);
                    }
                    if (sum > max){
                        max = sum;
                    }
                }
                return max;
            }

            // Don't access all the elements depending on the type
            else if (type == 'L')
            {
                for (int i = 0; i < n; i++){
                    double sum = 0;
                    for (int j = 0; j < n; j++){
                        if (i >= j){
                            sum += abs(a[(i*(i+1))/2 + j]);
                        }
                    }
                    if (sum > max){
                        max = sum;
                    }
                }
                return max;
            }

            else{
                for (int i = 0; i < n; i++){
                    double sum = 0;
                    for (int j = 0; j < n; j++){
                        if (i <= j){
                            sum += abs(a[j*(j+1)/2 + i]);
                        }
                    }
                    if (sum > max){
                        max = sum;
                    }
                }
                return max;
            }
        }

        double columnSumNorm(){ // column sum norm


            // Don't access all the elements depending on the type
            double max = 0;

            if (type == 'F')
            {
            for (int i = 0; i < n; i++){
                double sum = 0;
                for (int j = 0; j < n; j++){
                    sum += abs(a[j*n + i]);
                }
                if (sum > max){
                    max = sum;
                }
            }
            return max;
            }
            
        
            else if (type == 'L')
            {
                for (int i = 0; i < n; i++){
                    double sum = 0;
                    for (int j = 0; j < n; j++){
                        if (i <= j){
                            sum += abs(a[(j*(j+1))/2 + i]);
                        }
                    }
                    if (sum > max){
                        max = sum;
                    }
                }
                return max;
            }

            
            else{
                for (int i = 0; i < n; i++){
                    double sum = 0;
                    for (int j = 0; j < n; j++){
                        if (i >= j){
                            sum += abs(a[i*(i+1)/2 + j]);
                        }
                    }
                    if (sum > max){
                        max = sum;
                    }
                }
                return max;
            }

        }
    
    // Frobenius norm
        double frobeniusNorm(){
            double sum = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    sum += a[i*n + j] * a[i*n + j];
                }
            }
            return sqrt(sum);
        }

};


int main(){
    Matrix m1(3, 'F', 0);
    m1(0,0) = -3.0;
    m1(0,1) = 6.0;
    m1(0,2) = 9.0;
    m1(1,1) = 4.0;
    m1(2,1) = 3.0;
    m1(2,2) = 7.0;

    Matrix m2(3, 'L', 4);
    m2(1,0) = 0.0;
    m2(2,1) = 7.0;
    m2(2,0) = 1.0;
    cout << endl << "Matrix 1" << endl;
    m1.print();
    cout << endl << "Matrix 2" << endl;
    m2.print();

    // Column sum norm
    cout << endl << "Column sum norm matrix1: " << m1.columnSumNorm() << endl;
    cout << endl << "Column sum norm matrix2: " << m2.columnSumNorm() << endl;

    // testing rowSumNorm()
    cout << endl << "Row sum norm matrix1: " << m1.rowSumNorm() << endl;
    cout << endl << "Row sum norm matrix2: " << m2.rowSumNorm() << endl;

    // testing frobeniusNorm()
    cout << endl << "Frobenius norm matrix1: " << m1.frobeniusNorm() << endl;
    cout << endl << "Frobenius norm matrix2: " << m2.frobeniusNorm() << endl;
    

    return 0;
}

