distance = float(input('Qual é a distância da sua viagem? '))
print(f'Você está prestes a começar uma viagem de {distance}Km.')
price = distance * 0.5 if distance <= 200 else distance * 0.45
print(f'E o preço da sua passagem será de R${price:.2f}')
