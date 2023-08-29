/*Questão: Faça um programa com uma função que receba como parâmetro um número e retorne se o
número é primo ou não (pode ser um 0 ou 1 indicando falso ou verdadeiro, ou mesmo retornar
True ou False).*/

#include <stdio.h>

int primo(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i < x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int numero;

  scanf("%d", &numero);
  if (primo(numero)) {
    printf("O número %d é primo.\n", numero);
  } else {
    printf("O número %d não é primo.\n", numero);
  }

  return 0;
}
