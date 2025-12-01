#include <stdio.h>

#define MAX 5 

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

//inicializar
void initQueue(ColaCircular *q) {
    q->frente = 0;
    q->final = 0;
    q->size = 0;
    printf("Cola circular inicializada\n");
    }
    //operaciones 
    int isEmpty(ColaCircular *q) {
        return q->size == 0;
    }
    
    int isFull(ColaCircular *q) {
        return q->size == MAX;
    }
    
    void enqueue(ColaCircular *q, int valor) {
        if (isFull(q)) {
            printf("Error: cola llena\n");
            return;
        }
        q->datos[q->final] = valor;
        q->final = (q->final + 1) % MAX;
        q->size++;
    }
    
    int dequeue(ColaCircular *q) {
        if(isEmpty(q)) {
            printf("Error: cola vacía\n");
            return -1;
        }
        int valor = q->datos[q->frente];
        q->frente = (q->frente + 1) % MAX;
        q->size--;
        return valor;
    }
    
    int peek(ColaCircular *q) {
        if(isEmpty(q)) {
            printf("Cola vacía\n");
            return -1;
        }
        return q->datos[q->frente];
    } 
    
    void printQueue(ColaCircular *q) {
        printf("Cola: ");
        for(int i = 0; i < q->size; i++) {
            int idx = (q->frente + i) % MAX;
            printf("%d ", q->datos[idx]);
        }
        printf("\n");
    }
    //pruebas
    int main() {
    ColaCircular q;
    initQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    printQueue(&q);

    printf("Desencolado: %d\n", dequeue(&q));
    printQueue(&q);

    enqueue(&q, 20);
    enqueue(&q, 25);
    enqueue(&q, 30);
    printQueue(&q);

    return 0;
}
