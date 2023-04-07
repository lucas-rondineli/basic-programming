from tools import ctn_break

students = []
while True:
    name = input('Nome: ').strip()
    n1 = float(input('Nota 1: ').strip().replace(',', '.'))
    n2 = float(input('Nota 2: ').strip().replace(',', '.'))
    students.append([name, [n1, n2]])

    if ctn_break():
        break

print('-=' * 30)
print('No. NOME         MÉDIA')
print('-' * 22)
for n, std in enumerate(students):
    print(f'{n:<4}{std[0]:<13}{sum(std[1]) / 2:>5.1f}')

while True:
    print('-' * 30)
    std = int(input('Mostrar notas de qual aluno? (999 interromper): ').strip())
    if std == 999:
        break
    print(f'Notas de {students[std][0]} são {students[std][1]}')
print('FINALIZANDO...')
print('<<< VOLTE SEMPRE >>>')
