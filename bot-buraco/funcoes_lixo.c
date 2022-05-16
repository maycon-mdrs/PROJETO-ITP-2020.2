#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "baralho.h"

//* ----- ALOCAR LIXO DINAMICAMENTE ----- *//

card* alocar_lixo(card *trash, int qtd_trash){
  if(trash == NULL){
    trash = calloc(2,sizeof(card));
    //fprintf(stderr, "calloc lixo\n");
  }else{
    trash = realloc(trash, sizeof(jogo)*(qtd_trash+2)); 
    //fprintf(stderr, "realloc lixo\n");   
  }
  return trash;
  
}

//* ----- ADICIONAR CARTAS NO LIXO ----- *//

card* add_cartas_lixo(card *trash, int *qtd_trash, char descarte[]){
  char *pedaco;
  char carta[8];
  carta[0]='\0';

  int tam = strlen(descarte);

  fprintf(stderr, "descarte: %s, tam: %d\n", descarte, tam);

  //DISCARD 2♥ >= 12; (USUÁRIO)
  // 2♥ >= 4; (BOT)

  if(strlen(descarte)>=12){
    //fprintf(stderr, "lixo user\n");

    pedaco = NULL;
    pedaco=strtok(descarte, " ");
    pedaco=strtok(NULL, " ");
    strcpy(carta,pedaco); //USÁRIO 
  }else{
    //fprintf(stderr, "lixo bot\n");

    strcpy(carta,descarte); //BOT
  }
  
  *qtd_trash+=1;

  trash[*qtd_trash-1].value = value_card(carta);
  trash[*qtd_trash-1].suit = suit_card(carta);
  strcpy(trash[*qtd_trash-1].impressao, carta);

  return trash;
}

//* ----- VERIFICAR TOPO FAZ JOGO ----- *//

jogo* verificar_topo_jogo(card cartas_bot[], int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot, card *trash, int *qtd_trash){
  
  fprintf(stderr, "topo do lixo: %s\n", trash[*qtd_trash-1].impressao);
  
  for(int x = 0 ; x < *qtdcartas_bot; x++) {
    if(cartas_bot[x].value + 1 == cartas_bot[x+1].value && 
    cartas_bot[x].suit == cartas_bot[x+1].suit){
      if(trash[*qtd_trash-1].value + 1 == cartas_bot[x].value && 
        trash[*qtd_trash-1].suit == cartas_bot[x].suit){
          
          //fprintf(stderr, "funcionando posição 1\n");

          //TOPO
          printf("GET_DISCARD [ %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao);
          fprintf(stderr, "%s %s\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao); 

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=2;
          
          //fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);

          //LIXO
          (*qtd_trash) -= 1;
          lixo_na_mao(cartas_bot, qtdcartas_bot, trash, qtd_trash);

          imprimir_cartas(cartas_bot, *qtdcartas_bot);
          fprintf(stderr, "qtd_lixo: %d\n", *qtd_trash);
      }

      if(trash[*qtd_trash-1].value - 2 == cartas_bot[x].value && 
        trash[*qtd_trash-1].value - 1 == cartas_bot[x+1].value && 
        trash[*qtd_trash-1].suit == cartas_bot[x].suit){

          //fprintf(stderr, "funcionando posição 3\n");

          //TOPO
          printf("GET_DISCARD [ %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao);
          fprintf(stderr, "%s %s\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao); 

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=2;
          
          //fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);

          //LIXO
          (*qtd_trash) -= 1;
          lixo_na_mao(cartas_bot, qtdcartas_bot, trash, qtd_trash);

          imprimir_cartas(cartas_bot, *qtdcartas_bot);
          fprintf(stderr, "qtd_lixo: %d\n", *qtd_trash);
      }
    }

    if(cartas_bot[x].value + 2 == cartas_bot[x+2].value && 
      cartas_bot[x].suit == cartas_bot[x+2].suit){
      if(trash[*qtd_trash-1].value - 1 == cartas_bot[x].value && 
        trash[*qtd_trash-1].value + 1 == cartas_bot[x+2].value && 
        trash[*qtd_trash-1].suit == cartas_bot[x].suit){

          //fprintf(stderr, "funcionando posição 2\n");
          
          //TOPO
          printf("GET_DISCARD [ %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+2].impressao);
          fprintf(stderr, "%s %s\n", cartas_bot[x].impressao, cartas_bot[x+2].impressao); 

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+2] = remover_carta(cartas_bot[x+2]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=2;

          //fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);

          //LIXO
          (*qtd_trash) -= 1;
          lixo_na_mao(cartas_bot, qtdcartas_bot, trash, qtd_trash);

          imprimir_cartas(cartas_bot, *qtdcartas_bot);
          fprintf(stderr, "qtd_lixo: %d\n", *qtd_trash);
      }
    }
  }
  return jogos_bot;
}

//* ----- LIXO NA MÃO ----- *//

void lixo_na_mao(card cartas_bot[], int *qtdcartas_bot, card *trash, int *qtd_trash){

  for(int i=*qtdcartas_bot; i<*qtdcartas_bot + *qtd_trash; i++){
    cartas_bot[i]=trash[i-*qtdcartas_bot];
  }

  *qtdcartas_bot = *qtdcartas_bot + *qtd_trash; // Nova quantidade
  ordenar_cartas(cartas_bot, *qtdcartas_bot);

  *qtd_trash = 0;// ja que foi tudo para a mão
}
