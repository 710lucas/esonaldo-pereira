import sys
import playsound

def sla(inp):
    inp_ = inp.split(" ")
    if len(inp_)>1:
        if inp_[0] == "Birina":
            playsound.playsound("birina.mp3")
            if "vale tudo" in inp:
                playsound.playsound("vale_tudo.mp3")
            elif "vale nada" in inp:
                playsound.playsound("vale nada.mp3")

        elif inp_[0] == "Chico":
            playsound.playsound("chico.mp3")
            if "vale tudo" in inp:
                playsound.playsound("vale_tudo.mp3")
            elif "vale nada" in inp:
                playsound.playsound("vale nada.mp3")

        elif inp_[0] == "Melancia":
            playsound.playsound("Melancia.mp3")
            if "vale tudo" in inp:
                playsound.playsound("vale_tudo.mp3")
            elif "vale nada" in inp:
                playsound.playsound("vale nada.mp3")

        elif "voce quer ser tudo" in inp or "voce quer ser tudo," in inp:
            playsound.playsound("quer ser tudo.mp3")
            if inp_[4] == "Birina":
                playsound.playsound("birina.mp3")
            elif inp_[4] == "Chico":
                playsound.playsound("chico.mp3")
            elif inp_[4] == "Melancia":
                playsound.playsound("Melancia.mp3")


        if inp[0]+" "+inp[1]+" "+inp[2]+" "+inp[3]+" "+inp[4] == "e não é de nada":
            playsound.playsound("e nao é de nada.mp3")
        
        


if __name__ == "__main__":
    jooj = str(sys.argv[1])
    file = open(jooj, "r")
    linhas = file.readlines()

    # print(linhas [0])
    # print(linhas [1])
    # print(linhas [3])

    i = 0

    for line in linhas:
        if linhas == "" or linhas == " ":
            del linhas[i]
            print("sas")
        else:
            sla(linhas[i].replace("\n",''))
        i+=1

    # print(linhas)

