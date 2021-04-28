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
    Medico(std::string name, std::string cpf, std::string data, bool sexo,std::string crm, 
    std::string especialidade, bool disponibilidade);

    virtual int cadastrar() override;
    virtual int alterar(int id) override;
    virtual int consultar(int id) override;
    virtual int remover(int id) override;
    static int  listar();      


    std::string get_crm() const;
    void set_crm(std::string _crm);  

    std::string get_especialidade() const;
    void set_especialidade(std::string _especialidade);

    bool get_disponibilidade() const;
    void set_disponibilidade(bool _disponibilidade);
};
#endif
