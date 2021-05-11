#include "Paciente.h"
#include "Arquivo.h"
#include <string>
#include <sys/types.h>

int Paciente::listar() 
{
  Arquivo arquivo_paciente("arquivo/paciente.csv");
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

  for(std::vector<std::string> line : data) {
       for(std::string colum : line) {
           std::cout << colum << " ";
       } 
       std::cout << std::endl;
    }
  return 0;
}

Paciente::Paciente()
{

}

int Paciente::cadastrar() 
{
  std::string nome,data_nascimento,sexo,cpf,obs,tel,leito;
  std::vector<std::string> auxiliar;

  Arquivo arquivo_paciente("arquivo/paciente.csv");
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

  int id = stoi(data[data.size()-1][0]);
  std::cout << "Digite o nome do paciente: " << std::endl ;
  while(std::getline(std::cin, nome)){
    if(nome != "")
      break;
  }

  std::cout << "Digite o CPF do paciente: " << std::endl ;
  std::cin >> cpf;

  std::cout << "Digite a data de nascimento do paciente (dd/mm/aaaa): "  << std::endl ;
  std::cin >> data_nascimento;

  std::cout << "Digite o sexo(M/F): " << std::endl ;
  std::cin >> sexo;

  std::cout << "Digite alguma observação sobre o paciente(opcional): " << std::endl ;
  
  while(std::getline(std::cin, obs)){
    if(obs != "")
      break;
  }

  std::cout << "Digite o telefone do paciente: " << std::endl ;
  std::cin >> tel;

  std::cout << "Digite o número do leito do paciente: " << std::endl ;
  std::cin >> leito;

  auxiliar.push_back(std::to_string(++id));
  auxiliar.push_back(nome);
  auxiliar.push_back(data_nascimento);
  auxiliar.push_back(sexo);
  auxiliar.push_back(cpf);
  auxiliar.push_back(obs);
  auxiliar.push_back(tel);
  auxiliar.push_back(leito);
  
  data.push_back(auxiliar);

  arquivo_paciente.setConteudo(data);  
  return 0;
}

int Paciente::alterar(int id) 
{
  return 0;
}

int Paciente::consultar(int id) 
{
  return 0;
} 

//LISTAR UM ÚNICO CADASTRO
int Paciente::remover(int id) 
{
  return 0;
}
