#include "Paciente.h"
#include "Arquivo.h"



int Paciente::_max_leito = 1;


int Paciente::listar() {
  Arquivo arquivo_pessoa("arquivo/paciente.csv");
  std::vector<std::vector<std::string>> data = arquivo_pessoa.getConteudo();

  for(std::vector<std::string> line : data) {
       for(std::string colum : line) {
           std::cout << colum << " ";
       } 
       std::cout << std::endl;
    }
  return 0;
}

Paciente::Paciente() {
  

  }

//   Paciente::Paciente(std::string name, std::string cpf, std::string data, bool sexo,std::string observacao, 
// std::string telefone, Status status, int leito):
//   Pessoa(name, cpf, data, sexo),  _observacao(observacao), _telefone(telefone), _status(status), _leito(leito)
//   {

//   }


std::string Paciente::get_observacao() const{
  return this->_observacao;
}

void Paciente::set_observacao(std::string observacao){
  this->_observacao = observacao;
}

std::string Paciente::get_telefone() const{
  return this->_telefone;
}

void Paciente::set_telefone(std::string telefone){
  this->_telefone = telefone;
}

Status Paciente::get_status(){
  return this->_status;  
}

void Paciente::set_status(Status status){
  this->_status = status;
}

int Paciente::get_leito() const{
  return this->_leito;
}

void Paciente::set_leito(int leito){
  this->_leito = leito;
}

int Paciente::get_max_leito() const {
  return this->_max_leito;
}

void Paciente::set_max_leito (int max_leito){
  this->_max_leito = max_leito;
}


int Paciente::cadastrar() {
  return 0;
}
int Paciente::alterar(int id) {
  return 0;

}
int Paciente::consultar(int id) {
  return 0;

} //LISTAR UM ÚNICO CADASTRO
int Paciente::remover(int id) {
  return 0;

}
