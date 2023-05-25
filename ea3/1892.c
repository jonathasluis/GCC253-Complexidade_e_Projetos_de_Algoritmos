#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@author: Jonathas Luis de Sousa
@date: 25/05/2023

CALOURO VENCE VETERANO? - 1892

Professor Denis está curioso para saber se a classificação final de seus N alunos de programação competitiva 
segue a ordem de matrícula na universidade. Ele pediu a sua ajuda para, dada a classificação final, contar 
quantos pares (i, j) existem tais que i < j e m[i] > m[j], onde 1 ≤ i,j ≤ N e m[i] significa a matrícula do aluno 
que ficou em i-ésimo lugar.

Entrada
A entrada contém vários casos de teste.

A primeira linha de um caso de teste contém um único inteiro N, que representa o número de alunos, onde 1 ≤ N ≤ 105.

As próximas N linhas são a classificação final dos alunos. Cada linha contém uma cadeia de exatamente 10 caracteres.

Saída
Para cada caso de teste, imprima uma única linha com o número pedido na especificação.
*/

typedef struct {
    char s[11];
} string;

void mergeSort(string *,long long n, long long *result);
void intercala(string *,long long n, long long *result);

//string matriculas[100000];
int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        long long trocas = 0;
        string matriculas[n];
        for (long long i = 0; i < n; i++) {
            scanf("%s", matriculas[i].s);
        }
        mergeSort(matriculas, n, &trocas);

        printf("%lld\n", trocas);

        /*for (int i = 0; i < n; i++)
        {
           printf("%s ",matriculas[i].s);
        }*/
    }
    return 0;
}

void mergeSort(string *a,long long n, long long *result) {
    if (n > 1) {
        long long meio = n >> 1;
        mergeSort(a ,meio,result);
        mergeSort(a + meio, (n + 1) >> 1 ,result);
        intercala(a,n ,result);
    }
}

void intercala(string *vetor,long long n, long long *result) {
    string *aux;
    aux = (string*)malloc(n * sizeof(string));
    long long meio = n >> 1;
    long long i = 0;
    long long j = meio;

    for (long long k = 0; k < n; ++k) {
        if ((i < meio) && (j < n)) {
            if (strcmp(vetor[i].s, vetor[j].s) < 0) {
                strcpy(aux[k].s, vetor[i].s);
                ++i;

            } else if (strcmp(vetor[j].s, vetor[i].s) < 0) {
                strcpy(aux[k].s, vetor[j].s);
                ++j;
                *result += meio - i;
            }
        } else if (i < meio) {
            strcpy(aux[k].s, vetor[i].s);
            ++i;

        } else {
            strcpy(aux[k].s, vetor[j].s);
            ++j;
        }
    }
	memcpy(vetor, aux, sizeof(string) * n);
    //vetor = aux;
   
    free(aux);
}