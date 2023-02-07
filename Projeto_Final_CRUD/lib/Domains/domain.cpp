#include "domain.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

void Data::validate(string data) {
    if(data.size() > 15)
        throw invalid_argument("Invalid Data Format");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Email::validate(string email) {
    if (email.size() > 50)
        throw invalid_argument("Invalid Email Format");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Telefone::validate(string telefone) {
    if (telefone.size() > 15) {
        throw invalid_argument("Invalid Telefone Format");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Estado::validate(string estado) {
    if (estado.size() > 15) {
        throw invalid_argument("Invalid estado Format");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Cidade::validate(string cidade) {
    if (cidade.size() > 15) {
        throw invalid_argument("Invalid estado Format");
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Endereco::validate(string endereco) {
    if (endereco.size() > 50) {
        throw invalid_argument("Invalid endereco Format");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Nome::validate(string nome) {
    if (nome.size() > 50) {
        throw invalid_argument("Invalid nome Format");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void CPF::validate(string cpf) {
    if (cpf.size() > 15) {
        throw invalid_argument("Invalid cpf Format");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Nota::validate(string nota) {
    int grade_aux = stoi(nota);
    if (!(0 <= grade_aux && grade_aux <= 5))
        throw invalid_argument("Invalid nota");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Motivo::validate(string motivo) {
    if (motivo.size() > 150) {
        throw invalid_argument("Invalid motivo Format");
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Codigo::validate(string codigo) {
    if (codigo.size() > 15)
        throw invalid_argument("Invalid codigo");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Valor::validate(string valor) {
    if (valor.size() > 10)
        throw invalid_argument("Invalid codigo");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Forma_pagamento::validate(string forma_pagamento) {
    if (forma_pagamento.size() > 15)
        throw invalid_argument("Invalid forma de pagamento");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Status::validate(string status) {
    if (status.size() > 15)
        throw invalid_argument("Invalid status");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void CNPJ::validate(string cnpj) {
    if (cnpj.size() > 15)
        throw invalid_argument("Invalid codigo");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Matricula::validate(string matricula) {
    if (matricula.size() > 15)
        throw invalid_argument("Invalid matricula");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Funcao::validate(string funcao) {
    if (funcao.size() > 50)
        throw invalid_argument("Invalid funcao");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Quantidade::validate(string quantidade) {
    if (quantidade.size() > 15)
        throw invalid_argument("Invalid quantidade");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Modelo::validate(string modelo) {
    if (modelo.size() > 15)
        throw invalid_argument("Invalid modelo");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------




