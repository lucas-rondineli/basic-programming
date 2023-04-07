from random import sample
from time import sleep

print('-' * 30)
print('JOGA NA MEGA SENA'.center(30))
print('-' * 30)

opt = int(input('Quantos jogos você quer que eu sorteie? ').strip())
games = []
for i in range(opt):
    games.append(sorted(sample(range(1, 61), 6)))

print(f'-=-=-= SORTEANDO {opt} JOGOS -=-=-=')
for i in range(opt):
    print(f'Jogo {i + 1}: {games[i]}')
    sleep(1)
print('-=-=-=-=-= < BOA SORTE! > -=-=-=-=-=')
