#ifndef domainHppIncluded
#define domainHppIncluded

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * Classe Pai de todos os dominios
 * 
 */

class Domain {
    protected:
        string value;
        virtual ~Domain() {};
        virtual void validate(string) = 0;
    public:
        void setValue(string);
        string getValue() const;
};

inline void Domain::setValue(string value) {
    validate(value);
    this->value = value;
}

inline string Domain::getValue() const {
    return value;
}

/*********
  CLIENTE 
**********/

class Data:public Domain {
    private:
        void validate(string);
};

class Email:public Domain {
    private:
        void validate(string);
};

class Telefone:public Domain {
    private:
        void validate(string);
};

class Estado:public Domain {
    private:
        void validate(string);
};

class Cidade:public Domain {
    private:
        void validate(string);
};

class Endereco:public Domain {
    private:
        void validate(string);
};

class Nome:public Domain {
    private:
        void validate(string);
};

class CPF:public Domain {
    private:
        void validate(string);
};

/*********
  ATENDIMENTO 
**********/

class Nota:public Domain {
    private:
        void validate(string);
};

class Motivo:public Domain {
    private:
        void validate(string);
};

class Codigo:public Domain {
    private:
        void validate(string);
};

/*********
  PEDIDO 
**********/

class Valor:public Domain {
    private:
        void validate(string);
};

class Forma_pagamento:public Domain {
    private:
        void validate(string);
};

class Status:public Domain {
    private:
        void validate(string);
};

/*********
  RESTAURANTE 
**********/
class CNPJ:public Domain {
    private:
        void validate(string);
};

/*********
  FUNCIONARIO 
**********/

class Matricula:public Domain {
    private:
        void validate(string);
};

/*********
  TIPO DE FUNCIONARIO 
**********/

class Funcao:public Domain {
    private:
        void validate(string);
};

/*********
  ITEM 
**********/

class Quantidade:public Domain {
    private:
        void validate(string);
};

/*********
  CANCELAMENTO
**********/
// ja possui todos os dominios necessarios

/*********
  ENTREGADOR 
**********/
// ja possui todos os dominios necessarios

/*********
  TIPO DE ENTREGA 
**********/

class Modelo:public Domain {
    private:
        void validate(string);
};

#endif
