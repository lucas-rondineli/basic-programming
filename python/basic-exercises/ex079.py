values = []

while True:
    n = int(input('Digite um valor: ').strip())
    if n not in values:
        values.append(n)
        print('Valor adicionado com sucesso...')
    else:
        print('Valor duplicado! Não vou adicionar...')

    opt = ' '
    while opt not in 'sn':
        opt = input('Quer continuar? [S/N] ').lower().strip()[0]
    if opt == 'n':
        break
values.sort()

print(f'Você digitou os valores {values}')
