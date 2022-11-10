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

for i in my_file:
    if(globals.executar and not globals.started_while):
        ednaldo.start(i)
    elif(not globals.executar and "e não é de nada" in i):
        globals.executar = True

    elif(globals.started_while and  "enquanto" not in i and not "assim continuar" in i and not globals.in_while):
        tmp_while.append(i)

    elif(globals.started_while and "enquanto" in i and "assim continuar" in i and not globals.in_while):
        tmp_while.append(i)
        ednaldo.start(i)
        while(globals.in_while):
            for x in tmp_while:
                if(globals.executar):
                    ednaldo.start(x)
                elif(not globals.executar and "e não é de nada" in x):
                    globals.executar = True

input()