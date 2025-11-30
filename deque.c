#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

//inicialización
void initDeque(Deque *dq) {
    dq->front = 0;
    dq->size = 0;
    printf("Deque inicializado\n");
}

int rear(Deque *dq) {
    return (dq->front + dq->size - 1) % MAX;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

int isFull(Deque *dq) {
    return dq->size == MAX;
}

void insert_front(Deque *dq, int valor) {
    if (isFull(dq)) {
        printf("Error: Deque lleno\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->datos[dq->front] = valor;
    dq->size++;
}

void insert_rear(Deque *dq, int valor) {
    if (isFull(dq)) {
        printf("Error: Deque lleno\n");
        return;
    }
    int pos = (dq->front + dq->size) % MAX;
    dq->datos[pos] = valor;
    dq->size++;
}

void delete_front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Error: Deque vacío\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}

void delete_rear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Error: Deque vacío\n");
        return;
    }
    dq->size--;
}

int peek_front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque vacío\n");
        return -1;
    }
    return dq->datos[dq->front];
}

int peek_rear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque vacío\n");
        return -1;
    }
    return dq->datos[rear(dq)];
}

void printDeque(Deque *dq) {
    printf("Deque: ");
    for (int i = 0; i < dq->size; i++) {
        int idx = (dq->front + i) % MAX;
        printf("%d ", dq->datos[idx]);
    }
    printf("\n");
}

//pruebas
int main() {
    Deque dq;
    initDeque(&dq);

    insert_front(&dq, 10);
    insert_rear(&dq, 15);
    insert_rear(&dq, 20);
    insert_front(&dq, 30);
    insert_rear(&dq, 40);
    printDeque(&dq);

    delete_front(&dq);
    delete_rear(&dq);
    printDeque(&dq);

    insert_front(&dq, 50);
    insert_rear(&dq, 60);
    printDeque(&dq);
    
    return 0;
}
