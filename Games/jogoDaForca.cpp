#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

void menuJogoDaForca();

// Função para imprimir a forca atual
void imprimirForca(int tentativas) {
    switch (tentativas) {
    case 0:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 1:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 2:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 3:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 4:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        break;
    case 5:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " /    |" << endl;
        cout << "      |" << endl;
        break;
    case 6:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        cout << "      |" << endl;
        break;
    }
}

// Função para imprimir a palavra atual com as letras adivinhadas
void imprimirPalavra(const string& palavra, const string& letrasAdivinhadas) {
    for (char letter : palavra) {
        if (letrasAdivinhadas.find(letter) != string::npos) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Função para verificar se a letra está na palavra
bool letraNaPalavra(char letra, const string& palavra) {
    return (palavra.find(letra) != string::npos);
}

void jogo() {
    // Lista de palavras para o jogo
    string palavras[] = {"programacao", "computador", "linguagem", "desenvolvimento", "software", "hardware"};

    // Escolher uma palavra aleatória
    srand(static_cast<unsigned int>(time(0)));
    int indiceAleatorio  = rand() % (sizeof(palavras) / sizeof(palavras[0]));
    string palavraSelecionada = palavras[indiceAleatorio];

    int maxTentativas = 6;
    int tentativas = 0;
    string letrasAdivinhadas;
    int opcao;

    cout << "Bem-vindo ao Jogo da Forca!" << endl;

    while (tentativas < maxTentativas) {
        system("cls");

        // Imprimir a forca e a palavra atual
        imprimirForca(tentativas);
        imprimirPalavra(palavraSelecionada, letrasAdivinhadas);

        // Pedir ao jogador para adivinhar uma letra
        cout << "Digite uma letra: ";
        char palpite;
        cin >> palpite;

        // Verificar se a letra já foi adivinhada
        if (letrasAdivinhadas.find(palpite) != string::npos) {
            cout << "Voce ja tentou essa letra. Tente novamente." << endl;
            continue;
        }

        // Adicionar a letra às letras adivinhadas
        letrasAdivinhadas += palpite;

        // Verificar se a letra está na palavra
        if (letraNaPalavra(palpite, palavraSelecionada)) {
            cout << "Correto! A letra esta na palavra." << endl;
        } else {
            system("cls");
            cout << "Incorreto! Tente novamente." << endl;
            tentativas++;
        }

        // Verificar se o jogador ganhou
        bool palavraAdivinhada = all_of(palavraSelecionada.begin(), palavraSelecionada.end(), [&letrasAdivinhadas](char letra) {
            return letrasAdivinhadas.find(letra) != string::npos;
        });

        if (palavraAdivinhada) {

            while (opcao < 1 || opcao > 3) {
                system("cls");

                cout << "\x1b[33m" << "Parabens! " << "\x1b[0m" << "Voce adivinhou a palavra: " << palavraSelecionada << endl;
                imprimirForca(tentativas);

                cout << "\nEscolha uma Opcao:";
                cout << "\n 1 - Jogar Novamente";
                cout << "\n 2 - Voltar Para o Menu";
                cout << "\n 3 - Sair";
                cout << "\n";
                cin >> opcao;
            }

            switch (opcao) {
                case 1:
                    jogo();
                    break;
                case 2:
                    cout << "Voltando para o Menu";
                    menuJogoDaForca();
                    break;
            }

            break;
        }
    }

    // Se o jogador atingir o número máximo de tentativas
    if (tentativas == maxTentativas) {

        while (opcao < 1 || opcao > 3) {
            system("cls");

            cout << "\x1b[31m" << "Voce perdeu! " << "\x1b[0m" << "A palavra correta era: " << palavraSelecionada << endl;
            imprimirForca(tentativas);

            cout << "\nEscolha uma Opcao:";
            cout << "\n 1 - Jogar Novamente";
            cout << "\n 2 - Voltar Para o Menu";
            cout << "\n 3 - Sair";
            cout << "\n";
            cin >> opcao;
        }

        
        switch (opcao) {
            case 1:
                jogo();
                break;
            case 2:
                cout << "Voltando para o Menu";
                menuJogoDaForca();
                break;
        }
    }

}

void menuJogoDaForca() {
    int opcao;

    while (opcao < 1 || opcao > 3) {

        system("cls");
        cout << "Bem Vindo ao Jogo Da Forca!";
        cout << "\n 1 - Jogar";
        cout << "\n 2 - Sobre";
        cout << "\n 3 - Sair";
        cout << "\n\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                jogo();
                break;
            
            case 2:
                system("cls");
                cout << "No jogo da forca solo, o jogador desafia o computador, que escolhe uma palavra secreta. \n";
                cout << "O objetivo e adivinhar a palavra por meio de tentativas de letras, com um numero limitado de \n";
                cout << "erros permitidos. A emocao reside na busca pela palavra certa enquanto se evita exceder o  \n";
                cout << "limite de erros. ";
                cout << "\n\n";

                system("PAUSE");

                menuJogoDaForca();
                break;
        }
    }
}


void JogoDaForca() {
    srand(static_cast<unsigned>(time(NULL)));

    menuJogoDaForca();
}