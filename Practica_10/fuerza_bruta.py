from string import ascii_letters, digits
from itertools import product
from time import time

caracteres = ascii_letters + digits

def buscador(con):
    longitud = len(con)

    if longitud in [4, 8, 10]:
        for comb in product(caracteres, repeat=longitud):
            prueba = "".join(comb)
            if prueba == con:
                print(f'Tu contraseña es {prueba}')
                return
        print("Contraseña no encontrada")
    else:
        print('Ingresa una contraseña que contenga 4, 8 o 10 caracteres')

# Ejemplo de uso
t0 = time()
con = 'H0l4'   # puedes probar con una contraseña de 4, 8 o 10 caracteres
buscador(con)
print("Tiempo de ejecución:", round(time()-t0, 6))
