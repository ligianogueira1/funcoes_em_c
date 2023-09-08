/* Questão:  Escreva uma função que receba um vetor de inteiros e retorne a soma dos elementos do vetor, 
// o maior elemento e o menor elemento desse vetor. Observe que a função deve retornar três valores 
(a função não deve exibir nada na tela). Portanto, você precisará usar passagem de parâmetro por referência, 
já que funções só podem retornar um único valor.*/

#include <stdio.h>

void calculaSomaMaiorMenor(int vetor[], int tamanho, int *soma, int *maior,
                           int *menor) {
  if (tamanho == 0) {
    *soma = 0;
    *maior = 0;
    *menor = 0;
    return;
  }

  *soma = vetor[0];
  *maior = vetor[0];
  *menor = vetor[0];

  for (int i = 1; i < tamanho; i++) {
    *soma += vetor[i];

    if (vetor[i] > *maior) {
      *maior = vetor[i];
    }
    if (vetor[i] < *menor) {
      *menor = vetor[i];
    }
  }
}

int main(void) {
  int i, vetor[10], maior, menor, soma;
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);
  printf("Digite 10 números inteiros: ");
  for (i = 0; i < 10; i++) {
    scanf("%d", &vetor[i]);
  }

  calculaSomaMaiorMenor(vetor, tamanho, &soma, &maior, &menor);

  printf("Soma: %d\n", soma);
  printf("Maior: %d\n", maior);
  printf("Menor: %d\n", menor);
  return 0;
}
