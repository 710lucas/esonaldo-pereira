import sys
import ednaldo
import globals

my_file = []
globals.init()


with open(sys.argv[1], 'r', encoding='utf-8') as my_file:
    my_file = my_file.read()
    my_file = my_file.split('\n')
    my_file = list(filter(None, my_file))

tmp_while = []

linhas = []

for i in my_file:

    linhas.append(i)

posicao = 0
posicoes_inicio_while = []
qnt_whiles = 0

while(posicao != len(linhas)):
    # print("Linha sendo lida:", posicao)
    if(globals.executar and "e não é de nada" not in linhas[posicao] and "eu não vou parar de mesclar" not in linhas[posicao]):
        ednaldo.start(linhas[posicao])

    elif(not globals.executar and "e não é de nada" in linhas[posicao]):
        globals.executar = True

    elif("eu não vou parar de mesclar" in linhas[posicao]):
        tmp_while.append(linhas[posicao])
        posicoes_inicio_while.append(posicao)
        qnt_whiles += 1
        

    if("enquanto" in linhas[posicao] and "assim continuar" in linhas[posicao]):
        if(globals.in_while and qnt_whiles > 0):
            posicao = posicoes_inicio_while[qnt_whiles-1]+1
        else:
            qnt_whiles-=1
            posicao+=1
        
    else:
        posicao+=1

print("[PROGRAMA ENCERRADO, APERTE ENTER PARA FECHAR]")
input()