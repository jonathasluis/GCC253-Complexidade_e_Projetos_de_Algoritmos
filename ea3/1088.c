#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@author: Jonathas Luis de Sousa
@date: 25/05/2023

BOLHAS E BALDES - 1088

Andrea, Carlos e Marcelo são muito amigos e passam todos os finais de semana à
beira da piscina. Enquanto Andrea se bronzeia ao sol, os dois ficam jogando
Bolhas. Andrea, uma cientista da computação muito esperta, já disse a eles que
não entende por que passam tanto tempo jogando um jogo tão primário.

Usando o computador portátil dela, os dois geram um inteiro aleatório N e uma
seqüência de inteiros, também aleatória, que é uma permutação de 1, 2, . . . ,N.

O jogo então começa, cada jogador faz um movimento, e a jogada passa para o
outro jogador. Marcelo é sempre o primeiro a começar a jogar. Um movimento de um
jogador consiste na escolha de um par de elementos consecutivos da seqüência que
estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo,
dada a seqüência 1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou
de 4 e 2, mas não pode inverter as posições de 3 e 4, nem de 5 e 2. Continuando
com o exemplo, se o jogador decide inverter as posições de 5 e 3 então a nova
seqüência será 1, 3, 5, 4, 2.

Mais cedo ou mais tarde, a seqüência ficará ordenada. Perde o jogador
impossibilitado de fazer um movimento. Andrea, com algum desdém, sempre diz que
seria mais simples jogar cara ou coroa, com o mesmo efeito. Sua missão, caso
decida aceitá-la, é determinar quem ganha o jogo, dada a seqüência inicial.

Entrada
A entrada contém vários casos de teste. Os dados de cada caso de teste estão
numa única linha, e são inteiros separados por um espaço em branco. Cada linha
contém um inteiroN (2 ≤ N ≤ 105), seguido da seqüência inicial P = (X1, X2,
...,XN) de N inteiros distintos dois a dois, onde1 ≤ Xi ≤ N para 1 ≤ i ≤ N.

O final da entrada é indicado por uma linha que contém apenas o número zero.

Saída
Para cada caso de teste da entrada seu programa deve imprimir uma única linha,
com o nome do vencedor, igual a Carlos ou Marcelo., sem espaços em branco.
*/



void mergeSort(int *, int, int *);
void intercala(int *, int, int *);

int main() {
    int n;
    while (scanf("%i", &n) && n != 0) {
        int trocas = 0;
        int entrada[n];
        char *ganhador;

        for (int i = 0; i < n; i++) {
            scanf("%i", &entrada[i]);
        }

        mergeSort(entrada, n, &trocas);

        if (trocas % 2 == 0) {
            ganhador = "Carlos";
        } else {
            ganhador = "Marcelo";
        }
        printf("%s\n", ganhador);
    }
    return 0;
}

void mergeSort(int *a, int n, int *result) {
    if (n > 1) {
        int meio = n >> 1;
        mergeSort(a, meio, result);
        mergeSort(a + meio, (n + 1) >> 1, result);
        intercala(a, n, result);
    }
}

void intercala(int *vetor, int n, int *result) {
    int *aux;
    aux = (int *)malloc(n * sizeof(int));
    int meio = n >> 1;
    int i = 0;
    int j = meio;

    for (int k = 0; k < n; ++k) {
        if ((i < meio) && (j < n)) {
            if (vetor[i] < vetor[j]) {
                aux[k] = vetor[i];
                ++i;

            } else if (vetor[j] < vetor[i]) {
                aux[k] = vetor[j];
                ++j;
                *result += meio - i;
            }
        } else if (i < meio) {
            aux[k] = vetor[i];
            ++i;

        } else {
            aux[k] = vetor[j];
            ++j;
        }
    }
    memcpy(vetor, aux, sizeof(int) * n);
    free(aux);
}