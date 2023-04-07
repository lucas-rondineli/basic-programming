player = {
    'name': input('Nome do Jogador: ').strip().title(),
    'gols': []
}
for i in range(int(input(f'Quantas partidas {player["name"]} jogou? '))):
    player['gols'].append(int(input(f'Quantos gols na partida {i}? ').strip()))
player['total'] = sum(player['gols'])

print('-=' * 30)
print(player)
print('-=' * 30)
for k, v in player.items():
    print(f'O campo {k} tem o valor {v}')
print('-=' * 30)
print(f'O jogador {player["name"]} jogou {len(player["gols"])} partidas.')
for i in range(len(player['gols'])):
    print(f'    => Na partida {i}, fez {player["gols"][i]} gols.')
print(f'Foi um total de {player["total"]} gols.')
