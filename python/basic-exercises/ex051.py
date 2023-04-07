print('=' * 30)
print('10 TERMOS DE UMA PA'.center(30))
print('=' * 30)

a1 = int(input('Primeiro termo: '))
r = int(input('Razão: '))

for i in range(10):
    print(a1, end=' → ')
    a1 += r
print('ACABOU')
