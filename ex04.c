/*Questão: Considere uma aplicação gráfica que define dois tipos estruturados identificados pelos nomes
Ponto e Circulo. O tipo estruturado Ponto representa o objeto ponto em duas dimensões, que é
composto por duas coordenadas tipo float. O tipo estruturado Circulo representa o objeto
círculo composto por um nome (que nunca contém mais do que 10 caracteres, p.ex. Circulo015),
por um ponto que define o seu centro e por um raio com a precisão de um float. 
Escreva um programa completo (com includes, structs, funções e a main), em um único arquivo .c,
que implementa e testa as seguintes funções:
• criaCirculo – que cria um novo círculo. Esta função recebe um nome, as coordenadas x e
y do centro e o raio para este novo círculo, e retorna um ponteiro para Circulo.
• contem – que testa se um determinado círculo contém outro círculo dado. Esta função
recebe dois ponteiros para o tipo estruturado Circulo e retorna 0 se o primeiro círculo não
contém o segundo círculo e diferente de zero se contém.
Um círculo c1 contém outro círculo c2 se a distância entre os seus centros (d) somada ao raio de
c2 for menor ou igual ao raio de c1, isto é: d + r2 <= r1. A distância d entre dois pontos com
coordenadas (x1, y1) e (x2, y2) é calculada pela seguinte fórmula:
distancia = sqrt((x2− x1) + (y2− y1))*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  float x;
  float y;
} Ponto;

typedef struct {
  char nome[11];
  Ponto centro;
  float raio;
} Circulo;

Circulo *criaCirculo(char *nome, float x, float y, float raio);
int contem(Circulo *c1, Circulo *c2);

int main(void) {
  Circulo *c1, *c2, *c3;
  c1 = criaCirculo("Circulo01", 3.0, 4.0, 2.0);
  c2 = criaCirculo("Circulo02", 3.0, 3.0, 1.0);
  c3 = criaCirculo("Circulo01", 1.0, 5.0, 1.0);

  printf("%d\n", contem(c1, c2));
  printf("%d\n", contem(c1, c3));

  free(c1);
  free(c2);
  free(c3);

  return 0;
}

Circulo *criaCirculo(char *nome, float x, float y, float raio) {
  Circulo *novoCirculo = (Circulo *)malloc(sizeof(Circulo));
  if (novoCirculo == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }
  strncpy(novoCirculo->nome, nome, sizeof(novoCirculo->nome));
  novoCirculo->nome[sizeof(novoCirculo->nome) - 1] = '\0';
  novoCirculo->centro.x = x;
  novoCirculo->centro.y = y;
  novoCirculo->raio = raio;

  return novoCirculo;
}

int contem(Circulo *c1, Circulo *c2) {
  int diferencaX, diferencaY;
  float soma, distancia_centros;
  diferencaX = c2->centro.x - c1->centro.x;
  diferencaY = c2->centro.y - c1->centro.y;
  soma = pow(diferencaX, 2) + pow(diferencaY, 2);
  distancia_centros = sqrt(soma);
  return (distancia_centros + c2->raio <= c1->raio);
}
