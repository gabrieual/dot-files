#### 1. Em um terminal de comando, liste somente os processos que estão em execução no terminal atual. Ilustre o resultado obtido.
Para listar processos em execução nós usamos o comando `ps` com a opção `-t $(tty)` para filtra apenas os processos associados ao terminal atual (`tty` retorna o terminal em uso). 
```bash
ps -t $(tty)
```
Saída:
![[screenshot_2025-03-19_16-05-41.png]]
#### 2. Em um terminal de comando, liste todos os processos do Linux, exibindo nomes de usuários que iniciaram tais processos. Ilustre o resultado obtido.
Para mostrar os processos juntamente do usuário que o iniciou podemos usar o mesmo comando `ps` da questão anterior usando a flag `-e` para listar todos os processos e `-o user,cmd` para definir as colunas (`user`: nome do usuário, `cmd`: nome do comando que iniciou o processo)
```bash
ps -eo user,cmd
```
Porém, vou utilizar o comando `htop` que tenho instalado que vai nos mostrar de forma dinâmica (e mais bonita) os processos, na segunda coluna "USER" temos o nome do usuário que iniciou cada processo.
```bash
htop
```
Saída:
![[screenshot_2025-03-19_16-25-40 1.png]]
![[screenshot_2025-03-19_17-01-21 1.png]]
#### 3. Com o resultado obtido no item anterior, sumarize os estados dos processos obtidos e descreva cada um.
Os estados podem ser verificados na coluna "S", temos quatro estados principais `S`, `R`, `I` e `D`, vamos sumariza-los:
- **S (Sleeping)**: estado da maioria dos processos como o **systemd** e o **NetworkManager**, são processos que estão aguardando algum evento.
- **R (Running)**: estado do processo **htop** que é quem está nos mostrando todos os processos, são os processos que estão em execução no momento.
- **D (Uninterruptible Sleep)**: estado do processo **kworker/u66:1**, são processos que estão em espera.
- **I (Idle)**: estado de muitos dos processos, indica que são um thread inativo do kernel.
#### 4. Escolha um dos usuários presentes do item anterior e através de um terminal de comando, liste os processos somente deste usuário selecionado. Ilustre o resultado obtido.
Vamos usar `ps` novamente, mas com a flag `-u` e o nome do usuário passado como parâmetro, no caso o usuário escolhido será "gabrieu".
```bash
ps -u gabrieu
```
Saída:
![[screenshot_2025-03-19_18-07-30.png]]
#### 5. Em um terminal de comando, liste em forma de árvore hierárquica os processos residentes no sistema com seus respectivos identificadores (PID), ilustrando o resultado abaixo, e:
Usando `htop`:
```bash
htop --tree
```
Saída:
![[screenshot_2025-03-19_18-25-09.png]]
Usando `pstree` com `-p` para mostrar o PID:
```bash
pstree -p 
```
Saída:
![[screenshot_2025-03-19_18-46-57.png]]
##### a. Identifique qual o processo raiz do Linux e o seu respectivo PID.
O processo raíz é o **init** (um alias para o `systemd`) com **PID 1**, no `pstree` temos o nome do gerenciador de processos o **systemd**.
##### b) Identifique qual o processo pai do comando utilizado para realizar o item 4 acima e o seu identificador (PID).
O `pstree` tem como pai **bash** com PID 22468.
![[screenshot_2025-03-19_18-52-25.png]] 
##### c) Liste a árvore hierárquica de processos que tem como raiz da árvore, o pai do processo obtido no item anterior.
O Processo pai do bash é o **kitty**, o emulador de terminal. Listando eles:
├─kitty(22451)─┬─bash(22468)───pstree(24641)
│              ├─kitten(22466)─┬─{kitten}(22469)
│              │               ├─{kitten}(22470)
│              │               ├─{kitten}(22471)
│              │               ├─{kitten}(22472)
│              │               ├─{kitten}(22473)
│              │               ├─{kitten}(22474)
│              │               ├─{kitten}(22475)
│              │               ├─{kitten}(22476)
│              │               └─{kitten}(22477)
│              ├─{kitty}(22452)
│              ├─{kitty}(22453)
│              ├─{kitty}(22454)
│              ├─{kitty}(22455)
│              ├─{kitty}(22456)
│              ├─{kitty}(22457)
│              ├─{kitty}(22458)
│              ├─{kitty}(22459)
│              ├─{kitty}(22460)
│              ├─{kitty}(22461)
│              ├─{kitty}(22462)
│              ├─{kitty}(22463)
│              ├─{kitty}(22467)
│              ├─{kitty}(23869)
│              └─{kitty}(23870)

![[screenshot_2025-03-19_18-57-10.png]]
##### d) Liste a árvore de processos que foram iniciados pelo usuário escolhido no item 4.

6- (0,5) Em um terminal de comando, qual o comando utilizado para monitorar os processos e
recursos do sistema em tempo real com período de atualização igual a 10s? Execute o comando

em questão e ilustre o resultado obtido em uma iteração e explique o significado da informação
apresentada em cada coluna.
7- Liste os processos que estejam no diretório /proc e faça o que se pede:
a) (0,25) Identifique o nome de executável de 3 deles. Identifique como foram obtidas
estas informações ( comando, arquivo acessado, etc)
b) (0,25) Informe o número de trocas de contexto voluntárias e involuntárias ocorreram
para estes processos até o presente momento. Identifique como foi obtida estas
informações ( comando, arquivo acessado, etc.).
c) (0,25) Quais outras informações sobre os processos podem ser obtidas através da leitura
dos arquivos presentes no diretório de cada processo? Exemplifique uma destas
informações (apresente o resultado obtido, qual a operação utilizada para obter e
comente as informações).
d) (0,25) Navegue pelo diretório /proc/sys/kernel e exiba o número máximo de processos
e threads que o kernel pode executar simultaneamente.
8- Compile o programa-fonte codigo0.c. Este programa simplesmente fica em um laço ocioso.
Após compilar o programa, faça o que se pede:
a) Em dois terminais de comandos distintos, execute o programa (executável) gerado na
compilação (um em background e outro em foreground).
b) (0,75) Em um terceiro terminal utilize o comando top e verifique quais os identificadores
dado ao programa executado no item anterior. Quantos identificadores (PID) existem associados
ao programa teste? Os valores dos PIDs são diferentes? Por quê?
c) (0,25) Através do comando top, identifique quais os valores de prioridade efetiva, Nice (NI),
associados a estes processos pelo Sistema Operacional.
d) (0,25) Envie um sinal, através do terminal de comando, para parar os dois processos
descritos. Apresente o comando utilizado e o resultado obtido.
e) (0,25) Envie um sinal, através do terminal de comando, retomar/ desbloquear os processos.
Apresente o comando utilizado e o resultado obtido.
f) (0,25) Envie um sinal, através do terminal de comando, para finalizar os processos descritos
no item anterior. Apresente o comando utilizado e o resultado obtido.
g) (0,25) Em um terminal de comando, execute o programa codigo0 com valor de prioridade
(PR) igual a 5 unidades maior que o obtido no item c. Qual o comando utilizado? Apresente o
resultado obtido.
h) (0,25) Com o processo referido no item anterior em execução, aumente o valor da sua
prioridade (NI) em 10 unidades. Apresente o resultado obtido.
j) (0,25) Ainda com o processo em execução, aumente o valor de sua prioridade em 10. Foi
possível? Caso negativo, qual foi o valor configurado (aceito)? Apresente o resultado obtido.
l) (0,5) Reduza a prioridade do processo em execução (do item anterior) para -30. Foi possível?
Caso negativo, qual o problema ocorrido? Tente alterá-la para 0. Foi possível? Faça o login

como superusuário (root) e redefina a prioridade do processo para -30 novamente. Foi possível?
Caso negativo, qual foi o valor configurado (aceito)? Apresente o resultado obtido.
9. Compile o código-fonte codigo1.c e em seguida execute-o.
a) (0,5) Quantos processos foram criados com a execução do programa? Quais os
identificadores de cada um? Qual a hierarquia entre eles?
b) (1,0) Em outro terminal, identifique os estados dos processos. Qual o estado do processo pai?
Qual o estado do processo filho? O processo filho já terminou seu trabalho? Explique o motivo
do processo filho se encontrar no referido estado.
10. Compile o código-fonte codigo2.c e em seguida execute-o.
a) (0,5) Quais os identificadores (PID) dos processos criados? Qual a hierarquia entre eles?
b) (0,75) Em outro terminal, identifique os estados dos processos. Qual o estado do processo
pai? O processo filho terminou seu trabalho? Qual seu estado? Por que, neste caso, o processo
filho não ficou no estado Zumbi? Comente a diferença entre este caso e o apresentado na
questão 9.
11 (0,25) Todas as informações que o S.O. precisa para poder controlar a execução do processo
(atributos do processo) encontram-se no Bloco de Controle do Processo (ou Process Control
Block). No Linux, essa estrutura de dados é implementada por meio da estrutura task_struct,
que é definidas no arquivo sched.h. Procure e abra o arquivo fonte do sched.h no seu Linux. No
Ubuntu, ele fica no diretório include (por exemplo: /usr/src/linux-headers-4.15.0-58-
generic/include/linux). Analise a struct task_struct e destaque alguns dos seus campos.