#ifndef CNTRAPRESENTACAO_HPP_INCLUDED
#define CNTRAPRESENTACAO_HPP_INCLUDED

#include <string.h>
#include "../lib/Curses/curses.h"
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include "../interfaces.hpp"

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.


class CntrAControle:public IAControle{
    private:
        IA_CRUD *cntrA_CRUD;
    public:
        void executar();
        void setCntrA_CRUD(IA_CRUD*);
};

inline void CntrAControle::setCntrA_CRUD(IA_CRUD *cntr){
    cntrA_CRUD = cntr;
}


//--------------------------------------------------------------------------------------------

class CntrA_CRUD:public IA_CRUD{
    private:
        IS_CRUD *cntr;
        bool Create();
        bool Read();
        bool Update();
        bool Delete();
        Cliente formsCliente();
        Cliente formsClienteUpdate();
        Pedido formsPedido();
        Restaurante formsRestaurante();
        Funcionario formsFuncionario();
        Tipo_Funcionario formsTipodeFuncionario();
        Atendimento formsAtendimento();
        Item formsItem();
        Cancelamento formsCancelamento();
        Entregador formsEntregador();
        Tipo_Entrega formsTipodeEntrega();
        CPF pkCliente();
        Codigo pkPedido();
        CNPJ pkRestaurante();
        Codigo pkFuncionario();
        Codigo pkTipodeFuncionario();
        Codigo pkAtendimento();
        Codigo pkItem();
        Codigo pkCancelamento();
        Codigo pkEntregador();
        Codigo pkTipodeEntrega();
    public:
        void executar();
        void setCntrS_CRUD(IS_CRUD*);
};

inline void CntrA_CRUD::setCntrS_CRUD(IS_CRUD *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------


#endif // CNTRAPRESENTACAO_HPP_INCLUDED
