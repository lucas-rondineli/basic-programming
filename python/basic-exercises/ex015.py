days = int(input('Quantos dias alugados? '))
km = int(input('Quantos Km rodados? '))
print(f'O total a pagar é de R${days * 60 + km * 0.15:.2f}')
