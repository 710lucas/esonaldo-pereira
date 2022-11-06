class Nomes:
    def __init__(self, nome):
        self.nome = nome
        self.float_val = 0
        self.string_val = ""
        self.variavel = 0
        self.tipo = "N"

nomes = [Nomes("Birina"), Nomes("Chico"), Nomes("Melancia"), Nomes("Joao"), Nomes("Beberrao"), Nomes("Ednaldo")]





def start(linha):
    if(len(linha.split()) >= 4):
        if ("is the brother" in linha or "is the sister" in linha):
            if (getNome(linha.split()[0]) == False):
                nomes.append(Nomes(linha.split()[0]))

            for i in range(len(nomes)):
                if(linha.split()[0] == nomes[i].nome):
                    if ("sister" in linha):
                        nomes[i].tipo = "S"
                    else:
                        nomes[i].tipo = "N"
                    break


    if (len(linha.split()) == 3 and "vale nada" in linha):
        try:
            getNome(linha.split()[0]).float_val = 0
        except:
            print("A variavel passada não existe: ", linha.split()[0])

    elif (len(linha.split()) == 3 and "vale tudo" in linha):
        try:
            getNome(linha.split()[0]).float_val = 1
        except:
            print("A variavel passada não existe: ", linha.split()[0])
    
    elif (len(linha.split()) == 3 and "vale" in linha and isNumber(linha.split()[2])):
        try:
            getNome(linha.split()[0]).float_val = float(linha.split()[2])
        except:
            print("A variavel passada não existe: ", linha.split()[0])

    elif(len(linha.split()) >= 2 and ("respondeu" in linha.split()[1] or "respondeu:" in linha.split()[1])):
        try:
            variavel = getNome(linha.split()[0])
            if(variavel.tipo == "N"):
                print(variavel.float_val)
            else:
                print(variavel.string_val)
            
        except:
            print("A variavel passada não existe",linha.split()[1])
    
    elif( len(linha.split()) >= 2 and ("disse" == linha.split()[1] or "disse:" == linha.split()[1])):
        variavel = getNome(linha.split()[0])
        variavel.string_val = linha.replace(linha.split()[0]+" "+linha.split()[1]+" ", "")
    
    elif (len(linha.split()) >= 2 and (linha.split()[1] in ["pergunta", "pergunta:"])):
        variavel = getNome(linha.split()[0])
        if (variavel.tipo == "N"):
            variavel.float_val = float(input(linha.replace(linha.split()[0]+" "+linha.split()[1]+" ", "")))
        else:
            variavel.string_val = input(linha.replace(linha.split()[0]+" "+linha.split()[1]+" ", ""))
    
    elif(len(linha.split()) >= 6 and "fale o que quiser com" in linha ):
        variavel1 = getNome(linha.split()[0])
        variavel2 = getNome(linha.split()[6])
        variavel1.float_val = 0
        if(variavel1.string_val == variavel2.string_val):
            variavel1.float_val = 1
    
    elif (len(linha.split()) == 8 and "vamos procurar viver em igualdade com" in linha) :
        variavel1 = getNome(linha.split()[0])
        variavel2 = getNome(linha.split()[7])
        if(variavel1.tipo == "N"):
            variavel1.string_val = variavel2.string_val
        else:
            variavel2.float_val = variavel2.float_val
    
    elif(len(linha.split()) == 8 and "what is the brother" in linha and "ou" in linha):
        variavel1 = getNome(linha.split()[0])
        variavel2 = getNome(linha.split()[5])
        variavel3 = getNome(linha.split()[7])

        variavel1.variavel = nomes.index(variavel3)
        if(variavel2.float_val>variavel3.float_val):
            variavel1.variavel = nomes.index(variavel2)
            variavel.float_val = 1
        else:
            variavel1.float_val = 0
    
    elif (len(linha.split()) == 3 and "is good" in linha):
        variavel = getNome(linha.split()[0])
        print (nomes[variavel.variavel].nome)
    
    elif (len(linha.split()) == 8 and ("é igual ao que" in linha or "é igual ao que," in linha) and "e" == linha.split()[1]):
        variavel1 = getNome(linha.split()[0])
        variavel2 = getNome(linha.split()[2])
        variavel3 = getNome(linha.split()[7])
        variavel1.float_val = variavel2.float_val + variavel3.float_val

        

def isNumber(a):
    try:
        float(a)
        return True
    except ValueError:
        return False

def getNome(nm):
    for i in nomes:
        if nm == i.nome:
            return i
    
    for i in nomes:
        if nm+"," == i.nome:
            return i
    for i in nomes:
        if nm+"?" == i.nome:
            return i
    return False
