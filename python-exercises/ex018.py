from math import sin, cos, tan, radians

angle = float(input('Digite o ângulo que você deseja: '))
rad_angle = radians(angle)
print(f'O ângulo de {angle} tem o SENO de {sin(rad_angle):.2f}')
print(f'O ângulo de {angle} tem o SENO de {cos(rad_angle):.2f}')
print(f'O ângulo de {angle} tem o SENO de {tan(rad_angle):.2f}')
