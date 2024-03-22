#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void menuBatalhaNaval();

void indexEixoX() {
    int i;

    for (i = 0; i < 10; i++) {
        if (i == 0) {
            cout << "    "; 
        }
        cout << " " << i;
    }

    cout << "\n";
}

void mostrarTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostrarGabarito) {

    int linha, coluna;

    indexEixoX();

    for (linha = 0; linha < 10; linha++) {

        cout << linha << " - ";

        for (coluna = 0; coluna < 10; coluna++) {
            switch (mascara[linha][coluna]) {
                case 'A':

                    cout << " " << "\x1b[34m" << mascara[linha][coluna] << "\x1b[0m";
                    break;
                case 'P':
                
                    cout << " " << "\x1b[32m" << mascara[linha][coluna] << "\x1b[0m";
                    break;
                case 'M':
                
                    cout << " " << "\x1b[33m" << mascara[linha][coluna] << "\x1b[0m";
                    break;
                case 'G':
                
                    cout << " " << "\x1b[31m" << mascara[linha][coluna] << "\x1b[0m";
                    break;
                default:
                    cout  << " " << mascara[linha][coluna];
                    break;
            }
        }
        cout << "\n";
    }

    cout << "\n";

    if (mostrarGabarito) {

        indexEixoX();

        for (linha = 0; linha < 10; linha++) {

            cout << linha << " - ";

            for (coluna = 0; coluna < 10; coluna++) {

                if (tabuleiro[linha][coluna] == mascara[linha][coluna]) {
                    cout << " " << "\x1b[41m" << tabuleiro[linha][coluna] << "\x1b[0m";
                } else if (tabuleiro[linha][coluna] == 'A') {
                    cout << " " << "\x1b[34m" << tabuleiro[linha][coluna] << "\x1b[0m";
                } else if (tabuleiro[linha][coluna] == 'M') {
                    cout << " " << "\x1b[33m" << tabuleiro[linha][coluna] << "\x1b[0m";
                } else if (tabuleiro[linha][coluna] == 'G') {
                    cout << " " << "\x1b[31m" << tabuleiro[linha][coluna] << "\x1b[0m";
                } else {
                    cout << " " << "\x1b[32m" << tabuleiro[linha][coluna] << "\x1b[0m";
                }
            }
            cout << "\n";
        }
    }
}

void criacaoTabuleiro(char tabuleiro[10][10], char mascara[10][10]) {
    int linha, coluna, i;

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }

    for (i = 0; i < 6;) {
        int linhaAleotoria = rand() % 10;
        int colunaAleotoria = rand() % 10;

        if (tabuleiro[linhaAleotoria][colunaAleotoria] == 'A') {
            tabuleiro[linhaAleotoria][colunaAleotoria] = 'P';
            i++;
        }
    }

    for (i = 0; i < 4;) {
        int linhaAleotoria = rand() % 10;
        int colunaAleotoria = rand() % 10;

        if (tabuleiro[linhaAleotoria][colunaAleotoria] == 'A' and\
            tabuleiro[linhaAleotoria][colunaAleotoria + 1] == 'A' and colunaAleotoria + 1 <= 9) {

            tabuleiro[linhaAleotoria][colunaAleotoria] = 'M';
            tabuleiro[linhaAleotoria][colunaAleotoria + 1] = 'M';
            i++;
        }
    }

    for (i = 0; i < 2;) {
        int linhaAleotoria = rand() % 10;
        int colunaAleotoria = rand() % 10;

        if (tabuleiro[linhaAleotoria][colunaAleotoria] == 'A' and\
            tabuleiro[linhaAleotoria][colunaAleotoria + 1] == 'A' and colunaAleotoria + 1 <= 9 and\
            tabuleiro[linhaAleotoria][colunaAleotoria + 2] == 'A' and colunaAleotoria + 2 <= 9) {

            tabuleiro[linhaAleotoria][colunaAleotoria] = 'G';
            tabuleiro[linhaAleotoria][colunaAleotoria + 1] = 'G';
            tabuleiro[linhaAleotoria][colunaAleotoria + 2] = 'G';
            i++;
        }
    }
}

void jogo(char tabuleiro[10][10], char mascara[10][10], int tentativas = 0, int pontos = 0, int msg = 0) {

    int limiteTentativas = 20;
    int linha = -1;
    int coluna = -1;
    int opcao;

    if (limiteTentativas == tentativas) {

        while (opcao < 1 || opcao > 3) {
            system("clear");

            cout << "Voce Conseguiu: " << "\x1b[33m" << pontos << " Pontos\n\n" << "\x1b[0m";
            mostrarTabuleiro(tabuleiro, mascara, true);

            cout << "\nEscolha uma Opcao:";
            cout << "\n 1 - Jogar Novamente";
            cout << "\n 2 - Voltar Para o Menu";
            cout << "\n 3 - Sair";
            cout << "\n";
            cin >> opcao;
        }
        
        switch (opcao) {
            case 1:
                criacaoTabuleiro(tabuleiro, mascara);
                jogo(tabuleiro, mascara, 0, 0);
                break;
            case 2:
                cout << "Voltando para o Menu";
                menuBatalhaNaval();
                break;
        }

    } else {
        while((linha < 0 || coluna < 0) || (linha > 9 || coluna > 9) || (mascara[linha][coluna] != '*')) {
            system("clear");

            if (msg == 1) {
                cout << "\x1b[32m" "Acertou!" << "\x1b[0m" << "\n";
            } else if (msg == 2) {
                cout << "\x1b[31m" "Errou!" << "\x1b[0m" << "\n";
            } else if (msg == 0) {
                cout << "Bem Vindo ao Jogo!\n";
            }
            
            cout << "Tentativas Restantes: " << limiteTentativas - tentativas << "\n";
            cout << "\x1b[33m" << pontos << " Pts\n\n" << "\x1b[0m";
            mostrarTabuleiro(tabuleiro, mascara, false);

            cout << "\nDigite o Numero da linha: \n";
            cin >> linha;

            cout << "\nDigite o Numero da Coluna: \n";
            cin >> coluna;
        }

        mascara[linha][coluna] = tabuleiro[linha][coluna];

        if (mascara[linha][coluna] == 'P') {

            pontos = pontos + 5;
            jogo(tabuleiro, mascara, tentativas + 1, pontos, 1);
        } else if (mascara[linha][coluna] == 'M') {

            pontos = pontos + 10;
            jogo(tabuleiro, mascara, tentativas + 1, pontos, 1);
        } else if (mascara[linha][coluna] == 'G') {

            pontos = pontos + 20;
            jogo(tabuleiro, mascara, tentativas + 1, pontos, 1);
        } else if (mascara[linha][coluna] == 'A') {

            jogo(tabuleiro, mascara, tentativas + 1, pontos, 2);
        }


    }

}

void menuBatalhaNaval() {

    int opcao;
    char tabuleiro[10][10], mascara[10][10];
    while (opcao < 1 || opcao > 3) {

        system("clear");
        cout << "Bem Vindo a Batalha Naval!";
        cout << "\n 1 - Jogar";
        cout << "\n 2 - Sobre";
        cout << "\n 3 - Sair";
        cout << "\n\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                criacaoTabuleiro(tabuleiro, mascara);
                jogo(tabuleiro, mascara);

                break;
            
            case 2:
                system("clear");
                cout << "O jogo da Batalha Naval, jogado sozinho, e uma versao de estrategia em que o objetivo e \n";
                cout << "localizar e destruir navios inimigos ocultos em uma grade de quadrados. O jogador \n";
                cout << "posiciona seus proprios navios em uma grade, e o computador aleatoriamente posiciona a \n";
                cout << "frota inimiga.";
                cout << "\n\n";

                system("PAUSE");

                menuBatalhaNaval();
                break;
        }
    }
}

void BatalhaNaval() {
    srand(static_cast<unsigned>(time(NULL)));

    menuBatalhaNaval();
}

