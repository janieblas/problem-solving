/*
Scenario: 
We’ve received the following high priority request:
    
Nightly automation fails with SIGSEGV when running MyClass.

Description:
Test has failed multiple times trying to access different data indexes, backtrace attached:
    ./program
    Segmentation fault (core dumped)
    ./program(causeSegfault)[0x400726]
    ./program(accessData)[0x4007a4] at data[index]
    ./program(outputData)[0x4007a3] at obj→accessData(index)
    ./program(main)[0x4007a2] at outputData(obj, 3);
    ./lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3)[0x7f0d08bd703b]
    ./program[0x400649]

Find the root cause and provide a fix.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

class MyClass {
public:
    char* data;

    MyClass() {
        data = nullptr;
    }

    void allocateData(const char* newData) {
        size_t len = strlen(newData) + 1;
        data = new char[len];
        strcpy(data, newData);
    }

    void freeData() {
        delete[] data;
        data = nullptr;
    }

    void accessData(int index) {
        std::cout << "Value at index " << index << ": " << data[index] << std::endl;
    }
};

void outputData(MyClass* obj, int index) {
    obj->accessData(index);
}

int main() {
    MyClass* obj = new MyClass();
    outputData(obj, 3);
    
    //obj->allocateData("data");

    obj->freeData();
    
    return 0;
}