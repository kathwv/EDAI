from functools import lru_cache

#implementacion recursiva con memoizacion para evitar recomputaciones
@lru_cache(maxsize=None)
def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)
    
#posiciones solicitadas
posiciones = [7, 21, 40, 71, 94]

#calculando resultados
for pos in posiciones:
    print(f"Fibonacci({pos}) = {fibonacci(pos)}")
