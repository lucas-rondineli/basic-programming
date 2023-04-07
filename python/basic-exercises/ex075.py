numbers = (
    int(input('Digite um número: ')),
    int(input('Digite outro número: ')),
    int(input('Digite mais número: ')),
    int(input('Digite o último número: '))
)
print(f'Você digitou os valores: {numbers}')
print(f'O número 9 apareceu {numbers.count(9)} vezes')
if 3 in numbers:
    print(f'O número 3 apareceu na {numbers.index(3) + 1}° posição')
else:
    print(f'O número 3 não foi figitado em nenhuma posição')
print('Os valores pares digitados foram ')
for n in numbers:
    if n % 2 == 0:
        print('n ', end='')
