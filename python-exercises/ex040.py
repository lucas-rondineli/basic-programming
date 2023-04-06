n1 = float(input('Primeira nota: '))
n2 = float(input('Segunda nota: '))
nm = (n1 + n2) / 2
print(f'Tirando {n1:.1f} e {n2:.1f}, a média do aluno é {nm:.1f}')

if nm >= 7:
    print('O aluno está APROVADO.')
elif nm >= 5:
    print('O aluno está em RECUPERAÇÃO.')
else:
    print('O aluno está REPROVADO.')
