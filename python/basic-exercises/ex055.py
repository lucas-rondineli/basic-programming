weights = []

for i in range(1, 6):
    weight = float(input(f'Peso da {i}° pessoa: '))
    weights.append(weight)

print(f'O maior peso lido foi de {max(weights):.1f}Kg')
print(f'O menor peso lido foi de {min(weights):.1f}Kg')
