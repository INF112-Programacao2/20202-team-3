#ifndef TEAM_3_PESSOA_H
#define TEAM_3_PESSOA_H
#include <iostream>

class Pessoa
{
private:
    std::string _name;
    std::string _cpf;
    std::string _data;
    bool _sexo;
public:
    unsigned int _id;
    static unsigned int _next_id;
    Pessoa(std::string name, std::string cpf, std::string data, bool sexo);
    ~Pessoa();
    virtual int cadastrar(std::string name, std::string cpf, std::string data, bool sexo) = 0;
    virtual int alterar(int id) = 0;
    virtual int consultar(int id) = 0;
    virtual int remover(int id) = 0;
    static int  listar();        
};
#endif

