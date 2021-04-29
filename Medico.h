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
    //CONSTRUTOR
    Medico(std::string name, std::string cpf, std::string data, bool sexo,std::string crm, 
    std::string especialidade, bool disponibilidade);


    //METODOS HERDADOS A SEREM IMPLEMENTADOS
    virtual int cadastrar() override;
    virtual int alterar(int id) override;
    virtual int consultar(int id) override; //LISTAR UM ÚNICO CADASTRO
    virtual int remover(int id) override;


    static int  listar(); //LISTAR TODOS OS CADASTROS      


    //GETTERS AND SETERS PARA TODOS OS ATRIBUTOS
    std::string get_crm() const;
    void set_crm(std::string _crm);  

    std::string get_especialidade() const;
    void set_especialidade(std::string _especialidade);

    bool get_disponibilidade() const;
    void set_disponibilidade(bool _disponibilidade);
};
#endif
