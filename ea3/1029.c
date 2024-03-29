#include <stdio.h>

/*
@author: Jonathas Luis de Sousa
@date: 17/05/2023

FIBONACCI, QUANTAS CHAMADAS? - 1029

Quase todo estudante de Ciência da Computação recebe em algum momento no início de seu curso de
 graduação algum problema envolvendo a sequência de Fibonacci. Tal sequência tem como os dois primeiros
 valores 0 (zero) e 1 (um) e cada próximo valor será sempre a soma dos dois valores imediatamente anteriores. 
 Por definição, podemos apresentar a seguinte fórmula para encontrar qualquer número da sequência de Fibonacci:
fib(0) = 0
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2);

Uma das formas de encontrar o número de Fibonacci é através de chamadas recursivas.
 Isto é ilustrado a seguir, apresentando a árvore de derivação ao calcularmos o valor fib(4),
 ou seja o 5º valor desta sequência:

Desta forma,
fib(4) = 1+0+1+1+0 = 3
Foram feitas 8 calls, ou seja, 8 chamadas recursivas.

Entrada
A primeira linha da entrada contém um único inteiro N, indicando o número de casos de teste.
 Cada caso de teste contém um inteiro X (1 ≤ X ≤ 39) .

Saída
Para cada caso de teste de entrada deverá ser apresentada uma linha de saída, no seguinte
 formato: fib(n) = num_calls calls = result, aonde num_calls é o número de chamadas recursivas, 
 tendo sempre um espaço antes e depois do sinal de igualdade, conforme o exemplo abaixo.
*/

int calls;

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    calls += 2;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int numeroCasos;
    scanf("%i", &numeroCasos);

    for (int i = 0; i < numeroCasos; i++) {
        calls = 0;
        int n;
        scanf("%i", &n);
        int fib = fibonacci(n);
        printf("fib(%i) = %i calls = %i\n", n, calls, fib);
    }
    return 0;
}