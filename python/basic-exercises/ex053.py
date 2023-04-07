phrase = input('Digite uma frase: ').upper().replace(' ', '')
print(f'O inverso de {phrase} é {phrase[::-1]}')

if phrase == phrase[::-1]:
    print('A frase digitada é um palíndromo!')
else:
    print('A frase digitada não é um palíndromo!')
