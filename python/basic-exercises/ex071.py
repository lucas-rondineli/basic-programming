print('=' * 30)
print('BANCO CEV'.center(30))
print('=' * 30)
notes = [50, 20, 10, 5, 2, 1]
totnote = []

money = float(input('Que valor você quer sacar? R$').strip().replace(',', '.'))

for n, ced in enumerate(notes):
    totnote.append(0)

    while money >= ced:
        money -= ced
        totnote[n] += 1

for tot, note in zip(totnote, notes):
    if tot:
        print(f'Total de {tot} cédulas de R${note}')

print('=' * 30)
print('Volte sempre ao BANCO CEV! Tenha um bom dia!')
