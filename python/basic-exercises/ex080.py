values = []

for i in range(5):
    n = int(input('Digite um valor: '))

    if i == 0 or n > values[-1]:
        print('Adicionado ao final da lista...')
        values.append(n)
    else:
        for j in range(len(values)):
            if n <= values[j]:
                print(f'Adicionado na posição {j} da lista...')
                values.insert(j, n)
                break

print('-=' * 30)
print(f'Os valores digitados em ordem foram {values}')
