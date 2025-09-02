#include <stdio.h>

int main(void) {
    int n;
    int a[100];
    int suma=0;
    int resta; 
    float promedio; 
    int min, max; 
    int idmin=0, idmax=0;
    
    printf("Ingresa una cantidad (maximo 100): ");
    scanf("%d", &n);
    
    if(n<=0|| n>100) {
        printf("Error: solo numeros de 1 a 100.\n");
        return 1;
        
    }
    
    printf("Ingresa %d numeros: \n", n);
    for (int i=0; i<n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
        
    }
    
    suma=0; 
    resta=a[0];
    min=a[0];
    max=a[0];
    
    for(int i=0; i<n; i++) {
        suma += a[i];
        if (i>0) {
            resta -= a[i];
        }
        if (a[i]<min) {
            min=a[i];
            idmin=i;
        }
        if (a[i]>max) {
            max=a[i];
            idmax=i;
        }
    }
    
    promedio = (float)suma/n;
    
    printf("\n");
    printf("suma: %d\n", suma);
    printf("resta: %d\n", resta);
    printf("promedio: %.2f\n", promedio);
    printf("minimo: %d (posicion %d)\n", min, idmin);
    printf("maximo: %d (posicion %d)\n", max, idmax);
    
    return 0;
}
