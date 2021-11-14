#include "esonaldo.h"

void ednaldo::start(std::string inputln){
    std::vector<std::string> pals;
    // std::getline(std::cin, inputln);

    pals = separar_pals(inputln+' ');

    //importante lembrar que is_name também é
    //a posição da variavel sendo usada
    int is_name = get_arr_pos(pals[0]);

    //Caso a primeira palavraseja um nome 
    //(ou seja, variavel)

    if (is_name != -1 and cond_bool){
        //print str
        if(pals[1] == "respondeu"){
            std::cout<<nomes_str[is_name]<<"\n";
        }

        // =  string
        else if(pals[1] == "disse:"){
            std::string tmp;
            for(int i = 2; i<pals.size(); i++){
                tmp+=pals[i]+" ";
            }
            nomes_str[is_name] = tmp;

        }

        else if(pals[1] + " "+ pals[2] == "vale nada"){
            nomes_val[is_name] = 0;
        }

        else if(pals[1] + " "+ pals[2] == "vale tudo"){
            nomes_val[is_name] = 1;
        }

        else if(pals[1] == "vale" and pals[2]!="nada" and pals[2]!="tudo"){
            nomes_val[is_name] = std::stoi(pals[2]);
        }

        else if(pals[1]+" "+pals[2] == "is good"){
            std::cout<<nomes[nomes_val[is_name]]<<"\n";
        }

        //print
        else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4] == "fale o que quiser"){
            std::cout<<nomes_val[is_name]<<"\n";
        }

        //igualdade
        else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4]+" "+pals[5]+" "+pals[6] == "vamos procurar viver em igualdade com"){            
            int is_name_ = get_arr_pos(pals[7]);
            if (is_name_ != -1){
                nomes_val[is_name] = nomes_val[is_name_];
            }
        }
        
        //maior
        else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4] == "what is the broder" and pals[6]=="ou"){
            int is, is_;
            is = get_arr_pos(pals[5]);
            is_ = get_arr_pos(pals[7]);
            if(is != -1 and is_ != -1){
                if(nomes_val[is]>nomes_val[is_])
                    nomes_val[is_name] = is;
                else 
                    nomes_val[is_name] = is_;
            }
        }

        else{
            std::cout<<"Comando invalido\nLinha:\n"<<inputln;
        }

    }

    else if (cond_bool and is_name == -1){
        if(pals[1]+" "+pals[2]+" "+pals[3] == "is the broder"){
            nomes.push_back(pals[0]);
            nomes_val.push_back(0);
            nomes_str.push_back("0");
        }

        


        else if(pals[0]+ " "+pals[1]+ " "+pals[2]+ " "+pals[3]+ " "+pals[4] == "e não é de nada"){
            cond_bool = true;
        }

        //if
        else if(pals[0]+" "+pals[1]+" "+pals[2]+" "+pals[3] == "voce quer ser tudo," or pals[0]+" "+pals[1]+" "+pals[2]+" "+pals[3] == "voce quer ser tudo"){
            int is_name_ = get_arr_pos(pals[4]);
            if (is_name_ != -1){
                if(nomes_val[is_name_] <= 0){
                    cond_bool = false;
                }
                /*
                    Quando perceber que estiver em um if
                    e o if não for aceito, é necessário
                    que se tenha uma maneira de não executar 
                    nenhum codigo ate que se atinja o fim
                    do if
                */
            }
            else{
                cond_bool = true;
            }
        }

      

        else{
            std::cout<<"Nome não valido\nLinha:\n"<<inputln;
        }
    }

    else if(!cond_bool and pals[0]+ " "+pals[1]+ " "+pals[2]+ " "+pals[3]+ " "+pals[4] == "e não é de nada"){
        cond_bool =  true;
    }
    
    // std::cout<<pals[0]<<"\n"<<pals[1]<<"\n"<<pals[2]<<"\n";

    // std::cout<<inputln<<"\n";
}

int ednaldo::get_arr_pos(std::string inp){
    for(int i = 0; i<nomes.size(); i++){
        if(inp == nomes[i] or inp == nomes[i]+"," or inp == nomes[i]+"?")
            return i; //retorna posição da array
    }
    return -1; //retorna -1 pois não existe
    //criar mensagem de erro
}

std::vector<std::string> ednaldo::separar_pals(std::string inp){
    std::string temp;
    std::vector<std::string> out;
    for(int i = 0; i<inp.length(); i++){   
        if(inp[i] != ' '){
            temp += inp[i];
        }
        else if(inp[i] == ' '){
            out.push_back(temp);
            temp = "";
        }
    }
    return out;
}