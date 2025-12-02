#se crea una variable en el espacio global de nombres 
vg = 'Global'

#se crea una funcion que imprime la variable globaL
def funcion_vl():
    print(vg)

    #llamada a la funcion que imprime la variable global
funcion_vl()

    #imprime la variable
print(vg)

#se crea una variable local que tiene el mismo nombre que la variable global
def funcion_v2():
    vg = "local"
    print(vg)

#llamada a la funcion 
funcion_v2()

#imprime la variasbñe
print(vg)

#se trata de imprimir el valor de la variable global, a diferencia de la funcion_v1(),
#se creo en el espacio locoal de la funcion_v3() una variable con el mismo nombre,
#por lo que se reemplaza la variable global
def funcion_v3():
    global vg
    print(vg)
    vg = "local"
    print(vg)

#como se tiene una variable local y no se ha asignado un valor, se genera un error
funcion_v3()


#para resolver el problema y especificar que se quiere hacer uso de la 
#variable global dentro de la funcion funcion_v4(), se tiene que agregar ña 
#palabra reservada global
def funcion_v4():
    global vg
    print(vg)
    vg = "local"
    print(vg)

#al ejecutar se imprime el valor que tenia asignado vf
#antes de ser modificado por la funcion. despues de asignar el valor, se imprime
funcion_v4()

#se imprime la variable global con su valor modificado
print(vg)

    
