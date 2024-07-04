#include <iostream>
using namespace std;

class Employee{
    private:
    int Salary;
    
    public:
    void setSalary(int in_salary);
    int getSalary(void);

};

    void Employee::setSalary(int in_salary){
        Salary = in_salary;
    }

    int Employee::getSalary(void){

        return Salary;
    }

int main(void){
    Employee Antonio;

    Antonio.setSalary(45000);

    cout << Antonio.getSalary();
    


    return 0;
}