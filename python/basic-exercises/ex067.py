while True:
    number = int(input('Digite um número para ver sua tabuada: '))
    print('-' * 30)

    if number < 0:
        break

    for i in range(1, 11):
        print(f'{number} x {i:>2} = {number * i:>2}')
    print('-' * 30)

print('PROGRAMA TABUADA ENCERRADO. Volte sempre!')
