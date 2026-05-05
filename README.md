# Jogo das N Rainhas com Backtracking

Este projeto implementa o problema das N Rainhas em linguagem C.
O programa funciona como um jogo simples no terminal, onde o usuário pode tentar posicionar as rainhas manualmente ou pedir para o algoritmo encontrar uma solução automaticamente.

## O que é backtracking

Backtracking é uma técnica usada para resolver problemas testando possibilidades passo a passo.

A ideia principal é:

1. Fazer uma escolha.
2. Verificar se essa escolha é valida.
3. Avançar para a proxima etapa.
4. Se em algum momento o caminho não funcionar, voltar e desfazer a escolha.
5. Tentar outra possibilidade.

Por isso o nome backtracking pode ser entendido como "voltar atras".
O algoritmo avaça enquanto encontra caminhos validos, mas volta quando percebe que uma escolha não leva a uma solução.

## Como o backtracking aparece no projeto

No projeto das N Rainhas, o objetivo e colocar N rainhas em um tabuleiro NxN sem que uma rainha ataque a outra.

Uma rainha pode atacar:

- Na mesma linha.
- Na mesma coluna.
- Nas diagonais.

O backtracking tenta colocar uma rainha em cada coluna.
Quando encontra uma posição segura, coloca a rainha e tenta resolver a proxima coluna.
Se depois não conseguir completar o tabuleiro, remove a rainha e tenta outra linha.

O trecho principal e:

```c
tabuleiro[linha][coluna] = 1;

if (resolverRainhas(coluna + 1)) {
    return 1;
}

tabuleiro[linha][coluna] = 0;
```

Esse trecho significa:

- Colocar a rainha.
- Tentar resolver o restante do tabuleiro.
- Se nao der certo, remover a rainha e tentar outro caminho.

## Funcoes do codigo

### `limparTabuleiro`

Limpa o tabuleiro, colocando o valor `0` em todas as posicoes.
O valor `0` representa uma casa vazia.

### `mostrarTabuleiro`

Mostra o tabuleiro na tela.
O programa usa:

- `Q` para representar uma rainha.
- `.` para representar uma casa vazia.

### `ehSeguro`

Verifica se e seguro colocar uma rainha em uma determinada linha e coluna.

Essa funcao confere se ja existe alguma rainha:

- Na mesma linha.
- Na mesma coluna.
- Nas diagonais.

Se a posicao for segura, retorna `1`.
Se a posicao nao for segura, retorna `0`.

### `contarRainhas`

Conta quantas rainhas ja foram colocadas no tabuleiro.
Essa funcao e usada no modo manual para saber quando o jogador conseguiu colocar todas as rainhas.

### `resolverRainhas`

E a funcao principal do backtracking.

Ela tenta colocar uma rainha na coluna atual.
Se encontrar uma posicao segura, coloca a rainha e chama a si mesma para resolver a proxima coluna.
Se a escolha nao levar a uma solucao, remove a rainha e tenta outra posicao.

### `jogarManual`

Permite que o usuario jogue manualmente.
O usuario digita a linha e a coluna onde deseja colocar uma rainha.
O programa verifica se a jogada e valida antes de aceitar.

### `mostrarSolucaoAutomatica`

Limpa o tabuleiro e chama a funcao `resolverRainhas` para encontrar uma solucao automaticamente.
Depois mostra a solucao encontrada na tela.

### `main`

E a funcao principal do programa.
Ela mostra o menu com as opcoes:

- Jogar manualmente.
- Ver solucao automatica.
- Sair do programa.

## Como compilar e executar

Para compilar:

```bash
gcc main.c -o main.exe
```

Para executar no Windows:

```bash
./main.exe
```

Ou no PowerShell:

```powershell
.\main.exe
```
