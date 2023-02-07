#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "lib/Domains/domain.hpp"
#include "lib/Entities/entity.hpp"

#include <map>
#include <list>

//--------------------------------------------------------------------------------------------
// declaração antecipada

class IAControle;
class IA_CRUD;
class IS_CRUD;

//--------------------------------------------------------------------------------------------
// Interfaces camada de apresentação

class IAControle {
public:
    virtual void executar() = 0;
    virtual void setCntrA_CRUD(IA_CRUD*) = 0;
    virtual ~IAControle(){}
};

class IA_CRUD {
public:
    virtual void executar() = 0;
    virtual void setCntrS_CRUD(IS_CRUD*) = 0;
    virtual ~IA_CRUD(){}
};

//--------------------------------------------------------------------------------------------
// Interfaces camada de serviço

class IS_CRUD {
public:
    virtual bool createCliente(Cliente) = 0;
    virtual bool createPedido(Pedido) = 0;
    virtual bool createRestaurante(Restaurante) = 0;
    virtual bool createFuncionario(Funcionario) = 0;
    virtual bool createTipoFuncionario(Tipo_Funcionario) = 0;
    virtual bool createAtendimento(Atendimento) = 0;
    virtual bool createItem(Item) = 0;
    virtual bool createCancelamento(Cancelamento) = 0;
    virtual bool createEntregador(Entregador) = 0;
    virtual bool createTipoEntrega(Tipo_Entrega) = 0;
    virtual Cliente ReadCliente(CPF) = 0;
    virtual bool UpdateCliente(CPF) = 0;
    virtual bool DeleteCliente(CPF) = 0;
    virtual ~IS_CRUD(){}
};


#endif // INTERFACES_H_INCLUDED
