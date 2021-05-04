#include <iostream>
#include "Pessoa.h"
#include "Medico.h"
#include "Paciente.h"
#include "Status.h"

int main ()
{
    //ERA PRA TER OBJETOS CRIADOS AQUI

   

    unsigned int entrada = 0;

    //IMPLEMENTAR MENUS DO SISTEMA
    while (true)
    {
        try
        {
            std::cout << "-----MENU PRINCINPAL-----" << std::endl;
            std::cout << "1 - CENTRAL DE PESSOAS" << std::endl;
            std::cout << "2 - CENTRAL DE PACIENTES" << std::endl;
            std::cout << "3 - CENTRAL DE MEDICOS" << std::endl;
            std::cout << "4 - CENTRAL DE LEITOS" << std::endl;
            std::cout << "5 - VERIFICAR STATUS" << std::endl;
            std::cout << "6 - SAIR" << std::endl;

            std::cin >> entrada;


            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
  
    }
    
    return 0;
}