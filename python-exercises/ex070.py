print('-' * 30)
print('LOJA SUPER BARATÃO'.center(30))
print('-' * 30)

total = plus1000 = namec = pricec = 0

while True:
    name = input('Nome do Produto: ')
    price = float(input('Preço: R$').strip().replace(',', '.'))

    total += price
    if price > 1000:
        plus1000 += 1
    if pricec == 0 or price < pricec:
        pricec = price
        namec = name

    opt = input('Quer continuar? [S/N] ').lower().strip()[0]
    if opt == 'n':
        break

print(' FIM DO PROGRAMA '.center(40, '-'))
print(f'O total da compra foi R${total:.2f}')
print(f'Temos {plus1000} produtos custando mais de R$1000.00')
print(f'O produto mais barato foi {namec} que custa R${pricec:.2f}')
