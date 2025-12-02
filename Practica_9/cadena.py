#inicializando cadenas
cadena1 = 'hola '
cadena2 = "mundo"
print(cadena1)
print(cadena2)
concat_cadenas = cadena1 + cadena2 
print(concat_cadenas)


#para concatenar un numero y una cadena se debe usar la funcion str()
num_cadena = concat_cadenas + '  ' + str(3) #se agrega una cadena vacia para agregar un espacio
print(num_cadena)

#el valor de la variable se va a imprimir en el lugar donde se encuentre {} en la cadena
num_cadena = "{} {} {}". format(cadena1, cadena2, 3)
print(num_cadena)

#cuando se agrega un numero dentro de {#}, el valor de la variable que se encuentra en esa posición
#dento de la funcion format(), sera impreso
num_cadena = "Cambiando el orden: {1} {2} {0} #".format(cadena1, cadena2, 3)
print(num_cadena)
