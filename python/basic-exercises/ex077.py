words = (
    'APRENDER',
    'PROGRAMAR',
    'LINGUAGEM',
    'PYTHON',
    'CURSO',
    'GRATIS',
    'ESTUDAR',
    'PRATICAR',
    'TRABALHAR',
    'MERCADO',
    'PROGRAMADOR',
    'FUTURO'
)

for word in words:
    print(f'\nNa palavra {word} temos ', end='')
    for letter in word.lower():
        if letter in 'aeiou':
            print(f'{letter} ', end='')
