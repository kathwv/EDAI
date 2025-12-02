#declaracion de una tupla
tupla_diasDelMes=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

print (tupla_diasDelMes)
print (tupla_diasDelMes[0])
print (tupla_diasDelMes[3])
print (tupla_diasDelMes[1])

#declaracion de tuplas anidadas
tupla_numeros=(('cero', 0),('uno', 1, 'UNO'), ('dos',2), ('tres', 3), ('cuatro', 4), ('X', 5))

print (tupla_numeros)

print (tupla_numeros[0])
print (tupla_numeros[1])

print (tupla_numeros[2][0])
print (tupla_numeros[2][1])

print (tupla_numeros[1][0])
print (tupla_numeros[1][1])
print (tupla_numeros[1][2])


#probando la mutabilidad de las listas vs la no mutabilidad de las tuplas
print("valor actual {}".format(lista_diasDelMes[0]))
lista_diasDelMes[0] = 50
print("valor cambiado {}".format(lista_diasDelMes[0]))
tupla_diasDelMes[0] = 50




#####tupla con nombre

#se debe importar al libreria para hacer uso de namedtuple
from collections import namedtuple

#se crea la tupla con nombre
planeta = namedtuple('planeta', ['nombre', 'numero'])

#se crea el planeta 1 y se agregan a la tupla los valores correspondientes a los campos
planeta1 = planeta('Mercurio', 1)
print(planeta1)

#se crea el planeta 2 
planeta2 = planeta('Venus', 2)

#se imprimen los valores de los campos
print(planeta1.nombre, planeta1.numero)
#se obtienen los valores por el orden de los campos
print(planeta2[0], planeta2[1])

print('Campos de la tupla: {}'.format(planeta1._fields))
