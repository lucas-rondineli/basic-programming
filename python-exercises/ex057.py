sex = input('Informe seu sexo: [M/F] ').lower().strip()[0]

while sex not in 'mf':
    sex = input('Dados inválidos. Por favor, informe seu sexo: [M/F] ').lower().strip()[0]

print(f'Sexo {sex.upper()} registrado com sucesso')
