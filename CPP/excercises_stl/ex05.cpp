#include <iostream>
#include <queue>

int main(void){
    std::queue<int> numbers;

    for (int i = 1; i <= 5; i++)
    {
        numbers.push(i);
    }
    
    while (!numbers.empty())
    {
        std::cout << numbers.front() << " ";
        std::cout << numbers.front() << std:: endl;
        numbers.pop();
    }
    
    std::cout << std::endl;


    return 0;
}