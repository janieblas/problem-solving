#include <iostream>

using namespace std;

class MyClass{
    public:
    int age;
    string name;

    MyClass(void);//{
    //    cout << "myConstructor" << endl;
    //}
    void printAll(void);

};
MyClass::MyClass(void){
    cout << "myConstructor" << endl;
}

void MyClass::printAll(void){
    cout << name << endl;
}

int main(){

    MyClass MyObj;
    MyClass Person;


    MyObj.name = "Antonio";
    MyObj.age = 28;

    MyObj.printAll();

    cout << MyObj.name << endl; 
    cout << MyObj.age << endl; 

    
    Person.name = "jesus";
    Person.age = 16;

    cout << Person.name << endl; 
    cout << Person.age;

    //int n;
    //cin >> n;
    //cout<< "Hello World!" << n << endl;
    return 0;
}

