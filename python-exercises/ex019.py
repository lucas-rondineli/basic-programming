from random import choice

student_1 = input('Primeiro aluno: ')
student_2 = input('Segundo aluno: ')
student_3 = input('Terceiro aluno: ')
student_4 = input('Quarto aluno: ')
print(f'O aluno escolhido foi {choice((student_1, student_2, student_3, student_4))}')
