#include <stdio.h>

/*
Exercise 2: Function Pointers
Write a C program that uses function pointers to call different functions 
based on user input. Implement two functions, one for addition and one for 
multiplication, and use a function pointer to call the selected function.
*/

void performe_operation(int(*operator)(int, int), int a, int b);

int add(int a, int b);
int mult(int a, int b);

int main(void){

    int choice = 2 , x = 5, y = 2;
    int (*operation)(int, int);

    if (choice == 1)
    {
        operation = add;
    }
    else if (choice == 2)
    {
        operation = mult;
    }else
    {
        //none
        return 1;
    }
    
    performe_operation(operation, x, y);

    return 0;
}

void performe_operation(int(*operator)(int, int), int a, int b){

    int result = operator(a,b);
    printf("Result: %d\n", result);

}

int add(int a, int b){
    return a + b;
}
int mult(int a, int b){
    return a * b;
}