#include <iostream>
#include <fstream>
#include "esonaldo.h"

// https://esolangs.org/wiki/Introduction_to_esolang_design util


// Compiler

// Ednaldo         -> 
// Pereira         volta pro 0
// Chico           +
// Melancia        -
// EdnaldoPereira  print
// ValeTudo
// ValeNada

std::vector<std::string> while_lines;

void ed_while(std::string inp);
ednaldo ed;
std::vector<std::string> pals;

int main(int argc, char** argv){
    
    bool file = false;
    int filepos = 0;
    

    if (argc>1){
        file = true;
        filepos = 1;
    }

    if(file){
        std::ifstream f;
        f.open(argv[filepos]);
        std::string inp;
        while(std::getline(f, inp)){
            if (inp != "" and inp != " "){
                pals = ed.separar_pals(inp);
                if (!ed.in_while and !ed.started_a_while) //enquanto nada do while estiver ativo
                    ed.start(inp, 1);

                //enquanto o while tiver iniciado, mas o programa ainda n esteja rodando o seu codigo
                else if(ed.started_a_while and !ed.in_while){
                    // ed.start(inp, 1, true);
                    std::string inp_ = inp;
                    // std::cout<<inp_<<"==\n";
                    while_lines.push_back(inp_);
                    // std::cout<<while_lines[while_lines.size()-1]<<"-=-=\n";
                    
                    if(pals[0]+pals[2]+pals[3] == "enquantoassimcontinuar"){
                        ed.started_a_while = false;
                        // std::cout<<"lellele\n";
                        ed.start(inp, 1);
                        if(ed.in_while){
                            ed_while(inp);
                        }
                        
                    }
                }

                // //momento que o programa acha o enquanto assim continuar
                // else if(ed.started_a_while and !ed.in_while and pals[0]+pals[2]+pals[3] == "enquantoassimcontinuar"){
                //     std::cout<<"lel:)";
                //     if(pals[0]+pals[2]+pals[3] == "enquantoassimcontinuar"){
                //         std::cout<<"lel:)";
                //     }
                //     ed.start(inp, 1, true); //usa isso para verificar a pal[1] para nao ter que verificar novamente  se pals[0]+pals[2]...
                    
                //     // std::cout<<pals[0]+pals[2]+pals[3]<<"\n";

                //     std::cout<<"final\n";
                //     std::cout<<inp<<"\n";
                    
                // }

                //depois que o while iniciou e o programa começou a rodar seu codigo
                

                

            }
                // std::cout<<inp<<"\n";
        }
    }
    
    else{
        while(true){
            std::string inp;
            std::getline(std::cin, inp);
            
            ed.start(inp, 0);
        }
    }

    //std::cout<<"\nFim\n";
    std::cout<<"\n\n [ FIM DO PROGRAMA, APERTE CTRL+C PARA FECHAR O PROGRAMA ]\n";
    int e;
    std::cin>>e;
    return 0;
}

void ed_while(std::string inp){
    while(ed.in_while){
        for(int i = 0; i<while_lines.size(); i++){
            // std::cout<<inp<<"====\n";
            ed.start(while_lines[i], 1);
            
        }
    }
}