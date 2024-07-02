"""
String
Ejercicio:
Escribe una función es_palindromo que determine si una cadena de texto es un 
palíndromo (se lee igual de izquierda a derecha que de derecha a izquierda).
"""
"""
def es_palindromo(s):
    return_p = False
    new_s = s[::-1]
    if (s == new_s):
        return_p = True
    else:
        return_p = False
    
    return return_p
        

# Prueba tu función
print(es_palindromo("radar"))  # True
print(es_palindromo("python"))  # False
"""
################################################################################
"""
List
Ejercicio:
Escribe una función eliminar_duplicados que elimine los elementos duplicados 
de una lista manteniendo el orden original de los elementos.
"""

"""
def eliminar_duplicados(lst):
    new_lst = list(set(lst))
    new_lst.sort()
    return new_lst
    
# Prueba tu función
print(eliminar_duplicados([1, 2, 3, 1, 2, 4]))  # [1, 2, 3, 4]
print(eliminar_duplicados(['a', 'b', 'a', 'c', 'b']))  # ['a', 'b', 'c']
"""
################################################################################
"""
Tuple
Ejercicio:
Escribe una función intercambiar_tuplas que tome una tupla de dos elementos 
y devuelva una nueva tupla con los elementos intercambiados.
"""
"""
def intercambiar_tuplas(t):
    lst_t = list(t)
    return tuple(lst_t[::-1])

# Prueba tu función
print(intercambiar_tuplas((1, 2)))  # (2, 1)
print(intercambiar_tuplas(('a', 'b')))  # ('b', 'a')
"""
################################################################################
"""
Set
Ejercicio:
Escribe una función elementos_unicos que reciba una lista y devuelva un conjunto 
con los elementos únicos de la lista.
"""
"""
def elementos_unicos(lst):
    newlist = list(set(lst))
    return set(newlist)

# Prueba tu función
print(elementos_unicos([1, 2, 3, 1, 2, 4]))  # {1, 2, 3, 4}
print(elementos_unicos(['a', 'b', 'a', 'c', 'b']))  # {'a', 'b', 'c'}
"""
################################################################################
"""
Array
Ejercicio:
Escribe una función sumar_arrays que reciba dos arrays del mismo tamaño y 
devuelva un nuevo array con la suma de los elementos de los arrays dados.
"""
from array import array

def sumar_arrays(arr1, arr2):

    if(len(arr1) != len(arr2)):
        return -1
    
    suma = array('i',[])
    
    for x in range(len(arr1)):
        suma.append(arr1[x]+arr2[x])
    
    return suma 




# Prueba tu función
a1 = array('i', [1, 2, 3])
a2 = array('i', [4, 5, 6])
print(sumar_arrays(a1, a2))  # array('i', [5, 7, 9])
