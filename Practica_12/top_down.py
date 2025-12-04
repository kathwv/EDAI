#Memoria inicial
memoria = {1:0, 2:1, 3:1}

# Necesitas tener definida fibonacci_iterativo_v2 o usar recursión simple.
# Usaré la implementación de la práctica (requiere fibonacci_iterativo_v2 definida).
# Si no tienes fibonacci_iterativo_v2 definida, USA EL CÓDIGO ALTERNATIVO ABAJO.

def fibonacci_iterativo_v2(numero):
    f1=0
    f2=1
    for i in range(1,numero-1):
        f1,f2=f2,f1+f2
    return f2
    
def fibonacci_top_down(numero):
    if numero in memoria:
        return memoria[numero]
    f = fibonacci_iterativo_v2(numero-1) + fibonacci_iterativo_v2(numero-2) # Cuidado: Esta línea es del código de la práctica
    memoria[numero] = f
    return memoria[numero]

# --- Cambios para imprimir ---

# Ejecución 1 y impresión del resultado
print(fibonacci_top_down(12)) # <--- ¡Nuevo!

# Impresión del estado de la memoria
print("#Memoria después de obtener el elemento 12 de la sucesión de Fibonacci")
print("memoria")
print(memoria) # <--- ¡Nuevo!

# Ejecución 2 y impresión del resultado
print(fibonacci_top_down(8)) # <--- ¡Nuevo!

# Impresión del estado final de la memoria
print("#Memoria después de obtener el elemento 8 de la sucesión de Fibonacci")
print("memoria")
print(memoria) # <--- ¡Nuevo!

# --- Bloque Pickle (Añadir impresión para verificar) ---

import pickle
# ... (código para guardar y leer pickle) ...

archivo = open('memoria.p', 'wb')
pickle.dump(memoria, archivo)
archivo.close()

archivo = open('memoria.p', 'rb')
memoria_de_archivo = pickle.load(archivo)
archivo.close()

# Impresión de las variables de pickle para verificación
print("memoria_de_archivo")
print(memoria_de_archivo) # <--- ¡Nuevo!
