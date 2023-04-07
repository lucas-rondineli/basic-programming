number = int(input('Digite um número: '))
divisors = 0

for i in range(1, number + 1):
    print(i, end=' ')
    if number % i == 0:
        divisors += 1

print(f'\nO número {number} foi divisível {divisors} vezes')
if divisors == 2:
    print('E por isso ele É PRIMO!')
else:
    print('E por isso ele NÃO É PRIMO!')
