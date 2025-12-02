#las funciones pueden recibir n número de parámetros, no se necesita indicar el tipo
def imprime_nombre(nombre):
    print("hola "+nombre) 

#llamada a la función
imprime_nombre("JJ")

#definiendo una función que regresa el cuadrado de un número
def cuadrado(x):
    return x**2

x = 5

#la función format() sirve para convertir los parámetros que recibe, en cadenas
print("El cuadrado de {} es {}".format(x, cuadrado(x)))

#definiendo una funcion que regrese mas de un valor
def varios(x):
    return x**2, x**3, x**4

#los valores que regresa la funcion pueden ser guardados en variables separadas por ,
val1, val2, val3 = varios(2)
print("{} {} {}".format(val1, val2, val3))

#funcion con un parametro con un valor por defecto
def cuadrado_default(x=3):
    return x**2

cuadrado_default()
