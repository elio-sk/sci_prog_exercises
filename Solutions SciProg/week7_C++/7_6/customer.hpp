#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>
using namespace std;

class Customer
{
private:
    string name;
    double balance;
    int pin;

public:
    Customer(string name, double balance, int pin)
    {
        this->name = name;
        this->balance = balance;
        this->pin = pin;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    void setPin(int pin)
    {
        this->pin = pin;
    }

    string getName()
    {
        return this->name;
    }

    double getBalance()
    {
        return this->balance;
    }

    int getPin()
    {
        return this->pin;
    }

    void printBalance()
    {
        cout << "The current balance is  " << this->balance << endl;
    }

    bool checkPin(int pin)
    {
        if (this->pin == pin)
        {
            cout << "PIN is correct." << endl;
            return true;
        }
        else
        {
            cout << "PIN is incorrect." << endl;
            return false;
        }
    }

    void drawMoney(double amount , int pin )
    {
        // use assert to intentionally terminate the program and return error messages whenever needed
        assert (this->checkPin(pin) && "PIN is incorrect.");
        {
            assert (amount > 0 && "The desired amount must be a positive number.");
            {
                if (amount <= this->balance)
                {
                    this->balance -= amount;
                    cout << "The new balance is " << this->balance << endl;
                    
                    if (this->balance < 10.00)
                    {
                        cout << "Warning, the balance is less than 10.00 EUR." << endl;
                    }

                }
                
                else
                {
                    cout << "The desired amount is larger than the current balance." << endl;
                }
            }
        }
    }

};

#endif


