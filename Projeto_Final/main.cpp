#include "main.hpp"

#include <string.h>
#include <stdexcept>
#include <iostream>

using namespace std;

int main()
{
    // Instanciar controladoras de apresentação.

    IAControle *cntrApresentacaoControle;
    IA_CRUD *cntrApresentacao_CRUD;

    cntrApresentacaoControle = new CntrAControle();
    cntrApresentacao_CRUD = new CntrA_CRUD();

    // Instanciar controladoras de serviço.

    IS_CRUD *cntrServico_CRUD;

    cntrServico_CRUD = new CntrS_CRUD();

    // Interligar controladoras.

    cntrApresentacaoControle->setCntrA_CRUD(cntrApresentacao_CRUD);

    cntrApresentacao_CRUD->setCntrS_CRUD(cntrServico_CRUD);

    initscr();                                                                      // Iniciar curses.
    cntrApresentacaoControle->executar();                                           // Solicitar serviço apresentacao.
    endwin();                                                                       // Finalizar curses.

    return 0;
}
