from datetime import datetime

underage = overage = 0
for i in range(1, 8):
    year = int(input(f'Em que ano a {i}° pessoa nasceu? '))
    if datetime.today().year - year < 18:
        underage += 1
    else:
        overage += 1

print(f'Ao todo tivemos {overage} pessoas maiores de idade')
print(f'E também tivemos {underage} pessoas menores de idade')
