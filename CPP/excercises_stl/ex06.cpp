#include <iostream>
#include <vector>
#include <algorithm>

class Vector_en{
    
    public:

    ~Vector_en() {}

    void addNumber(int num){
        numbers.push_back(num);
    }
    void removeNumber(int num){
        auto it = std::find(numbers.begin(), numbers.end(), num);
        if (it != numbers.end()) {
            numbers.erase(it);
            //return true;
        }
        //return false; 
    }

    void printNumbers(void){

        for (const auto& number : numbers)
        {
            std::cout << number << std::endl;
        }
    }

    size_t getStudentCount() const {
        return numbers.size();
    }

    private:
        std::vector<int> numbers;
};

int main(void){
    
    Vector_en numbers;

    for (int i = 1; i <= 5; i++)
    {
        numbers.addNumber(i);
    }
    
    numbers.printNumbers();

    numbers.removeNumber(3);

    numbers.printNumbers();


    return 0;
}