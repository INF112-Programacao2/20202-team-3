#include "Paciente.h"


Paciente::Paciente(std::string name, std::string cpf, std::string data, bool sexo,std::string observacao, 
std::string telefone, Status status, int leito):
  Pessoa(name, cpf, data, sexo),  _observacao(observacao), _telefone(telefone), _status(status), _leito(leito){}


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

Status Paciente::get_status(Status status){
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
