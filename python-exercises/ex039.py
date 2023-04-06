from datetime import datetime

year = int(input('Ano de nascimento: '))
age = datetime.today().year - year
enlistment_year = year + 18
actual_year = datetime.today().year

print(f'Quem nasceu em {year} tem {age} em {actual_year}.')

if enlistment_year < actual_year:
    print(f'Você deveria ter se alistado há {actual_year - enlistment_year} anos.')
    print(f'Seu alistamento foi em {enlistment_year}.')
elif enlistment_year > actual_year:
    print(f'Ainda faltam {enlistment_year - actual_year} anos para o alistamento.')
    print(f'Seu alistamento será em {enlistment_year}.')
else:
    print(f'Você tem que se alistar IMEDIATAMENTE!')
