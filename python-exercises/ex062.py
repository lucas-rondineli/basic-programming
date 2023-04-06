print('Gerador de PA')
print('-=' * 10)

a1 = int(input('Primeiro termo: '))
r = int(input('Razão da PA: '))
count = 10
total = 0

while count > 0:
    print(a1, end=' → ')
    a1 += r
    count -= 1
    total += 1

    if count == 0:
        print('PAUSA')
        count = int(input('Quantos termos você quer mostrar a mais? '))

print(f'Progressão finalizada com {total} termos mostrados.')
