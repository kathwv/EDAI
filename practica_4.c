#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int *arr, *arr2;
    
    //malloc
    printf("¿Cuántos enteros quieres almacenar? ");
    scanf("%d", &n);
    
    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }
    
    printf("\nValores iniciales con malloc (basura):\n");
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    //calloc
    arr2 = (int*) calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Error al reservar memoria con calloc.\n");
        free(arr);
        return 1;
    }
    
    printf("\nValores iniciales con calloc (ceros):\n");
    for(int i=0; i<n; i++) {
        printf("arr2[%d]= %d\n", i, arr2[i]);
    }
    
    printf("\nIngresa %d valores para arr2:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    
    //realloc
    printf("\nIngresa un nuevo tamaño m: ");
    scanf("%d", &m);
    
    arr2= (int*) realloc(arr2, m * sizeof(int));
    if(arr2 == NULL) {
        printf("Error al redimensionar memoria con realloc.\n");
        free(arr);
        return 1;
    }
    
    if(m>n) {
        printf("\nIngresa %d valores adicionales:\n", m-n);
        for(int i=0; i<m; i++) {
            scanf("%d", &arr2[i]);
        }
    }
    
    printf("\nValores finales en arr2:\n");
    for(int i=0; i<m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");
    
    return 0;
}
