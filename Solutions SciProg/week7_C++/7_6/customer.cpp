#include "customer.hpp"

// main program
int main(){
    
    // create a new customer, input from the user
    Customer c1("John", 3000, 1111);
    cout << "The customer's name is " << c1.getName() << "." << endl;
    cout << "The customer's balance is " << c1.getBalance() << "." << endl;
    cout << "The customer's PIN is " << c1.getPin() << "." << endl;

    c1.printBalance();
    c1.checkPin(0000);
    c1.checkPin(1111);
  

    c1.setBalance(c1.getBalance() + 100); // add 100 to the balance
    cout << "The customer's new balance is " << c1.getBalance() << "." << endl;

    int money, my_pin;
    cout << "Enter the amount you want to withdraw" << endl; 
    cin >> money;
    cout << "Enter your PIN" << endl;
    cin >> my_pin;
    c1.drawMoney(money, my_pin);
    cout << "The new balance is " << c1.getBalance() << "." << endl;
    return 0;
}
    
