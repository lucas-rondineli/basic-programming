number = int(input('Digite um número para calcular seu fatorial: '))
count = 1

print(f'Calculando {number}! = ', end='')
for i in range(number, 1, -1):
    print(f'{i} x ', end='')
    count *= i

print(f'1 = {count}')
