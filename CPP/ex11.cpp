#include <iostream>
#include <vector>
#include <string>

// Clase base Employee
class Employee {
protected:
    std::string name;
    double salary;
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}
    virtual ~Employee() {}
    
    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", Salary: " << salary << std::endl;
    }

    // Métodos de acceso
    std::string getName() const { return name; }
    double getSalary() const { return salary; }

    void setName(const std::string& name) { this->name = name; }
    void setSalary(double salary) { this->salary = salary; }
};

// Clase derivada Manager
class Manager : public Employee {
public:
    Manager(const std::string& name, double salary) : Employee(name, salary) {}
    
    void displayInfo() const override {
        std::cout << "Manager - Name: " << name << ", Salary: " << salary << std::endl;
    }
};

// Clase derivada Developer
class Developer : public Employee {
public:
    Developer(const std::string& name, double salary) : Employee(name, salary) {}
    
    void displayInfo() const override {
        std::cout << "Developer - Name: " << name << ", Salary: " << salary << std::endl;
    }
};

// Clase Company que maneja una lista de empleados
class Company {
private:
    std::vector<Employee*> employees;
public:
    ~Company() {
        for (Employee* emp : employees) {
            delete emp;
        }
    }
    
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void displayAllEmployees() const {
        for (const Employee* emp : employees) {
            emp->displayInfo();
        }
    }
};

int main() {
    Company company;
    company.addEmployee(new Manager("Alice", 90000));
    company.addEmployee(new Developer("Bob", 70000));
    company.addEmployee(new Developer("Charlie", 75000));

    std::cout << "All Employees:" << std::endl;
    company.displayAllEmployees();

    return 0;
}
