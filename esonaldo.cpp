#include "esonaldo.h"

bool isNumber(const std::string& str);

void ednaldo::start(std::string inputln, int file){

    std::vector<std::string> pals;
    // std::getline(std::cin, inputln);
    

    pals = separar_pals(inputln);
    

    // std::cout<<"amogus";


    //importante lembrar que is_name também é
    //a posição da variavel sendo usada
    int is_name = 0;
    if(pals.size()>=4){
        if(pals[0] + pals[2] + pals[3] == "enquantoassimcontinuar"){
            is_name = -2;
            
        }
        else
            is_name = get_arr_pos(pals[0]);
    }
    
    else{
        is_name = get_arr_pos(pals[0]);
        
    }


    //Caso a primeira palavra seja um nome 
    //(ou seja, variavel)

    if (is_name > -1 and cond_bool){
        //print str
        if(pals[1] == "respondeu"){

            if(nomes_tip[is_name] == "N"){
                std::cout<<nomes_val[is_name];
                std::cout<<"\n";
            }
            else if(nomes_tip[is_name] == "S")
                std::cout<<nomes_str[is_name];
            
            //acho que significa que, caso o programa
            //esteja rodando a partir de um arquivo,
            // é necessário que se tenha um \n no final
            // if (file == 0)
            //     std::cout<<"\n";
        }


        // =  string
        else if(pals[1] == "disse:" or pals[1] == "disse"){

            std::string tmp;

            // começa a armazenar o que vem depois da 
            // terceira palavra na variavel
            // ex: Birina disse: jogo da velha
            //      [0]    [1]    [2] [3] [4]
            for(int i = 2; i<pals.size(); i++){
                if(i < pals.size()-1)
                    tmp+=pals[i]+" "; //adiciona um espaço entre as palavras
                else
                    tmp+=pals[i];
            }

            //adiciona a possibilidade de adicionar \n às
            //strings
            for(int i = 0; i<tmp.length(); i++){
                    if(tmp[i] == '\\' and tmp[i+1] == 'n'){
                        // std::cout<<"lol";
                        tmp[i] = '\0';
                        tmp[i+1] = '\n';
                    }
            }

            //armazena a string informada na variavel
            nomes_str[is_name] = tmp;

        }

        //adiciona o valor 0 à variavel
        else if(pals[1] + " "+ pals[2] == "vale nada"){
            nomes_val[is_name] = 0;
        }

        //adiciona o valor 1 à variavel
        else if(pals[1] + " "+ pals[2] == "vale tudo"){
            nomes_val[is_name] = 1;
        }

        //adiciona o valor numerico informado á variavel
        else if(pals[1] == "vale" and pals[2]!="nada" and pals[2]!="tudo"){
            nomes_val[is_name] = std::stoi(pals[2]);
        }

        //printa o nome da variavel que estiver armazenado dentro da variavel
        //especificada
        else if(pals[1]+" "+pals[2] == "is good"){
            std::cout<<nomes[nomes_var[is_name]]<<"\n";
        }

        //Input
        /*
            Ideia que veio na minha cabeça aqui
            Fazer um switch onde uma variavel muda o tipo
            por exemplo:
            Birina numeros
            Birina respondeu (birina responde o que tiver
            armazenado na array de valores numericos)
            Birina palavras
            Birina respondeu (birina responde o que estiver
            armazenado na array de strings )

            Util para diminuir a quantidade de comandos
            (e tambem para não ter dois prints diferentes e
            nem dois modos diferentes de se declarar uma
            variavel)
        */
       // #interessante lucas do passado, muito  interessante...

       //input
        else if(pals[1] == "pergunta" or pals[1] == "pergunta," or pals[1] == "pergunta:"){
            std::string tmp;

            for(int i = 2; i<pals.size(); i++){
                tmp+=pals[i]+" ";
            }

            if(nomes_tip[is_name] == "S"){
                std::cout<<tmp<<": ";
                std::string tmp_;
                std::getline(std::cin, tmp_);
                nomes_str[is_name] = tmp_;
            }

            //precisa verificar se o input é um numero
            else if(nomes_tip[is_name] == "N"){
                std::cout<<tmp<<": ";
                std::string tmp_;
                std::getline(std::cin, tmp_);
                if (isNumber(tmp_)){
                    // std::cout<<"valor informado é um numero \n";
                    nomes_val[is_name] = std::stoi(tmp_);
                }
                else
                    std::cout<<"O valor informado não é um numero\n";
            }
        }

        //Muda o tipo de variavel caso ja exista
        else if(pals[1]+" "+pals[2]+" "+pals[3] == "is the brother"){
            int tmp_ = get_arr_pos(pals[0]);
            nomes_tip[tmp_] = "N";
        }

        else if(pals[1]+" "+pals[2]+" "+pals[3] == "is the sister"){
            // std::cout<<"Is siter que ja existe\n";
            int tmp_ = get_arr_pos(pals[0]);
            nomes_tip[tmp_] = "S";
        }

        //print defasado (util talvez no futuro)
        // else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4] == "fale o que quiser"){
        //     std::cout<<nomes_val[is_name]<<"\n";
        // }
        
        //maior
        else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4] == "what is the brother" and pals[6]=="ou"){
            int is, is_;
            is = get_arr_pos(pals[5]);
            is_ = get_arr_pos(pals[7]);
            if(is != -1 and is_ != -1){
                if(nomes_val[is]>nomes_val[is_]){
                    nomes_val[is_name] = 1;
                    nomes_var[is_name] = is;
                }
                else {
                    nomes_var[is_name] = is_;
                    nomes_val[is_name] = 0;
                }
            }
        }

        //menor
        else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4] == "who is the sister" and pals[6]=="ou"){
            int is, is_;
            is = get_arr_pos(pals[5]);
            is_ = get_arr_pos(pals[7]);
            if(is != -1 and is_ != -1){
                if(nomes_val[is]<nomes_val[is_])
                    nomes_val[is_name] = is;
                else 
                    nomes_val[is_name] = is_;
            }
        }
        
        //igualdade
        else if(pals[1]+" "+pals[2]+" "+pals[3]+" "+pals[4]+" "+pals[5]+" "+pals[6] == "vamos procurar viver em igualdade com"){            
            int is_name_ = get_arr_pos(pals[7]);
            if (is_name_ != -1){
                nomes_val[is_name] = nomes_val[is_name_];
            }
        }
        //=========================
        //        Matematica      =
        //=========================

        //Soma
        //soma pals[1] com pals[2] e armazena em pals[7]
        //fazer com que sintaxe seja mais flexivel
        else if(pals[1] == "e" and pals[3]+" "+pals[4]+" "+pals[5]+" "+pals[6] == "é igual ao que,"){
            // std::cout<<"Lol";    
            int tmp1, tmp2, tmp3;
            tmp1 = nomes_val[is_name];
            tmp2 = nomes_val[get_arr_pos(pals[2])];

            tmp3 = tmp1+tmp2;

            nomes_val[get_arr_pos(pals[7])] = tmp3;
            
        }

        //Subtração
        // faz pals[2] - pals[4] e armazena
        // em pals[0]
        else if(pals[1] == "entre" and pals[3] == "e" and pals[5]+" "+pals[6]+" "+pals[7]+" "+pals[8] == "qual é a diferença?"){
            int tmp1, tmp2, tmp3;
            tmp2 = nomes_val[get_arr_pos(pals[2])];
            tmp3 = nomes_val[get_arr_pos(pals[4])];

            tmp1 = tmp2 - tmp3;

            nomes_val[is_name] = tmp1;
        }

        
        else{
            std::cout<<"Comando invalido\nLinha: "<<inputln<<"\ne";
        }

    }
    /*
        Fim do if de comandos que iniciam com variaveis
    */

    else if (cond_bool and is_name == -1){
        
        //Cria nova variavel NUMERICA caso não exista
        if(pals[1]+" "+pals[2]+" "+pals[3] == "is the brother"){
            nomes.push_back(pals[0]);
            nomes_val.push_back(0);
            nomes_str.push_back("0");
            nomes_tip.push_back("N");
        }
        
        else if(pals[1]+" "+pals[2]+" "+pals[3] == "is the sister"){
            // std::cout<<"Is sister que não existe\n";
            nomes.push_back(pals[0]);
            nomes_val.push_back(0);
            nomes_str.push_back("0");
            nomes_tip.push_back("S");
        }

        else if(pals[0]+ " "+pals[1]+ " "+pals[2]+ " "+pals[3]+ " "+pals[4] == "e não é de nada"){
            cond_bool = true;
        }

        else if(pals[0]+pals[1]+pals[2]+pals[3]+pals[4]+pals[5] == "eunaovouparardemesclar" or pals[0]+pals[1]+pals[2]+pals[3]+pals[4]+pals[5] == "eunãovouparardemesclar"){
            // std::cout<<"reconheceu\n";
            started_a_while = true; // IMPORTANTE, falar que acabou o while
        }
        
        // else if(pals[0] == "enquanto"){
        //     std::cout<<"leeeel\n";
            
        //     int is_name_ = get_arr_pos(pals[1]);
        //     if (is_name_ != -1 and nomes_val[is_name_] == 1)
        //         in_while = true;

        //     else
        //         in_while = false;
        // }

        // if
        /*
            O if é apenas considerado verdadeiro se for igual a 1
        */
        else if(pals[0]+" "+pals[1]+" "+pals[2]+" "+pals[3] == "voce quer ser tudo," or pals[0]+" "+pals[1]+" "+pals[2]+" "+pals[3] == "voce quer ser tudo"){
            int is_name_ = get_arr_pos(pals[4]);
            if (is_name_ != -1){
                if(nomes_val[is_name_] != 1){
                    cond_bool = false;
                }
                /*
                    Quando perceber que estiver em um if
                    e o if não for aceito, é necessário
                    que se tenha uma maneira de não executar 
                    nenhum codigo ate que se atinja o fim
                    do if

                    [Ja foi feito]
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

    //While
    else if(cond_bool and is_name == -2){
        // std::cout<<"leeeel\n";
        started_a_while = false;
        int is_name_ = get_arr_pos(pals[1]);
        // std::cout<<nomes_val[is_name_];
            if (is_name_ > -1 and nomes_val[is_name_] == 1)
                in_while = true;

            else
                in_while = false;
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
    if (inp == "enquanto")
        return -10;
    return -1; //retorna -1 pois não existe
    //criar mensagem de erro
}

std::vector<std::string> ednaldo::separar_pals(std::string inp){
    std::string temp;
    std::vector<std::string> out;
    inp = inp+' ';
    for(int i = 0; i<inp.length(); i++){   
        if(inp[i] != ' '){
            temp += inp[i];
        }
        else if(inp[i] == ' '){
            out.push_back(temp);
            temp = "";
        }
        // std::cout<<temp<<"==\n";
    }
    return out;
}


bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
