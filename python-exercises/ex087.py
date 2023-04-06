values = [[], [], []]

for i in range(3):
    for j in range(3):
        values[i].append(int(input(f'Digite um valor para [{i}, {j}]: ')))

print('-=' * 30)
for i in range(3):
    for j in range(3):
        print(f'[{values[i][j]:^5}]', end='')
    print()

print('-=' * 30)
print(f'A soma dos valores pares é {sum([values[i][j] for i in range(3) for j in range(3) if values[i][j] % 2 == 0])}')
print(f'A soma dos valores da terceira coluna é {sum([values[i][2] for i in range(3)])}')
print(f'O maior valor da segunda linha é {max(values[1])}')
