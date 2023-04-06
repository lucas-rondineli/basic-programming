from random import randint
from time import sleep

print('-=-' * 20)
print('Vou pensar em um número entre 0 e 5. Tente adivinhar...')
print('-=-' * 20)

guess = int(input('Em que número pensei? '))
print('PROCESSANDO...')
sleep(1)

number = randint(0, 5)
if guess == number:
    print('PARABÉNS! Você conseguiu me vencer!')
else:
    print(f'GANHEI! Eu pensei no número {number} e não no {guess}!')
