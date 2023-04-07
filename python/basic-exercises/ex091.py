from random import randint
from time import sleep


players = {
    'jogador1': randint(1, 6),
    'jogador2': randint(1, 6),
    'jogador3': randint(1, 6),
    'jogador4': randint(1, 6)
}

print('Valores sorteados:')
for k, v in players.items():
    print(f'{k} tirou {v} no dado.')
    sleep(1)

print('-=' * 30)
print('  == RANKING DOS JOGADORES ==  ')
players = sorted(players.items(), key=lambda x: x[1], reverse=True)
for i, player in enumerate(players, 1):
    print(f'   {i}° lugar: {player[0]} com {player[1]}.')
    sleep(1)
