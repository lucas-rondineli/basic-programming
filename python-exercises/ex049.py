number = int(input('Digite um número para ver sua tabuada: '))

for i in range(1, 11):
    print(f'{number} x {i:>2} = {number * i:>2}')
