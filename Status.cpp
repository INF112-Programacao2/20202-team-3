#include "Status.h"
#include <chrono>
#include <random>
#include <string>
#include <vector>


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

int Status::gerar_status(){
    /*Saturação -> 89
     BPM -> (bradicardia)<50 a 90<(taquicardia)std::vector<std::string>
     Frequência Cardíaca -> 15 a 22
     Pressão -> 9/6 a 18/11
    */
    
    std::vector<std::vector<std::string>> data_status = arquivo_status.getConteudo();
    std::vector<std::string> data_status_problemas;
    for(int i=1; i<data_status.size(); i++){
        if(std::stoi(data_status[i][1])<89){
            data_status_problemas.push_back(data_status[i][0]);
        }
        if(data_status_problemas[i-1]!=data_status[i][0]) {
            if(std::stoi(data_status[i][2])<50 || std::stoi(data_status[i][2])>90)
                data_status_problemas.push_back(data_status[i][0]);
        }
        if(data_status_problemas[i-1]!=data_status[i][0]) {
            if(std::stoi(data_status[i][3])<15 || std::stoi(data_status[i][3])>22)
                data_status_problemas.push_back(data_status[i][0]);
        }
        /*if(data_status_problemas[i-1]!=data_status[i][0]) {
            if(std::stoi(data_status[i][2])<50)          //TODO: checar pressão
                data_status_problemas.push_back(data_status[i][0]);
        }*/ 
    }
    data_status.clear();
    data_status_problemas.clear();
   return 0;


}