#include <iostream>
#include <cstring>

class Employee {
public:
    Employee(const char* name, int id) : id(id) {
        strncpy(this->name, name, 49);
        this->name[49] = '\0';
    }
    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", ID: " << id << std::endl;
    }
    int getId() const { return id; }  // Método para obtener el id

protected:
    char name[50];
    int id;
};

class RegularEmployee : public Employee {
public:
    RegularEmployee(const char* name, int id, double baseSalary)
        : Employee(name, id), baseSalary(baseSalary) {}
    
    double calculateSalary() const override {
        return baseSalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Type: Regular Employee, Salary: " << calculateSalary() << std::endl;
    }

private:
    double baseSalary;
};

class Manager : public Employee {
public:
    Manager(const char* name, int id, double baseSalary, double bonus)
        : Employee(name, id), baseSalary(baseSalary), bonus(bonus) {}
    
    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Type: Manager, Salary: " << calculateSalary() << std::endl;
    }

private:
    double baseSalary;
    double bonus;
};

class Contractor : public Employee {
public:
    Contractor(const char* name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
    
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Type: Contractor, Salary: " << calculateSalary() << std::endl;
    }

private:
    double hourlyRate;
    int hoursWorked;
};

class EmployeeManager {
public:
    EmployeeManager() : employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < MAX_EMPLOYEES) {
            employees[employeeCount++] = employee;
        } else {
            std::cout << "Error: Maximum number of employees reached." << std::endl;
        }
    }

    void displayAllEmployees() const {
        for (int i = 0; i < employeeCount; ++i) {
            employees[i]->displayInfo();
        }
    }

    double calculateTotalSalary() const {
        double total = 0;
        for (int i = 0; i < employeeCount; ++i) {
            total += employees[i]->calculateSalary();
        }
        return total;
    }

    Employee* findEmployeeById(int id) const {
        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i]->getId() == id) {
                return employees[i];
            }
        }
        return nullptr;
    }

private:
    static const int MAX_EMPLOYEES = 10;
    Employee* employees[MAX_EMPLOYEES];
    int employeeCount;
};

int main() {
    EmployeeManager em;

    em.addEmployee(new RegularEmployee("John Doe", 1, 50000));
    em.addEmployee(new Manager("Jane Smith", 2, 70000, 10000));
    em.addEmployee(new Contractor("Bob Johnson", 3, 100, 160));

    std::cout << "All Employees:" << std::endl;
    em.displayAllEmployees();

    std::cout << "\nTotal Salary: " << em.calculateTotalSalary() << std::endl;

    int searchId = 2;
    Employee* found = em.findEmployeeById(searchId);
    if (found) {
        std::cout << "\nFound employee with ID " << searchId << ":" << std::endl;
        found->displayInfo();
    } else {
        std::cout << "\nEmployee with ID " << searchId << " not found." << std::endl;
    }

    return 0;
}
