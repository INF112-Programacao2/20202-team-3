#include "Status.h"
#include <chrono>
#include <random>


Arquivo arquivo_status("arquivo/status.csv");
Arquivo arquivo_dados("arquivo/dados.csv");

/*
    a funcao atualiza de acordo com o CLOOOOOOOOOOOCK
*/ 
static unsigned int randomgen()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,100);
    int rndnum = dis(gen);
    return (unsigned int) rndnum;
}

int Status::cadastrar(std::string id)
{
    std::vector <std::string> status;
    std::vector<std::vector<std::string>> data_status = arquivo_status.getConteudo();
    status.push_back(id);
    data_status.push_back(status);
    arquivo_status.setConteudo(data_status);
    return 0;
}

int Status::atualizar()
{
    std::vector<std::vector<std::string>> data_status = arquivo_status.getConteudo();
    std::vector<std::vector<std::string>> data_dados = arquivo_dados.getConteudo();
    
    for(int i=1; i<data_status.size(); i++)    
    {   
        std::srand(randomgen());
        int rand_status = std::rand() % data_dados.size()+1;
        for(int j=1; j < data_status[i].size(); j++)
        {
            rand_status = std::rand() % data_dados.size()+1;

            data_status[i][j] = data_dados[rand_status-1][j-1];

        }
    }
    arquivo_status.setConteudo(data_status);
    return 0;
}
