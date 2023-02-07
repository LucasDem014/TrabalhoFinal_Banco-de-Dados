#ifndef entityHppIncluded
#define entityHppIncluded

#include "../Domains/domain.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Cliente {
    private:
        CPF cpf;
        Nome nome;
        Data data_nascimento;
        Endereco endereco;
        Cidade cidade;
        Estado estado;
        Telefone telefone;
        Email email;
        Data data_cadastro;
    public:
        CPF getCPF() const {return cpf;};
        Nome getNome() const { return nome; };
        Data getDataNasc() const { return data_nascimento;};
        Endereco getEndereco() const {return endereco;};
        Cidade getCidade() const {return cidade;};
        Estado getEstado() const {return estado;};
        Telefone getTelefone() const {return telefone;};
        Email getEmail() const { return email; };
        Data getDataCadastro() const { return data_cadastro;};
        void setCPF(const CPF& cpf) { this->cpf = cpf;};
        void setNome(const Nome& nome) { this->nome = nome; };
        void setDateNasc(const Data& data_nascimento) { this->data_nascimento = data_nascimento;};
        void setEndereco(const Endereco& endereco) { this->endereco = endereco;};
        void setCidade(const Cidade& cidade) { this->cidade = cidade;};
        void setEstado(const Estado& estado) { this->estado = estado;};
        void setTelefone(const Telefone& telefone) { this->telefone = telefone;};
        void setEmail(const Email& email) { this->email = email; };
        void setDataCadastro(const Data& data_cadastro) { this->data_cadastro = data_cadastro; };
};

class Pedido {
    private:
        Status status;
        Codigo codigo;
        Cidade cidade;
        Estado estado;
        Forma_pagamento forma_pagamento;
        Valor valor_total;
    public:
        Status getStatus() const {return status;};
        Codigo getCodigo() const {return codigo;};
        Cidade getCidade() const {return cidade;};
        Estado getEstado() const {return estado;};
        Forma_pagamento getFormaPagamento() const {return forma_pagamento;};
        Valor getValorTotal() const {return valor_total;};
        void setStatus(const Status& status) { this->status = status;};
        void setCodigo(const Codigo& codigo) { this->codigo = codigo;};
        void setCidade(const Cidade& cidade) { this->cidade = cidade;};
        void setEstado(const Estado& estado) { this->estado = estado;};
        void setFormaPagamento(const Forma_pagamento& forma_pagamento) { this->forma_pagamento = forma_pagamento;};
        void setValorTotal(const Valor& valor_total) { this->valor_total = valor_total;};
};

class Restaurante {
    private:
        CNPJ cnpj;
        Endereco endereco;
        Cidade cidade;
        Estado estado;
        Data data_cadastro;
    public:
        CNPJ getCNPJ() const {return cnpj;};
        Endereco getEndereco() const {return endereco;};
        Cidade getCidade() const {return cidade;};
        Estado getEstado() const {return estado;};
        Data getDataCadastro() const { return data_cadastro;};
        void setCNPJ(const CNPJ& cnpj) { this->cnpj = cnpj;};
        void setEndereco(const Endereco& endereco) { this->endereco = endereco;};
        void setCidade(const Cidade& cidade) { this->cidade = cidade;};
        void setEstado(const Estado& estado) { this->estado = estado;};
        void setDataCadastro(const Data& data_cadastro) { this->data_cadastro = data_cadastro; };
};

class Funcionario {
    private:
        Matricula matricula;
        Nome nome;
        Data data_nascimento;
        Telefone telefone;
        Email email;
        Data data_entrada;
    public:
        Matricula getMatricula() const {return matricula;};
        Nome getNome() const { return nome; };
        Data getDataNasc() const { return data_nascimento;};
        Telefone getTelefone() const {return telefone;};
        Email getEmail() const { return email; };
        Data getDataEntrada() const { return data_entrada;};
        void setMatricula(const Matricula& matricula) { this->matricula = matricula;};
        void setNome(const Nome& nome) { this->nome = nome; };
        void setDateNasc(const Data& data_nascimento) { this->data_nascimento = data_nascimento;};
        void setTelefone(const Telefone& telefone) { this->telefone = telefone;};
        void setEmail(const Email& email) { this->email = email; };
        void setDataEntrada(const Data& data_entrada) { this->data_entrada = data_entrada; };
};

class Tipo_Funcionario {
    private:
        Codigo codigo_funcao;
        Funcao funcao;
    public:
        Codigo getCodigo() const {return codigo_funcao;};
        Funcao getFuncao() const {return funcao;};
        void setCodigo(const Codigo& codigo_funcao) { this->codigo_funcao = codigo_funcao;};
        void setFuncao(const Funcao& funcao) { this->funcao = funcao;};
};

class Atendimento {
    private:
        Codigo codigo_contato;
        Motivo motivo;
        Nota nota;
    public:
        Codigo getCodigo() const {return codigo_contato;};
        Motivo getMotivo() const {return motivo;};
        Nota getNota() const {return nota;};
        void setCodigo(const Codigo& codigo_contato) { this->codigo_contato = codigo_contato;};
        void setMotivo(const Motivo& motivo) {this->motivo = motivo;};
        void setNota(const Nota& nota) { this->nota = nota;};
};

class Item {
    private:
        Nome nome;
        Valor valor_unitario;
        Quantidade quantidade;
        Codigo codigo;
    public:
        Nome getNome() const {return nome;};
        Valor getValorUnitario() const {return valor_unitario;};
        Quantidade getQuantidade() const {return quantidade;};
        Codigo getCodigo() const {return codigo;};
        void setNome(const Nome& nome) { this->nome = nome; };
        void setValorUnitario(const Valor& valor_unitario) { this->valor_unitario = valor_unitario;};
        void setQuantidade(const Quantidade& quantidade) {this->quantidade = quantidade;};
        void setCodigo(const Codigo& codigo_contato) { this->codigo = codigo;};
};

class Cancelamento {
    private:
        Codigo codigo;
        Motivo motivo;
    public:
        Codigo getCodigo() const {return codigo;};
        Motivo getMotivo() const {return motivo;};
        void setCodigo(const Codigo& codigo) { this->codigo = codigo;};
        void setMotivo(const Motivo& motivo) {this->motivo = motivo;};
};

class Entregador {
    private:
        Codigo codigo_entregador;
        Nome nome;
        Data data_nascimento;
        Cidade cidade;
        Estado estado;
        Telefone telefone;
        Email email;
        Data data_entrada;
    public:
        Codigo getCodigo() const {return codigo_entregador;};
        Nome getNome() const { return nome; };
        Data getDataNasc() const { return data_nascimento;};
        Cidade getCidade() const {return cidade;};
        Estado getEstado() const {return estado;};
        Telefone getTelefone() const {return telefone;};
        Email getEmail() const { return email; };
        Data getDataCadastro() const { return data_entrada;};
        void setCodigo(const Codigo& codigo_entragador) { this->codigo_entregador = codigo_entregador;};
        void setNome(const Nome& nome) { this->nome = nome; };
        void setDateNasc(const Data& data_nascimento) { this->data_nascimento = data_nascimento;};
        void setCidade(const Cidade& cidade) { this->cidade = cidade;};
        void setEstado(const Estado& estado) { this->estado = estado;};
        void setTelefone(const Telefone& telefone) { this->telefone = telefone;};
        void setEmail(const Email& email) { this->email = email; };
        void setDataEntrada(const Data& data_entrada) { this->data_entrada = data_entrada; };
};

class Tipo_Entrega {
    private:
        Codigo codigo_transporte;
        Modelo modelo;
        Valor valor;
    public:
        Codigo getCodigo() const {return codigo_transporte;};
        Modelo getModelo() const {return modelo;};
        Valor getValor() const {return valor;};
        void setCodigo(const Codigo& codigo_transporte) { this->codigo_transporte = codigo_transporte;};
        void setModelo(const Modelo& modelo) { this->modelo = modelo;};
        void setValor(const Valor& valor) {this->valor = valor;};
};

#endif