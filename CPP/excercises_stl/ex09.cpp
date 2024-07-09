#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class EmployeeManager{

    public:
    ~EmployeeManager(void){}

    void addEmployee(std::string name, double salary){
        employees.emplace_back(name, salary);
    }

    bool removeEmployee(const std::string& name){
        auto it = std::find_if(employees.begin(), employees.end(), [&name](const auto& employee){
            return employee.first == name;
        });

        if (it != employees.end())
        {
            employees.erase(it);
            return true;
        }
        
        return false;
    }

    bool updateEmployeeSalary(const std::string& name, double newSalary){
        auto it = std::find_if(employees.begin(), employees.end(), [&name](const auto& employee){
            return employee.first == name;
        });

        if (it != employees.end())
        {
            it->second = newSalary;
            return true;
        }

        return false;
    }

    void printEmployees() const {
        for (const auto& employee : employees)
        {
            std::cout << "employee: " << employee.first << ", salary: " << employee.second << std::endl;
        }
        
    }

    private:
    std::vector<std::pair<std::string, double>> employees;

};


int main(void){

    EmployeeManager employers;

    employers.addEmployee("Antonio", 40);
    employers.addEmployee("Alan", 60);

    employers.printEmployees();

    std::cout << std::endl;

    employers.removeEmployee("Alan");
    employers.updateEmployeeSalary("Antonio", 60);

    employers.printEmployees();

    return 0;
}

/*
    auto it = std::find_if(names.begin(), names.end, [&nam](const auto& name){
        return name.first == nam;
    });
 */