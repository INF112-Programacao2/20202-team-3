#ifndef TEAM_3_PACIENTE_H
#define TEAM_3_PACIENTE_H
#include <iostream>
#include "Status.h"
#include "Pessoa.h"

class Paciente : public Pessoa
{
private:
    std::string _observacao;
    std::string _telefone;
    Status _status; 
    int _leito;

public:
    Paciente(std::string name, std::string cpf, std::string data, bool sexo,std::string observacao, 
    std::string telefone, Status status, int leito);

    virtual int cadastrar() override;
    virtual int alterar(int id) override;
    virtual int consultar(int id) override;
    virtual int remover(int id) override;
    static int  listar(); 

    std::string get_observacao() const;
    void set_observacao(std::string _observacao);  

    std::string get_telefone() const;
    void set_telefone(std::string _telefone);

    int get_leito() const;
    void set_leito(int _leito);

    Status get_status(Status status);
    void set_status(Status status);     
};
#endif
