#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string>
#include <list>
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include "../interfaces.hpp"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços.

class CntrS_CRUD:public IS_CRUD{
    public:
        bool createCliente(Cliente);
        bool createPedido(Pedido);
        bool createRestaurante(Restaurante);
        bool createFuncionario(Funcionario);
        bool createTipoFuncionario(Tipo_Funcionario);
        bool createAtendimento(Atendimento);
        bool createItem(Item);
        bool createCancelamento(Cancelamento);
        bool createEntregador(Entregador);
        bool createTipoEntrega(Tipo_Entrega);
        Cliente ReadCliente(CPF);
        bool UpdateCliente(CPF);
        bool DeleteCliente(CPF);
};


#endif // CONTROLADORASSERVICO_H_INCLUDED