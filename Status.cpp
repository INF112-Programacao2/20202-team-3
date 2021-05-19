#include "Status.h"
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include "Arquivo.h"


Arquivo arquivo_status("arquivo/status.csv");
Arquivo arquivo_dados("arquivo/dados.csv");
Arquivo arquivo_paciente_status("arquivo/dados.csv");


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

static std::vector<std::string> split(const std::string& str, char delim){
   auto i = 0;
   std::vector<std::string> list; 
   auto pos = str.find(delim);
   while (pos != std::string::npos){
      list.push_back(str.substr(i, pos - i));
      i = ++pos;
      pos = str.find(delim, pos);
   }
   list.push_back(str.substr(i, str.length()));
   return list;
}

bool isInList(std::vector<std::string> list, std::string id_paciente) {
    bool exist = false;
    for(std::string id : list) {
        if(id == id_paciente) {
            exist = true;
        }
    }

    return exist;
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
    data_status_problemas.push_back("-1");
    for(int i=1; i<data_status.size(); i++){
        if(!isInList(data_status_problemas, data_status[i][0])) {
            if(std::stoi(data_status[i][1])<89)
                data_status_problemas.push_back(data_status[i][0]);
        }

        if(!isInList(data_status_problemas, data_status[i][0])) {
            if(std::stoi(data_status[i][2])<50 || std::stoi(data_status[i][2])>90)
                data_status_problemas.push_back(data_status[i][0]);
        }

        if(!isInList(data_status_problemas, data_status[i][0])) {
            if(std::stoi(data_status[i][3])<15 || std::stoi(data_status[i][3])>22)
                data_status_problemas.push_back(data_status[i][0]);
        }

        if(!isInList(data_status_problemas, data_status[i][0])) {
            std::vector<std::string> pressao = split(data_status[i][4], '/');

            std::cout << pressao[0] << " " << pressao[1] << std::endl;


            if((std::stoi(pressao[0]) < 9 && std::stoi(pressao[1]) < 6) 
            || (std::stoi(pressao[0]) > 18 && std::stoi(pressao[1]) > 11)) {
                data_status_problemas.push_back(data_status[i][0]);
            }  
        }
    }
    
    for (std::string id : data_status_problemas)
        if(id != "-1") {
            std::cout << id << std::endl;
        }
    return 0;
}

