def ctn_break():
    while True:
        ctn = input('Quer continuar? [S/N] ').lower().strip()[0]
        if ctn in 'sn':
            break
        print(f'ERRO! Responda apenas S ou N.')
    if ctn == 'n':
        return True
    return False
