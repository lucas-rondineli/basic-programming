# from math import trunc
#
# value = float(input('Digite um valor: '))
# print(f'O valor digitado foi {value} e a sua porção inteira é {trunc(value)}')

value = float(input('Digite um valor: '))
print(f'O valor digitado foi {value} e a sua porção inteira é {value.__floor__()}')
