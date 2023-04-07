from time import sleep
from random import randint

p_option = int(input('Suas opções:\n'
                     '[ 1 ] PEDRA\n'
                     '[ 2 ] PAPEL\n'
                     '[ 3 ] TESOURA\n'
                     'Qual é a sua jogada? ')) - 1
c_option = randint(0, 2)
moves = ('Pedra', 'Papel', 'Tesoura')

print('JO')
sleep(1)
print('KEN')
sleep(1)
print('PO!!!')
sleep(1)

print('-=' * 11)
print(f'Computador jogou {moves[c_option]}')
print(f'Jogador jogou {moves[p_option]}')
print('-=' * 11)

if p_option == c_option:
    print('EMPATE')
elif p_option - c_option in (1, -2):
    print('JOGADOR VENCE')
else:
    print('COMPUTADOR VENCE')
