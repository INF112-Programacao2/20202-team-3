#include "Pessoa.h"

Pessoa::Pessoa(std::string name, std::string cpf, std::string data, bool sexo):
  _name(name), _cpf(cpf), _data(data), _sexo(sexo){}


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
