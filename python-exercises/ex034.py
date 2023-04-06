salary = float(input('Qual é o salário do funcionário? R$'))
new_salary = salary * 1.15 if salary <= 1250 else salary * 1.1

print(f'Quem ganhava R${salary:.2f} passa a ganhar R${new_salary:.2f} agora.')
