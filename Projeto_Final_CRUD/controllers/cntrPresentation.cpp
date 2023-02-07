#include "cntrPresentation.hpp"
#include <string>
#include <list>

using namespace std;

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CntrAControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="BEM VINDO A REDE DE RESTAURANTES COMIDA DE VOH!";
    char texto2[]="Selecione um dos servicos : ";
    char texto3[]="1 - Acessar sistema";
    char texto4[]="2 - Encerrar execucao do sistema.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                //limpa janela
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: cntrA_CRUD->executar();                       
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

void CntrA_CRUD::executar(){

    // Mensagens a serem apresentadas na tela de seleção de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Create";
    char texto3[]="2 - Read";
    char texto4[]="3 - Update";
    char texto5[]="4 - Delete";
    char texto6[]="5 - Encerrar sessao.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        clear();                                                                                // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: Create();
                    break;
            case 2: Read();
                    break;
            case 3: Update();
                    break;
            case 4: Delete();
                    break;
            case 5: apresentar = false;
                    break;
        }
    }
    return; 
}

//--------------------------------------------------------------------------------------------

bool CntrA_CRUD::Create(){
    char texto1[] ="Selecione qual entidade deseja criar:";
    char texto2[] ="0 - Cliente";
    char texto3[] ="1 - Pedido.";
    char texto4[] ="2 - Restaurante.";
    char texto5[] ="3 - Funcionario.";
    char texto6[] ="4 - Tipo de funcionario.";
    char texto7[] ="5 - Atendimento.";
    char texto8[] ="6 - Item.";
    char texto9[] ="7 - Cancelamento.";
    char texto10[] ="8 - Entregador.";
    char texto11[] ="9 - Tipo de entrega.";
    char texto12[] ="R - Retornar.";            // campo = 34 ou campo 66
    char texto13[]="Sucesso no cadastramento. Digite algo.";
    char texto14[]="Falha no cadastramento. Digite algo.";

    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;                                                                     // Controle de laço.
    echo();                                                                                     // Habilita eco.
    while(apresentar){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);                                                                               // Limpa janela.
        mvprintw(linha/4,coluna/8,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/8,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/8,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/8,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/8,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/8,"%s",texto6);
        mvprintw(linha/4 + 2,coluna/2,"%s",texto7);
        mvprintw(linha/4 + 4,coluna/2,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/2,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/2,"%s",texto10);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/2,"%s",texto11);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/2,"%s",texto12);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        Cliente cliente;
        Pedido pedido;
        Restaurante restaurante;
        Funcionario funcionario;
        Tipo_Funcionario tipo_funcionario;
        Atendimento atendimento;
        Item item;
        Cancelamento cancelamento;
        Entregador entregador;
        Tipo_Entrega tipo_entrega;
        switch(campo){
            case 0:
                cliente = formsCliente();
                if(cntr->createCliente(cliente)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 1:
                pedido = formsPedido();
                if(cntr->createPedido(pedido)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 2:
                restaurante = formsRestaurante();
                if(cntr->createRestaurante(restaurante)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 3:
                funcionario = formsFuncionario();
                if(cntr->createFuncionario(funcionario)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 4:
                tipo_funcionario = formsTipodeFuncionario();
                if(cntr->createTipoFuncionario(tipo_funcionario)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 5:
                atendimento = formsAtendimento();
                if(cntr->createAtendimento(atendimento)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 6:
                item = formsItem();
                if(cntr->createItem(item)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 7:
                cancelamento = formsCancelamento();
                if(cntr->createCancelamento(cancelamento)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 8:
                entregador = formsEntregador();
                if(cntr->createEntregador(entregador)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 9:
                tipo_entrega = formsTipodeEntrega();
                if(cntr->createTipoEntrega(tipo_entrega)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                        box(stdscr, 0, 0);
                    }
                    mvprintw(linha/4 + 2,coluna/4,"%s",texto13);                                               // Informa sucesso.
                    noecho();
                    getch();
                    echo();
                    return true;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"%s",texto14);                                                       // Informa falha.
                noecho();
                getch();
                echo();
                return false;
                break;
            case 34: // R
                apresentar = false;
                break;
            case 66: // r
                apresentar = false;
                break;
        }
    }
    return true;
}

bool CntrA_CRUD::Read(){
    char texto1[] ="Selecione qual entidade deseja ler:";
    char texto2[] ="0 - Cliente";
    char texto3[] ="1 - Pedido.";
    char texto4[] ="2 - Restaurante.";
    char texto5[] ="3 - Funcionario.";
    char texto6[] ="4 - Tipo de funcionario.";
    char texto7[] ="5 - Atendimento.";
    char texto8[] ="6 - Item.";
    char texto9[] ="7 - Cancelamento.";
    char texto10[] ="8 - Entregador.";
    char texto11[] ="9 - Tipo de entrega.";
    char texto12[] ="R - Retornar.";            // campo = 34 ou campo 66

    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;                                                                     // Controle de laço.
    echo();                                                                                     // Habilita eco.
    while(apresentar){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);                                                                               // Limpa janela.
        mvprintw(linha/4,coluna/8,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/8,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/8,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/8,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/8,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/8,"%s",texto6);
        mvprintw(linha/4 + 2,coluna/2,"%s",texto7);
        mvprintw(linha/4 + 4,coluna/2,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/2,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/2,"%s",texto10);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/2,"%s",texto11);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/2,"%s",texto12);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        CPF cpf;
        Cliente cliente;
        switch(campo){
            case 0:
                cpf = pkCliente();
                cliente = cntr->ReadCliente(cpf);
                if (cliente.getNome().getValue() == ""){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                    }
                    box(stdscr, 0, 0);
                    mvprintw(linha/4 + 2,coluna/4,"Erro na consulta. Digite Algo");
                    noecho();
                    campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                    echo();
                    break;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"CPF                   : %s ",cliente.getCPF().getValue().c_str());                                                 // Imprime nome do campo.
                mvprintw(linha/4 + 4,coluna/4,"Nome                  : %s ",cliente.getNome().getValue().c_str());                                                 // Imprime nome do campo.
                mvprintw(linha/4 + 6,coluna/4,"Data de Nascimento    : %s ",cliente.getDataNasc().getValue().c_str());                                                 // Imprime nome do campo.
                mvprintw(linha/4 + 8,coluna/4,"Telefone              : %s ",cliente.getTelefone().getValue().c_str());                                                 // Imprime nome do campo.
                mvprintw(linha/4 + 10,coluna/4,"Email                : %s ",cliente.getEmail().getValue().c_str());                                                // Imprime nome do campo.
                mvprintw(linha/4 + 12,coluna/4,"Data de Cadastro     : %s ",cliente.getDataCadastro().getValue().c_str());                                                // Imprime nome do campo.
                mvprintw(linha/4 + 14,coluna/4,"Cidade               : %s ",cliente.getCidade().getValue().c_str());                                                // Imprime nome do campo.
                mvprintw(linha/4 + 16,coluna/4,"Estado               : %s ",cliente.getEstado().getValue().c_str());                                              // Imprime nome do campo.
                mvprintw(linha/4 + 20,coluna/4,"Digite Algo");
                noecho();
                campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                echo();
                break;
            case 1:
                pkPedido();
                break;
            case 2:
                pkRestaurante();
                break;
            case 3:
                pkFuncionario();
                break;
            case 4:
                pkTipodeFuncionario();
                break;
            case 5:
                pkAtendimento();
                break;
            case 6:
                pkItem();
                break;
            case 7:
                pkCancelamento();
                break;
            case 8:
                pkEntregador();
                break;
            case 9:
                pkTipodeEntrega();
                break;
            case 34: // R
                apresentar = false;
                break;
            case 66: // r
                apresentar = false;
                break;
        }
    }
    return true;
}

bool CntrA_CRUD::Update(){
    char texto1[] ="Selecione qual entidade deseja atualizar:";
    char texto2[] ="0 - Cliente";
    char texto3[] ="1 - Pedido.";
    char texto4[] ="2 - Restaurante.";
    char texto5[] ="3 - Funcionario.";
    char texto6[] ="4 - Tipo de funcionario.";
    char texto7[] ="5 - Atendimento.";
    char texto8[] ="6 - Item.";
    char texto9[] ="7 - Cancelamento.";
    char texto10[] ="8 - Entregador.";
    char texto11[] ="9 - Tipo de entrega.";
    char texto12[] ="R - Retornar.";            // campo = 34 ou campo 66

    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;                                                                     // Controle de laço.
    echo();                                                                                     // Habilita eco.
    while(apresentar){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);                                                                               // Limpa janela.
        mvprintw(linha/4,coluna/8,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/8,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/8,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/8,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/8,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/8,"%s",texto6);
        mvprintw(linha/4 + 2,coluna/2,"%s",texto7);
        mvprintw(linha/4 + 4,coluna/2,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/2,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/2,"%s",texto10);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/2,"%s",texto11);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/2,"%s",texto12);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        CPF cpf;
        Cliente cliente;
        Cliente modificado;
        switch(campo){
            case 0:
                cpf = pkCliente();
                cliente = cntr->ReadCliente(cpf);
                if (cliente.getNome().getValue() == ""){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                    }
                    box(stdscr, 0, 0);
                    mvprintw(linha/4 + 2,coluna/4,"Erro na consulta. Digite Algo");
                    noecho();
                    campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                    echo();
                    break;
                }
                else {
                    modificado = formsClienteUpdate();
                    modificado.setCPF(cliente.getCPF());
                    if (modificado.getNome().getValue() == "")
                        modificado.setNome(cliente.getNome());
                    if (modificado.getDataNasc().getValue() == "")
                        modificado.setDateNasc(cliente.getDataNasc());
                    if (modificado.getTelefone().getValue() == "")
                        modificado.setTelefone(cliente.getTelefone());
                    if (modificado.getEmail().getValue() == "")
                        modificado.setEmail(cliente.getEmail());
                    if (modificado.getDataCadastro().getValue() == "")
                        modificado.setDataCadastro(cliente.getDataCadastro());
                    if (modificado.getCidade().getValue() == "")
                        modificado.setCidade(cliente.getCidade());
                    if (modificado.getEstado().getValue() == "")
                        modificado.setEstado(cliente.getEstado());
                    cntr->DeleteCliente(cliente.getCPF());
                    if (cntr->createCliente(modificado)){
                        clear();
                        if (has_colors()){
                            start_color();
                            init_color(COLOR_CYAN, 930, 910, 850);
                            init_pair(1, COLOR_BLACK, COLOR_CYAN);
                            attron(COLOR_PAIR(1));
                            for (int y = 0; y < linha; y++) {
                                mvhline(y, 0, ' ', coluna);
                            }
                        }
                        box(stdscr, 0, 0);
                        mvprintw(linha/4 + 2,coluna/4,"Atualizacao efetuada com sucesso.");
                        noecho();
                        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                        echo();
                        break;
                    }
                    else {
                        clear();
                        if (has_colors()){
                            start_color();
                            init_color(COLOR_CYAN, 930, 910, 850);
                            init_pair(1, COLOR_BLACK, COLOR_CYAN);
                            attron(COLOR_PAIR(1));
                            for (int y = 0; y < linha; y++) {
                                mvhline(y, 0, ' ', coluna);
                            }
                        }
                        box(stdscr, 0, 0);
                        mvprintw(linha/4 + 2,coluna/4,"Falha na atualizacao.");
                        noecho();
                        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                        echo();
                        break;
                    }
                }
                break;
            case 1:
                formsPedido();
                break;
            case 2:
                formsRestaurante();
                break;
            case 3:
                formsFuncionario();
                break;
            case 4:
                formsTipodeFuncionario();
                break;
            case 5:
                formsAtendimento();
                break;
            case 6:
                formsItem();
                break;
            case 7:
                formsCancelamento();
                break;
            case 8:
                formsEntregador();
                break;
            case 9:
                formsTipodeEntrega();
                break;
            case 34: // R
                apresentar = false;
                break;
            case 66: // r
                apresentar = false;
                break;
        }
    }
    return true;
}

bool CntrA_CRUD::Delete(){
    char texto1[] ="Selecione de qual entidade eh o objeto que deseja deletar:";
    char texto2[] ="0 - Cliente";
    char texto3[] ="1 - Pedido.";
    char texto4[] ="2 - Restaurante.";
    char texto5[] ="3 - Funcionario.";
    char texto6[] ="4 - Tipo de funcionario.";
    char texto7[] ="5 - Atendimento.";
    char texto8[] ="6 - Item.";
    char texto9[] ="7 - Cancelamento.";
    char texto10[] ="8 - Entregador.";
    char texto11[] ="9 - Tipo de entrega.";
    char texto12[] ="R - Retornar.";            // campo = 34 ou campo 66

    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;                                                                     // Controle de laço.
    echo();                                                                                     // Habilita eco.
    while(apresentar){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);                                                                               // Limpa janela.
        mvprintw(linha/4,coluna/8,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/8,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/8,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/8,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/8,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/8,"%s",texto6);
        mvprintw(linha/4 + 2,coluna/2,"%s",texto7);
        mvprintw(linha/4 + 4,coluna/2,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/2,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/2,"%s",texto10);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/2,"%s",texto11);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/2,"%s",texto12);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        CPF cpf;
        switch(campo){
            case 0:
                cpf = pkCliente();
                if (cntr->DeleteCliente(cpf)){
                    clear();
                    if (has_colors()){
                        start_color();
                        init_color(COLOR_CYAN, 930, 910, 850);
                        init_pair(1, COLOR_BLACK, COLOR_CYAN);
                        attron(COLOR_PAIR(1));
                        for (int y = 0; y < linha; y++) {
                            mvhline(y, 0, ' ', coluna);
                        }
                    }
                    box(stdscr, 0, 0);
                    mvprintw(linha/4 + 2,coluna/4,"Cliente deletado com sucesso.");
                    noecho();
                    campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                    echo();
                    break;
                }
                clear();
                if (has_colors()){
                    start_color();
                    init_color(COLOR_CYAN, 930, 910, 850);
                    init_pair(1, COLOR_BLACK, COLOR_CYAN);
                    attron(COLOR_PAIR(1));
                    for (int y = 0; y < linha; y++) {
                        mvhline(y, 0, ' ', coluna);
                    }
                }
                box(stdscr, 0, 0);
                mvprintw(linha/4 + 2,coluna/4,"Erro ao deletar cliente.");
                noecho();
                campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
                echo();
                break;
            case 1:
                pkPedido();
                break;
            case 2:
                pkRestaurante();
                break;
            case 3:
                pkFuncionario();
                break;
            case 4:
                pkTipodeFuncionario();
                break;
            case 5:
                pkAtendimento();
                break;
            case 6:
                pkItem();
                break;
            case 7:
                pkCancelamento();
                break;
            case 8:
                pkEntregador();
                break;
            case 9:
                pkTipodeEntrega();
                break;
            case 34: // R
                apresentar = false;
                break;
            case 66: // r
                apresentar = false;
                break;
        }
    }
    return true;
}

Cliente CntrA_CRUD::formsCliente(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome                  :";
    char texto3[] ="CPF                   :";
    char texto4[] ="Data de nascimento    :";
    char texto6[] ="Cidade                :";
    char texto7[] ="Estado                :";
    char texto8[] ="Telefone              :";
    char texto9[] ="Email                 :";
    char texto10[]="Data de cadastro      :";
    char texto11[]="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo5[80], campo6[80], campo7[80], campo8[80], campo9[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    CPF cpf;
    Data data_nasc;
    Cidade cidade;
    Estado estado;
    Telefone telefone;
    Email email;
    Data data_cad;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto8);                                                // Imprime nome do campo.
    getstr(campo7);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 14,coluna/4,"%s ",texto9);                                                // Imprime nome do campo.
    getstr(campo8);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 16,coluna/4,"%s ",texto10);                                                // Imprime nome do campo.
    getstr(campo9);                                                                             // Lê valor do campo.


    try{
        nome.setValue(string(campo1));
        cpf.setValue(string(campo2));
        data_nasc.setValue(string(campo3));
        cidade.setValue(string(campo5));
        estado.setValue(string(campo6));
        telefone.setValue(string(campo7));
        email.setValue(string(campo8));
        data_cad.setValue(string(campo9));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto11);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Cliente nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Cliente cliente;

    cliente.setNome(nome);
    cliente.setCPF(cpf);
    cliente.setDateNasc(data_nasc);
    cliente.setCidade(cidade);
    cliente.setEstado(estado);
    cliente.setTelefone(telefone);
    cliente.setEmail(email);
    cliente.setDataCadastro(data_cad);

    return cliente;
}

Cliente CntrA_CRUD::formsClienteUpdate(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: (Deixe em branco caso nao queria atualizar)";
    char texto2[] ="Nome                  :";
    char texto4[] ="Data de nascimento    :";
    char texto6[] ="Cidade                :";
    char texto7[] ="Estado                :";
    char texto8[] ="Telefone              :";
    char texto9[] ="Email                 :";
    char texto10[]="Data de cadastro      :";
    char texto11[]="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo3[80], campo5[80], campo6[80], campo7[80], campo8[80], campo9[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Data data_nasc;
    Cidade cidade;
    Estado estado;
    Telefone telefone;
    Email email;
    Data data_cad;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto8);                                                // Imprime nome do campo.
    getstr(campo7);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto9);                                                // Imprime nome do campo.
    getstr(campo8);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 14,coluna/4,"%s ",texto10);                                                // Imprime nome do campo.
    getstr(campo9);                                                                             // Lê valor do campo.


    try{
        nome.setValue(string(campo1));
        data_nasc.setValue(string(campo3));
        cidade.setValue(string(campo5));
        estado.setValue(string(campo6));
        telefone.setValue(string(campo7));
        email.setValue(string(campo8));
        data_cad.setValue(string(campo9));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto11);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Cliente nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Cliente cliente;

    cliente.setNome(nome);
    cliente.setDateNasc(data_nasc);
    cliente.setCidade(cidade);
    cliente.setEstado(estado);
    cliente.setTelefone(telefone);
    cliente.setEmail(email);
    cliente.setDataCadastro(data_cad);

    return cliente;
}



Pedido CntrA_CRUD::formsPedido(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo                  :";
    char texto3[] ="Cidade                  :";
    char texto4[] ="Estado                  :";
    char texto5[] ="Valor Total             :";
    char texto6[] ="Forma de Pagamento      :";
    char texto7[] ="Status do Pedido        :";
    char texto8[] ="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Cidade cidade;
    Estado estado;
    Valor valor_total;
    Forma_pagamento forma;
    Status status;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.


    try{
        codigo.setValue(string(campo1));
        cidade.setValue(string(campo2));
        estado.setValue(string(campo3));
        valor_total.setValue(string(campo4));
        forma.setValue(string(campo5));
        status.setValue(string(campo6));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Pedido nulo;
        return nulo;
    }

    // Instancia e inicializa entidade pedido.

    Pedido pedido;

    pedido.setCodigo(codigo);
    pedido.setCidade(cidade);
    pedido.setEstado(estado);
    pedido.setValorTotal(valor_total);
    pedido.setFormaPagamento(forma);
    pedido.setStatus(status);

    return pedido;
}

Restaurante CntrA_CRUD::formsRestaurante(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="CNPJ                    :";
    char texto3[] ="Endereco                :";
    char texto4[] ="Cidade                  :";
    char texto5[] ="Estado                  :";
    char texto6[] ="Data de cadastro        :";
    char texto7[] ="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    CNPJ cnpj;
    Endereco endereco;
    Cidade cidade;
    Estado estado;
    Data data_cad;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.


    try{
        cnpj.setValue(string(campo1));
        endereco.setValue(string(campo2));
        cidade.setValue(string(campo3));
        estado.setValue(string(campo4));
        data_cad.setValue(string(campo5));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Restaurante nulo;
        return nulo;
    }

    // Instancia e inicializa entidade restaurante.

    Restaurante restaurante;

    restaurante.setCNPJ(cnpj);
    restaurante.setEndereco(endereco);
    restaurante.setCidade(cidade);
    restaurante.setEstado(estado);
    restaurante.setDataCadastro(data_cad);

    return restaurante;
}

Funcionario CntrA_CRUD::formsFuncionario(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome                  :";
    char texto3[] ="Matricula             :";
    char texto4[] ="Data de nascimento    :";
    char texto5[] ="Telefone              :";
    char texto6[] ="Email                 :";
    char texto7[]="Data de entrada        :";
    char texto8[]="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Matricula matricula;
    Data data_nasc;
    Telefone telefone;
    Email email;
    Data data_entrada;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    
    try{
        nome.setValue(string(campo1));
        matricula.setValue(string(campo2));
        data_nasc.setValue(string(campo3));
        telefone.setValue(string(campo4));
        email.setValue(string(campo5));
        data_entrada.setValue(string(campo6));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Funcionario nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Funcionario funcionario;

    funcionario.setNome(nome);
    funcionario.setMatricula(matricula);
    funcionario.setDateNasc(data_nasc);
    funcionario.setTelefone(telefone);
    funcionario.setEmail(email);
    funcionario.setDataEntrada(data_entrada);

    return funcionario;
}

Tipo_Funcionario CntrA_CRUD::formsTipodeFuncionario(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo da funcao    :";
    char texto3[] ="Funcao              :";
    char texto4[] ="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Funcao funcao;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    try{
        codigo.setValue(string(campo1));
        funcao.setValue(string(campo2));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Tipo_Funcionario nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Tipo_Funcionario tipo_funcionario;

    tipo_funcionario.setCodigo(codigo);
    tipo_funcionario.setFuncao(funcao);

    return tipo_funcionario;
}

Atendimento CntrA_CRUD::formsAtendimento(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo do contato    :";
    char texto3[] ="Motivo               :";
    char texto4[] ="Nota                 :";
    char texto5[] ="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Motivo motivo;
    Nota nota;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);    
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                          // Lê valor do campo.
    try{
        codigo.setValue(string(campo1));
        motivo.setValue(string(campo2));
        nota.setValue(string(campo3));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto5);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Atendimento nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Atendimento atendimento;

    atendimento.setCodigo(codigo);
    atendimento.setMotivo(motivo);
    atendimento.setNota(nota);

    return atendimento;
}

Item CntrA_CRUD::formsItem(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome                  :";
    char texto3[] ="Valor unitario        :";
    char texto4[] ="Quantidade            :";
    char texto5[] ="Codigo do item        :";
    char texto6[]="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Valor valor_unitario;
    Quantidade quantidade;
    Codigo codigo;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.                                                                             // Lê valor do campo.
    
    try{
        nome.setValue(string(campo1));
        valor_unitario.setValue(string(campo2));
        quantidade.setValue(string(campo3));
        codigo.setValue(string(campo4));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto6);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Item nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Item item;

    item.setNome(nome);
    item.setValorUnitario(valor_unitario);
    item.setQuantidade(quantidade);
    item.setCodigo(codigo);

    return item;
}

Cancelamento CntrA_CRUD::formsCancelamento(){
     // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo do cancelamento    :";
    char texto3[] ="Motivo                    :";
    char texto4[] ="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Motivo motivo;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    try{
        codigo.setValue(string(campo1));
        motivo.setValue(string(campo2));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Cancelamento nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Cancelamento cancelamento;

    cancelamento.setCodigo(codigo);
    cancelamento.setMotivo(motivo);

    return cancelamento;
}

Entregador CntrA_CRUD::formsEntregador(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome                  :";
    char texto3[] ="Codigo do entregador  :";
    char texto4[] ="Data de nascimento    :";
    char texto5[] ="Cidade                :";
    char texto6[] ="Estado                :";
    char texto7[] ="Telefone              :";
    char texto8[] ="Email                 :";
    char texto9[] ="Data de entrada       :";
    char texto10[]="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80], campo7[80], campo8[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Codigo codigo;
    Data data_nasc;
    Cidade cidade;
    Estado estado;
    Telefone telefone;
    Email email;
    Data data_ent;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 14,coluna/4,"%s ",texto8);                                                // Imprime nome do campo.
    getstr(campo7);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 16,coluna/4,"%s ",texto9);                                                // Imprime nome do campo.
    getstr(campo8);                                                                             // Lê valor do campo.                                                                  


    try{
        nome.setValue(string(campo1));
        codigo.setValue(string(campo2));
        data_nasc.setValue(string(campo3));
        cidade.setValue(string(campo4));
        estado.setValue(string(campo5));
        telefone.setValue(string(campo6));
        email.setValue(string(campo7));
        data_ent.setValue(string(campo8));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Entregador nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Entregador entregador;

    entregador.setNome(nome);
    entregador.setCodigo(codigo);
    entregador.setDateNasc(data_nasc);
    entregador.setCidade(cidade);
    entregador.setEstado(estado);
    entregador.setTelefone(telefone);
    entregador.setEmail(email);
    entregador.setDataEntrada(data_ent);

    return entregador;
}

Tipo_Entrega CntrA_CRUD::formsTipodeEntrega(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo do transporte      :";
    char texto3[] ="Modelo                    :";
    char texto4[] ="Dados em formato incorreto. Digite algo.";

    char campo1[80], campo2[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Modelo modelo;


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    try{
        codigo.setValue(string(campo1));
        modelo.setValue(string(campo2));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        Tipo_Entrega nulo;
        return nulo;
    }

    // Instancia e inicializa entidade cliente.

    Tipo_Entrega tipo_entrega;

    tipo_entrega.setCodigo(codigo);
    tipo_entrega.setModelo(modelo);

    return tipo_entrega;
}

//-------------------------------------------------------------------------------------------------------------------------------

CPF CntrA_CRUD::pkCliente(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Digite o CPF do cliente: ";
    char texto2[] ="CPF                   :";
    char texto3[]="Dados em formato incorreto. Digite algo.";

    char campo1[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    CPF cpf;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de leitura

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.


    try{
        cpf.setValue(string(campo1));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();
        CPF nulo;                                                                                 // Habilita eco.
        return nulo;
    }

    return cpf;
}

Codigo CntrA_CRUD::pkPedido(){
    Codigo codigo;
    return codigo;
}

CNPJ CntrA_CRUD::pkRestaurante(){
    CNPJ cnpj;
    return cnpj;
}

Codigo CntrA_CRUD::pkFuncionario(){
    Codigo codigo;
    return codigo;
}

Codigo CntrA_CRUD::pkTipodeFuncionario(){
    Codigo codigo;
    return codigo;
}

Codigo CntrA_CRUD::pkAtendimento(){
    Codigo codigo;
    return codigo;
}

Codigo CntrA_CRUD::pkItem(){
    Codigo codigo;
    return codigo;
}

Codigo CntrA_CRUD::pkCancelamento(){
    Codigo codigo;
    return codigo;
}

Codigo CntrA_CRUD::pkEntregador(){
    Codigo codigo;
    return codigo;
}

Codigo CntrA_CRUD::pkTipodeEntrega(){
    Codigo codigo;
    return codigo;
}