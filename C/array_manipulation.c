
#include <stdio.h>
/*
Exercise 1: Pointer Arithmetic and Array Manipulation
Write a C program to manipulate an array using pointers. The program should initialize 
an array of integers, modify its elements using pointer arithmetic, and print the array 
before and after modification.
*/

#define SIZE 5

void modify_array(int *myarray, int size);

int main(void){

    int myarray[SIZE] = {1,2,3,4,5};

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",myarray[i]);
    }
    printf("\n");

    modify_array(myarray, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",myarray[i]);
    }

    return 0;
}

void modify_array(int *myarray, int size){
    
    for (int i = 0; i < size; i++)
    {
        *(myarray + i) = *(myarray + i) * 2;
    }
}