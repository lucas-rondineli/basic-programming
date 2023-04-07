print('-=' * 20)
print('Analisador de Triângulos')
print('-=' * 20)

a = int(input('Primeiro segmento: '))
b = int(input('Segundo segmento: '))
c = int(input('Terceiro segmento: '))

if a < b + c and b < a + c and c < a + b:
    if a == b and b == c:
        print('Os segmentos acima PODEM FORMAR um triângulo EQUILATERO!')
    elif a == b or b == c or a == c:
        print('Os segmentos acima PODEM FORMAR um triângulo ISÓCELES!')
    else:
        print('Os segmentos acima PODEM FORMAR um triângulo ESCALENO!')
else:
    print('Os segmentos acima NÃO PODEM FORMAR triângulo!')
