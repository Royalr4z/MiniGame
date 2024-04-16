#include <stdio.h>
#include <iostream>

#include "Games/batalhaNaval.cpp"
#include "Games/jogoDaVelha.cpp"
#include "Games/jogoDaForca.cpp"

int main() {

    int opcao = 0;
    while (opcao < 1 || opcao > 3) {
        system("clear");
        std::cout << "================================== " << std::endl;
        std::cout << "    ________________               " << std::endl;
        std::cout << "   |   |,\"    `.|   |             " << std::endl;
        std::cout << "   |   /  SONY  \\   |             " << std::endl;
        std::cout << "   |O _\\   />   /_  |   ___ _     " << std::endl;
        std::cout << "   |_(_)'.____.'(_)_|  (\")__(\")  " << std::endl;
        std::cout << "   [___|[=]__[=]|___]  //    \\\\  " << std::endl;
        std::cout << "================================== " << std::endl;

        std::cout << "| O que Deseja Jogar? |" << std::endl;
        std::cout << "|   1 - Batalha Naval |" << std::endl;
        std::cout << "|   2 - Jogo Da Velha |" << std::endl;
        std::cout << "|   3 - Jogo da Forca |" << std::endl;
        std::cout << "=======================" << std::endl;
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
            JogoDaForca();
            break;

    }

    return 0;
}