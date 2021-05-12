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
  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_medico.getConteudo();

  int campo = -1;
  std::string novo;

  std::cout << "Digite o digito do campo que você deseja alterar:" << std::endl;
  std::cout << "1 - Nome" << std::endl;
  std::cout << "2 - CPF" << std::endl;
  std::cout << "3 - Data" << std::endl;
  std::cout << "4 - Sexo" << std::endl;
  std::cout << "5 - CRM" << std::endl;
  std::cout << "6 - Especialidade" << std::endl;
  std::cout << "7 - Disponibilidade" << std::endl;

  std::cin >> campo;
  std::cout << std::endl;

  for (int i = 1; i < data.size(); i++)
  {
    //FAZ A VERIFICAÇÃO DE ID
    int id_linha = stoi(data[i][0]);

    if (id_linha == id)
    {

      
      switch (campo)
      {
      case 1:

        std::cout << "Digite o novo nome: " << std::endl;
        while(std::getline(std::cin, novo))
        {
          if(novo != "")
            break;
        }
        data[i][1] = novo;
        break;

      case 2:

        std::cout << "Digite o novo cpf: " << std::endl;
        std::cin >> novo;
        data[i][2] = novo;
        break;

      case 3:

        std::cout << "Digite a nova Data: " << std::endl;
        std::cin >> novo;
        data[i][3] = novo;
        break;

      case 4:
        
        std::cout << "Digite o novo Sexo: " << std::endl;
        std::cin >> novo;
        data[i][4] = novo;
        break;

      case 5:
        
        std::cout << "Digite o novo CRM: " << std::endl;
        std::cin >> novo;
        data[i][5] = novo;
        break;

      case 6:
        
        std::cout << "Digite a  Especialidade: " << std::endl;
        std::cin >> novo;
        data[i][6] = novo;
        break;

      case 7:
        
        std::cout << "Digite a  Disponibilidade: " << std::endl;
        std::cin >> novo;
        data[i][7] = novo;
        break;
   
      default:
        break;
      }

    }

  }
  arquivo_medico.setConteudo(data);  
  return 0; 
}

int Medico::consultar(int id) {
   //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_medico.getConteudo();

  for (int i = 1; i < data.size(); i++)
  {
    //FAZ A VERIFICAÇÃO DE ID
    int id_linha = stoi(data[i][0]);

    if (id_linha == id)
    {
      //IMPRIMIR TODAS AS COLUNAS
      for (int k = 0; k < data[0].size(); k++)
      {
        std::cout << data[0][k] << " ";
      }
      std::cout << std::endl;

      //IMPRIMIR O DADO DESEJADO
      for (int j = 0; j < data[i].size(); j++)
      {

        std::cout << data[i][j] << " ";
      }
      std::cout << std::endl;
      break;
    }

    //TODO: VERIFICAÇÃO DE ID
  }

  return 0;

  
}

int Medico::remover(int id) {
  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_medico.getConteudo();

  for (int i = 1; i < data.size(); i++)
  {
    //FAZ A VERIFICAÇÃO DE ID
    int id_linha = stoi(data[i][0]);

    if (id_linha == id)
    {

      data.erase(data.begin() + i, data.begin() + i + 1);

      std::cout << std::endl;
      break;
    }

    //TODO: VERIFICAÇÃO DE ID
  }

  arquivo_medico.setConteudo(data);

  for (std::vector<std::string> line : data)
  {
    for (std::string colum : line)
    {
      std::cout << colum << " ";
    }
    std::cout << std::endl;
  }

  return 0;
  
}
