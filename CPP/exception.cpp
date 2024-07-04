#include <iostream>
#include <string>
using namespace std;


// try throw, catch
int main(void){
    try{
        int number = 17;
        if (number >= 18)
        {
            cout << "acepted";
        }else{
            throw(number);
        }
        
    }catch(int t_number){
        cout << "denied" << endl;
        cout << t_number;
    }
    return 0;
}
