n = []

while True:
    n.append(int(input('Digite um número: ')))

    opt = input('Quer continuar? [S/N] ').lower().strip()[0]
    if opt == 'n':
        break

print(f'Você digitou {len(n)} números  a média foi {sum(n) / len(n): .2f}')
print(f'O maior valor foi {max(n)} e o menor foi {min(n)}')
