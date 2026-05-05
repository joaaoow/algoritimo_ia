#include <stdio.h>

// Define o tamanho do tabuleiro
// N = 4 significa que um tabuleiro 4x4 e 4 rainhas
#define N 4

//Matriz que representa o tabuleiro
// 0 significa casa vazia
// 1 significa que existe yuma rainha naquela posição
int tabuleiro[N][N] {
    int linha, coluna;

    for (linha = 0, linha < N; linha++){
        for (coluna = 0; coluna < N; coluna++){
            tabuleiro[linha][coluna] = 0;
        }
    }
}

//Limpa o tabuleiro, colocando 0 em todas as posições
void limparTabuleiro() {
    int, coluna, linha;

    for (linha = 0; linha < N; linha ++) {
        for (coluna = 0; coluna < N; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
}


//Mostra tabuleiro nab tela
// Q representa uma rainha
// . representa uma casa vazia
void mostrarTabuleiro(){
    int linha, coluna;

    printf("\nTabuleiro:\n\n");
    printf("   ");

    // Mostra os números das colunas
    for (coluna = 0; coluna < N; coluna++){
        printf("%d", coluna);
    }

    printf("\n");

    // Mostra as linhas e o conteúdo do tabuleiro
    for (linha = 0; linha < N; linha++){
        printf("%d ", linha);

        for (coluna = 0; coluna < N; coluna++){
            if(tabuleiro[linha][coluna] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Verifica se é seguro colocar uma rainha na posicção informada.
int ehSeguro(int linha, int coluna) {
    int i, j;

    // Verifica se já existe rainha na mesma linha
    for (i = 0; i < N; i++) {
        if (tabuleiro[linha][i] == 1) {
            return 0;
        }
    }

    // Verifica se já existe rainha na mesma coluna
    for (i = 0; i < N; i++) {
        if (tabuleiro[i][coluna] == 1) {
            return 0;
        }
    }

    // Verifica a diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 1) {
            return 0;
        }
    }

    // Verifica a diagonal inferior esquerda
    for (i = linha, j = coluna; i < N && j > 0; i++, j--) {
        if(tabuleiro[i][j] == 1) {
            return 0;
        }
    }

    // Verifica a diagonal superior direita
    for (i = linha, j = coluna; i < N && j < N; i--, j++) {
        if (tabuleiro[i][j] == 1) {
            return 0;
        }
    }

    // Verifica a diagonal inferior direita
    for (i = linha, j = coluna; i < N && j < N; i++, j++) {
        if (tabuleiro[i][j] == 1) {
            return 0;
        }
    }

    // Se não encontrou nenhuma rainha atacando, então a posição é segura
    return 1;
}

// Conta quantas rainhas já existem no tabuleiro
int contarRainhas() {
    int linha, coluna, quantidade = 0;

    for (linha = 0; linha < N; linha++) {
        for (coluna = 0; coluna< N; coluna++) {
            if(tabuleiro[linha][coluna] == 1) {
                quantidade++;
            }
        }
    }

    return quantidade;
}

// Função principal do backtracking
// Ela tenta colocar uma rinha em cada coluna
int resolverRainhas(int coluna) {
    int linha;

    // Caso base:
    // Se coluna == N, significa que todas as rainhas
    // foram colocadas com sucesso
    if (coluna == N) {
        return 1;
    }

    // Testa todas as linhas da coluna atual
    for (linha = 0; linha < N; linha++) {
        // Só coloca a rainha se a posição for segura
        if(ehSeguro(linha,coluna)) {
            // Faz a escoilha: coloca a rainha
            tabuleiro[linha][coluna] = 1;

            // Chama funlção novamente para tenta resolver
            // a próxima coluna
            if(resolverRainhas(coluna + 1)) {
                return 1;
            }

            // Se não deu certo, desfaz a escolha
            // Essa é a parte de "voltar" do backtraking
            tabuleiro[linha][coluna] = 0
        }
    }

    // Se nenhuma linha funcionou nessa coluna
    // retorna 0 para indicar falha
    return 0;
}

// Permite que o usuário jogue manualmente,
// escolhendo onde colocar as rainhas
void jogarManual() {
    int linha, coluna;

    limparTabuleiro();

    // O jogo continua enquanto o usuário
    // ainda não colocou todas as rainhas
    while (contarRainhas() < N) {
        mostrarTabuleiro();

        printf("Digite a linha e a coluna para colocar uma rainha: ");
        scanf("%d %d", &linha, &coluna);

        // Verifica se a posição digitada existe no tabuleiro.
        if (linha < 0 || linha >= N || coluna < 0 || coluna >= N) {
            printf("Posicao fora do tabuleiro. Tente novamente.\n");
        }
        // Verifica se já existe rainha naquela casa.
        else if (tabuleiro[linha][coluna] == 1) {
            printf("Ja existe uma rainha nessa posicao.\n");
        }
        // Se a posição for segura, coloca a rainha.
        else if (ehSeguro(linha, coluna)) {
            tabuleiro[linha][coluna] = 1;
            printf("Rainha colocada com sucesso!\n");
        }
        // Se não for segura, a jogada é inválida.
        else {
            printf("Jogada invalida. Essa rainha seria atacada.\n");
        }
    }

    mostrarTabuleiro();
    printf("Parabens! Voce colocou todas as rainhas sem ataques.\n");
}

void mostrarSolucaoAutomatica() {
    limparTabuleiro();

    if(resolverRainhas(0)) {
        printf("\nSolucao encontrada pelo backtracking:\n");
        mostrarTabuleiro();
    } else {
        printf("Nao foi possivel encontrar uma solucao.\n");
    }
}

// Função principal do programa
// Mostra o menu e chama as outras funções
int main() {
    int opcao;

    do {
        printf("=== Jogo das N Rainhas ===\n");
        printf("1 - Jogar manualmente\n");
        printf("2 - Ver solucao automatica\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            jogarManual();
        } else if (opcao == 2) {
            mostrarSolucaoAutomatica();
        } else if (opcao == 3) {
            printf("Encerrando o programa.\n");
        } else {
            printf("Opcao invalida.\n");
        }

        printf("\n");
    } while (opcao != 3);

    return 0;
}

// O backtracking acontece na função resolverRainhas.
// Ela tenta colocar uma rinha em uma posição segura.
// Se conseguir, avança para a prróxima coluna.
// Se no futuro essa escolha não leva a uma solução, ela remove a rainha e tenta outra posição.
// Por isso o algoritimo é chamado de backtracking:
// o algoritimo avança tentando, mas volta quando encontra um caminho errado