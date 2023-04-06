products = (
    'Lápis', 1.75,
    'Borracha', 2,
    'Caderno', 15.9,
    'Estojo', 25,
    'Transferidor', 4.2,
    'Compasso', 9.99,
    'Mochila', 120.32,
    'Canetas', 22.3,
    'Livro', 34.90,
)

print('-' * 40)
print('LISTAGEM DE PREÇOS'.center(40))
print('-' * 40)

for product in products:
    if type(product) == str:
        print(f'{product:.<30}', end='')
    else:
        print(f'R${product:>7.2f}')
print('-' * 40)