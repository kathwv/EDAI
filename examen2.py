def max_recursivo(lista, inicio, fin):
    #caso base: solo un elemento
    if inicio == fin:
        return lista[inicio]
    
    medio = (inicio+fin)//2
    max_izq = max_recursivo(lista, inicio, medio)
    max_der = max_recursivo(lista, medio +1, fin)

    return max(max_izq, max_der)

n = int(input("Ingresa el tamaño de la lista: "))
lista = []
print("Ingresa los elementos:")
for _ in range(n):
    lista.append(int(input()))
resultado = max_recursivo(lista, 0, n-1)

print("El valor máximo es:", resultado)
