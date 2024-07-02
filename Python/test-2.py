'''
String
Ejercicio:
Escribe una función encriptar_cesar que implemente el cifrado César, 
que desplaza cada letra de la cadena una cantidad fija de lugares en 
el alfabeto. La función debe recibir una cadena y un número n como 
desplazamiento, y devolver la cadena encriptada.
'''

def encriptar_cesar(s, n):
    resultado = []
    for char in s:
        if char.isalpha():
            desplazamiento = 65 if char.isupper() else 97
            resultado.append(chr((ord(char) - desplazamiento + n) % 26 + desplazamiento))
        else:
            resultado.append(char)
    return ''.join(resultado)
    
    

# Prueba tu función
print(encriptar_cesar("abc", 3))  # "def"
print(encriptar_cesar("xyz", 2))  # "zab"