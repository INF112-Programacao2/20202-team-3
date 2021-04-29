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
    
    //METODO RESPONSAVEL POR ATRIBUIR DADOS PARA O PACIENTE
    Status _status;

    //ATRIBUTO PARA FAZER O CONTROLE DA DISPONIBILIDADE DE LEITOS 
    int _leito;

    //DEFINE CAPACIDADE TOTAL DO HOSPITAL
    static int _max_leito;

public:

    //CONSTRUTOR
    Paciente(std::string name, std::string cpf, std::string data, bool sexo,std::string observacao, 
    std::string telefone, Status status, int leito);

    //METODOS HERDADOS A SEREM IMPLEMENTADOS
    virtual int cadastrar() override;
    virtual int alterar(int id) override;
    virtual int consultar(int id) override; //LISTAR UM ÚNICO CADASTRO
    virtual int remover(int id) override;


    static int  listar(); //LISTAR TODOS OS CADASTROS


    //GETTERS AND SETERS PARA TODOS OS ATRIBUTOS
    std::string get_observacao() const;
    void set_observacao(std::string _observacao);  

    std::string get_telefone() const;
    void set_telefone(std::string _telefone);

    int get_leito() const;
    void set_leito(int _leito);

    Status get_status(Status status);
    void set_status(Status status);  

    int  get_max_leito () const;
    void set_max_leito (int max_leito);
};
#endif
