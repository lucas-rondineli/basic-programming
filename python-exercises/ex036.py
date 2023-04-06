value = float(input('Valor da casa: R$'))
salary = float(input('Salário do comprador: R$'))
years = float(input('Quantos anos de financiamento? '))
payment = value / (years * 12)

print(f'Para pagar uma casa de R${value:.2f} em {years} anos a prestação será de R${payment:.2f}')


if payment > salary * 0.3:
    print('Empréstimo NEGADO!')
else:
    print('O empréstimo pode ser CONCEDIDO!')
