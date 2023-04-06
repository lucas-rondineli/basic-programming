total_sum = cont = 0
for i in range(6):
    number = int(input(f'Digite o {i + 1}° valor: '))
    if number % 2 == 0:
        total_sum += number
        cont += 1
print(f'Você informou {cont} valores PARES e a soma foi {total_sum}')
