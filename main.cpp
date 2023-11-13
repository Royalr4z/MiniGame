#include <stdio.h>
#include <iostream>

#include "Games/batalhaNaval.cpp"
#include "Games/jogoDaVelha.cpp"

int main() {

    int opcao = 0;
    while (opcao < 1 || opcao > 3) {
        system("cls");
        std::cout << "O que Deseja Jogar? ";
        std::cout << "\n  1 - Batalha Naval";
        std::cout << "\n  2 - Jogo Da Velha";
        std::cout << "\n  3 - Jogo da Forca";
        std::cout << "\n";
        std::cin >> opcao;
    }

    switch (opcao) {
        case 1:
            BatalhaNaval();
            break;
        case 2:
            JogoDaVelha();
            break;
        case 3:
            system("cls");
            std::cout << "\n 3 - Jogo da Forca Indisponivel no momento!\n";
            break;

    }

    return 0;
}