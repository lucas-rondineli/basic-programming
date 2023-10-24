;inicia a stack do programa com 128B
pilha segment stack
db 128 dup(?)
pilha ends

;inicia os dados usados pelo programa
dados segment
msgnt1 db 'Digite a primeira nota (entre 000 e 100): #'
msgnt2 db 'Digite a segunda nota (entre 000 e 100): #'
msgnt3 db 'Digite a terceira nota (entre 000 e 100): #'
msgmed db 'A sua media foi de: #'
msgapv db 'Voce foi aprovado, parabens!#'
msgrpv db 'Voce foi reprovado, que pena!#'
msgrec db 'Voce ficou de recuperacao. A nota necessaria na final sera: #'
msgerr1 db 'Erro! Digite apenas caracteres numericos, ou ENTER para sair.#'
msgerr2 db 'Erro! Digite apenas notas entre 0 e 100.#'
nota1asc db '000#'
nota2asc db '000#'
nota3asc db '000#'
notamedasc db '000#'
notafinasc db '000#'
nota1bin dw 1 dup(?)
nota2bin dw 1 dup(?)
nota3bin dw 1 dup(?)
notamedbin dw 1 dup(?)
notafinbin dw 1 dup(?)
dados ends

;inicia o segmento de código do programa
codigo segment
    assume	ss:pilha, cs:codigo, ds:dados, es:dados

;início padrão de todo código assembly
;guardar o valor de ds na stack assim como o valor 0 (vindo de ax) também
;e seta o valor de ds e es como o valor da posição do segmento de dados
teste proc far
    push    ds
    xor     ax,ax
    push    ax
    mov     ax,dados
    mov     ds,ax
    mov     es,ax

    ;limpa a tela
    call    limpa
    ;reseta a posição do cursor
    mov     dx,0
    call    pos
    ;prepara a mensagem da primeira nota
    lea     bx,msgnt1
    lea     si,nota1asc
    mov     ch,3
    mov     cl,3

;escrita das mensagens de entrada
PrtMsgEnt:
    call    printmsg

;lê a entrada do usuário
LerEntUs:
    call    tec
    ;finaliza o programa caso ENTER seja digitado
    cmp     al,0dh
    jnz     continuar
    ret
continuar:
    ;testa se o valor digitado é numérico
    cmp     al,30h
    jl      TratErr1
    cmp     al,39h
    jg      TratErr1

    ;testa se é o primeiro dígito lido
    cmp     cl,3
    jl      GuardarDigito
    ;caso seja o primeiro dígito e não esteja entre 0 e 1, mostra uma mensagem de erro
    call    PrimeiroDigito
    cmp     dl,1
    je      PrtMsgEnt
    ;caso seja o primeiro dígito e ele seja 1, completa a nota com 100
    cmp     dh,1
    je      ProxNota

GuardarDigito:
    ;guarda o valor na memória e o escreve na tela
    mov     [si],al
    call    print

    ;incrementa o apontador para a memória das notas e decrementa o registrador de loop cl
    inc     si
    dec     cl
    ;lê dados até que a nota seja preenchida
    jnz     LerEntUs

;prepara para escrever a segunda ou terceira notas
ProxNota:
    call    quebralinha
    lea     bx,msgnt2
    lea     si,nota2asc
    mov     cl,3
    dec     ch
    cmp     ch,1
    jg      PrtMsgEnt
    lea     bx,msgnt3
    lea     si,nota3asc
    cmp     ch,0
    jne     PrtMsgEnt
    jmp     CalcularMedia

;mostra uma mensagem de erro caso o usuário digite um valor não numérico
TratErr1:
    lea     bx,msgerr1
    call    quebralinha
    ;escrita da mensagem de erro
    call    printmsg

    ;realiza novamente a quebra de linha e volta para a leitura da entrada do usuário
    ;caso o usuário erre, ele reseta o contador para que 3 dígitos sejam lidos novamente
    ;além disso, prepara o apontador para que a mensagem seja mostrada novamente
    call    quebralinha
    call    quebralinha
    mov     cl,3
    lea     bx,msgnt1
    lea     si,nota1asc
    cmp     ch,3
    je      PrtMsgEnt
    lea     bx,msgnt2
    lea     si,nota2asc
    cmp     ch,2
    je      PrtMsgEnt
    lea     bx,msgnt3
    lea     si,nota3asc
    jmp     PrtMsgEnt

CalcularMedia:
    ;converte as notas para binário
    lea     si,nota1asc
    lea     di,nota1bin
    call    asctobin3
    lea     si,nota2asc
    lea     di,nota2bin
    call    asctobin3
    lea     si,nota3asc
    lea     di,nota3bin
    call    asctobin3

    ;faz o somatório das 3 notas, divide por 3 e converte pra ASCII
    xor     ax,ax
    xor     bx,bx
    mov     ax,[nota1bin]
    mov     bx,[nota2bin]
    add     ax,bx
    mov     bx,[nota3bin]
    add     ax,bx
    xor     dx,dx
    mov     bx,3
    div     bx
    mov     [notamedbin],ax
    lea     si,notamedbin
    lea     di,notamedasc
    call    bintoasc3

    ;escrita da mensagem da média
    call    quebralinha
    lea     bx,msgmed
    call    printmsg

    ;escrita da nota média
    lea     bx,notamedasc
    call    printmsg
    call    quebralinha
    call    quebralinha

    ;faz o teste da situação do usuário
    ;caso a nota seja maior que 69, mostra a mensagem de aprovado
    mov     ax,[notamedbin]
    cmp     ax,69
    jg      Aprovado
    ;caso a nota seja menor que 40, mostra a mensagem de reprovado
    cmp     ax,40
    jl      Reprovado

    ;fora isso, mostra a nota necessária para a final
    ;prepara os registradores necessários
    xor     bx,bx
    xor     dx,dx

    ;multiplica a média por 6
    mov     bx,6
    mul     bx

    ;subtrai 500 pela média multiplicada por 6
    mov     bx,ax
    mov     ax,500
    sub     ax,bx

    ;divide essa subtração por 4
    mov     bx,4
    div     bx

    ;guarda o valor na variável
    mov     [notafinbin],ax
    ;transforma ela em ASCII
    lea     si,notafinbin
    lea     di,notafinasc
    call    bintoasc3
    ;mostra a mensagem na tela
    lea     bx,msgrec
    call    printmsg

    ;mostra a nota necessária para final
    lea     bx,notafinasc
    call    printmsg
    jmp     fim

Aprovado:
    lea     bx,msgapv
    call    printmsg
    jmp     fim

Reprovado:
    lea     bx,msgrpv
    call    printmsg
    jmp     fim

fim:
    call quebralinha
    ret
teste endp


;print de um caractere na posição atual do cursor
;parâmetros:
;ah - tem que ser 14 para essa operação funcionar direito
;al - caractere que será escrito 
;bh - página para ser escrita (o padrão parece ser 0)
;bl - cor do fundo (0 é preto)
print proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    si
    push    di
    push    ax
    push    bx
    push    cx

    ;prepara os parâmetros pra chamada correta da interrupção
    mov     bx,0
    mov     ah,14
    int     10h

    ;restaura os valores que os registradores tinham antes
    pop     cx
    pop     bx
    pop     ax
    pop     di
    pop     si
    ret
print endp


;printa uma mensagem inteira na tela
;parâmetros:
;bx - apontador para o inicio da mensagem
printmsg proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    ax
    push    bx
repetir:
    mov     al,[bx]
    cmp     al,'#'
    je      fim3
    call    print;
    inc     bx
    jmp     repetir
fim3:
    ;restaura os valores que os registradores tinham antes
    pop     bx
    pop     ax
    ret
printmsg endp


;realiza a quebra de linha
quebralinha proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    ax

    ;retorna o cursor para o início da linha
    mov     al,0dh
    call    print
    ;pula para proxima linha
    mov     al,0ah
    call    print

    ;restaura os valores que os registradores tinham antes
    pop     ax
    ret
quebralinha endp


;limpa o terminal
;parâmetros:
;ah - tem que ser 6 para essa operação funcionar direito
;al - tem que ser 0 para a tela ser limpa
;bh - cor de preenchimento (7 é branco)
;ch - linha do canto superior esquerdo
;cl - coluna do canto superior esquerdo
;dh - linha do canto inferior direito
;dl - coluna do canto inferior direito
limpa proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    ax
    push    bx
    push    cx
    push    dx

    ;prepara os parâmetros pra chamada correta da interrupção
    mov     ah,06
    xor     al,al
    mov     bh,07h
    xor     cx,cx
    mov     dh,24
    mov     dl,79
    int     10h

    ;restaura os valores que os registradores tinham antes
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
limpa endp


;mudar a posição do cursor na tela
;parâmetros:
;ah - tem que ser 2 para essa operação funcionar direito
;bh - página para onde vai o cursor (o padrão parece ser 0)
;dh - linha para onde o cursor vai
;dl - coluna para onde o cursor vai
pos proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    ax
    push    bx
    push    cx

    ;prepara os parâmetros pra chamada correta da interrupção
    xor     bx,bx
    mov     ah,2
    int     10h

    ;restaura os valores que os registradores tinham antes
    pop     cx
    pop     bx
    pop     ax
    ret
pos endp


;lê um caractere do teclado
;parâmetros:
;ah - tem que ser 0 para essa operação funcionar direito (talvez selecione qual entrada, não tenho certeza)
;al - caractere lido do teclado
tec proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    si
    push    di
    push    bx
    push    cx

    ;prepara os parâmetros pra chamada correta da interrupção
    mov     ah,0
    int     16h

    ;restaura os valores que os registradores tinham antes
    pop     cx
    pop     bx
    pop     di
    pop     si
    ret
tec endp


;transforma um número binário de 2 byte (entre 0 e 999) em 3 caracteres ASCII
;parâmetros:
;si - ponteiro para o número binário
;di - ponteiro para o início dos três espaços para o ASCII
bintoasc3 proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    si
    push    di
    push    ax
    push    bx

    ;realiza as divisões e põe cada valor em sua forma binária na posição correta
    mov     ax,[si]
    mov     bl,10
    div     bl
    mov     [di+2],ah
    xor     ah,ah
    div     bl
    mov     [di+1],ah
    mov     [di],al

    ;converte cada valor binário para sua forma em ASCII
    clc
    mov     al,[di]
    add     al,30h
    mov     [di],al
    mov     al,[di+1]
    add     al,30h
    mov     [di+1],al
    mov     al,[di+2]
    add     al,30h
    mov     [di+2],al

    ;restaura os valores que os registradores tinham antes
    pop     bx
    pop     ax
    pop     di
    pop     si
    ret
bintoasc3 endp


;transforma 3 caracteres ASCII em um número binário de 2 bytes (entre 0 e 999) 
;parâmetros:
;si - ponteiro para o início dos três caracteres ASCII
;di - ponteiro para o espaço do número binário
asctobin3 proc near
    ;guarda todos os valores dos registradores para eles não serem perdidos
    push    si
    push    di
    push    ax
    push    bx
    push    cx

    ;converte cada valor em ASCII para sua forma binária
    clc
    xor     ax,ax
    mov     al,[si+2]
    sub     ax,30h
    push    ax
    mov     al,[si+1]
    sub     ax,30h
    push    ax
    mov     al,[si]
    sub     ax,30h
    push    ax

    ;realiza as multiplicações de cada dígito com relação a suas respectivas posições e realiza suas somas
    mov     bl,10
    pop     ax
    mul     bl
    mul     bl
    mov     cx,ax
    pop     ax
    mul     bl
    add     cx,ax
    pop     ax
    add     cx,ax
    mov     [di],cx

    ;restaura os valores que os registradores tinham antes
    pop     cx
    pop     bx
    pop     ax
    pop     di
    pop     si
    ret
asctobin3 endp


;testa se as notas estao entre 0 e 100
;parâmetros:
;dl - 0 caso esteja e 1 caso não
EntreCem proc near
    ;testa se a nota esta no intervalo correto
    cmp     al,30h
    jl      TratErr2
    cmp     al,31h
    jg      TratErr2
    mov     dl,0
    jmp     fim1

;mostra uma mensagem de erro caso o usuário digite uma nota fora do intervalo 0-100
TratErr2:
    ;escrita da mensagem de erro
    call    quebralinha
    lea     bx,msgerr2
    call    printmsg

    ;realiza novamente a quebra de linha e volta para a leitura da entrada do usuário
    mov     dl,1
    call    quebralinha
    mov     cl,3
    lea     bx,msgnt1
    lea     si,nota1asc
    cmp     ch,3
    je      fim1
    lea     bx,msgnt2
    lea     si,nota2asc
    cmp     ch,2
    je      fim1
    lea     bx,msgnt3
    lea     si,nota3asc

fim1:
    ret
EntreCem endp


;sendo o primeiro digito, testa se esta entre 0 e 1 e trata isso
;parâmetros:
;dl - registrador que informa se o digito esta entre 0 e 1 (valor 0) ou não (valor 1)
;dh - registrador que informa se o digito foi especificamente 1 (valor 1) ou não (valor 0)
PrimeiroDigito proc near
    xor     dx,dx
    call    EntreCem
    cmp     dl,1
    je     fim2
    
    ;estando entre 0 e 1, testa se é 1
    cmp     al,30h
    je      fim2

    ;se for 1, completa a nota com 100
    mov     [si],al
    call    print
    mov     al,30h
    mov     [si+1],al
    call    print
    mov     [si+2],al
    call    print
    sub     cl,3
    inc     si
    mov     dh,1
fim2:
    ret
PrimeiroDigito endp

;escreve '#' cinco vezes seguida na tela
debug proc near
    push    ax
    mov     al,23h
    call    print
    call    print
    call    print
    call    print
    call    print
    pop     ax
debug endp

codigo ends
    end teste	
