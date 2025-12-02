#declaracion de una lista simple
lista_diasDelMes=[31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31]

print (lista_diasDelMes)
print (lista_diasDelMes[0])
print (lista_diasDelMes[6])
print (lista_diasDelMes[11])

#declaracion de listas anidadas 

lista_numeros=[['cero', 0],['uno', 1, 'UNO'], ['dos',2], ['tres', 3], ['cuatro',4], ['X',5]]

print (lista_numeros) 

print (lista_numeros[0])
print (lista_numeros[1])

print (lista_numeros[2][0])
print (lista_numeros[2][1])

print (lista_numeros[1][0])
print (lista_numeros[1][1])
print (lista_numeros[1][2])

#se cambia el valor de uno de los elementos de la lista

lista_numeros[5][0] = "cinco"
print (lista_numeros[5])
