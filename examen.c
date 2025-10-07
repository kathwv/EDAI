#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, new_tamano, i; 
    float *calificaciones;
    float suma= 0.0, promedio;
    char respuesta;
    
    //1. solicitar al usuario cuántos estudiantes va a registrar 
    printf("¿Cuántos estudiantes deseas regridtrar? ");
    scanf("%d", &n);
    
    //2. reservar memoria dinámica
    calificaciones = (float *)malloc(n * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error: no se pudo aisgnar memoria.\n");
        return 1; //terminar si malloc falla
    }
    // 3. Capturar calificaciones y calcular promedio
    for (i=0; i<n; i++) {
        printf("Ingresa la calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }
    promedio = suma/n;
    
    //4. mostrar todas las calificaciones y el promedio
    printf("\nCalificaciones registradas:\n");
    for (i=0; i<n; i++) {
        printf("Estudiante %d: %.2f\n", i+1, calificaciones[i]);
    }
    printf("Promedio general: %.2f\n", promedio);
    
    // 5. preguntar si se desea agregar más estudiantes
    printf("\n¿Deseas agregar más estudiantes? (s/n): ");
    scanf(" %c", &respuesta);
    
    if(respuesta == 's'|| respuesta == 'S') {
        int adicionales; 
        printf("¿Cuántos estudiantes más deseas agregar? ");
        scanf("%d", &adicionales);
        
        new_tamano = n+adicionales; 
        
        //usar realloc para ampliar el tamaño del arreglo
        float *temp= realloc(calificaciones, new_tamano * sizeof(float));
        if (temp == NULL) {
            printf("Error: no se pudo ampliar la memoria.\n");
            free(calificaciones); //liberar memoria
            return 1;
        }
        calificaciones= temp;
        
        //capturar las nuevas calificaciones
        for(i=n; i< new_tamano; i++) {
            printf("Ingresa la calificación del estudiante %d: ", i+1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }
        
        //volver a calcular el promedio total
        promedio = suma/new_tamano;
    }
    
    return 0;
}
