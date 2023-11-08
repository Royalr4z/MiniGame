#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela() {
    system("cls");
}

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

void jogo(char tabuleiro[3][3], int i) {

    int linha, coluna;

    while (((linha < 0 || coluna < 0 ) || (linha > 2 || coluna > 2)) || (tabuleiro[linha][coluna] != ' ')) {
        limpaTela();

        cout << "Bem Vindo ao Jogo!\n"; 

        mostrarTabuleiro(tabuleiro);

        cout << "\nDigite o Numero da linha: \n";
        cin >> linha;

        cout << "\nDigite o Numero da Coluna: \n";
        cin >> coluna;
    }

    if (i == 1) {
        tabuleiro[linha][coluna] = 'X';
        i = 2;
    } else if (i == 2) {
        tabuleiro[linha][coluna] = 'O';
        i = 1;
    }

    jogo(tabuleiro, i);
}


void menuInicial() {

    int opcao;
    char tabuleiro[3][3];
    while (opcao < 1 || opcao > 3) {

        limpaTela();
        cout << "Bem Vindo ao Jogo Da Velha!";
        cout << "\n 1 - Jogar";
        cout << "\n 2 - Sobre";
        cout << "\n 3 - Sair";
        cout << "\n\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                criacaoTabuleiro(tabuleiro);
                jogo(tabuleiro, 1);

                break;
            
            case 2:
                limpaTela();
                cout << "O Jogo da Velha e um jogo de estratégia simples e popular para dois jogadores, que se \n";
                cout << "alternam marcando X e O em uma grade 3x3. O objetivo é conseguir uma linha, coluna ou \n";
                cout << "diagonal completa com suas marcações antes do adversário. ";
                cout << "\n\n";

                system("PAUSE");

                menuInicial();
                break;
        }
    }
}

void JogoDaVelha() {
    srand(static_cast<unsigned>(time(NULL)));

    menuInicial();
}
