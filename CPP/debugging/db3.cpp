#include <iostream>
#include <vector>

class MyClass {
public:
    MyClass(int size) : data(size) {}
    void setValue(int index, int value) {
        if (index >= 0 && index < data.size())
        {
            data.at(index) = value; // Puede lanzar una excepción si el índice está fuera de los límites
        }else{
            std::cout << "Error: Index " << index << " is out of bounds" << std::endl;
        }
        
    }
    void printValues() {
        for (const auto& val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
private:
    std::vector<int> data;
};

int main() {
    MyClass myObject(5);
    myObject.setValue(2, 10);
    myObject.setValue(6, 20); // Error: índice fuera de los límites
    myObject.printValues();

    return 0;
}
