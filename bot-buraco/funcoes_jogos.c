#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "baralho.h"

//* ----- ALOCAR JOGO DINAMICAMENTE ----- *//

jogo* alocar_jogo(jogo *cartas_bot, int qtdjogos_bot){
  if(cartas_bot == NULL){
    cartas_bot = calloc(1,sizeof(jogo));
    //fprintf(stderr, "alocar - cartas_bot: %p\n", cartas_bot);//endereço
    cartas_bot[0].cartas = calloc(3,sizeof(card));
  }else{
    cartas_bot = realloc(cartas_bot, sizeof(jogo)*(qtdjogos_bot+1));
    //fprintf(stderr, "realloc - cartas_bot: %p\n", cartas_bot);//endereço
    cartas_bot[qtdjogos_bot+1].cartas = calloc(3,sizeof(card));
    //fprintf(stderr, "qtd +1 - cartas_bot: %p\n", cartas_bot); //endereço
  }
  return cartas_bot;
  
}

//* ----- DESCER JOGO PARA MESA ----- *//

jogo *baixar_jogo_3(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot){
  for(int x=0; x < *qtdcartas_bot; x++){
    if(cartas_bot[x].suit == cartas_bot[x+1].suit && 
      cartas_bot[x].suit == cartas_bot[x+2].suit){
      if(cartas_bot[x].value + 1 == cartas_bot[x+1].value && 
        cartas_bot[x].value + 2 == cartas_bot[x+2].value){

          //fprintf(stderr, "3 cartas\n");

          printf("MELD_NEW [ %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao);

          fprintf(stderr, "jogo formado: [ %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao);

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);
          cartas_bot[x+2] = remover_carta(cartas_bot[x+2]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=3;
          fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);
      }
    }
  }
  return jogos_bot;
}

jogo *baixar_jogo_4(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot){
  for(int x=0; x < *qtdcartas_bot; x++){
    if(cartas_bot[x].suit == cartas_bot[x+1].suit && 
      cartas_bot[x].suit == cartas_bot[x+2].suit && 
      cartas_bot[x].suit == cartas_bot[x+3].suit){
        if(cartas_bot[x].value + 1 == cartas_bot[x+1].value && 
          cartas_bot[x].value + 2 == cartas_bot[x+2].value && 
          cartas_bot[x].value + 3 == cartas_bot[x+3].value){

            //fprintf(stderr, "4 cartas\n");

            printf("MELD_NEW [ %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao);

            fprintf(stderr, "jogo formado: [ %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao);

            //ZERAR
            cartas_bot[x] = remover_carta(cartas_bot[x]);
            cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);
            cartas_bot[x+2] = remover_carta(cartas_bot[x+2]);
            cartas_bot[x+3] = remover_carta(cartas_bot[x+3]);

            //ORDENAR
            ordenar_cartas(cartas_bot,*qtdcartas_bot);
            *qtdcartas_bot-=4;
            fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

            //JOGOS
            *qtdjogos_bot += 1;
            jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);
      }
    }
  }
  return jogos_bot;
}

jogo *baixar_jogo_5(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot){
  for(int x=0; x < *qtdcartas_bot; x++){
    if(cartas_bot[x].suit == cartas_bot[x+1].suit && 
      cartas_bot[x].suit == cartas_bot[x+2].suit && cartas_bot[x].suit == cartas_bot[x+3].suit && 
      cartas_bot[x].suit == cartas_bot[x+4].suit){
      if(cartas_bot[x].value + 1 == cartas_bot[x+1].value && 
        cartas_bot[x].value + 2 == cartas_bot[x+2].value && 
        cartas_bot[x].value + 3 == cartas_bot[x+3].value && 
        cartas_bot[x].value + 4 == cartas_bot[x+4].value){

          //fprintf(stderr, "5 cartas\n");

          printf("MELD_NEW [ %s %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao, cartas_bot[x+4].impressao);

          fprintf(stderr, "jogo formado: [ %s %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao, cartas_bot[x+4].impressao);

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);
          cartas_bot[x+2] = remover_carta(cartas_bot[x+2]);
          cartas_bot[x+3] = remover_carta(cartas_bot[x+3]);
          cartas_bot[x+4] = remover_carta(cartas_bot[x+4]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=5;
          fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);
      }
    }
  }
  return jogos_bot;
}

jogo *baixar_jogo_6(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot){
  for(int x=0; x < *qtdcartas_bot; x++){
    if(cartas_bot[x].suit == cartas_bot[x+1].suit && 
      cartas_bot[x].suit == cartas_bot[x+2].suit && 
      cartas_bot[x].suit == cartas_bot[x+3].suit && 
      cartas_bot[x].suit == cartas_bot[x+4].suit && 
      cartas_bot[x].suit == cartas_bot[x+5].suit){
      if(cartas_bot[x].value + 1 == cartas_bot[x+1].value && 
        cartas_bot[x].value + 2 == cartas_bot[x+2].value && 
        cartas_bot[x].value + 3 == cartas_bot[x+3].value && 
        cartas_bot[x].value + 4 == cartas_bot[x+4].value && 
        cartas_bot[x].value + 5 == cartas_bot[x+5].value){

          //fprintf(stderr, "6 cartas\n");

          printf("MELD_NEW [ %s %s %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao, cartas_bot[x+4].impressao, cartas_bot[x+5].impressao);

          fprintf(stderr, "jogo formado: [ %s %s %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao, cartas_bot[x+4].impressao, cartas_bot[x+5].impressao);

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);
          cartas_bot[x+2] = remover_carta(cartas_bot[x+2]);
          cartas_bot[x+3] = remover_carta(cartas_bot[x+3]);
          cartas_bot[x+4] = remover_carta(cartas_bot[x+4]);
          cartas_bot[x+5] = remover_carta(cartas_bot[x+5]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=6;
          fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);
      }
    }
  }

  return jogos_bot;
}

jogo *baixar_jogo_7(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot){
  for(int x=0; x < *qtdcartas_bot; x++){
    if(cartas_bot[x].suit == cartas_bot[x+1].suit &&
      cartas_bot[x].suit == cartas_bot[x+2].suit && 
      cartas_bot[x].suit == cartas_bot[x+3].suit && 
      cartas_bot[x].suit == cartas_bot[x+4].suit && 
      cartas_bot[x].suit == cartas_bot[x+5].suit && 
      cartas_bot[x].suit == cartas_bot[x+6].suit){
      if(cartas_bot[x].value + 1 == cartas_bot[x+1].value &&
        cartas_bot[x].value + 2 == cartas_bot[x+2].value &&
        cartas_bot[x].value + 3 == cartas_bot[x+3].value && cartas_bot[x].value + 4 == cartas_bot[x+4].value && cartas_bot[x].value + 5 == cartas_bot[x+5].value && cartas_bot[x].value + 6 == cartas_bot[x+6].value){

          //fprintf(stderr, "7 cartas\n");

          printf("MELD_NEW [ %s %s %s %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao, cartas_bot[x+4].impressao, cartas_bot[x+5].impressao, cartas_bot[x+6].impressao);

          fprintf(stderr, "jogo formado: [ %s %s %s %s %s %s %s ]\n", cartas_bot[x].impressao, cartas_bot[x+1].impressao, cartas_bot[x+2].impressao, cartas_bot[x+3].impressao, cartas_bot[x+4].impressao, cartas_bot[x+5].impressao, cartas_bot[x+6].impressao);

          //ZERAR
          cartas_bot[x] = remover_carta(cartas_bot[x]);
          cartas_bot[x+1] = remover_carta(cartas_bot[x+1]);
          cartas_bot[x+2] = remover_carta(cartas_bot[x+2]);
          cartas_bot[x+3] = remover_carta(cartas_bot[x+3]);
          cartas_bot[x+4] = remover_carta(cartas_bot[x+4]);
          cartas_bot[x+5] = remover_carta(cartas_bot[x+5]);
          cartas_bot[x+6] = remover_carta(cartas_bot[x+6]);

          //ORDENAR
          ordenar_cartas(cartas_bot,*qtdcartas_bot);
          *qtdcartas_bot-=7;
          fprintf(stderr, "qtd_cartas_bot: %d\n", *qtdcartas_bot);

          //JOGOS
          *qtdjogos_bot += 1;
          jogos_bot =  alocar_jogo(jogos_bot, *qtdjogos_bot);
      }
    }
  }
  return jogos_bot;
}