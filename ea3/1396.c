#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@author: Jonathas Luis de Sousa
@date: 25/05/2023

HOJE TEM PROVA DA CRIS! - 1396

A Profa. Cristina é muito exigente. Sua fama de maquiavélica já é conhecida fora
da universidade e ela até gosta disso... Mas, parece que agora ela exagerou...
Na última prova de sua disciplina, a professora exigiu que os alunos formassem
fila indiana para entrar na sala de aula. Eles formaram. Quando eles iam entrar,
ela gritou: "Mas, vocês não estão em ordem lexicográfica crescente!!!???"

Os alunos revoltados formaram uma comissão e foram conversar com a professora
dizendo que aquilo já era demais. Para não parecerem intransigentes eles
disseram que permitiriam no máximo um número k de trocas de posição entre
pessoas consecutivas na fila. A professora gostou da idéia, e colocou como um
problema extra da prova.

Dada uma sequência de nomes e um inteiro k, devolver a menor sequência (em ordem
lexicográfica) que pode ser obtida a partir da original com no máximo k trocas
de elementos vizinhos. Sua tarefa é resolver este exercício para os alunos da
Profa. Cristina a fim de que eles consigam entrar na sala e começar a prova.

Entrada
A entrada é composta de diversas instâncias. Cada instância começa com dois
inteiros n e k, onde 1 ≤ n ≤ 100 e 0 ≤ k ≤ n, indicando a quantidade nomes e a
quantidade máxima de trocas, respectivamente. A próxima linha contém uma
sequência de n nomes. Cada nome possui tamanho máximo de 20 caracteres, e letras
de 'a' a 'z'.

O programa deve parar de processar a entrada quando n = k = 0.

Saída
Para cada instância, você deverá imprimir um identificador "Instancia c", onde c
é o número da instância atual. Na linha seguinte você deve imprimir a lista de
nomes resultante do processo. Após cada nome, seu programa deve imprimir um
espaço em branco, inclusive após o último nome (por exemplo, na saída do
primeiro caso de teste abaixo: wanderleybthadeubchegadob, onde b representa um
espaço em branco. Após cada instância, seu programa deve imprimir uma linha em
branco, inclusive após a última.
*/

typedef struct {
    char s[25];
} string;

void ordena(string *, int n, int k);

int main() {
    int n, k;
    int i = 0;
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n == 0 && k == 0) {
            break;
        }

        ++i;
        string nomes[n];
        for (int i = 0; i < n; i++) {
            scanf("%s", nomes[i].s);
        }
        ordena(nomes, n, k);

        printf("Instancia %d\n", i);
        for (int j = 0; j < n; j++) {
            printf("%s ", nomes[j].s);
        }
        printf("\n\n");
    }
    return 0;
}

void ordena(string *a, int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        int trocas = k < n - i - 1 ? k : n - i - 1;
        int m = i;
        for (int j = i + 1; j < i + trocas + 1; j++) {
            if (strcmp(a[j].s, a[m].s) < 0) {
                m = j;
            }
        }
        for (int j = m; j > i && k != 0; j--) {
            string aux = a[j];
            strcpy(a[j].s, a[j - 1].s);
            strcpy(a[j - 1].s, aux.s);
            --k;
        }
    }
}