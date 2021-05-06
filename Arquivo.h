#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>

#include <vector>
#include <fstream>
#include "arquivo/rapidcsv.h"



class Arquivo
{
private:
    rapidcsv::Document arquivo;
public:
    //CONSTRUTOR
    Arquivo(std::string dirArquivo);
    std::vector<std::vector<std::string>> getConteudo();
    
    

};
#endif
