student = {'name': input('Nome: ')}
student['mean'] = float(input(f'Média de {student["name"]}: '))
student['situation'] = 'Aprovado' if student['mean'] >= 7 else 'Recuperação' if student['mean'] >= 5 else 'Reprovado'

print('-=' * 30)
for k, v in student.items():
    print(f'  - {k} é igual a {v}')
