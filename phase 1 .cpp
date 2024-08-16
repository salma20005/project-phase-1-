//# Auto detect text files and perform LF normalization
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string namecheck(string s) {
    if(s.size() < 5 || s.size() > 20) {
        return "name must be between 5 and 20 char";
    }
    for(char c : s) {
        if(!isalpha(c)) {
            return "name must be alphabetical only";
        }
    }
    return s;
}

string CheckPass(string p){
    if(p.size() < 8 || p.size() > 20) {
        return "password min. lenght is 8 and max length is 20";
    }
    return p;
}

double CheckSalary(double b ){
    if(b < 5000){
        cout << "The conditions not achieved" << endl;
        return -1;
    }
    return b;
}

double balanceCheck(double balance){
if (balance < 1500){
        cout << "Invalid Balance" <<endl;
    return -1 ;
}
return balance;

}


class Person {
protected:
    string name;
    int id;
    string password;

public:
    Person() {
        id = 0;
    }

    Person(string s , int i , string p ) {
        name = namecheck(s);
        id = i;
        password = CheckPass(p);
    }

    void setName(string s ) {
        string result = namecheck(s);
        if (result != "") {
            name = result;
        } else {
            cout << "Invalid name provided." << endl;
        }
    }

    string getName() {
        return name;
    }

    void setId(int i  ) {
        id = i;
    }

    int getId() {
        return id;
    }

    void setPassword(string p ) {
        string result = CheckPass(p);
        if (result != "") {
            password = result;
        } else {
            cout << "Invalid password provided." << endl;
        }
    }

    string getPassword() {
        return password;
    }
};

class Client: public Person {
double balance;

public:

    void setBalance(double balance){
    double result = balanceCheck(balance);
    if (result >= 1500){
    this-> balance = result;
     } else{
         cout << "Invalid Balance" <<endl;
     }
    }

    double getBalance(){
     return balance;
    }

    void deposite(double amount){
    balance += amount;
    }

    void withdraw(double amount){
        if (amount > balance){
            cout << "Not Enough Balance";
        } else{
           balance -= amount;
        }
    }

    void transferTo(double amount, Client& c){
        if (amount <= balance){
            c.deposite(amount);
            balance-=amount;
        }
    else {
        cout << "amount exceeds" << endl;
    }
    }

    void checkBalance(){
        if ( balanceCheck(balance) >= 1500){
            cout << this-> balance;
        }
    else{
        cout << "Invalid Balance";
    }

    }
    void DisplayInfo(){
        cout << "Name is : "<< getName() << endl;
        cout << "Id is : "<<getId()<< endl;
        cout << "The password is : "<< getPassword()   << endl;
        cout << "The Balance is : " <<  getBalance() << endl;
    }
};



class Employee : public Person {
    double salary;
public:
    Employee() {
        salary = 0;
    }

    Employee(string n ,int i , string p  , double s ) : Person(n,i,p) {
        salary = CheckSalary(s);
        if(salary == -1){
            cout << "Invalid Salary is provided"<< endl;
            salary =0;
        }

    }
    void setSalary(double s ){
        double result = CheckSalary(s);
        if (result != -1) {
            salary = result;
        } else {
            cout << "Invalid salary provided." << endl;
        }
    }
    double getSalary(){
        return salary;
    }
    void DisplayInfo(){
        cout << "Name is : "<< getName() << endl;
        cout << "Id is : "<<getId()<< endl;
        cout << "The password is : "<< getPassword()   << endl;
        cout << "The salary is : "<< getSalary() << endl;
    }
};

int main() {
    Employee emp("Michelle", 1234, "securePass123",5000);
    emp.DisplayInfo();
    Client c1,c2;
    c1.setBalance(2000);
    c1.deposite(1500);
    c1.transferTo(1000,c2);
    cout << "The balance is : ";
    c1.checkBalance();
    cout <<endl;

    return 0;
}
