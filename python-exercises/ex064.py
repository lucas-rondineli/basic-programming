count = total = 0

while True:
    n = int(input('Digite um número [999 para parar]: '))
    if n == 999:
        break
    total += n
    count += 1

print(f'Você digitou {count} números e a soma entre eles foi {total}.')
