#ifndef TEAM_3_STATUS_H
#define TEAM_3_STATUS_H
#include <iostream>
#include "Arquivo.h"
#include <time.h>
#include <chrono>
#include <cstdlib>

class Status
{
private:
public:
    
    int cadastrar(std::string id);
    int gerar_status();

    //ATUALIZAR DADOS NO ARQUIVO ESPECÍFICO 
    static int atualizar();
};
#endif
