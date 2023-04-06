print(' LOJAS GUANABARA '.center(40, '='))
price = float(input('Preço das compras: R$'))
option = int(input('FORMAS DE PAGAMENTO\n'
                   '[ 1 ] à vista dinheiro/cheque\n'
                   '[ 2 ] à vista cartão\n'
                   '[ 3 ] 2x no cartão\n'
                   '[ 4 ] 3x ou mais no cartão\n'
                   'Qual é a opção? '))

if option == 1:
    total = price * 0.9

elif option == 2:
    total = price * 0.95
elif option == 3:
    total = price
    print(f'Sua compra será parcelada em 2x de R${total / 2:.2f}')
else:
    total = price * 1.2
    itm = int(input('Quantas parcelas? '))
    print(f'Sua compra será parcelada em {itm}x de R${total / itm:.2f} COM JUROS')
print(f'Sua compra de R${price:.2f} vai custar R${total:.2f} no final.')
