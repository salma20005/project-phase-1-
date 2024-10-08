//# Auto detect text files and perform LF normalization
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
bool nameFlag = false;
bool passFlag = false;
bool balance_salary = false;


class Validation{
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

        Person(string s, int i, string p) {
            setId(i);
            setName(s);
            setPassword(p);

        }

        void setName(string s) {
            if (Validation::validateName(s)) {
                name = s;
                nameFlag = false;
            } else {
                cout << "Invalid name\n";
                nameFlag = true;
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
                passFlag = false;
            } else {
                cout << "Invalid password\n";
                passFlag = true;
            }
        }

        string getPassword() {
            return password;
        }

        void display() {
            cout << "Name is : " << name << endl;
            cout << "Id is : " << id << endl;
            cout << "Password is " << password;
        }
    };

    class Client : public Person {
    private:
        double balance;

    public:
        Client() : Person() {
            balance = 0;
        }

        Client(string s, int i, string p, double b) : Person(s, i, p) {
            setBalance(b);
        }


        void setBalance(double b) {
            if (Validation::valiadateBalance(b)) {
                balance = b;
                balance_salary  = false;
            }
            else {
                cout << "Invalid Balance" << endl;
                balance_salary  = true;
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

        double checkBalance() {
           return balance;
        }
        void DisplayInfo() {
            Person::display();
            cout << "Balance is : " << balance;
        }
    };
    vector<Client> clients;
    static inline Client* cl;
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
        void addClient(Client& c){
            if(nameFlag == false && passFlag == false && balance_salary == false){
                clients.push_back(c);
            }
            else{
                cout << "Invalid";
            };
        }
        Client* searchClient(int id){
            for(int i = 0 ; i < clients.size() ; i++){
                if(clients[i].getId() == id){
                    cl = &clients[i];
                    return cl;
                    break;
                }
            }
            return nullptr;
        }
        void listClient(){
            cl->DisplayInfo();
        }
        void editClient(int id , string name , string password , double balance){
            cl->setId(id);
            cl->setName(name);
            cl->setPassword(password);
            cl->setBalance(balance);
        }
        void listClients(){
            for(int i = 0 ; i < clients.size() ; i++){
                clients[i].DisplayInfo();
            }
        }
    };
    vector<Employee> employees;
    static inline Employee* em;
    class Admin : public Employee {
    public:
        Admin() : Employee() {

        }
        Admin(string n, int i, string p, double s) : Employee(n, i, p, s) {

        }
        void addEmployee(Employee& e){
            if(nameFlag == false && passFlag == false && balance_salary == false){
                employees.push_back(e);
            }
            else{
                cout << "Invalid";
            };
        }
      Employee* searchEmployee(int id){
            for(int i = 0 ; i < employees.size() ; i++){
                if(employees[i].getId() == id){
                    em = &employees[i];
                    return em;
                    break;
                }
            }
            return nullptr;
        }
        void editEmployee(int id , string name ,string password , double salary){
            em->setId(id);
            em->setName(name);
            em->setPassword(password);
            em->setSalary(salary);
        }
        void listEmployee(){
            em->DisplayInfo();
        }
        void listEmplpoyees(){
            for(int i = 0 ; i < employees.size() ; i++){
                employees[i].DisplayInfo();
            }
        }
    };
vector <Admin> admins;
static inline Admin* ad;
class DataSourceInterface {
public:
    DataSourceInterface() {};
    virtual void addClient(Client c) = 0;
    virtual void addEmployee(Employee e) = 0;
    virtual void addAdmin(Admin a) = 0;
    virtual void getAllClients() = 0;
    virtual void getAllEmployees() = 0;
    virtual void getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};
class Parser {
public:
    static inline vector<string> temps;
    static inline vector<string> split( string line) {
        istringstream s(line);
        string temp;
        temps.clear();
        while (getline(s, temp, ',')) {
            temps.push_back(temp);
        }
        return temps;
    }
    static inline Client parseToClient( string line) {
        split(line);
        Client c = Client(temps[0], stoi(temps[1]), temps[2], stod(temps[3]));
        temps.clear();
        return c;
    }
    static inline Employee parseToEmployee(string line) {
        split(line);
        Employee e = Employee(temps[0], stoi(temps[1]), temps[2], stod(temps[3]));
        temps.clear();
        return e;
    }
    static inline Admin parseToAdmin(string line) {
        split(line);
        Admin a = Admin(temps[0],stoi( temps[1]), temps[2], stod(temps[3]));
        temps.clear();
        return a;
    }
};
class FileManager : public DataSourceInterface{
public:
    void addClient(Client c ){
        fstream file("Clients.txt" , ios :: app);
        string ci = to_string(c.getId()) + "," + c.getName() + "," + c.getPassword() + "," + to_string(c.checkBalance());
        file << ci << endl;
        file.close();
    }
    void addEmployee(Employee e) {
        fstream file("Employees.txt", ios::app);
        string emp = to_string(e.getId()) + "," + e.getName() + "," + e.getPassword() + "," + to_string(e.getSalary());
        file << emp << endl;
        file.close();
    }
    void addAdmin(Admin a) {
        fstream file("Admins.txt", ios::app);
        string adm = to_string(a.getId()) + "," + a.getName() + "," + a.getPassword() + "," + to_string(a.getSalary());
        file << adm << endl;
        file.close();
    }
    void getAllClients() {
        fstream file("Clients.txt", ios::in);
        string cli;
        while (getline(file, cli)) {
            Parser p;
            Client cc;
            cc = p.parseToClient(cli);
            clients.push_back(cc);
        }
        file.close();
    }
    void getAllEmployees() {
        fstream file("Employees.txt", ios::in);
        string emp;
        while (getline(file, emp)) {
            Parser p;
            Employee ee;
            ee = p.parseToEmployee(emp);
            employees.push_back(ee);
        }
        file.close();
    }
    void getAllAdmins() {
        fstream file("Admins.txt", ios::in);
        string adm;
        while (getline(file, adm)) {
            Parser p;
            Admin aa;
            aa = p.parseToAdmin(adm);
            admins.push_back(aa);
        }
        file.close();
    }
    void removeAllClients() {
        fstream file("Clients.txt", ios::out);
        file.close();
    }
    void removeAllEmployees() {
        fstream file("Employees.txt", ios::out);
        file.close();
    }
    void removeAllAdmins() {
        fstream file("Admins.txt", ios::out);
        file.close();
    }
    void saveAllClients() {
        removeAllClients();
        for (int i = 0; i < clients.size(); i++) {
            addClient(clients[i]);
        }
    }
    void saveAllEmployees() {
        removeAllEmployees();
        for (int i = 0; i < employees.size(); i++) {
            addEmployee(employees[i]);
        }
    }
    void saveAllAdmins() {
        removeAllAdmins();
        for (int i = 0; i < admins.size(); i++) {
            addAdmin(admins[i]);
        }
    }
};
class FilesHelper{
public:
    static void saveLast(string filename , int id){
        fstream file(filename, ios ::out);
        file<< to_string(id) << endl;
        file.close();
    }
    static int getLast(string filename){
        fstream file(filename,ios::in);
        string id;
        file >> id;
        file.close();
        int i = stoi(id);
        return i;
    }
    static void saveClient(Client c){
        FileManager f;
        f.addClient(c);
    }
    static void saveEmployee(string filename , string lastIdFile, Employee e){
        fstream file(filename, ios::app);
        fstream file2(lastIdFile, ios::app);
        string emp = to_string(e.getId()) + "," + e.getName() + "," + e.getPassword() + "," + to_string(e.getSalary());
        file << emp << endl;
        string lastID = to_string(e.getId());
        file2 << lastID;
        file.close();
        file2.close();
    }
    static void getClients(){
        FileManager f;
        f.getAllClients();
    }
    static void getEmployees(){
        FileManager f;
        f.getAllEmployees();
    }
    static void getAdmins(){
        FileManager f;
        f.getAllAdmins();
    }
    static void clearFile(string filename,string lastIdFile){
        fstream file(filename, ios :: out);
        file.close();
        fstream file2(lastIdFile,ios :: out);
        file2.close();
    }
};
    int main() {
        return 0;
}
