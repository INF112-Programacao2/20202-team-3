#include "Medico.h"
#include "Arquivo.h"

Arquivo arquivo_medico("arquivo/medico.csv");

int Medico::listar() {
  std::vector<std::vector<std::string>> data = arquivo_medico.getConteudo();

  for(std::vector<std::string> line : data) {
       for(std::string colum : line) {
           std::cout << colum << " ";
       } 
       std::cout << std::endl;
    }
  return 0;
}

Medico::Medico()
{

} 

int Medico::cadastrar() 
{
  std::string nome,cpf,data_nascimento,sexo,crm,esp,disp;
  std::vector<std::string> auxiliar;

  Arquivo arquivo_medico("arquivo/medico.csv");
  std::vector<std::vector<std::string>> data = arquivo_medico.getConteudo();

  int id = stoi(data[data.size()-1][0]);
  std::cout << "Digite o nome do médico: " << std::endl ;
  while(std::getline(std::cin, nome)){
    if(nome != "")
      break;
  }

  std::cout << "Digite o CPF do médico: " << std::endl ;
  std::cin >> cpf;

  std::cout << "Digite a data de nascimento do médico (dd/mm/aaaa): "  << std::endl ;
  std::cin >> data_nascimento;

  std::cout << "Digite o sexo(M/F): " << std::endl ;
  std::cin >> sexo;

  std::cout << "Digite o crm do médico: " << std::endl ;
  std::cin >> crm;

  std::cout << "Digite a especialidade do médico: " << std::endl ;
  while(std::getline(std::cin, esp)){
    if(esp != "")
      break;
  }
  std::cout << "O médico está disponível(S/N): " << std::endl ;
  std::cin >> disp;

  auxiliar.push_back(std::to_string(++id));
  auxiliar.push_back(nome);
  auxiliar.push_back(cpf);
  auxiliar.push_back(data_nascimento);
  auxiliar.push_back(sexo);
  auxiliar.push_back(crm);
  auxiliar.push_back(esp);
  auxiliar.push_back(disp);
  
  data.push_back(auxiliar);

  arquivo_medico.setConteudo(data);  
  return 0;
}


int Medico::alterar(int id) {
  return 0;

  
}
int Medico::consultar(int id) {
    return 0;

  
} //LISTAR UM ÚNICO CADASTRO
int Medico::remover(int id) {
    return 0;
  
}
