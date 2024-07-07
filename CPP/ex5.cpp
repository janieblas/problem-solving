#include <iostream>
#include <vector>

using namespace std;
     

class Person{
    public:
    Person(string name_i, int age_i):name(name_i), age(age_i){}

    void displayInfo(void){
        cout << "name: " << name << ", edad: " << age << endl;
    }
    bool isAdult(void){
        return (age >= 18) ? true :  false;
    }

    private:
    string name;
    int age;

};


int main(void){

    vector<Person*> persons;

    persons.push_back(new Person("Antonio", 26));
    persons.push_back(new Person("Rogelio", 16));

    for (const auto& person : persons)
    {
        person->displayInfo();
        if(person->isAdult()){
            cout<< "is Adult" << endl; 
        }else{
            cout<< "is menor" << endl;
        }
    }

    for(auto& person : persons){
        delete person;
    }
    


    return 0;
}