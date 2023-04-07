print('-' * 30)
print('Sequência de Fibonacci')
print('-' * 30)

numbers = int(input('Quantos termos você quer mostrar? '))
n1 = 0
n2 = 1
print('~' * 30)

for i in range(numbers):
    print(f'{n1} → ', end='')
    n1, n2 = n2, n1 + n2

print('FIM')
