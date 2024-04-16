#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

#ifdef _WIN32
    #define PAUSE_COMMAND "pause"
#else
    #define PAUSE_COMMAND "read -p 'Pressione Enter para continuar...'"
#endif

using namespace std;

void menuJogoDaVelha();
void jogo(char tabuleiro[3][3]);

void criacaoTabuleiro(char tabuleiro[3][3]) {
    
    int linha, coluna;
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {

            tabuleiro[linha][coluna] = ' ';
        }
    }
}

void mostrarTabuleiro(char tabuleiro[3][3]) {

    cout << "\n   0   1   2 \n";

    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {

            
            if (coluna == 0) {
                cout << linha << "  ";
            }

            cout << tabuleiro[linha][coluna];
            if (coluna < 2) cout << " | ";
        }
        cout << endl;
        if (linha < 2) cout << "   ---------" << endl;
    }
    cout << endl;
}

bool verificarVitoria(char tabuleiro[3][3], char jogador) {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return true;
        }
    }

    // Verifica diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return true;
    }

    return false;
}

bool tabuleiroCheio(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[linha][coluna] == ' ') {
                return false; // Ainda há espaços vazios no tabuleiro
            }
        }
    }
    return true; // O tabuleiro está cheio
}

void jogo(char tabuleiro[3][3]) {
    int linha, coluna;
    char jogador = 'X';
    int opcao;

    while (true) {
        system("clear");
        cout << "Jogador " << jogador << ", e sua vez!\n";

        mostrarTabuleiro(tabuleiro);

        cout << "\nDigite o numero da linha: ";
        cin >> linha;

        cout << "Digite o numero da coluna: ";
        cin >> coluna;

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador;

            if (verificarVitoria(tabuleiro, jogador)) {

                while (opcao < 1 || opcao > 3) {
                    system("clear");
                    mostrarTabuleiro(tabuleiro);
                    cout << "Parabens! Jogador " << jogador << " venceu!\n";

                    cout << "\nEscolha uma Opcao:";
                    cout << "\n 1 - Jogar Novamente";
                    cout << "\n 2 - Voltar Para o Menu";
                    cout << "\n 3 - Sair";
                    cout << "\n";
                    cin >> opcao;
                }

                break;
            } else if (tabuleiroCheio(tabuleiro)) {

                while (opcao < 1 || opcao > 3) {
                    system("clear");
                    mostrarTabuleiro(tabuleiro);
                    cout << "O jogo empatou!\n";

                    cout << "\nEscolha uma Opcao:";
                    cout << "\n 1 - Jogar Novamente";
                    cout << "\n 2 - Voltar Para o Menu";
                    cout << "\n 3 - Sair";
                    cout << "\n";
                    cin >> opcao;
                }
                break;
            }

            jogador = (jogador == 'X') ? 'O' : 'X'; // Alternar entre X e O
        }    
    }

    switch (opcao) {
        case 1:
            criacaoTabuleiro(tabuleiro);
            jogo(tabuleiro);
            break;
        case 2:
            cout << "Voltando para o Menu...";
            menuJogoDaVelha();
            break;
    }
}

void menuJogoDaVelha() {

    int opcao;
    char tabuleiro[3][3];
    while (opcao < 1 || opcao > 3) {

        system("clear");
        cout << "===============================" << endl;
        cout << "           _._______           " << endl;
        cout << "          | _______ |          " << endl;
        cout << "          ||,-----.||          " << endl;
        cout << "          |||     |||          " << endl;
        cout << "          |||_____|||          " << endl;
        cout << "          |`-------'|          " << endl;
        cout << "          | +     O |          " << endl;
        cout << "          |      O  |          " << endl;
        cout << "          | / /  ##,\"         " << endl;
        cout << "           `------\"           " << endl;
        cout << "===============================" << endl;

        cout << "| Bem Vindo ao Jogo Da Velha! |" << endl;;
        cout << "|  1 - Jogar                  |" << endl;
        cout << "|  2 - Sobre                  |" << endl;
        cout << "|  3 - Sair                   |" << endl;
        cout << "===============================" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                criacaoTabuleiro(tabuleiro);
                jogo(tabuleiro);

                break;
            
            case 2:
                system("clear");
                cout << "O Jogo da Velha e um jogo de estrategia simples e popular para dois jogadores, que se \n";
                cout << "alternam marcando X e O em uma grade 3x3. O objetivo e conseguir uma linha, coluna ou \n";
                cout << "diagonal completa com suas marcacoes antes do adversario. ";
                cout << "\n\n";

                system(PAUSE_COMMAND);

                menuJogoDaVelha();
                break;
        }
    }
}

void JogoDaVelha() {
    srand(static_cast<unsigned>(time(NULL)));

    menuJogoDaVelha();
}
