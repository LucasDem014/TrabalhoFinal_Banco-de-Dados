/* Lógico_1: */
CREATE DATABASE VO_1;
USE VO_1;

CREATE TABLE Pedido (
    Codigo_do_pedido VARCHAR(6) PRIMARY KEY,
    Cidade VARCHAR(50),
    Estado VARCHAR(2),
    Valor_Total FLOAT,
    Status_do_pedido VARCHAR(12),
    fk_Restaurante_CNPJ VARCHAR(14),
    fk_Cancelamento_Codigo_de_cancelamento VARCHAR(3),
    fk_Cliente_CPF VARCHAR(11),
    fk_Entregador_Codigo_do_entregador VARCHAR(3),
    Forma_de_pagamento VARCHAR(20)
);

CREATE TABLE Cliente (
    CPF VARCHAR(11) PRIMARY KEY,
    Nome VARCHAR(100),
    Data_de_Nascimento DATE,
    Telefone VARCHAR(11),
    E_mail VARCHAR(50),
    Data_de_cadastro DATE,
    Cidade VARCHAR(50),
    Estado VARCHAR(2)
);

CREATE TABLE Item (
    Codigo_do_item VARCHAR(5) PRIMARY KEY,
    Valor_unitario FLOAT,
    Nome_ VARCHAR(100)
);

CREATE TABLE Restaurante (
    CNPJ VARCHAR(14) PRIMARY KEY,
    Data_de_Cadastro DATE,
    Cidade VARCHAR(50),
    Estado VARCHAR(2)
);

CREATE TABLE Entregador (
    Codigo_do_entregador VARCHAR(3) PRIMARY KEY,
    Nome VARCHAR(100),
    Data_de_nascimento DATE,
    Cidade VARCHAR(50),
    Estado VARCHAR(2),
    Telefone VARCHAR(11),
    E_mail VARCHAR(50),
    Data_de_entrada DATE,
    Sexo VARCHAR(1),
    fk_Tipo_de_entrega_Codigo_do_transporte VARCHAR(1)
);

CREATE TABLE Tipo_de_entrega (
    Modal VARCHAR(20),
    Codigo_do_transporte VARCHAR(1) PRIMARY KEY,
    Valor FLOAT
);

CREATE TABLE Cancelamento (
    Codigo_de_cancelamento VARCHAR(3) PRIMARY KEY,
    Motivo VARCHAR(100)
);

CREATE TABLE Atendimento (
    Codigo_do_contato VARCHAR(5) PRIMARY KEY,
    Motivo VARCHAR(150),
    Nota FLOAT
);

CREATE TABLE Funcionario (
    Matricula VARCHAR(5) PRIMARY KEY,
    Nome VARCHAR(100),
    Data_de_nascimento DATE,
    Telefone VARCHAR(11),
    E_mail VARCHAR(50),
    Data_de_entrada DATE,
    Sexo VARCHAR(1),
    fk_Restaurante_CNPJ VARCHAR(14),
    fk_Tipo_de_funcionario_Codigo_da_funcao VARCHAR(3)
);

CREATE TABLE Tipo_de_funcionario (
    Codigo_da_funcao VARCHAR(3) PRIMARY KEY,
    Funcao VARCHAR(50)
);

CREATE TABLE Possui (
    fk_Item_Codigo_do_item VARCHAR(5),
    fk_Pedido_Codigo_do_pedido VARCHAR(6)
);

CREATE TABLE Gerou (
    fk_Atendimento_Codigo_do_contato VARCHAR(5),
    fk_Pedido_Codigo_do_pedido VARCHAR(6)
);
 
ALTER TABLE Pedido ADD CONSTRAINT FK_Pedido_2
    FOREIGN KEY (fk_Restaurante_CNPJ)
    REFERENCES Restaurante (CNPJ)
    ON DELETE CASCADE;
 
ALTER TABLE Pedido ADD CONSTRAINT FK_Pedido_3
    FOREIGN KEY (fk_Cancelamento_Codigo_de_cancelamento)
    REFERENCES Cancelamento (Codigo_de_cancelamento)
    ON DELETE SET NULL;
 
ALTER TABLE Pedido ADD CONSTRAINT FK_Pedido_4
    FOREIGN KEY (fk_Cliente_CPF)
    REFERENCES Cliente (CPF)
    ON DELETE CASCADE;
 
ALTER TABLE Pedido ADD CONSTRAINT FK_Pedido_5
    FOREIGN KEY (fk_Entregador_Codigo_do_entregador)
    REFERENCES Entregador (Codigo_do_entregador)
    ON DELETE SET NULL;
 
ALTER TABLE Entregador ADD CONSTRAINT FK_Entregador_2
    FOREIGN KEY (fk_Tipo_de_entrega_Codigo_do_transporte)
    REFERENCES Tipo_de_entrega (Codigo_do_transporte)
    ON DELETE CASCADE;
 
ALTER TABLE Funcionario ADD CONSTRAINT FK_Funcionario_2
    FOREIGN KEY (fk_Restaurante_CNPJ)
    REFERENCES Restaurante (CNPJ)
    ON DELETE RESTRICT;
 
ALTER TABLE Funcionario ADD CONSTRAINT FK_Funcionario_3
    FOREIGN KEY (fk_Tipo_de_funcionario_Codigo_da_funcao)
    REFERENCES Tipo_de_funcionario (Codigo_da_funcao)
    ON DELETE CASCADE;
 
ALTER TABLE Possui ADD CONSTRAINT FK_Possui_1
    FOREIGN KEY (fk_Item_Codigo_do_item)
    REFERENCES Item (Codigo_do_item)
    ON DELETE RESTRICT;
 
ALTER TABLE Possui ADD CONSTRAINT FK_Possui_2
    FOREIGN KEY (fk_Pedido_Codigo_do_pedido)
    REFERENCES Pedido (Codigo_do_pedido)
    ON DELETE SET NULL;
 
ALTER TABLE Gerou ADD CONSTRAINT FK_Gerou_1
    FOREIGN KEY (fk_Atendimento_Codigo_do_contato)
    REFERENCES Atendimento (Codigo_do_contato)
    ON DELETE SET NULL;
 
ALTER TABLE Gerou ADD CONSTRAINT FK_Gerou_2
    FOREIGN KEY (fk_Pedido_Codigo_do_pedido)
    REFERENCES Pedido (Codigo_do_pedido)
    ON DELETE SET NULL;
    
INSERT INTO Cliente(CPF, Nome, Data_de_Nascimento, Telefone, E_mail, Data_de_cadastro, Cidade, Estado) VALUES('04589484444', 'Renata Souza', '1990-03-01', '61987654098', 'renata_souza@mail.com', '2022-11-01', 'Taguatinga', 'DF');
INSERT INTO Cliente(CPF, Nome, Data_de_Nascimento, Telefone, E_mail, Data_de_cadastro, Cidade, Estado) VALUES('03940485894', 'Julio Gomes', '1995-07-01', '61976540987', 'julio_gomes@mail.com', '2022-12-01', 'Asa Norte', 'DF');
INSERT INTO Cliente(CPF, Nome, Data_de_Nascimento, Telefone, E_mail, Data_de_cadastro, Cidade, Estado) VALUES('73634932949', 'Joana da Mata', '1880-11-23', '61954739221', 'joana_mata@mail.com', '2023-01-01', 'Águas Claras', 'DF');
INSERT INTO Cliente(CPF, Nome, Data_de_Nascimento, Telefone, E_mail, Data_de_cadastro, Cidade, Estado) VALUES('47867634720', 'Marcelo Oliveira', '1997-02-01', '62965830202', 'marcelo_gomes@mail.com', '2022-11-02', 'Goiânia', 'GO');
INSERT INTO Cliente(CPF, Nome, Data_de_Nascimento, Telefone, E_mail, Data_de_cadastro, Cidade, Estado) VALUES('39478484940', 'Fabiana Medeiros', '1950-06-13', '62974631234', 'fabiana_medeiros@mail.com', '2022-12-02', 'Goiânia', 'GO');

INSERT INTO Cancelamento(Codigo_de_cancelamento, Motivo) VALUES('100','Endereço não localizado');
INSERT INTO Cancelamento(Codigo_de_cancelamento, Motivo) VALUES('200', 'Cliente não recebeu');
INSERT INTO Cancelamento(Codigo_de_cancelamento, Motivo) VALUES('300', 'Problemas no restaurante');
INSERT INTO Cancelamento(Codigo_de_cancelamento, Motivo) VALUES('400', 'Problemas sistêmicos');
INSERT INTO Cancelamento(Codigo_de_cancelamento, Motivo) VALUES('500', 'Acidente');

INSERT INTO Restaurante(CNPJ, Data_de_Cadastro, Cidade, Estado) VALUES('09876543000123','2022-10-01', 'Taguatinga', 'DF');
INSERT INTO Restaurante(CNPJ, Data_de_Cadastro, Cidade, Estado) VALUES('09876543000124', '2022-10-01', 'Asa Norte', 'DF');
INSERT INTO Restaurante(CNPJ, Data_de_Cadastro, Cidade, Estado) VALUES('09876543000125', '2022-10-01', 'Águas Claras', 'DF');
INSERT INTO Restaurante(CNPJ, Data_de_Cadastro, Cidade, Estado) VALUES('09876543000126', '2022-10-02', 'Goiânia', 'DF');
INSERT INTO Restaurante(CNPJ, Data_de_Cadastro, Cidade, Estado) VALUES('09876543000127', '2022-10-02', 'Sudoeste', 'DF' );

INSERT INTO Item(Codigo_do_item, Valor_unitario, Nome_) VALUES('1','19.99', 'Batata Frita');
INSERT INTO Item(Codigo_do_item, Valor_unitario, Nome_) VALUES('2', '69.99', 'Camarão Internacional');
INSERT INTO Item(Codigo_do_item, Valor_unitario, Nome_) VALUES('3', '109.99', 'Costela ao molho barbecue');
INSERT INTO Item(Codigo_do_item, Valor_unitario, Nome_) VALUES('4', '5.99', 'Água');
INSERT INTO Item(Codigo_do_item, Valor_unitario, Nome_) VALUES('5', '7.99', 'Suco de Laranja' );


INSERT INTO Atendimento(Codigo_do_contato, Motivo, Nota) VALUES('10','Pedido está atrasado a 30 minutos', '2');
INSERT INTO Atendimento(Codigo_do_contato, Motivo, Nota) VALUES('20', 'Não consigo entrar em contato com o restaurante', '4');
INSERT INTO Atendimento(Codigo_do_contato, Motivo, Nota) VALUES('30', 'Entregador foi antiprofissional', '4.5');
INSERT INTO Atendimento(Codigo_do_contato, Motivo, Nota) VALUES('40', 'Quero mudar o endereço de entrega', '3');
INSERT INTO Atendimento(Codigo_do_contato, Motivo, Nota) VALUES('50', 'Pedido atrasado', '5');

INSERT INTO Tipo_de_entrega(Modal, Codigo_do_transporte, Valor) VALUES('Carro', '1', '7.99');
INSERT INTO Tipo_de_entrega(Modal, Codigo_do_transporte, Valor) VALUES('Moto', '2', '4.99');
INSERT INTO Tipo_de_entrega(Modal, Codigo_do_transporte, Valor) VALUES('Bicicleta', '3', '2.99');
INSERT INTO Tipo_de_entrega(Modal, Codigo_do_transporte, Valor) VALUES('Bicicleta Elétrica', '4', '2.49');
INSERT INTO Tipo_de_entrega(Modal, Codigo_do_transporte, Valor) VALUES('Patinete Elétrico', '5', '2.99');


INSERT INTO Entregador(Codigo_do_entregador, Nome, Data_de_nascimento, Cidade, Estado, Telefone, E_mail, Data_de_entrada, Sexo, fk_Tipo_de_entrega_Codigo_do_transporte) VALUES('101', 'Akira Kibo', '1992-03-01', 'Ceilândia' , 'DF', '61187254098', 'akira_kibo@mail.com', '2022-11-01', 'M', '2');
INSERT INTO Entregador(Codigo_do_entregador, Nome, Data_de_nascimento, Cidade, Estado, Telefone, E_mail, Data_de_entrada, Sexo, fk_Tipo_de_entrega_Codigo_do_transporte) VALUES('120', 'Marcos Machado', '1985-02-19', 'Samambaia', 'DF', '61946550987', 'marcos_machado@mail.com', '2022-12-01', 'M', '1');
INSERT INTO Entregador(Codigo_do_entregador, Nome, Data_de_nascimento, Cidade, Estado, Telefone, E_mail, Data_de_entrada, Sexo, fk_Tipo_de_entrega_Codigo_do_transporte) VALUES('102', 'Cíntia Behr', '1870-05-02', 'Goiânia', 'GO', '61924734221', 'cintia_behr@mail.com', '2023-01-01', 'F', '3');
INSERT INTO Entregador(Codigo_do_entregador, Nome, Data_de_nascimento, Cidade, Estado, Telefone, E_mail, Data_de_entrada, Sexo, fk_Tipo_de_entrega_Codigo_do_transporte) VALUES('103', 'Penélope Vibrante', '1993-01-01', 'Goiânia', 'GO', '62955830202', 'penelope_vibrante@mail.com', '2022-11-02', 'F', '2');
INSERT INTO Entregador(Codigo_do_entregador, Nome, Data_de_nascimento, Cidade, Estado, Telefone, E_mail, Data_de_entrada, Sexo, fk_Tipo_de_entrega_Codigo_do_transporte) VALUES('121', 'Sérgio Romeu', '1980-07-15','Recanto das Emas', 'DF', '62974655234', 'sergio_romeu@mail.com', '2022-12-02', 'M', '4');


INSERT INTO Pedido(Codigo_do_pedido, Cidade, Estado, Valor_total, Status_do_pedido, fk_Restaurante_CNPJ, fk_Cancelamento_Codigo_de_cancelamento, fk_Cliente_CPF, fk_Entregador_Codigo_do_entregador, forma_de_pagamento) VALUES('101010', 'Asa Norte', 'DF', '97.97', 'Concluído', '09876543000124', null, '03940485894', '120', 'Cartão');
INSERT INTO Pedido(Codigo_do_pedido, Cidade, Estado, Valor_total, Status_do_pedido, fk_Restaurante_CNPJ, fk_Cancelamento_Codigo_de_cancelamento, fk_Cliente_CPF, fk_Entregador_Codigo_do_entregador, forma_de_pagamento) VALUES('101011', 'Águas Claras', 'DF', '25.98', 'Cancelado', '09876543000125', '100', '73634932949', '101', 'Dinheiro');
INSERT INTO Pedido(Codigo_do_pedido, Cidade, Estado, Valor_total, Status_do_pedido, fk_Restaurante_CNPJ, fk_Cancelamento_Codigo_de_cancelamento, fk_Cliente_CPF, fk_Entregador_Codigo_do_entregador, forma_de_pagamento) VALUES('101012', 'Goiânia', 'GO', '109.99', 'Concluído', '09876543000126', null, '47867634720', '102', 'Cartão');
INSERT INTO Pedido(Codigo_do_pedido, Cidade, Estado, Valor_total, Status_do_pedido, fk_Restaurante_CNPJ, fk_Cancelamento_Codigo_de_cancelamento, fk_Cliente_CPF, fk_Entregador_Codigo_do_entregador, forma_de_pagamento) VALUES('101013', 'Águas Claras', 'DF', '69.99', 'Cancelado', '09876543000125', '200', '73634932949', '121', 'Cartão');
INSERT INTO Pedido(Codigo_do_pedido, Cidade, Estado, Valor_total, Status_do_pedido, fk_Restaurante_CNPJ, fk_Cancelamento_Codigo_de_cancelamento, fk_Cliente_CPF, fk_Entregador_Codigo_do_entregador, forma_de_pagamento) VALUES('101014', 'Taguatinga', 'DF', '139.98', 'Concluído', '09876543000123', null,'04589484444', '101', 'Dinheiro');

INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('1','101010');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('2', '101010');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('5', '101010');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('1', '101011');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('4', '101011');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('3','101012');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('2', '101013');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('2', '101014');
INSERT INTO Possui(fk_Item_Codigo_do_item, fk_Pedido_Codigo_do_pedido) VALUES('2', '101014');


INSERT INTO Gerou(fk_Atendimento_Codigo_do_contato, fk_Pedido_Codigo_do_pedido) VALUES('10','101010');
INSERT INTO Gerou(fk_Atendimento_Codigo_do_contato, fk_Pedido_Codigo_do_pedido) VALUES('20', '101013');
INSERT INTO Gerou(fk_Atendimento_Codigo_do_contato, fk_Pedido_Codigo_do_pedido) VALUES('30', '101010');
INSERT INTO Gerou(fk_Atendimento_Codigo_do_contato, fk_Pedido_Codigo_do_pedido) VALUES('40', '101013');
INSERT INTO Gerou(fk_Atendimento_Codigo_do_contato, fk_Pedido_Codigo_do_pedido) VALUES('50', '101010');

INSERT INTO Tipo_de_funcionario(Codigo_da_funcao, Funcao) VALUES('11','TI');
INSERT INTO Tipo_de_funcionario(Codigo_da_funcao, Funcao) VALUES('12', 'Serviços Auxiliares');
INSERT INTO Tipo_de_funcionario(Codigo_da_funcao, Funcao) VALUES('13', 'Chef');
INSERT INTO Tipo_de_funcionario(Codigo_da_funcao, Funcao) VALUES('14', 'Cozinheiro');
INSERT INTO Tipo_de_funcionario(Codigo_da_funcao, Funcao) VALUES('15', 'Garçom');


INSERT INTO Funcionario(Matricula, Nome, Data_de_nascimento, Telefone, E_mail, Data_de_entrada, Sexo, fk_Restaurante_CNpJ, fk_Tipo_de_funcionario_Codigo_da_funcao) VALUES('45959', 'Laura Caixão', '1990-03-01', '61987653098', 'laura_caixao@mail.com', '2021-11-01', 'F', '09876543000123', '11');
INSERT INTO Funcionario(Matricula, Nome, Data_de_nascimento, Telefone, E_mail, Data_de_entrada, Sexo, fk_Restaurante_CnpJ, fk_Tipo_de_funcionario_Codigo_da_funcao) VALUES('65656', 'Godofredo Quero-Tudo-Que-É-Seu', '1995-07-01', '61976540947', 'godo_qtqs@mail.com', '2022-05-01', 'M', '09876543000124', '12');
INSERT INTO Funcionario(Matricula, Nome, Data_de_nascimento, Telefone, E_mail, Data_de_entrada, Sexo, fk_Restaurante_CNPJ, fk_Tipo_de_funcionario_Codigo_da_funcao) VALUES('54874', 'Caleb Vatore', '1880-11-23', '61954739821', 'caleb_vatore@mail.com', '2019-01-01', 'M', '09876543000125', '13');
INSERT INTO Funcionario(Matricula, Nome, Data_de_nascimento, Telefone, E_mail, Data_de_entrada, Sexo, fk_Restaurante_CNPJ, fk_Tipo_de_funcionario_Codigo_da_funcao) VALUES('65841', 'Zé Marcondes', '1997-02-01', '62965835242', 'marcondes_ze@mail.com', '2020-11-02', 'M', '09876543000126', '14');
INSERT INTO Funcionario(Matricula, Nome, Data_de_nascimento, Telefone, E_mail, Data_de_entrada, Sexo, fk_Restaurante_CNPJ, fk_Tipo_de_funcionario_Codigo_da_funcao) VALUES('65959', 'Eliza Pancakes', '1950-06-13', '62974641534', 'eliza_pancakes@mail.com', '2021-12-02','F', '09876543000124', '15');

