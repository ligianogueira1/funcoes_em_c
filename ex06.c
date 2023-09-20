/*Questão: Desenvolva um programa para uma livraria, a qual precisa de um sistema para organizar seus
livros. Para cadastrar os livros, o usuário deve fornecer:
• o título do livro,
• o autor do livro,
• o preço do livro.
(a) Deve existir uma estrutura (struct) chamada Livro.
(b) O usuário poderá escolher as funcionalidades solicitadas nos tópicos 1 a 5 abaixo por meio
de um menu, podendo repeti-las até que ele deseje sair do programa.
1. O programa deve permitir o cadastro de livros em um vetor de Livros.
2. O programa deve realizar o cálculo da média de preço de todos os livros.
3. O programa deve realizar o cálculo de quantos livros têm preço acima da média de
preços.
4. O programa deve localizar um livro cadastrado pelo nome do autor ou pelo nome do
livro, de maneira tal que o usuário não precise especificar se a busca é pelo autor ou
nome do livro.
5. Sair do programa.*/

/* --- Descrição do código ---

Obs.: o código-fonte está repleto de quebras de linhas ("\n") e separadores
("-") para melhor agradabilidade visual no output.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char titulo[100];
  char autor[100];
  float preco;
} Livro;

void cadastrarLivro(Livro livros[], int *numLivros);

float calcularMediaPreco(Livro livros[], int numLivros);
int verificarQuantidadeLivrosAcimaMedia(Livro livros[], int numLivros,
                                        float media_precos);
int localizarLivro(Livro livros[], int numLivros, const char *chave);

int main() {
  Livro livros[100];
  int numLivros = 0;
  char op;

  do {
    printf("\n------------------------------------------------------\n");
    printf("\n--- Menu principal ---\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Consultar média de preço\n");
    printf("3 - Consultar quantidade de livros com preços acima da média\n");
    printf("4 - Localizar livro\n");
    printf("5 - Sair do programa\n");
    printf("\nDigite uma opção: ");
    scanf(" %c", &op);

    switch (op) {
    case '1':
      printf("\n------------------------------------------------------\n");
      printf("Você escolheu cadastrar um novo livro. Por favor, siga as instruções.\n");

      cadastrarLivro(livros, &numLivros);

      printf("Livro cadastrado com sucesso!\n");
      break;

    case '2':
      printf("Você escolheu consultar a média de preço dos livros.\n");
      float media = calcularMediaPreco(livros, numLivros);
      printf("A média de preço é: %.2f\n", media);
      break;

    case '3':
      if (numLivros > 0) {
        printf("Você escolheu consultar a quantidade de livros com preços acima da média.\n");
        int quantidade = verificarQuantidadeLivrosAcimaMedia(livros, numLivros, media);
        printf("A quantidade é: %d\n", quantidade);
      } else {
        printf("Não há livros cadastrados para calcular a quantidade acima da "
               "média.\n");
      }
      break;

    case '4':
      printf("\n------------------------------------------------------\n");
      printf("Você escolheu localizar um livro\n");

      char chave[100];

      printf("Digite o nome do autor ou título: ");
      scanf(" %[^\n]", chave);

      int indiceEncontrado = localizarLivro(livros, numLivros, chave);

      if (indiceEncontrado != -1) {
        printf("\nLivro encontrado:\n");
        printf("Título: %s\n", livros[indiceEncontrado].titulo);
        printf("Autor: %s\n", livros[indiceEncontrado].autor);
        printf("Preço: %.2f\n", livros[indiceEncontrado].preco);
      } else {
        printf("\nNenhum livro encontrado para a pesquisa. Por favor, tente "
               "novamente.\n");
      }
      break;

    case '5':
      break;

    default:
      printf("\n------------------------------------------------------\n");
      printf("Opção inválida.\n");
    }
  } while (op != '5');

  return 0;
}

void cadastrarLivro(Livro livros[], int *numLivros) {
  if (*numLivros < 100) {
    printf("Informe o título: ");
    scanf(" %[^\n]", livros[*numLivros].titulo);

    printf("Informe o autor: ");
    scanf(" %[^\n]", livros[*numLivros].autor);

    printf("Informe o preço: ");
    scanf("%f", &livros[*numLivros].preco);

    (*numLivros)++;
  } else {
    printf("Limite máximo de livros atingido.\n");
  }
}

float calcularMediaPreco(Livro livros[], int numLivros) {
  if (numLivros > 0) {
    float soma_precos = 0.0;
    for (int i = 0; i < numLivros; i++) {
      soma_precos += livros[i].preco;
    }
    float media_precos = soma_precos / numLivros;
    return media_precos;
  } else {
    return 0.0;
  }
}

int verificarQuantidadeLivrosAcimaMedia(Livro livros[], int numLivros, float media_precos) {
  int livros_acima_media = 0;
  if (numLivros > 0) {
    for (int i = 0; i < numLivros; i++) {
      if (livros[i].preco > media_precos) {
        livros_acima_media++;
      }
    }
  }
  return livros_acima_media;
}

int localizarLivro(Livro livros[], int numLivros, const char *chave) {
  for (int i = 0; i < numLivros; i++) {
    if (strcmp(chave, livros[i].autor) == 0 ||
        strcmp(chave, livros[i].titulo) == 0) {
      return i;
    }
  }
  return -1;
}
