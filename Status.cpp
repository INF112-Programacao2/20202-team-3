#include "Status.h"


Status::Status(int id_pessoa, int _saturacao, int _bpm, int _freq, std::string pressao)
{
	

}

int Status::get_id_pessoa() const{
  return this->_id_pessoa;
}

int Status::set_id_pessoa(int id_pessoa){
  return this->_id_pessoa = id_pessoa;
}

int Status::get_saturacao() const{
  return this->_saturacao;
}

void Status::set_saturacao(int saturacao){
  this->_saturacao = saturacao;
}

int Status::get_bpm() const{
  return this->_bpm;
}

void Status::set_bpm(int bpm){
  this->_bpm = bpm;
}

int Status::get_freq() const{
  return this->_freq;
}

void Status::set_freq(int freq){
  this->_freq = freq;
}

std::string Status::get_pressao() const{
  return this->_pressao;
}

void Status::set_pressao(std::string pressao){
  this->_pressao = pressao;
}
