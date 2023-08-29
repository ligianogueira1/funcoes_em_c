/*Questão: Faça um programa para calcular e exibir o fatorial de um número. Para isso, crie uma função
que recebe um número como parâmetro e retorna o fatorial desse número.*/

#include <stdio.h>

int fatorial(int x) {
  printf("%d! = ", x);

  int resultado = 1;

  for (int i = x; i > 0; i--) {
    resultado *= i;

    if (i != x) {
      printf(" * ");
    }

    printf("%d", i);
  }

  printf("\nResultado = %d", resultado);
}

int main(void) {
  int numero;
  scanf("%d", &numero);
  fatorial(numero);
  return 0;
}
