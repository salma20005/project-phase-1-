//# Auto detect text files and perform LF normalization
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string namecheck(string s) {
    if(s.size() < 5 || s.size() > 20) {
        return "";
    }
    for(char c : s) {
        if(!isalpha(c)) {
            return "";
        }
    }
    return s;
}

string CheckPass(string p){
    if(p.size() < 8 || p.size() > 20) {
        return "";
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

class Person {
protected:
    string name;
    int id;
    string password;
    double balance;
public:
    Person() {
        id = 0;
        balance = 0;
    }

    Person(string s , int i , string p , double b ) {
        name = namecheck(s);
        id = i;
        password = CheckPass(p);
        balance = b;
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

    void setBalance(double b ) {
        balance = b;
    }

    double getBalance() {
        return balance;
    }
};

class Employee : public Person {
    double salary;
public:
    Employee() {
        salary = 0;
    }

    Employee(string n ,int i , string p , double b , double s ) : Person(n,i,p,b) {
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
        cout << "The Balance is : " <<  getBalance() << endl;
        cout << "The salary is : "<< getSalary() << endl;
    }
};

int main() {
    Employee emp("Michelle", 1234, "securePass123", 10000, 5000);
    emp.DisplayInfo();
    return 0;
}
