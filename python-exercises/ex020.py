# from random import shuffle
# student_1 = input('Primeiro aluno: ')
# student_2 = input('Segundo aluno: ')
# student_3 = input('Terceiro aluno: ')
# student_4 = input('Quarto aluno: ')
#
# student_list = [student_1, student_2, student_3, student_4]
# shuffle(student_list)
#
# print(f'A ordem da apresentação será: ')
# print(student_list)

from random import sample

student_1 = input('Primeiro aluno: ')
student_2 = input('Segundo aluno: ')
student_3 = input('Terceiro aluno: ')
student_4 = input('Quarto aluno: ')
print(f'A ordem da apresentação será: ')
print(sample([student_1, student_2, student_3, student_4], k=4))
