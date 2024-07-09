#include <iostream>
#include <string>
#include <set>
#include <algorithm>

class StudentManager{

    public:
    ~StudentManager(void){}

    void addStudent(const std::string& name){
        students.insert(name);
    }

    bool removeStudent(const std::string& name){
        return students.erase(name) > 0;
    }

    bool isStudentPresent(const std::string& name){
        return students.find(name) != students.end();
    }

    void printStudents(void) const{
        for (const auto& student : students)
        {
            std::cout << student << std::endl; 
        }
    }

    private:
    std::set<std::string> students;
};

int main(void){

    StudentManager students;

    students.addStudent("Antonio");
    students.addStudent("Alan");
    students.addStudent("Luis");

    students.printStudents();

    std::cout << std::endl; 

    students.removeStudent("Luis");
    std::cout << students.isStudentPresent("Antonio") << std::endl; 
    students.printStudents();
    
    return 0;
}