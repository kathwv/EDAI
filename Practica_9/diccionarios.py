#creando un diccionario
elementos = { 'hidrogeno': 1, 'helio': 2, 'carbon': 6 }

print (elementos)

print (elementos['hidrogeno'])

#se pueden agregar elementos al diccionario
elementos['litio'] = 3
elementos['nitrogeno'] = 8

print (elementos)

#creando un nuevo diccionario 
elementos2 = {}
elementos2['H'] = { 'name': 'Hydrogen', 'number': 1, 'weight': 1.00794}
elementos2['He'] = { 'name': 'Helium', 'number': 2, 'weight': 4.002602}

print (elementos2)

#imprimiendo los datos de un elemento del diccionario
print (elementos2['H'])
print (elementos2['H']['name'])
print (elementos2['H']['number'])
elementos2['H']['weight'] = 4.30
print (elementos2['H']['weight'])


#agregando elementos a una llave
elementos2['H'].update({'gas noble': True})
print (elementos2['H'])

#muestra todos los elementos del diccionario
print (elementos2.items())

#muestra todas las llaves del diccionario
print (elementos2.keys())
