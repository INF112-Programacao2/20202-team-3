#include <iostream>
#include "Pessoa.h"
#include "Medico.h"
#include "Paciente.h"
#include "Status.h"

#include "Paciente.h"

int main ()
{
    int entrada[2] = {-1,-1};
    int id = 0;
    Paciente paciente;
    Medico   medico;

    
    while (entrada[0]!=0)
    {
        try
        {
            std::cout << "-----MENU PRINCIPAL-----" << std::endl;
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
                    entrada[1] = -1;
                    break; 
                case 2:
                //TODO verificar id quanto a digito e se esta no vetor de id
                    std::cout << "Digite o id do paciente" << std::endl;
                    std::cin >> id;
                    paciente.consultar(id);
                    entrada[1] = -1;
                    break;
                case 3:
                    std::cout << "Digite o id do paciente" << std::endl;
                    std::cin >> id;
                    paciente.consultar(id);
                    entrada[1] = -1;
                    break;   
                case 4:
                    std::cout << "Digite o id do paciente" << std::endl;
                    std::cin >> id;
                    paciente.remover(id);
                    entrada[1] = -1;
                    break; 
                case 5:
                    Paciente::listar();
                    entrada[1] = -1;
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
                case 1:
                    medico.cadastrar();
                    entrada[1] = -1;
                    break;
                case 2:
                    std::cout << "Digite o id do médico" << std::endl;
                    std::cin >> id;
                    medico.alterar(id);
                    entrada[1] = -1;
                    break;
                case 3:
                    std::cout << "Digite o id do médico" << std::endl;
                    std::cin >> id;
                    medico.consultar(id);
                    entrada[1] = -1;
                    break;
                case 4:
                    std::cout << "Digite o id do médico" << std::endl;
                    std::cin >> id;
                    medico.remover(id);
                    entrada[1] = -1;
                    break;                
                case 5:
                    Medico::listar();
                    entrada[1] = -1;
                    break; 
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
                //TODO: TEORICAMENTE AQUI VAI CHAMAR O METODO QUE ATUALIZA E INFORMA O STATUS DO CIDADAO 
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