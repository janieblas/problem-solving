#include <iostream>
#include <map>

using namespace std;


int main(void){
    map<string, int> students;
    students["Alan"] = 90;
    students["Luis"] = 70;
    students["Marcelo"] = 40;
    students["Antonio"] = 80;
    students["Alberto"] = 90;

    for (const auto& student : students)
    {
        cout << student.first << "\t" << student.second << endl;
    }
    

    return 0;
}