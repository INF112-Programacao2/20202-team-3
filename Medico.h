#ifndef TEAM_3_MEDICO_H
#define TEAM_3_MEDICO_H
#include <iostream>

#include "Pessoa.h"

class Medico : public Pessoa
{
private:
    std::string _crm;
    std::string _especialidade;
    bool _disponibilidade;

public:
    Medico(std::string crm, std::string especialidade, bool disponibilidade);
    ~Medico();
    virtual int cadastrar(std::string name, std::string cpf, std::string data, bool sexo) override;
    virtual int alterar(int id) override;
    virtual int consultar(int id) override;
    virtual int remover(int id) override;
    static int  listar();        
};
#endif
