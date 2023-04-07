tot18 = totm = totw20 = 0

while True:
    print('-' * 25)
    print('CADASTRE UMA PESSOA'.center(25))
    print('-' * 25)
    age = int(input('Idade: ').strip())
    sex = input('Sexo: [M/F] ').lower().strip()[0]

    if age > 18:
        tot18 += 1
    if sex == 'm':
        totm += 1
    if age < 20 and sex == 'f':
        totw20 += 1

    opt = input('Quer continuar? [S/N] ').lower().strip()[0]
    if opt == 'n':
        break

print(f'Total de pessoas com mais de 18: {tot18}')
print(f'Ao todo temos {totm} homens cadastrados')
print(f'E tems {totw20} mulheres com menos de 20 anos')
