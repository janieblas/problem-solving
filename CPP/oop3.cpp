#include <iostream>
#include <string>

using namespace std;

class Fhater{

    public:
    string lastname = "Nieblas";
    
    void charisma(void){
        cout << "funny person";
    }
};

class Mother{
    public:
    string second_lastname = "Bobadilla";
};

class Son: public Fhater, public Mother{
    public:
    string firt_name;

    void complete_name(void){
        cout << firt_name + " " +  lastname + " " +  second_lastname;
    }
};

int main(void){

    Son Antonio;
    Antonio.firt_name = "Antonio";

    Antonio.complete_name();

    return 0;
}