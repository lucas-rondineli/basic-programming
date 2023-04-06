n1 = int(input('Primeiro número: '))
n2 = int(input('Segundo número: '))

if n1 == n2:
    print('Os dois valores são IGUAIS')
else:
    print(f'O {"PRIMEIRO" if n1 > n2 else "SEGUNDO"} valor é maior')
