#include <iostream>
#include <string>

using namespace std;

class OriginalClass{
    public:
    void hello(void){
        cout<< "Hello World!";
    }

};

class inheritanceClass: public OriginalClass{
    public:
        void hello(void){
            cout << "Hello World!, I'm Antonio!";
        }
};

int main(void){

    OriginalClass ori;
    inheritanceClass Antonio;

    ori.hello();
    cout << endl;
    Antonio.hello();



    return 0;
}