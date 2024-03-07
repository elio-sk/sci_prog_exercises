#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
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



		Matrix (int n, char type, double lb, double ub){
			this->n = n;
			this->type = type;
			this->value = value;

			
			assert(type == 'F' || type == 'U' || type == 'L');

			
			if (type == 'F'){
				a = vector<double>(n*n);
				for (int i = 0; i < n*n; i++)
				{
					a[i] = lb + (ub - lb) * rand() / (RAND_MAX + 1.0);
				}
			}

			
			else if (type == 'L'){
				a = vector<double>((n*(n+1))/2);
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < i+1; j++)
					{
						a[i*(i+1)/2 + j] = lb + (ub - lb) * rand() / (RAND_MAX + 1.0);
					}
				}
			}

	
			else if (type == 'U'){
				a = vector<double>((n*(n+1))/2);
				for (int j = 0; j < n; j++)
				{
					for (int i = 0; i < j+1; i++)
					{
						a[i*(i+1)/2 + j] = lb + (ub - lb) * rand() / (RAND_MAX + 1.0);
					}
				}
			}
			
			cout << "Matrix created: " << n << "x" << n << " " << type << endl;
		}

    // Accessing
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
        
};


int main(){
    
	// 
	Matrix mL(3, 'L', -3, 3);
	mL.print();
	cout << endl;

	// Matrix U with random entries in [2 6]
	Matrix mU(3, 'U', 2, 6);
	mU.print();
	cout << endl;

	// Matrix F with random entries in [1.2 1.3]
	Matrix mF(3, 'F', 1.2, 1.3);
	mF.print();
	cout << endl;

    return 0;
}

