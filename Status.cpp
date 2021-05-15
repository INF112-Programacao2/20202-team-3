#include "Status.h"
#include "Arquivo.h"
#include <cstdlib>


Arquivo arquivo_status("arquivo/status.csv");
Arquivo arquivo_dados("arquivo/dados.csv");

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
    
    for(int i=1, rand_status; i<data_status.size(); i++)    
    {   

        std::srand(time(NULL));
        rand_status = std::rand() % data_dados.size();
        for(int j=0; data_status[i].size(); j++)
        {
            data_status[i][j] = data_dados[rand_status][j];
        }
    }
    return 0;
}
