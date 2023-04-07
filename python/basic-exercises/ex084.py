people = []

while True:
    name = input('Nome: ')
    weight = float(input('Peso: '))
    people.append((name, weight))

    ctn = ' '
    while ctn not in 'sn':
        ctn = input('Quer continuar? [S/N] ').lower().strip()[0]
    if ctn == 'n':
        break

people.sort(key=lambda x: x[1])
print('-=' * 30)
print(f'Ao todo, você cadastrou {len(people)} pessoas.')
print(f'O maior peso foi de {people[-1][1]:.1f}Kg. Peso de {[i[0] for i in people if i[1] == people[-1][1]]}')
print(f'O menor peso foi de {people[0][1]:.1f}Kg. Peso de {[i[0] for i in people if i[1] == people[0][1]]}')

# people = []
#
# while True:
#     name = input('Nome: ')
#     weight = float(input('Peso: '))
#     people.append((name, weight))
#
#     ctn = ' '
#     while ctn not in 'sn':
#         ctn = input('Quer continuar? [S/N] ').lower().strip()[0]
#     if ctn == 'n':
#         break
#
# people.sort(key=lambda x: x[1])
#
# print('-=' * 30)
# print(f'Ao todo, você cadastrou {len(people)} pessoas.')
# print(f'O maior peso foi de {people[-1][1]:.1f}Kg. Peso de ', end='')
# for p in people:
#     if p[1] == people[-1][1]:
#         print(f'[{p[0]}] ', end='')
#
# print(f'\nO menor peso foi de {people[0][1]:.1f}Kg. Peso de ', end='')
# for p in people:
#     if p[1] == people[0][1]:
#         print(f'[{p[0]}] ', end='')
