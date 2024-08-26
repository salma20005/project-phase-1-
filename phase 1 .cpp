//# Auto detect text files and perform LF normalization
# pragma once
#include<iostream>
#include<string>
#include<cctype>

using namespace std;


class Validation {
public:
    static bool validateName(string name) {
        if (!(name.size() >= 5 && name.size() <= 20)) {
            cout << "The size is not valid\n ";
            return false;
        }
        for (int i = 0; i < name.size(); i++) {
            if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
                return false;
            }
        }
        return true;
    }

    static bool validatePass(string pass) {
        if (pass.size() >= 8 && pass.size() <= 20) {
            return true;
        } else {
            cout << " the password must be >= 8 And <= 20\n";
            return false;
        }
    }

    static bool valiadateBalance(double balance) {
        if (balance < 1500) {
            return false;
        }
        return true;

    }

    static bool validateSalary(double salary) {
        if (salary < 5000) {
            return false;
        }
        return true;
    }

};
class Person {
    protected:
        string name;
        int id;
        string password;

    public:
        Person() {
            id = 0;
            name = "";
            password = "";
        }

        Person(string n, int i, string p) {
            setId(i);
            setName(n);
            setPassword(p);

        }

        void setName(string s) {
            if (Validation::validateName(s)) {
                name = s;
            } else {
                cout << "Invalid name\n";
            }
        }

        string getName() {
            return name;
        }

        void setId(int i) {
            id = i;
        }

        int getId() {
            return id;
        }

        void setPassword(string p) {
            if (Validation::validatePass(p)) {
                password = p;
            } else {
                cout << "Invalid password\n";
            }
        }

        string getPassword() {
            return password;
        }

        void display() {
            cout << "Name is : " << name << endl;
            cout << "Id is : " << id << endl;
            cout << "Password is :" << password <<endl;
        }
    };

    class Client : public Person {
        double balance;

    public:
        Client() : Person() {
            balance = 0;
        }

        Client(string n, int i, string p, double b) : Person(n, i, p) {
            setBalance(b);
        }

        void setBalance(double b) {
            if (Validation::valiadateBalance(b)) {
                balance = b;
            } else {
                cout << "Invalid Balance" << endl;
            }
        }

        double getBalance() {
            return balance;

        }

        void deposite(double amount) {
            balance += amount;
        }

        void withdraw(double amount) {
            if (amount > balance) {
                cout << "Not Enough Balance";
            } else {
                balance -= amount;
            }
        }

        void transferTo(double amount, Client &c) {
            if (amount <= balance) {
                c.deposite(amount);
                balance -= amount;
            } else {
                cout << "amount exceeds" << endl;
            }
        }

        void checkBalance() {
            cout << "Balance : " << balance << endl;

        }

        void DisplayInfo() {
            Person::display();
            cout << "Balance is : " << balance;
        }
    };

    class Employee : public Person {
        double salary;
    public:
        Employee() {
            salary = 0;
        }

        Employee(string n, int i, string p, double s) : Person(n, i, p) {
            setSalary(s);
        }

        void setSalary(double s) {
            if (Validation::validateSalary(s)) {
                salary = s;
            }
            else cout << "Invalid salary\n";
        }

        double getSalary() {
            return salary;
        }

        void DisplayInfo() {
            Person::display();

            cout << "The salary is : " << salary<< endl;
        }

    };

    class Admin : public Employee {
        Admin() : Employee() {

        }

        Admin(string n, int i, string p, double s) : Employee(n, i, p, s) {

        }
    };

    int main() {
        Employee emp("michele",123,"secure1254",5000);
        emp.DisplayInfo();
        Client c1, c2;
        c1.setBalance(2000);
        c1.deposite(1500);
        c1.transferTo(1000, c2);
        c1.checkBalance();
        cout << endl;
        return 0;
}
