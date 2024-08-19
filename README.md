#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Employee Class
class Employee {
protected:
    int id;
    string name;
    string password;
    double salary;

public:
    // Constructors
    Employee() : id(0), salary(0.0) {}
    Employee(int id, const string& name, const string& password, double salary)
        : id(id) {
        setName(name);
        setPassword(password);
        setSalary(salary);
    }

    // Setter functions with validation
    void setName(const string& name) {
        if (name.length() >= 5 && name.length() <= 20 && all_of(name.begin(), name.end(), ::isalpha)) {
            this->name = name;
        }
        else {
            cout << "Invalid name: Name must be alphabetic and between 5 and 20 characters long.\n";
        }
    }

    void setPassword(const string& password) {
        if (password.length() >= 8 && password.length() <= 20) {
            this->password = password;
        }
        else {
            cout << "Invalid password: Password must be between 8 and 20 characters long.\n";
        }
    }

    void setSalary(double salary) {
        if (salary >= 5000) {
            this->salary = salary;
        }
        else {
            cout << "Invalid salary: Salary must be at least 5000.\n";
        }
    }

    // Getter functions
    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }
    double getSalary() const { return salary; }

    // Display function
    virtual void displayInfo() const {
        cout << "Employee ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
    }
};

// Admin Class
class Admin : public Employee {
private:
    vector<Employee> employees;

public:
    // Constructor
    Admin(int id, const string& name, const string& password, double salary)
        : Employee(id, name, password, salary) {}

    // Add new Employee
    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
        cout << "Employee added successfully.\n";
    }

    // Search for Employee by ID
    Employee* searchEmployee(int id) {
        for (auto& emp : employees) {
            if (emp.getId() == id) {
                return &emp;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
        return nullptr;
    }

    // Edit Employee
    void editEmployee(int id) {
        Employee* emp = searchEmployee(id);
        if (emp) {
            string newName, newPassword;
            double newSalary;
            cout << "Enter new name: ";
            cin >> newName;
            cout << "Enter new password: ";
            cin >> newPassword;
            cout << "Enter new salary: ";
            cin >> newSalary;
            emp->setName(newName);
            emp->setPassword(newPassword);
            emp->setSalary(newSalary);
            cout << "Employee information updated.\n";
        }
    }

    // List all Employees
    void listAllEmployees() const {
        if (employees.empty()) {
            cout << "No employees found.\n";
            return;
        }
        for (const auto& emp : employees) {
            emp.displayInfo();
            cout << "----------------------\n";
        }
    }

    // Display Admin info
    void displayInfo() const override {
        cout << "Admin ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
        cout << "----------------------\n";
        listAllEmployees();
    }
};

// Main function
int main() {
    Admin admin(1, "AdminName", "AdminPass123", 8000);

    // Adding employees
    admin.addEmployee(Employee(2, "ahmed ali ", "Pass1234", 6000));
    admin.addEmployee(Employee(3, " omer khaled ", "SecurePass", 7000));

    // Searching and editing employee
    admin.searchEmployee(2);
    admin.editEmployee(2);

    // Listing all employees
    admin.listAllEmployees();

    // Displaying admin info
    admin.displayInfo();

    return 0;
}



