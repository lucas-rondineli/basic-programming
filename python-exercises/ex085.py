values = [[], []]
for i in range(1, 8):
    v = int(input(f'Digite o {i}° valor: '))
    if v % 2 == 0:
        values[0].append(v)
    else:
        values[1].append(v)
values[0].sort()
values[1].sort()

print('-=' * 30)
print(f'Os valores pares digitados foram: {values[0]}')
print(f'Os valores ímpares digitados foram: {values[1]}')
