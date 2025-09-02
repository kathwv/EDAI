#include <stdio.h>

int main(void) {
    int n;
    int a [100];
    
    printf("Ingresa una cantidad (maximo 100): ");
    scanf("%d", &n);
    
    if(n<=0|| n>100) {
        printf("Error: solo numeros de 1 a 100\n");
        return 1;
    }
    
    printf("Ingresa %d numeros:\n", n);
    for(int i=0; i<n; i++) {
        printf("Elemento %d:",i);
        scanf("%d", &a[i]);
    
    }
    
    printf("\nLos elementos del array son: \n");
    for(int i=0; i<n; i++) {
        printf("%d", a[i]);
    }
    
    printf("\n");
    return 0;
}
