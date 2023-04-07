from random import randint

print('=-' * 15)
print('VAMOS JOGAR PAR OU ÍMPAR')
wins = 0

while True:
    print('=-' * 15)
    pn = int(input('Digite um valor: ').strip())
    cn = randint(0, 10)
    total = pn + cn
    while True:
        pc = input('Par ou Ímpar? [P/I] ').lower().strip()[0]
        if pc in 'pi':
            break
        print(f'ERRO! Digite corretamente.')

    print('-' * 30)
    print(f'Você jogou {pn} e o computador jogou {cn}. Total de {total} DEU '
          f'{"PAR" if total % 2 == 0 else "ÍMPAR"}')
    print('-' * 30)

    if pc == 'p' and total % 2 == 0 or pc == 'i' and total % 2 == 1:
        wins += 1
        print('Você VENCEU!')
        print('Vamos jogar novamente...')
    else:
        print('Você PERDEU!')
        break

print('=-' * 15)
print(f'GAME OVER! Você venceu {wins} {"vez" if wins == 1 else "vezes"}.')
