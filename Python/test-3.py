"""
List
Ejercicio:
Escribe una función sublistas que reciba una lista y devuelva una 
lista de todas las sublistas posibles.
"""
def sublistas(lst):
    resultado = [[]]
    for i in range(len(lst)):
        for j in range(i + 1, len(lst) + 1):
            resultado.append(lst[i:j])
    return resultado

# Prueba tu función
print(sublistas([1, 2, 3]))  
# [[], [1], [2], [3], [1, 2], [2, 3], [1, 2, 3]]