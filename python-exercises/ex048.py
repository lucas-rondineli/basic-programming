total_sum = cont = 0

for i in range(1, 500, 2):
    if i % 3 == 0:
        total_sum += i
        cont += 1
print(f'A soma de todos os {cont} valores é {total_sum}')
