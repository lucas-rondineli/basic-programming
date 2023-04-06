from random import randint

values = (
    randint(1, 10),
    randint(1, 10),
    randint(1, 10),
    randint(1, 10),
    randint(1, 10)
)
print(f'Os valores sorteados foram: ')
for n in values:
    print(f'{n} ', end='')
print(f'\nO maior valor sorteado foi {max(values)}')
print(f'O menor valor sorteado foi {min(values)}')
