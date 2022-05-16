#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "baralho.h"

//* ----- IDENTIFICADOR DE CARTAS ----- *//

int value_card(char card[]){
  char valor[1];

  valor[0] = card[0];

  switch(valor[0]){
    case '2': return two; break; 
    case '3': return three; break;
    case '4': return four; break;
    case '5': return five; break;
    case '6': return six; break;
    case '7': return seven; break;
    case '8': return eight; break;
    case '9': return nine; break;
    case '1': return ten; break;
    case 'J': return jack; break;
    case 'Q': return queen; break;
    case 'K': return king; break;
    case 'A': return ace; break;
  }

  return 0;
}

int suit_card(char card[]){
  int tam = strlen(card);
  char suit[3] = {'\0'};

  suit[0]=card[tam-3];
  suit[1]=card[tam-2];
  suit[2]=card[tam-1];

  if(strcmp(suit,"♦")==0){ 
    return Diamonds;
  }
  if(strcmp(suit,"♠")==0){
    return Spades;
  }
  if(strcmp(suit,"♥")==0){
    return Heart;
  }
  else{
    return Clubs;
  }
}

//* ----- ORDENAR CARTAS ----- *//

void ordenar_cartas(card baralho[], int tam){
  card aux; 

  for(int i=0; i<tam-1; i++){
    for(int k=i+1; k<tam; k++){
      if(baralho[i].suit > baralho[k].suit){
          aux = baralho[i];
          baralho[i] = baralho[k];
          baralho[k] = aux;
      }
      else if(baralho[i].suit == baralho[k].suit && baralho[i].value > baralho[k].value){
        aux = baralho[i];
        baralho[i] = baralho[k];
        baralho[k] = aux;
      }
    }
  } 
}

//* ----- ADICIONAR CARTA NA MÃO ----- *//

void add_cartas(card cartas_bot[], int *qtdcartas_bot, char carta[]){
  *qtdcartas_bot+=1;

  cartas_bot[*qtdcartas_bot-1].value = value_card(carta);

  //fprintf(stderr, "*qtdcartas_bot: %d, *qtdcartas_bot-1: %d\n", *qtdcartas_bot, *qtdcartas_bot-1);

  cartas_bot[*qtdcartas_bot-1].suit = suit_card(carta); 
  strcpy(cartas_bot[*qtdcartas_bot-1].impressao, carta); 

  //fprintf(stderr, "cartas_bot[*qtdcartas_bot-1].impressao: %s\n", cartas_bot[*qtdcartas_bot-1].impressao);

  ordenar_cartas(cartas_bot, *qtdcartas_bot);

  fprintf(stderr, "CARTAS BOT: ");
  imprimir_cartas(cartas_bot, *qtdcartas_bot); //apenas para saber por enquanto 
}

//* ----- ZERAR ----- *//

card remover_carta(card carta){

  carta.value = ZERAR;
  carta.suit = ZERAR;
  carta.impressao[0]='\0';

  //fprintf(stderr, "zerar: %d %d %s \n", carta.valor, carta.naipe, carta.impressao);
  return carta;
}

//* ----- DESCARTAR 1 CARTA ----- *//

void descartar_bot(card cartas_bot[], int *qtdcartas_bot, card *trash, int *qtd_trash){

  int possibilidade_descarte[*qtdcartas_bot];

  possibilidade_descarte[0]=1;

  for(int i = 1; i<=*qtdcartas_bot; i++){
    
    possibilidade_descarte[i]=1;

    fprintf(stderr, "possivel descartar_antes: %d", possibilidade_descarte[i]);
  
    if((cartas_bot[i-1].value + 2 >= cartas_bot[i].value && 
      cartas_bot[i-1].suit == cartas_bot[i].suit) ||
      (cartas_bot[i+1].value - 2 <= cartas_bot[i].value && 
      cartas_bot[i+1].suit == cartas_bot[i].suit)){

      possibilidade_descarte[i]=3;
    }

    fprintf(stderr, " ;depois: %d\n", possibilidade_descarte[i]);
  }

  int prioridade = 1;
  int checar_prioridade = 99;
  
  for(int i = 0; i<*qtdcartas_bot; i++){
    
    if(possibilidade_descarte[i]==prioridade){
      checar_prioridade = i;  
      fprintf(stderr, "tem na prioridade: %d\n", checar_prioridade);
    }
    if(i == *qtdcartas_bot-1){
      trash = add_cartas_lixo(trash, qtd_trash, cartas_bot[checar_prioridade].impressao);

      printf("DISCARD %s\n", cartas_bot[checar_prioridade].impressao);

      //fprintf(stderr, "discard: %s\n", cartas_bot[temnaprioridade].impressao );
      //fprintf(stderr, "int - tem na prio_discard - quantidade de cartas: %d\n", temnaprioridade);

      cartas_bot[checar_prioridade] = remover_carta(cartas_bot[checar_prioridade]);

      ordenar_cartas(cartas_bot, *qtdcartas_bot);
      *qtdcartas_bot-=1;
      
      return;
    }
  }
}

//* ----- IMPRIMIR ----- *//

void imprimir_cartas(card str[], int tam){
  for(int i = 0; i<tam; i++){
    fprintf(stderr, "%s ", str[i].impressao);
  }
  fprintf(stderr, "\n");
}
