values = []
while True:
    values.append(int(input('Digite um número:').strip()))

    cnt = ' '
    while cnt not in 'sn':
        cnt = input('Quer continuar? [S/N] ').lower().strip()[0]
    if cnt == 'n':
        break

print('-=' * 30)
print(f'A lista completa é {values}')
print(f'A lista de pares é {[i for i in values if i % 2 == 0]}')
print(f'A lista de ímpares é {[i for i in values if i % 2 != 0]}')
