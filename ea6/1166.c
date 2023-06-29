/*
@author: Jonathas Luis de Sousa
@date: 29/06/2023

TORRE DE HANOI, NOVAMENTE! - 1166

As pessoas pararam de mover discos de uma haste para outra depois que eles
descobriram o número de passos necessários para completar a tarefa. Por outro
lado, elas não pararam de pensar sobre puzzles similares à Torre de Hanoi.
Senhor S, como é conhecido, inventou um pequeno jogo. O jogo consiste de N astes
e um MONTE de bolas. As bolas são numeradas 1,2,3... As bolas parecem comum, mas
na verdade elas são mágicas. Se a soma dos números de duas bolas não for um
quadrado perfeito elas irão se repelir com uma força grande quando estiverem
muito perto, portanto, elas NUNCA podem ser colocadas encostando uma na outra.

O jogador deve colocar uma bola no topo de cada haste por vez. Ele deve primeiro
tentar a bola 1, então a bola 2, depois a bola 3, assim por diante... Se ele
falhar em fazer isto, o jogo termina. O Jogador deve tentar colocar o máximo de
bolas possíveis nas hastes. Você pode ver o exemplo da figura acima, que nos
mostra o melhor resultado possível de se obter utilizando 4 hastes.

Entrada
A primeira linha de entrada contem um único inteiro T (1 ≤ T ≤ 50), indicando o
número de casos de teste Cada caso de teste contém um único inteiro N (1 ≤ N ≤
50), indicando o número de varetas disponíveis.

Saída
Para cada caso de teste da entrada, imprima uma linha contendo um inteiro que
indica o número máximo de bolas que podem ser colocadas. Imprima -1 se um número
infinito de bolas pode ser colocado.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int isQuadradoPerfeito(int);

int main() {
    int T;
    scanf("%i", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%i", &n);

        int varetas[n];
        for (int i = 0; i < n; i++) {  // inicializa vetor
            varetas[i] = 0;
        }

        int contador = 0;
        int bola = 1;
        int indice = 0;
        while (indice < n) {
            if (varetas[indice] == 0 ||
                isQuadradoPerfeito(varetas[indice] + bola)) {
                varetas[indice] = bola;
                bola++;
                contador++;
                indice = 0;
            } else {
                indice++;
            }
        }
        printf("%i\n", contador);
    }
    return 0;
}

int isQuadradoPerfeito(int x) {
    double raiz = sqrt(x);
    return ((raiz - floor(raiz)) == 0);
}