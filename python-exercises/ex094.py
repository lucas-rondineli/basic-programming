from tools import ctn_break

people = []

while True:
    person = {'name': input('Nome: ').strip().title()}
    while True:
        person['sex'] = input('Sexo: [M/F] ').lower().strip()[0]
        if person['sex'] in 'mf':
            break
        print('ERRO! Por favor, digite apenas M ou F.')
    person['age'] = int(input('Idade: ').strip())
    people.append(person.copy())

    if ctn_break():
        break
print('-=' * 30)
print(f'A) Ao todo temos {len(people)} pessoas cadastradas.')
people_mean = sum([x["age"] for x in people]) / len(people)
print(f'B) A média de idade é de {people_mean:.2f} anos.')
print(f'C) As mulheres cadastradas foram {" ".join([x["name"] for x in people if x["sex"] == "f"])}')
print(f'D) Lista das pessoas que estão acima da média:')
for person in filter(lambda x: x['age'] > people_mean, people):
    print(f'    nome = {person["name"]}; sexo = {person["sex"]}; idade = {person["age"]}')
print('<< ENCERRADO >>')
