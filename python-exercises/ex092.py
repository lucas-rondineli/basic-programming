from datetime import date

worker = {
    'name': input('Nome: ').strip().title(),
    'age': date.today().year - int(input('Ano de Nascimento: ').strip()),
    'jw': int(input('Carteira de Trabalho (0 não tem): ').strip())
}
if worker['jw'] != 0:
    worker['hy'] = int(input('Ano de Contratação: ').strip())
    worker['salary'] = float(input('Salário: R$').strip().replace(',', '.'))
    worker['retirement'] = worker['hy'] + 35 - date.today().year + worker['age']

print('-=' * 30)
for k, v in worker.items():
    print(f'  - {k} tem o valor {v}')

