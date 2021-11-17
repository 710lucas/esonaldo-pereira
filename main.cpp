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

int main(int argc, char** argv){
    ednaldo ed;
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
            if (inp != "" and inp != " ")
                ed.start(inp, 1);
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
    int e;
    std::cin>>e;
    return 0;
}