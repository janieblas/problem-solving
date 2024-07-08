#include <iostream>
#include <set>


int main(void){
    std::set<int> numbers;

    for (int i = 1; i <= 5; i++)
    {
        numbers.insert(i);
    }

    numbers.insert(2);//duplicade

    for ( const auto& number : numbers)
    {
        std::cout << number << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}