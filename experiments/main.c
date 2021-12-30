#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
  int len = 1000;
  int lista[len];

  //Decrescente
  gerarListaDecrescente(lista, len);

  //(Função imprime lista)
  imprimeLista(lista, len);

  //Crescente
  gerarListaCrescente(lista, len);

  //(Função imprime lista)
  imprimeLista(lista, len);

    return 0;
}