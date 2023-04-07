print('Gerador de PA')
print('-=' * 10)

a1 = int(input('Primeiro termo: '))
r = int(input('Razão da PA: '))
count = 10

while count > 0:
    print(a1, end=' → ')
    a1 += r
    count -= 1
print('FIM')
