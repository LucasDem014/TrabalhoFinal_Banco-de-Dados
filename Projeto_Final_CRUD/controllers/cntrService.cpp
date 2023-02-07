#include "cntrService.hpp"
#include "../lib/Curses/curses.h"
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include <list>
#include <bits/stdc++.h>

#include <stdlib.h>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/cppconn/exception.h>
#include <mysql-cppconn-8/jdbc/cppconn/prepared_statement.h>

using namespace sql;

//--------------------------------------------------------------------------------------------
// Implementações de métodos de classes controladoras da camada de serviço.

bool CntrS_CRUD::createCliente(Cliente cliente){
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *prep_stmt;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "senha");  
        
        con->setSchema("VO_1");
        prep_stmt = con->prepareStatement("INSERT INTO Cliente(CPF, Nome, Data_de_Nascimento, Telefone, E_mail, Data_de_cadastro, Cidade, Estado) VALUES(?, ?, ?, ?, ?, ?, ?, ?);");
        prep_stmt->setString(1, cliente.getCPF().getValue());
        prep_stmt->setString(2, cliente.getNome().getValue());
        prep_stmt->setString(3, cliente.getDataNasc().getValue());
        prep_stmt->setString(4, cliente.getTelefone().getValue());
        prep_stmt->setString(5, cliente.getEmail().getValue());
        prep_stmt->setString(6, cliente.getDataCadastro().getValue());
        prep_stmt->setString(7, cliente.getCidade().getValue());
        prep_stmt->setString(8, cliente.getEstado().getValue());
        prep_stmt->execute();
        

        delete prep_stmt;
        delete con;

    } catch (sql::SQLException &e) {    
        return false;
    }

    return true;
}

Cliente CntrS_CRUD::ReadCliente(CPF cpf){
    Cliente cliente;
    try {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "senha");   
    
    con->setSchema("VO_1");
    stmt = con->createStatement();
    char query[100];
    sprintf(query, "SELECT * FROM Cliente WHERE CPF = \"%s\"", cpf.getValue().c_str());
    res = stmt->executeQuery(query);

    Nome nome;
    Data data_nasc;
    Telefone telefone;
    Email email;
    Data data_cad;
    Cidade cidade;
    Estado estado;

    while(res->next()) {
     
      nome.setValue(res->getString(2));
      data_nasc.setValue(res->getString(3));
      telefone.setValue(res->getString(4));
      email.setValue(res->getString(5));
      data_cad.setValue(res->getString(6));
      cidade.setValue(res->getString(7));
      estado.setValue(res->getString(8));
    }

    cliente.setCPF(cpf);
    cliente.setNome(nome);
    cliente.setDateNasc(data_nasc);
    cliente.setTelefone(telefone);
    cliente.setEmail(email);
    cliente.setDataCadastro(data_cad);
    cliente.setCidade(cidade);
    cliente.setEstado(estado);
    

    delete res;
    delete stmt;
    delete con;

  } catch (sql::SQLException &e) {    
    return cliente;
  }

  return cliente;
}

bool CntrS_CRUD::createPedido(Pedido pedido){
    return true;
}

bool CntrS_CRUD::createRestaurante(Restaurante restaurante){
    return true;
}

bool CntrS_CRUD::createFuncionario(Funcionario funcionario){
    return true;
}

bool CntrS_CRUD::createTipoFuncionario(Tipo_Funcionario tipo_funcionario){
    return true;
}

bool CntrS_CRUD::createAtendimento(Atendimento atendimento){
    return true;
}

bool CntrS_CRUD::createItem(Item item){
    return true;
}

bool CntrS_CRUD::createCancelamento(Cancelamento cancelamento){
    return true;
}

bool CntrS_CRUD::createEntregador(Entregador entregador){
    return true;
}

bool CntrS_CRUD::createTipoEntrega(Tipo_Entrega tipo_entrega){
    return true;
}

bool CntrS_CRUD::UpdateCliente(CPF cpf){
    return true;
}

bool CntrS_CRUD::DeleteCliente(CPF cpf){
    try {
    sql::Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *prep_stmt;
    
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "senha");   
    
    con->setSchema("VO_1");

    char query[100];
    sprintf(query, "DELETE FROM Cliente WHERE CPF = \"%s\"", cpf.getValue().c_str());
    

    prep_stmt = con->prepareStatement(query);      
    prep_stmt->execute();

    delete prep_stmt;
    delete con;

  } catch (sql::SQLException &e) {    
    return false;
  }


  return true;
}

