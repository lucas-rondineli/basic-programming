number = int(input('Digite um número inteiro: '))

option = int(input('Escolha uma das bases para conversão:\n'
                   '[ 1 ] converter para BINÁRIO\n'
                   '[ 2 ] converter para OCTAL\n'
                   '[ 3 ] converter para HEXADECIMAL\n'
                   'Sua opção: '))

if option == 1:
    print(f'{number} convertido para BINÁRIO é igual a {str(bin(number))[2:]}')
elif option == 2:
    print(f'{number} convertido para OCTAL é igual a {str(oct(number))[2:]}')
else:
    print(f'{number} convertido para HEXADECIMAL é igual a {str(hex(number))[2:]}')
