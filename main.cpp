#include <iostream>
#include "Pessoa.h"
#include "Medico.h"
#include "Paciente.h"
#include "Status.h"

#include "Paciente.h"

int main ()
{
    //ERA PRA TER OBJETOS CRIADOS AQUI
    int entrada[2] = {-1,-1};

    //IMPLEMENTAR MENUS DO SISTEMA
    Paciente paciente;
    
    while (entrada[0]!=0)
    {
        try
        {
            std::cout << "-----MENU PRINCINPAL-----" << std::endl;
            std::cout << "1 - CENTRAL DE PACIENTES" << std::endl;
            std::cout << "2 - CENTRAL DE MEDICOS" << std::endl;
            std::cout << "3 - CENTRAL DE LEITOS" << std::endl;
            std::cout << "4 - VERIFICAR STATUS" << std::endl;
            std::cout << "0 - SAIR" << std::endl;

            std::cin >> entrada[0];
            
            switch (entrada[0])
            {
            case 1:
                std::cout << "-----MENU PACIENTES-----" << std::endl;
                std::cout << "1 - CADASTRAR" << std::endl;
                std::cout << "2 - ALTERAR" << std::endl;
                std::cout << "3 - CONSULTAR" << std::endl;
                std::cout << "4 - REMOVER" << std::endl;
                std::cout << "5 - LISTAR" << std::endl;  
                std::cout << "0 - SAIR" << std::endl;
                std::cin >> entrada[1];

                switch (entrada[1])
                {
                case 1:
                    paciente.cadastrar();
                    break; 
                case 5:
                    Paciente::listar();
                    break;
                default:
                    break;
                }
                break;
            case 2:
                std::cout << "-----MENU MEDICOS -----" << std::endl;
                std::cout << "1 - CADASTRAR" << std::endl;
                std::cout << "2 - ALTERAR" << std::endl;
                std::cout << "3 - CONSULTAR" << std::endl;
                std::cout << "4 - REMOVER" << std::endl;
                std::cout << "5 - LISTAR" << std::endl; 
                std::cout << "0 - SAIR" << std::endl;
                std::cin >> entrada[1];

                switch (entrada[1])
                {
                case 5:
                    Medico::listar();
                default:
                    break;
                }
                break;
            case 3:
                std::cout << "-----MENU LEITOS -----" << std::endl;
                std::cout << "1 - CAPACIDADE MAXIMA" << std::endl;
                std::cout << "2 - DISPONIBILIDADE" << std::endl;
                std::cout << "3 - MODIFICAR CAPACIDADE" << std::endl;
                std::cout << "0 - SAIR" << std::endl;
                std::cin >> entrada[1];
                break;  
            case 4:
                //TODO: TEORICAMENTE AQUI VAI CHAMAR O METODO QUE ATULIZA E INFOMAR O STATUS DO CIDADAO 
            break;      
            default:
                break;          
            }


            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

  
    }
    
    return 0;
}