### Compilar e executar o bot usando um terminal Linux:

* Nosso bot vs nosso bot:
  ```sh
  $ gcc nosso_bot.c -o nosso_bot -g -w
  $ node buraco.js nosso_bot nosso_bot
  ``` 

* Nosso bot vs bot (exemplo):
  ```sh
  $ gcc nosso_bot.c -o nosso_bot -g -w
  $ node buraco.js nosso_bot bot
  ``` 

* Nosso bot vs usuário:
  ```sh
  $ gcc nosso_bot.c -o nosso_bot -g -w
  $ node buraco.js nosso_bot
  ``` 

### Do que foi feito no bot? 

No bot foram feitas funções para:
  * Ordenar as cartas;
  * Definir o descarte;
  * Baixar jogos de até 7 cartas;
  * Organizar e puxar o lixo, dentre outras. 
  
Foi utilizada uma estratégia de formar jogos de até 6 sequências de cartas, a realização desses jogos foi dada a partir de comparações entre as cartas da mão do bot, começando com a checagem se é possível formar uma sequência de 7 cartas, depois de 6 cartas, 5 cartas 4 cartas e por fim de 3 cartas. 

Outra estratégia utilizada foi realizar uma verificação se a carta do topo do lixo conseguirá realizar jogos com as cartas da mão do bot e então puxar as cartas do lixo para formar jogos. 

Foram tentadas a realização de outras estratégia, mas até o tempo da entrega do trabalho não conseguimos resolver os problemas e torna-los utilizáveis.

A estratégia de descarte utilizada foi descartar as cartas através de comparações feitas entre elas baseadas em prioridades pré definidas, em casos de várias cartas possuírem a mesma prioridade de descarte, aquela que será descartada será a carta mais próxima ao fim da mão do bot.

### Tivemos problemas encontrados durante o projeto ??

Os principais problemas encontrados foram em relação ao armazenamento e verificação do lixo, toda estrutura foi difícil para nós de ser construída. Outra dificuldade foi descer uma carta da mão do bot para completar jogos já formadas na mesa, algo que não conseguimos até a entrega do trabalho.