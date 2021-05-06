#include "Pessoa.h"

unsigned int Pessoa::_next_id = 1;



Pessoa::Pessoa(std::string name, std::string cpf, std::string data, bool sexo) {
  this->_name = name;
  this->_cpf = cpf;
  this->_data = data;
  this->_sexo = sexo;
}

std::string Pessoa::get_name() const{
  return this->_name;
}

void Pessoa::set_name(std::string name){
  this->_name = name;
}

std::string Pessoa::get_cpf() const{
  return this->_cpf;
}

void Pessoa::set_cpf(std::string cpf){
  this->_cpf = cpf;
}

std::string Pessoa::get_data() const{
  return this->_data;
}

void Pessoa::set_data(std::string data){
  this->_data = data;
}

bool Pessoa::get_sexo() const{
  return this->_sexo;
}

void Pessoa::set_sexo(bool sexo){
  this->_sexo = sexo;
}

unsigned int Pessoa::get_id() const{
  return this->_id;
}

void Pessoa::set_id(unsigned int id){
  this->_id = id;
}

int Pessoa::get_next_id() const{
  return this->_next_id;
}

void Pessoa::set_next_id(int next_id){
  _next_id = next_id;  
}


int Pessoa::listar()
{
   return 0;  
}
