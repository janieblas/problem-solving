#include <iostream>
#include <vector>
#include <string>
#include <memory> // Incluir la librería para std::shared_ptr

class Employee {
public:
    Employee(const std::string& empName, double empSalary) : name(empName), salary(empSalary) {}
    virtual void printDetails() const {
        std::cout << "Employee: " << name << ", Salary: " << salary << std::endl;
    }
    
    virtual ~Employee() {}

protected:
    std::string name;
    double salary;
};

class Manager : public Employee {
public:
    Manager(const std::string& mgrName, double mgrSalary) : Employee(mgrName, mgrSalary) {}
    void addEmployee(std::shared_ptr<Employee> emp) {
        employees.push_back(emp);
    }
    void printDetails() const override {
        /*
        std::cout << "Manager: " << name << ", Salary: " << salary << std::endl;
        std::cout << "Managed Employees: " << std::endl;
        for (const auto& emp : employees) {
            emp->printDetails();
        }
        */
        // Llamar correctamente a la función printDetails de la clase base
        Employee::printDetails();
        std::cout << "Managed Employees: " << std::endl;
        for (const auto& emp : employees) {
            emp->printDetails();
        }

    }
private:
    //std::vector<Employee*> employees;
    std::vector<std::shared_ptr<Employee>> employees;
};

int main() {
    auto emp1 = std::make_shared<Employee>("John Doe", 50000);
    auto emp2 = std::make_shared<Employee>("Jane Smith", 55000);
    Manager mgr("Alice Johnson", 75000);

    //Employee emp1("John Doe", 50000);
    //Employee emp2("Jane Smith", 55000);
    //Manager mgr("Alice Johnson", 75000);

    //mgr.addEmployee(&emp1);
    //mgr.addEmployee(&emp2);

    mgr.addEmployee(emp1);
    mgr.addEmployee(emp2);

    emp1->printDetails();
    emp2->printDetails();
    mgr.printDetails();

    return 0;
}