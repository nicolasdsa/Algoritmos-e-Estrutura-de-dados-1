#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void raizes(float a, float b, float c, float *x1, float *x2){
    float delta, raiz;

    delta = (b * b) - 4 * a * c;
    raiz = sqrt(delta);

    if(delta < 0){
        printf("Nao existe real.\n");
        return;
    }
    else if(delta == 0){
        printf("Existe uma raiz real\n");
        printf("Raiz: %f\n", -(b) / (2 * a));
        return;
    }
    
    else if(delta > 0){
        *x1 = ((-(b) + raiz)/ (2 * a));
        *x2 = ((-(b) - raiz)/ (2 * a));

        printf("\nExiste duas raizes reais e distintas");
        return;
    }

}

int main()
{
   void raizes(float a, float b, float c, float *x1, float *x2);
   float a, b, c, x1, x2;

    printf("Calculadora de Bhaskara:\nDigite o valor de A\n");
    scanf("%f", &a);
    printf("Digite o valor de B:\n");
    scanf("%f", &b);
    printf("Digite o valor de C:\n");
    scanf("%f", &c);
    
    raizes(a, b, c, &x1, &x2);

    if(floor(x1) == 0 && floor(x2) == 0){
      
    }
    else{
      printf("\nX1: %.2f e X2: %.2f\n", x1, x2);
    }

    system("pause");

    return 0;
}