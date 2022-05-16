#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "baralho.h"
#include "funcoes_cartas.c"
#include "funcoes_jogos.c"
#include "funcoes_lixo.c"

/** Tamanho máximo de uma linha da entrada-padrão */
#define MAX_LINE 200

/** Tamanho máximo do identificador do bot */
#define ID_SIZE 50
#define QTDBARALHO 104

/**
 * Lê uma linha da entrada padrão e remove o '\n' se necessário.
 * @param line string a ser alterada com o conteúdo da entrada-padrão.
 */
void readline(char *line) {
  fgets(line, MAX_LINE, stdin);
  int l = strlen(line) - 1;
  if(line[l] == '\n') {
    line[l] = '\0';
  }
}

int main() {
  char line[MAX_LINE];   // dados temporários
  char myId[ID_SIZE];    // identificador do bot em questão
  char *pedaco;
  
  card cartas_bot[QTDBARALHO-11];
  int qtdcartas_bot = 11;

  card *trash = NULL;
  int qtd_trash = 0;

  jogo* jogos_bot = NULL;
  int qtdjogos_bot = 0;

  jogos_bot = alocar_jogo(jogos_bot, qtdjogos_bot);

  for(int i =0; i<QTDBARALHO-11; i++){
    cartas_bot[i] = remover_carta(cartas_bot[i]);
  }

  setbuf(stdin, NULL);   // stdin, stdout e stderr não terão buffers
  setbuf(stdout, NULL);  // assim, nada é "guardado temporariamente"
  setbuf(stderr, NULL);

                         // DADOS DO INÍCIO DA PARTIDA
  readline(line);        // lê os identificadores dos jogadores
  readline(line);        // lê o identificador do bot (seu id)
  strncpy(myId, line, ID_SIZE); // guarda para uso futuro
  readline(line);        // lê as cartas que o bot tem na mão
  pedaco=strtok(line, " "); // o primeiro vai ser o [, por isso logo ao iniciar o for eu chamo de novo

  for(int i = 0; i<11; i++){
    pedaco = strtok(NULL, " ");
    cartas_bot[i].value = value_card(pedaco);
    cartas_bot[i].suit = suit_card(pedaco);
    strcpy(cartas_bot[i].impressao, pedaco); //Copia a string -> destino, ou seja, peadoco para cartas_bot[i].impressao
    
  }

  ordenar_cartas(cartas_bot, 11);
  fprintf(stderr, "CARTAS BOT: ");
  imprimir_cartas(cartas_bot, 11); //apenas para saber por enquanto 

  readline(line);        // lê a carta inicial da pilha de descarte.
  fprintf(stderr, "lixo: %s\n", line);

  trash = alocar_lixo(trash, qtd_trash);
  trash = add_cartas_lixo(trash, &qtd_trash, line);

  while(1) {              // DADOS DURANTE A PARTIDA
    do {                  // lê e descarta os dados até chegar sua vez
      readline(line);     // sai do laço quando for enviado seu id
      //fprintf(stderr, "%s\n", line);  // exemplo de saída para debugar

      if(strstr(line,"DISCARD")){
        trash = alocar_lixo(trash, qtd_trash);
        trash = add_cartas_lixo(trash, &qtd_trash, line);

        fprintf(stderr, "LIXO: ");
        imprimir_cartas(trash, qtd_trash); //imprimir o lixo
      }
      if(strstr(line,"GET_DISCARD")){
        pedaco = NULL;
        pedaco = strtok(line, "]");
        strcat(pedaco,trash[qtd_trash-1].impressao);
        strcat(pedaco," ]");
        free(trash); // liberar
        trash = NULL; // ja que vai pegar todo o lixo
        qtd_trash = 0; // ja que vai pegar todo o lixo
      }
    } while (strcmp(line, myId)); // sai do laço quando for a sua vez!

    jogos_bot = verificar_topo_jogo(cartas_bot, &qtdcartas_bot, jogos_bot, &qtdjogos_bot, trash, &qtd_trash);

    if(qtd_trash == 0){
      //qtd_trash == 0, ja que pegou todo o lixo
      //fprintf(stderr, "puxar do lixo\n");

      free(trash);
      trash = NULL;
      trash = alocar_lixo(trash, qtd_trash);
    }else{
      //fprintf(stderr, "puxar do deque\n");
      
      printf("GET_STOCK\n");    // envia a ação para puxar uma carta
      readline(line);           // recebe a carta que puxou

      fprintf(stderr, "Carta puxada: %s\n", line); //carta puxada

      add_cartas(cartas_bot, &qtdcartas_bot, line); //add carta para a mão
    }

    jogos_bot = baixar_jogo_7(cartas_bot, trash[qtd_trash], &qtdcartas_bot, jogos_bot, &qtdjogos_bot); // 7 cartas

    jogos_bot = baixar_jogo_6(cartas_bot, trash[qtd_trash], &qtdcartas_bot, jogos_bot, &qtdjogos_bot); // 6 cartas

    jogos_bot = baixar_jogo_5(cartas_bot, trash[qtd_trash], &qtdcartas_bot, jogos_bot, &qtdjogos_bot); // 5 cartas

    jogos_bot = baixar_jogo_4(cartas_bot, trash[qtd_trash], &qtdcartas_bot, jogos_bot, &qtdjogos_bot); // 4 cartas

    jogos_bot = baixar_jogo_3(cartas_bot, trash[qtd_trash], &qtdcartas_bot, jogos_bot, &qtdjogos_bot); // 3 cartas

    descartar_bot(cartas_bot, &qtdcartas_bot, trash, &qtd_trash); // descartar 1 carta 
  }

  return 0;
}