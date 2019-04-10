#include <stdio.h>
#include <ctype.h>

int executa_opcao(char comando[]) {
    char aux[64], ficheiro[64], peca[64];
    int linha, coluna, nivel;
    switch(toupper(comando[0])) {
        case 'N':
            sscanf(comando, "%s %s", aux, peca);
            printf("Começar a jogar com a peça %c\n", peca[0]);
            if ((toupper(peca[0])) != 'X' && (toupper(peca[0])) != 'O') {
                printf("A peça %c não é válida\n", peca[0]);
            } else {
                printf("A peça %c é válida\n", peca[0]);
            }
            break;
        case 'L':
            sscanf(comando, "%s %s", aux, ficheiro);
            printf("Ler ficheiro %s\n", ficheiro);
            break;
        case 'E':
            sscanf(comando, "%s %s", aux, ficheiro);
            printf("Escrever ficheiro %s\n", ficheiro);
            break;
        case 'J':
            sscanf(comando, "%s %d %d", aux, &linha, &coluna);
            if (linha >= 1 && linha <= 8 && coluna >= 1 && coluna <= 8)
                printf("Jogar na posição: %d %d\n", linha, coluna);
            else
                printf("Posição inválida\n");
            break;
        case 'S':
            printf("Opção por implementarq\n");
            break;
        case 'H':
        case 'U':
        case 'A':
            sscanf(comando, "%s %s %d", aux, peca, &nivel);
            if (nivel >= 1 && nivel <= 3) {
                printf("No jogo contra bot a jogar com peça %s (nível %d)\n", peca, nivel);

            } else {
                printf("Nível %d inválido\n", nivel);
            }
            break;
        case 'Q':
            break;
        default:
            printf("Comando desconhecido: %s\n", comando);
    }
}

int mostra_menu() {
    printf("Introduza o seu comando:\n\n");
    printf("N <peça>\n");
    printf("L <ficheiro>\n");
    printf("E <ficheiro>\n");
    printf("J <linha> <coluna>\n");
    printf("S\n");
    printf("H\n");
    printf("U\n");
    printf("A <paça> <nível>\n");
    printf("Q\n");
}

int main() {
    char linha[64];
    do {
        mostra_menu();
        fgets(linha, 64, stdin);
        executa_opcao(linha);
    } while (toupper(linha[0]) != 'Q');
    return 0;
}