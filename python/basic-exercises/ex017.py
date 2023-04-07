# side_a = float(input('Comprimento do cateto oposto: '))
# side_b = float(input('Comprimento do cateto adjacente: '))
# side_c = (side_a ** 2 + side_b ** 2) ** (1 / 2)
# print(f'A hipotenusa vai medir {side_c:.2f}')

from math import hypot

side_a = float(input('Comprimento do cateto oposto: '))
side_b = float(input('Comprimento do cateto adjacente: '))
side_c = hypot(side_a, side_b)
print(f'A hipotenusa vai medir {side_c:.2f}')
