#include "Medico.h"
#include "Arquivo.h"


int Medico::listar() {
  Arquivo arquivo_medico("arquivo/medico.csv");
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

int Medico::cadastrar() {
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
