values = [[], [], []]

for i in range(3):
    for j in range(3):
        values[i].append(int(input(f'Digite um valor para [{i}, {j}]: ')))

print('-=' * 30)
for i in range(3):
    for j in range(3):
        print(f'[{values[i][j]:^5}]', end='')
    print()
