#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@author: Jonathas Luis de Sousa
@date: 25/05/2023

HOJE TEM PROVA DA CRIS! - 1396

A Profa. Cristina é muito exigente. Sua fama de maquiavélica já é conhecida fora da universidade e ela até gosta disso...
Mas, parece que agora ela exagerou... Na última prova de sua disciplina, a professora exigiu que os alunos formassem 
fila indiana para entrar na sala de aula. Eles formaram. Quando eles iam entrar, ela gritou: "Mas, vocês não estão 
em ordem lexicográfica crescente!!!???"

Os alunos revoltados formaram uma comissão e foram conversar com a professora dizendo que aquilo já era demais. 
Para não parecerem intransigentes eles disseram que permitiriam no máximo um número k de trocas de posição entre 
pessoas consecutivas na fila. A professora gostou da idéia, e colocou como um problema extra da prova.

Dada uma sequência de nomes e um inteiro k, devolver a menor sequência (em ordem lexicográfica) que pode ser 
obtida a partir da original com no máximo k trocas de elementos vizinhos. Sua tarefa é resolver este exercício 
para os alunos da Profa. Cristina a fim de que eles consigam entrar na sala e começar a prova.

Entrada
A entrada é composta de diversas instâncias. Cada instância começa com dois inteiros n e k, onde 1 ≤ n ≤ 100 e 0 ≤ k ≤ n, 
indicando a quantidade nomes e a quantidade máxima de trocas, respectivamente. A próxima linha contém uma sequência de n nomes. 
Cada nome possui tamanho máximo de 20 caracteres, e letras de 'a' a 'z'.

O programa deve parar de processar a entrada quando n = k = 0.

Saída
Para cada instância, você deverá imprimir um identificador "Instancia c", onde c é o número da instância atual. 
Na linha seguinte você deve imprimir a lista de nomes resultante do processo. 
Após cada nome, seu programa deve imprimir um espaço em branco, inclusive após o último nome 
(por exemplo, na saída do primeiro caso de teste abaixo: wanderleybthadeubchegadob, onde b representa um espaço em branco. 
Após cada instância, seu programa deve imprimir uma linha em branco, inclusive após a última.


OBS: o código a seguir atende as definições do problema, no entanto não é aprovado pelo Beecrowd, pois mesmo alterando os
elementos consecultivos, o código pode ficar diferente, pois não é escolhido o mesmo criterio de movimentação. 

A SOLUÇÃO ESTÁ INCOMPLETA!!!
*/

typedef struct {
    char s[21];
} string;

int max = 0;

void mergeSort(string *, int n, int *result);
void intercala(string *, int n, int *result);

int main() {
    int n;
    int i = 0;
    while (scanf("%d %d", &n, &max) != EOF) {
        if (n == 0 && max == 0) {
            break;
        }

        ++i;
        int trocas = 0;
        string nomes[n];
        for (int i = 0; i < n; i++) {
            scanf("%s", nomes[i].s);
        }
        mergeSort(nomes, n, &trocas);

        printf("Instancia %d\n", i);
        for (int j = 0; j < n; j++) {
            printf("%s ", nomes[j].s);
        }
        printf("\n\n");
    }
    return 0;
}

void mergeSort(string *a, int n, int *result) {
    if (n > 1) {
        int meio = (n) >> 1;
        mergeSort(a, meio, result);
        mergeSort(a + meio, (n + 1) >> 1, result);
        intercala(a, n, result);
    }
}

void intercala(string *vetor, int n, int *result) {
    string *aux;
    aux = (string *)malloc(n * sizeof(string));
    int meio = n >> 1;
    int i = 0;
    int j = meio;

    for (int k = 0; k < n; ++k) {
        if ((i < meio) && (j < n)) {
            if (strcmp(vetor[i].s, vetor[j].s) < 0) {
                strcpy(aux[k].s, vetor[i].s);
                ++i;

            } else if (strcmp(vetor[j].s, vetor[i].s) < 0 && *result < max) {
                strcpy(aux[k].s, vetor[j].s);
                ++j;
                *result += meio - i;
            } else {
                strcpy(aux[k].s, vetor[i].s);
                ++i;
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
    free(aux);
}