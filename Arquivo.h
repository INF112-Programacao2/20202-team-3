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
    
    

};
#endif
