values = []
while True:
    values.append(int(input('Digite um valor:').strip()))

    cnt = ' '
    while cnt not in 'sn':
        cnt = input('Quer continuar? [S/N] ').lower().strip()[0]
    if cnt == 'n':
        break

print(f'Você digitou {len(values)} elementos.')
print(f'Os valores em ordem decrescente são {sorted(values, reverse=True)}')
print(f'O valor 5 {"faz" if 5 in values else "não faz"} parte da lista!')
