#include "Paciente.h"
#include "Arquivo.h"

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
