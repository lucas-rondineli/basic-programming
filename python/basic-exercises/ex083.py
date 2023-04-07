expression = input('Digite a expressão: ')
parenthesis = 0

for lt in expression:
    if lt == '(':
        parenthesis += 1
    elif lt == ')':
        parenthesis -= 1

    if parenthesis < 0:
        break

if parenthesis == 0:
    print('Sua expressão está válida!')
else:
    print('Sua expressão está errada!')
