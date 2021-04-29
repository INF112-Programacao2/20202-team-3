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
    //AS DUAS VARIAVEIS ABAIXO MANIPULAM TODO ID DO PROGRAMA
    unsigned int _id; 
    static unsigned int _next_id;
    
    
    //CONSTRUTOR
    Pessoa(std::string name, std::string cpf, std::string data, bool sexo);
    

    //METODOS A SEREM UTILIZADOS NAS CLASSES FILHAS
    virtual int cadastrar() = 0; 
    virtual int alterar(int id) = 0;
    virtual int consultar(int id) = 0; // LISTAR UM ÚNICO CADASTRO
    virtual int remover(int id) = 0;


    static int  listar(); // LISTAR TODOS OS CADASTROS
    

    //GETTERS AND SETERS PARA TODOS OS ATRIBUTOS
    std::string get_name() const;
    void set_name(std::string _name);
    
    std::string get_cpf() const;
    void set_cpf(std::string _cpf);
   
    std::string get_data() const;
    void set_data(std::string _data);
    
    
    bool get_sexo() const;
    void set_sexo(bool _sexo);  

    unsigned int get_id() const;
    void set_id(unsigned int id);

    int get_next_id() const;
    void set_next_id(int next_id);
};
#endif

