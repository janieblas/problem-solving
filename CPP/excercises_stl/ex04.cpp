#include <iostream>
#include <stack>


int main(void){
    std::stack<int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);
    numbers.push(5);

    while (!numbers.empty())
    {
        std::cout << numbers.top() << " ";
        std::cout << numbers.top() << " " << std::endl;
        numbers.pop();
    }
    
    std::cout << std::endl;
    return 0;
}