#include "Medico.h"




Medico::Medico(std::string name, std::string cpf, std::string data,
bool sexo, std::string crm, std::string especialidade, bool disponibilidade):
    Pessoa(name, cpf,  data, sexo), _crm(crm), _especialidade(especialidade), _disponibilidade(disponibilidade){} 


std::string Medico::get_crm() const{
  return this->_crm;
}

void Medico::set_crm(std::string crm){
  this->_crm = crm;
}

std::string Medico::get_especialidade() const{
  return this->_especialidade;
}

void Medico::set_especialidade(std::string especialidade){
  this->_especialidade = especialidade;
}

bool Medico::get_disponibilidade() const{
  return this->_disponibilidade;
}

void Medico::set_disponibilidade(bool disponibilidade){
  this->_disponibilidade = disponibilidade;
}
