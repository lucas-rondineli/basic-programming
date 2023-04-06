from time import sleep

n1 = int(input('Primeiro valor: '))
n2 = int(input('Segundo valor: '))

while True:
    opt = int(input('    [ 1 ] somar\n'
                    '    [ 2 ] multiplicar\n'
                    '    [ 3 ] maior\n'
                    '    [ 4 ] novos números\n'
                    '    [ 5 ] sair do programa\n'
                    '>>>>> Qual é a sua opção? '))

    if opt == 1:
        print(f'A soma entre {n1} + {n2} é {n1 + n2}')
    elif opt == 2:
        print(f'O resultado de {n1} x {n2} é {n1 * n2}')
    elif opt == 3:
        print(f'Entre {n1} e {n2} o maior valor é {max(n1, n2)}')
    elif opt == 4:
        print('Informe os números novamente:')
        n1 = int(input('Primeiro valor: '))
        n2 = int(input('Segundo valor: '))
    elif opt == 5:
        print('Finalizando...')
        print('=-=' * 10)
        sleep(1)
        break
    else:
        print('Opção inválida. Tente novamente')

    print('=-=' * 10)
    sleep(1)


print('Fim do programa! Volte sempre!')
