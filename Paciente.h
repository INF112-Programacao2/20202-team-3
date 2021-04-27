#ifndef TEAM_3_PACIENTE_H
#define TEAM_3_PACIENTE_H
#include <iostream>

#include "Pessoa.h"

class Paciente : public Pessoa
{
private:
    std::string _observacao;
    std::string _telefone;
    std::string _status; //TODO tipo status
    int _leito;

public:
    Paciente(std::string _observacao, std::string _telefone, std::string _status, int _leito);
    ~Paciente();
    virtual int cadastrar(std::string name, std::string cpf, std::string data, bool sexo) override;
    virtual int alterar(int id) override;
    virtual int consultar(int id) override;
    virtual int remover(int id) override;
    static int  listar();        
};
#endif
