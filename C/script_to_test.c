#include <stdio.h>
#include <stdlib.h>

#define MIN3(a,b, c) (((a) < (b) ? (a) : (b)) < (c) ? ((a) < (b) ? (a) : (b)) : (c))
#define SWAP(a, b) do { typeof(a) temp = (a); (a) = (b); (b) = temp; } while(0)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define UPPER(A, B) (A < B ? B : A)

int main(void){
    int x = 10, y = 20, z = 5;
    
    //printf("El mínimo entre %d, %d, y %d es: %d\n", x, y, z, MIN3(x, y, z));

    //printf("Antes de SWAP: x = %d, y = %d\n", x, y);
    //SWAP(x, y);
    //printf("Despues de SWAP: x = %d, y = %d\n", x, y);

    //int numeros[] = {1, 2, 3, 4, 5};
    //printf("El tamano del array es: %lu\n", ARRAY_SIZE(numeros));
    
    printf("%d",UPPER(50,10));
    return 0;
}