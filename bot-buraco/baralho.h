#ifndef ZERAR
#define ZERAR 99

//* ----- ENUMERAÇÕES / REGISTROS ----- *//

typedef enum value{
  ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
}value;

typedef enum suit{
  Heart, Diamonds, Clubs, Spades
}suit;

typedef struct card{
  suit suit; // 4
  value value; // ♥
  char impressao[6]; // 4♥
}card;

typedef struct jogo{
  card *cartas;
  int qtd_cartas;
  suit suit;
}jogo;

#endif

//* ----- FUNÇÕES CARTAS ----- *//

int value_card(char card[]); // 1°
int suit_card(char card[]); // 2°
void ordenar_cartas(card baralho[], int tam); // 3°

void add_cartas(card cartas_bot[], int *qtdcartas_bot, char carta[]); // 4°

card remover_carta(card carta); // 5°

void descartar_bot(card cartas_bot[], int *qtdcartas_bot, card *trash, int *qtd_trash); // 6°

void imprimir_cartas(card vet[], int tam); // 7°

/* --- DESCRIÇÃO --- 

1° - Função com o objetivo de dar valor a uma determinada carta, ultilizando o artifício de enumerações. - passando como parâmetro cada carta.

2° - Função com o objetivo de dar um naipe para uma determinada carta, ultilizando o artifício de enumerações também. - passando como parâmetro cada carta.

3° - Função que compara valores e naipes das cartas com finalidade de ordena-las. - passando como parâmetro todas as cartas da mão do bot e uma quantidade de cartas que possui na mão.

4° - Função para adicionar cartas na mão do bot. - passando como parâmetro todas as cartas que o bot possui na mão, a quantidade de cartas que o bot possui na mão e a carta puxada. 

5° - Função com o objetivo de "zerar" determinado valor, naipe, ou seja, carta.

6° - Função que verifica todas as cartas na mão do bot e descarta uma carta ultizando uma estratégia adotada. - passando como parâmetro todas as cartas da mão do bot, a quantidade de cartas que o bot possui na mão, cartas do lixo e quantdade de cartas do lixo.

7° - Função com afins de apenas "imprimir internamente", podendo ser tanto as cartas que o bot possui na mão, quanto as cartas do lixo. - passando sempre como parâmetro as cartas e a quantidade dessas cartas. 

*/

//* ----- FUNÇÕES JOGOS ----- *//

jogo* alocar_jogo(jogo *cartas_bot, int qtdjogos_bot); // 1°

jogo *baixar_jogo_3(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot); // 2°

jogo *baixar_jogo_4(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot); // 3°

jogo *baixar_jogo_5(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot); // 4°

jogo *baixar_jogo_6(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot); // 5°

jogo *baixar_jogo_7(card cartas_bot[], card trash, int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot); // 6°

/* --- DESCRIÇÃO --- 

1° - Aloca dinamicamente o jogos do bot na memória, caso não possua jogo faz-se um calloc, caso ja possua um jogo faz-se um realloc. - passando como parâmetro as cartas do bot que formam um jogo e quantidade dessas cartas.

2° - Verifica se as cartas que o bot possui na mão formam um jogo de 3 cartas (ja que é o mínimo para descer um jogo na mesa). - passando como parâmetro todas as cartas do bot, lixo e quantidade dessas cartas.

3° ao 6° - Verifica se as cartas que o bot possui na mão formam um jogo de 7, 6, 5 ou 4 cartas. - passando como parâmetro todas as cartas do bot, lixo e quantidade dessas cartas.

*/

//* ----- FUNÇÕES LIXO ----- *//

card* alocar_lixo(card *trash, int qtd_trash); // 1°
card* add_cartas_lixo(card *trash, int *qtd_trash, char string[]); // 2°

jogo* verificar_topo_jogo(card cartas_bot[], int *qtdcartas_bot, jogo *jogos_bot, int *qtdjogos_bot, card *trash, int *qtd_trash); // 3°

void lixo_na_mao(card cartas_bot[], int *qtdcartas_bot, card *trash, int *qtd_trash); // 4°

/* --- DESCRIÇÃO --- 

1° - Aloca dinamicamente o(s) lixo(s) na memória, caso não possua ainda um lixo faz-se um calloc, caso ja possua faz-se um realloc. - passando como parâmetro o lixo(normalmente é o topo do lixo) e quantidade dessas cartas que estão no lixo. 

2° - Função que atribui valores e naipes para as cartas do lixo. - passando como parâmetro todas as cartas que possui no lixo e a quantidade dessas cartas.

3° - Verifica se o topo do lixo faz jogo com 2 cartas que o bot possui na mão. Possui 3 casos:
  CASO 1- o topo do lixo fique na primeira possição, ou seja, lixo - carta1 - carta2, sendo carta1 e carta2 duas cartas que possui na mão do bot;

  CASO 2- o topo do lixo fique na segunda possição, ou seja, carta1 - lixo - carta2;

  CASO 3- o topo do lixo fique na terceira possição, ou seja, carta1 - carta2 - lixo;

  Com isso, faz-se um "GET_DISCARD [ %s %s ]\n", carta1, carta2. (envia para o juiz as 2 cartas que formarão um jogo com o topo do lixo), com isso desce o jogo e todas as cartas que estavam no lixo vai para a mão do bot.

4° - Função que atualiza a nova quantidade de cartas que o bot vai ter na mão, ou seja, a quantidade de cartas da mão + quantidade de cartas do lixo, se o bot conseguir fazer um jogo com o topo do lixo.

*/