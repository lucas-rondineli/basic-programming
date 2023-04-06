phrase = input('Digite uma frase: ').lower().strip()
print(f'A letra A aparece {phrase.count("a")} vezes na frase.')
print(f'A primeira letra A apareceu na posição {phrase.find("a") + 1}')
print(f'A última letra A apareceu na posição {phrase.rfind("a") + 1}')
