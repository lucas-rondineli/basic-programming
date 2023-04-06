from random import randint

print('Sou seu computador...')
print('Acabei de pensar em um número entre 0 e 10.')
print('Será que você consegue adivinhar qual foi?')
number = randint(0, 10)
guesses = 0

while True:
    guess = int(input('Qual é o seu palpite? '))
    guesses += 1
    if guess == number:
        break
    if guess < number:
        print('Mais... Tente mais uma vez.')
    if guess > number:
        print('Menos... Tente mais uma vez.')

print(f'Acertou com {guesses} {"tentativa" if guesses == 1 else "tentativas"}. Parabéns!')
