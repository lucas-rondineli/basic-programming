# Essa função vai fazer com que o programa espere durante um tempo.
from time import sleep


# Essa função vai mostrar os dois tabuleiros de inicio, depois mostrará um de cada vez.
# Isso dependerá do jogador da vez.
def mostrartabuleiro(jogador, inicio=False):
    if inicio:
        for nomeetab in ((jogador1, tabj1), (jogador2, tabj2)):
            print('\n', ' ' * 7, f'\033[1;37;7;40m{f"Tabuleiro de: {nomeetab[0]}":^67}\033[0m', sep='')
            print('             Colunas                                   \n'
                  '       \033[37;40m      |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  |\033[0m')
            for linha in 'ABCDEFGHIJ':
                if linha == 'A':
                    print('Linhas ', end='')
                else:
                    print('       ', end='')
                print('\033[37;40m', end='')
                print(f'|  {linha}  ', end='')
                for coluna in range(1, 11):
                    if visivel == 'N':
                        print(f'|  ?  ', end='')
                    else:
                        if nomeetab[1][linha][coluna] == '?':
                            print(f'|  ?  ', end='')
                        else:
                            print(f'|  {nomeetab[1][linha][coluna][0]}  ', end='')
                print('|\033[0m')
                sleep(0.1)
            sleep(2)
    else:
        nomeetab = {jogador1: tabj2, jogador2: tabj1}
        print('\n', ' ' * 7, f'\033[1;7;37;40m{f"Vez do jogador: {jogador}":^67}\033[0m', sep='')
        print('             Colunas                                   \n'
              '       \033[37;40m      |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  |\033[0m')
        for linha in 'ABCDEFGHIJ':
            if linha == 'A':
                print('Linhas ', end='')
            else:
                print('       ', end='')
            print('\033[37;40m', end='')
            print(f'|  {linha}  ', end='')
            for coluna in range(1, 11):
                if nomeetab[jogador][linha][coluna] == '?' or nomeetab[jogador][linha][coluna] != '*' and\
                        (visivel == 'N' and not(nomeetab[jogador][linha][coluna][1])):
                    print(f'|  ?  ', end='', flush=True)
                elif nomeetab[jogador][linha][coluna] == '*':
                    print(f'|\033[37;44m  *  \033[40m', end='')
                else:
                    if visivel == 'S':
                        if nomeetab[jogador][linha][coluna][1]:
                            print(f'|\033[37;41m  {nomeetab[jogador][linha][coluna][0]}  \033[40m', end='')
                        else:
                            print(f'|  {nomeetab[jogador][linha][coluna][0]}  ', end='')
                    else:
                        print(f'|\033[37;41m  {nomeetab[jogador][linha][coluna][0]}  \033[40m', end='')
            print('|\033[0m')
            sleep(0.1)


# Essa função vai perguntar ao usuário onde atirar, testar se o local já foi bombardeado ou
# Se nele há um navio, modificar o tabuleiro do jogador e retornar 'S' ou 'N', dependendo se
# O jogador acertou ou não um navio.
def atirar(tab):
    mostrartabuleiro(vez)
    global totaln1
    global totaln2
    # Começa com uma repetição para só parar quando o usuário inserir um espaço válido.
    while True:
        tiro = input(f'       Escolha um bloco (Ex: "A1", "B2"): ').strip().upper()
        # Aqui é feito um teste para ver se o espaço é válido e se nele há ou não um navio.
        if tab[tiro[0]][int(tiro[1:])] == '*':
            print(' ' * 7, 'Tiro Inválido! Espaço já bombardeado, tente novamente.', sep='')
        elif tab[tiro[0]][int(tiro[1:])] == '?':
            tab[tiro[0]][int(tiro[1:])] = '*'
            return 'N'
        else:
            if tab[tiro[0]][int(tiro[1:])][1]:
                print(' ' * 7, 'Tiro Inválido! Espaço já bombardeado, tente novamente.', sep='')
            else:
                # Aqui o valor 'True' significa que o bloco, que tem um navio, recebeu um tiro.
                tab[tiro[0]][int(tiro[1:])][1] = True
                if vez == jogador1:
                    totaln1 -= 1
                elif vez == jogador2:
                    totaln2 -= 1
                return 'S'


# Essa função vai definir a posição dos navios de forma aleatória.
def definirnavios(tab):
    from random import choice

    linhas = {1: 'A', 2: 'B', 3: 'C', 4: 'D', 5: 'E', 6: 'F', 7: 'G', 8: 'H', 9: 'I', 10: 'J'}
    colunas = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    tamporta = 4
    tamcruz = 3
    tamsub = 2
    for n in ((totporta, tamporta), (totcruz, tamcruz), (totsub, tamsub)):
        for x in range(n[0]):
            while True:
                navio = list()
                direcao = choice(('V', 'H'))
                blocoini = choice(range(1, 11) if direcao == 'H' else range(1, 12 - n[1])),\
                           choice(range(1, 11) if direcao == 'V' else range(1, 12 - n[1]))
                for c in range(n[1]):
                    if blocoini[0] + (c if direcao == 'V' else 0) == 1:
                        linhastestadas = (linhas[blocoini[0] + (c if direcao == 'V' else 0)],
                                          linhas[blocoini[0] + 1 + (c if direcao == 'V' else 0)])
                    elif blocoini[0] + (c if direcao == 'V' else 0) == 10:
                        linhastestadas = (linhas[blocoini[0] - 1 + (c if direcao == 'V' else 0)],
                                          linhas[blocoini[0] + (c if direcao == 'V' else 0)])
                    else:
                        linhastestadas = (linhas[blocoini[0] - 1 + (c if direcao == 'V' else 0)],
                                          linhas[blocoini[0] + (c if direcao == 'V' else 0)],
                                          linhas[blocoini[0] + 1 + (c if direcao == 'V' else 0)])
                    if blocoini[1] + (c if direcao == 'H' else 0) == 1:
                        colunastestadas = colunas[blocoini[1] - 1 + (c if direcao == 'H' else 0)
                                                  :blocoini[1] + 1 + + (c if direcao == 'H' else 0)]
                    elif blocoini[1] + (c if direcao == 'H' else 0) == 10:
                        colunastestadas = colunas[blocoini[1] - 2 + (c if direcao == 'H' else 0)
                                                  :blocoini[1] + (c if direcao == 'H' else 0)]
                    else:
                        colunastestadas = colunas[blocoini[1] - 2 + (c if direcao == 'H' else 0)
                                                  :blocoini[1] + 1 + (c if direcao == 'H' else 0)]

                    testados = list()
                    for lin in linhastestadas:
                        for col in colunastestadas:
                            testados.append(f'{lin}{col}')
                    if c != 0:
                        testados.remove(f'{linhas[blocoini[0] + (c - 1 if direcao == "V" else 0)]}'
                                        f'{blocoini[1] + (c - 1 if direcao == "H" else 0)}')
                    contador = 0
                    for blocotestado in testados:
                        if tab[blocotestado[0]][int(blocotestado[1:])] == '?':
                            contador += 1
                    if contador == len(testados):
                        navio.append(f'{linhas[blocoini[0] + (c if direcao == "V" else 0)]}'
                                     f'{blocoini[1] + (c if direcao == "H" else 0)}')
                    else:
                        break
                if len(navio) == n[1]:
                    if n[1] == tamporta:
                        navioadicionado = ['P', False]
                    elif n[1] == tamcruz:
                        navioadicionado = ['C', False]
                    elif n[1] == tamsub:
                        navioadicionado = ['S', False]
                    for bloco in navio:
                        tab[bloco[0]][int(bloco[1:])] = navioadicionado[:]
                    break


# Essa função vai mostrar uma mensagem formatada.
def msgformatada(msg, corbg, cormsg=37):
    tam = len(msg) + 4
    print(' ' * 7, f'\033[1;{cormsg};{corbg}m', '~' * tam, '\033[0m', sep='')
    print(' ' * 7, f'\033[1;{cormsg};{corbg}m{msg:^{tam}}\033[0m', sep='')
    print(' ' * 7, f'\033[1;{cormsg};{corbg}m', '~' * tam, '\033[0m', sep='')


# PROGRAMA PRINCIPAL
# Criando a Matriz dos Tabuleiros
tabj1 = {x: {y: '?' for y in range(1, 11)} for x in 'ABCDEFGHIJ'}
tabj2 = {x: {y: '?' for y in range(1, 11)} for x in 'ABCDEFGHIJ'}

# Definindo a Tela Inicial, a Quantidade dos Navios e sua Visibilidade
print(' ' * 7, f'\033[1;7;37;40m{"BATALHA NAVAL":^67}\033[0m\n',
      ' ' * 7, f'\033[1;37;40m{"Por: Lucas, Walter e Erick":^67}\033[0m\n\n',
      '\033[37;40mOpções:\033[0m', sep='')

resp = input('Deseja jogar com a frota máxima (1 Porta-avião, 2 Cruzadores e 3 Submarinos)? [S/N] ').strip().upper()[0]
if resp == 'N':
    totporta = int(input('Com quantos Porta-aviões você deseja jogar (entre 0 e 1)? ').strip())
    totcruz = int(input('Com quantos Cruzadores você deseja jogar (entre 0 e 2)? ').strip())
    totsub = int(input('Com quantos Porta-aviões você deseja jogar (entre 1 e 3)? ').strip())
else:
    totporta = 1
    totcruz = 2
    totsub = 3
totaln1 = totaln2 = totporta * 4 + totcruz * 3 + totsub * 2
jogador1 = input('Digite o nome do 1° Jogador: ').strip().capitalize()
jogador2 = input('Digite o nome do 2° Jogador: ').strip().capitalize()
visivel = input('(Opção para fins de teste) Deseja tornar os navios visíveis? [S/N] ').strip().upper()[0]

# Definindo a Posição do Navios no Tabuleiro de Forma Aleatória
definirnavios(tabj1)
definirnavios(tabj2)

# Recebendo a Jogada do Usuário
# O 'jogador' começa com 2 pois o valor sempre se inverterá na repetição a seguir.
# Assim, o jogo poderá começar com a jogada do jogador 1
vez = jogador2
# Mostrando o Tabuleiro na Tela pela Primeira Vez
mostrartabuleiro(vez, inicio=True)

while True:
    # Entrada de Tiros dos Jogadores
    if vez == jogador2:
        vez = jogador1
    elif vez == jogador1:
        vez = jogador2
    while True:
        if not (totaln1 != 0 and totaln2 != 0):
            break
        acertou = atirar(tabj2 if vez == jogador1 else tabj1)
        if acertou == 'N':
            break
        msgformatada('FOGO', 41)
        sleep(2)
    if not (totaln1 != 0 and totaln2 != 0):
        break
    msgformatada('ÁGUA', 44)
    sleep(2)

# Mostrando o Resultado do Jogo
if totaln1 == 0:
    print()
    msgformatada(f'Vitória de {jogador1}!', 42)
elif totaln2 == 0:
    print()
    msgformatada(f'Vitória de {jogador2}!', 42)