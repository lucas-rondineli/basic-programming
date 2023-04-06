# sum_age = total_people = old_age = new_women = 0
# old_name = ''
#
# for i in range(1, 5):
#     print(f' {i}° PESSOA '.center(21, '-'))
#     name = input('Nome: ')
#     age = int(input('Idade: '))
#     sex = input('Sexo [M/F]: ').lower().strip()
#
#     sum_age += age
#     total_people += 1
#     if age > old_age and sex == 'm':
#         old_age = age
#         old_name = name
#     if age < 20 and sex == 'f':
#         new_women += 1
#
# mean_age = sum_age / total_people
#
# print(f'A média de idade do grupo é de {mean_age}')
# print(f'O homem mais velho tem {old_age} e se chama {old_name}')
# print(f'Ao todo são {new_women} mulheres com menos de 20 anos.')

people = []

for i in range(1, 5):
    print(f' {i}° PESSOA '.center(21, '-'))
    name = input('Nome: ')
    age = int(input('Idade: '))
    sex = input('Sexo [M/F]: ').lower().strip()

    people.append({'name': name, 'age': age, 'sex': sex})

print(f'A média de idade do grupo é de {sum(map(lambda x: x["age"], people)) / len(people)}')

old = max(filter(lambda x: x['sex'] == 'm', people), key=lambda y: y['age'])
print(f'O homem mais velho tem {old["age"]} e se chama {old["name"]}')

print(
    f'Ao todo são {len(tuple(filter(lambda x: x["sex"] == "f" and x["age"] < 20, people)))} '
    f'mulheres com menos de 20 anos.')
