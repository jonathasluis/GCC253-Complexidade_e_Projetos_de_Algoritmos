#include <stdio.h>
 
int main() {
    
    double pi = 3.14159;
    double raio;

    scanf("%lf",&raio);
    double result = pi * raio * raio;
    printf("A=%.4f\n",result);
    return 0;
}