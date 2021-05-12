#include "Paciente.h"
#include "Arquivo.h"
#include <string>

Arquivo arquivo_paciente("arquivo/paciente.csv");

int Paciente::listar()
{
  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

  //IMPRIMIR ARQUIVO TODO
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

Paciente::Paciente()
{
}

int Paciente::cadastrar()
{
  std::string nome, data_nascimento, sexo, cpf, obs, tel, leito;
  std::vector<std::string> auxiliar;

  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

  //OS std::cout`s ABAIXO RECUPERAM CAMPOS PRO VETOR AUXILIAR
  int id = stoi(data[data.size() - 1][0]);
  std::cout << "Digite o nome do paciente: " << std::endl;
  while (std::getline(std::cin, nome))
  {
    if (nome != "")
      break;
  }

  while(true){
    std::cout << "Digite o CPF do paciente(Somente números): " << std::endl ;
    std::cin >> cpf;

  //VERIFICA A QUANTIDADE DE DIGITOS E SE HÁ APENAS NUMEROS
    int aux=0;
    for(int i=0;cpf[i]!='\0';i++){
      if(cpf[i]<='0' || cpf[i]>='9'){
        aux=0;
        break;
      }
      aux++;
    }
    if(aux==11)
      break;
    else
      std::cout<< "CPF inválido!" << std::endl;
  }

  std::cout << "Digite a data de nascimento do paciente (dd/mm/aaaa): " << std::endl;
  std::cin >> data_nascimento;

  while(true){
    std::cout << "Digite o sexo(M/F): " << std::endl ;
    std::cin >> sexo;

    //VERIFICA SE DIGITOU M OU F
    //TODO TRANSFORMAR MIN EM MAIUSCULO
    if((sexo[0]== 'M'  || sexo[0] == 'F') && sexo[1]=='\0')
      break;
    else
      std::cout << "Sexo inválido" << std::endl;
  }

  std::cout << "Digite alguma observação sobre o paciente (opcional): " << std::endl;

  while (std::getline(std::cin, obs))
  {
    if (obs != "")
      break;
  }

  std::cout << "Digite o telefone do paciente: " << std::endl;
  std::cin >> tel;

  std::cout << "Digite o número do leito do paciente: " << std::endl;
  std::cin >> leito;

  //AUXILIAR RECEBE DADOS
  auxiliar.push_back(std::to_string(++id));
  auxiliar.push_back(nome);
  auxiliar.push_back(cpf);
  auxiliar.push_back(data_nascimento);
  auxiliar.push_back(sexo);
  auxiliar.push_back(obs);
  auxiliar.push_back(tel);
  auxiliar.push_back(leito);

  //JOGAR OS DADOS DO AUXILIAR PRA MATRIZ
  data.push_back(auxiliar);

  //ARQUIVO RECEBE A MATRIZ
  arquivo_paciente.setConteudo(data);
  return 0;
}

int Paciente::alterar(int id)
{
  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

  int campo = -1;

  std::cout << "Digite o digito do campo que você deseja alterar:" << std::endl;
  std::cout << "1 - Nome do paciente " << std::endl;
  std::cout << "2 - CPF do paciente " << std::endl;
  std::cout << "3 - Data de nascimento " << std::endl;
  std::cout << "4 - Sexo " << std::endl;
  std::cout << "5 - Observação " << std::endl;
  std::cout << "6 - Telefone " << std::endl;

  for (int i = 1; i < data.size(); i++)
  {
    //FAZ A VERIFICAÇÃO DE ID
    int id_linha = stoi(data[i][0]);

    if (id_linha == id)
    {

      
      switch (campo)
      {
      case 1:
        break;
      
      default:
        break;
      }
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

int Paciente::consultar(int id)
{
  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

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

//LISTAR UM ÚNICO CADASTRO
int Paciente::remover(int id)
{
  //JOGAR ARQUIVO NA MATRIZ
  std::vector<std::vector<std::string>> data = arquivo_paciente.getConteudo();

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

  arquivo_paciente.setConteudo(data);

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
