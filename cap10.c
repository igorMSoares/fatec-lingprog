#include <stdio.h>
#include <stdlib.h>

#define ex2

void limpaBuffer() {
  while (getchar() != '\n')
    ;
}

/*
1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).
 */
#ifdef ex1
int main() {
  char res = '1';
  FILE *f;

  while (res == '1') {
    if ((f = fopen("arq.txt", "w")) == NULL) {
      printf("Erro ao abrir \"arq.txt\"\n");
      exit(0);
    }

    printf("\n>> Digite uma letra por vez, seguido de ENTER.\n");
    printf(">> Para encerrar a entrada de dados, digite 0 seguido de ENTER.\n");
    while (res != '0') {
      res = getchar();

      if (res == '0') {
        fclose(f);
        continue;
      }
      putc(res, f);
    }

    if ((f = fopen("arq.txt", "r")) == NULL) {
      printf("Erro ao abrir \"arq.txt\"\n");
      exit(0);
    }

    printf("\n");
    printf("===================================================\n");
    printf("                       arq.txt                     \n");
    printf("===================================================\n");

    char c;
    while ((c = getc(f)) != EOF) {
      putchar(c);
    }

    limpaBuffer();
    printf("\n> Digite 1 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}

#endif

/*
2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida

*/
#ifdef ex2
typedef struct Niver {
  int dia;
  int mes;
} Niver;

typedef struct Contato {
  char nome[21];
  char tel[21];
  Niver niver;
} Contato;

void escreverContatosNoArquivo(Contato *contatos, int max) {
  FILE *f = fopen("contatos.txt", "w");

  if (f == NULL) {
    printf("Erro ao abrir arquivo de contatos.\n");
    exit(0);
  }

  fwrite(contatos, sizeof(Contato), max, f);
  fclose(f);
}

void apagarString(char *s) {
  for (int i = 0; s[i] != '\0'; i++) {
    s[i] = '\0';
  }
}

int ehListaVazia(Contato *contatos, int max) {
  for (int i = 0; i < max; i++) {
    if (contatos[i].nome[0] != '\0') {
      return 0;
    }
  }

  return 1;
}

void lerContatosDoArquivo(Contato *contatos, int max) {
  FILE *f = fopen("contatos.txt", "r");

  if (f == NULL) {
    printf(">> Arquivo de contatos não existente.\nCriando arquivo...\n");

    for (int i = 0; i < max; i++) {
      contatos[i].nome[0] = '\0';
      contatos[i].tel[0] = '\0';
      contatos[i].niver.mes = 0;
      contatos[i].niver.dia = 0;
    }

    escreverContatosNoArquivo(contatos, max);
    printf(">> Arquivo de contatos criado com sucesso.\n");
    return;
  }

  fread(contatos, sizeof(Contato), max, f);
  if (!ehListaVazia(contatos, max)) {
    printf(">> Contatos carregados na memória.\n");
  }
  fclose(f);
}

void menu(char *res) {
  printf("\n");
  printf("===================================\n");
  printf("                MENU               \n");
  printf("===================================\n");
  printf("\t1. Inserir contato\n");
  printf("\t2. Listar todos os contatos\n");
  printf("\t3. Pesquisar contato por nome\n");
  printf("\t4. Filtrar contatos pela primeira letra do nome\n");
  printf("\t5. Listar os aniversariantes do mes\n");
  printf("\t6. Alterar contato\n");
  printf("\t7. Excluir contato\n");
  printf("\t8. Encerrar\n");
  printf("> Escolha uma das opções: ");
  scanf("%c", res);
  limpaBuffer();
}

void inserirContato(Contato *c) {
  printf("\n");
  printf("====================================\n");
  printf("             NOVO CONTATO           \n");
  printf("====================================\n");

  printf("> Nome: ");
  gets(c->nome);

  printf("> Telefone: ");
  gets(c->tel);

  printf("> Mes do aniversário: ");
  scanf("%d", &c->niver.mes);
  limpaBuffer();
  printf("> Dia do aniversário: ");
  scanf("%d", &c->niver.dia);
  limpaBuffer();
}

char NOME_DO_MES[12][10] = {"Janeiro",  "Fevereiro", "Março",    "Abril",
                            "Maio",     "Junho",     "Julho",    "Agosto",
                            "Setembro", "Outubro",   "Novembro", "Dezembro"};

void imprimirContato(Contato *c) {
  printf("\t%s\n", c->nome);
  printf("\tTelefone: %s\n", c->tel);
  printf("\tAniversario: %d de %s\n", (c->niver).dia,
         NOME_DO_MES[(c->niver).mes - 1]);
}

void listarContatos(Contato *contatos, int max) {
  if (ehListaVazia(contatos, max)) {
    printf("\nNenhum contato cadastrado.\n");
    printf("Digite 1 no MENU para cadastrar.\n\n");

    return;
  }

  int count = 1;
  for (int i = 0; i < max; i++) {
    if (contatos[i].nome[0] == '\0') {
      continue;
    }

    printf("\n%.3d:\n", count++);
    imprimirContato(&contatos[i]);
  }

  printf("\n");
}

int comparaStrings(char *a, char *b) {
  for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}

int pesquisarContatoPorNome(char *nome, Contato *c, int max) {
  for (int i = 0; i < max; i++) {
    if (comparaStrings(c[i].nome, nome)) {
      return i;
    }
  }

  return -1;
}

void filtrarContatoPrimeiraLetraNome(char x, Contato *contatos, int max) {
  int count = 1;

  for (int i = 0; i < max; i++) {
    if (x == contatos[i].nome[0]) {
      printf("\n%.3d:\n", count++);
      imprimirContato(&contatos[i]);
    }
  }
}

void listarAniversariantesDoMes(int mes, Contato *contatos, int max) {
  printf("\n");
  printf("====================================\n");
  printf("           ANIVERSARIANTES          \n");
  printf("====================================\n");

  int total = 0;

  for (int i = 0; i < max; i++) {
    if (contatos[i].niver.mes == mes) {
      printf("\n%.3d:\n", total + 1);
      imprimirContato(&contatos[i]);
      total++;
    }
  }

  if (total == 0) {
    printf(">> Nenhum aniversariante em %s\n", NOME_DO_MES[mes - 1]);
  }
}

void alterarContato(char *nome, Contato *contatos, int max) {
  int id = pesquisarContatoPorNome(nome, contatos, max);

  if (id == -1) {
    printf(">> \"%s\" nao esta cadastrado no sistema.\n\n", nome);
    return;
  }

  printf(">> Digite os novos dados\n");

  printf("> Nome: ");
  gets(contatos[id].nome);

  printf("> Telefone: ");
  gets(contatos[id].tel);

  printf("> Mes do aniversário: ");
  scanf("%d", &contatos[id].niver.mes);
  limpaBuffer();
  printf("> Dia do aniversário: ");
  scanf("%d", &contatos[id].niver.dia);
  limpaBuffer();
}

void excluirContato(char *nome, Contato *contatos, int max) {
  int id = pesquisarContatoPorNome(nome, contatos, max);

  if (id == -1) {
    printf(">> \"%s\" nao esta cadastrado no sistema.\n\n", nome);
    return;
  }

  apagarString(contatos[id].nome);
  apagarString(contatos[id].tel);
  contatos[id].niver.mes = 0;
  contatos[id].niver.dia = 0;

  printf("\"%s\" removido do registro de contatos.\n", nome);
}

int main() {
  char res = '0';
  int MAX_USUARIOS = 4;
  Contato contatos[4];
  char nome[21];
  char letra;
  int mes;

  lerContatosDoArquivo(contatos, MAX_USUARIOS);

  while (1) {
    menu(&res);

    switch (res) {
    case '1':
      for (int i = 0; i < MAX_USUARIOS; i++) {
        printf("\n%.3d:", i + 1);
        inserirContato(&contatos[i]);
      }
      break;
    case '2':
      listarContatos(contatos, MAX_USUARIOS);
      break;
    case '3':
      if (ehListaVazia(contatos, MAX_USUARIOS)) {
        printf("\nNenhum contato cadastrado.\n");
        printf("Digite 1 no MENU para cadastrar.\n\n");

        break;
      }

      printf("> Digite o nome do contato a ser pesquisado: ");
      gets(nome);
      int id = pesquisarContatoPorNome(nome, contatos, MAX_USUARIOS);

      if (id == -1) {
        printf(">> \"%s\" nao esta cadastrado no sistema.\n\n", nome);
        break;
      }

      printf("\n");
      imprimirContato(&contatos[id]);
      break;
    case '4':
      if (ehListaVazia(contatos, MAX_USUARIOS)) {
        printf("\nNenhum contato cadastrado.\n");
        printf("Digite 1 no MENU para cadastrar.\n\n");

        break;
      }

      printf("> Digite a primeira letra do nome: ");
      scanf("%c", &letra);
      limpaBuffer();

      filtrarContatoPrimeiraLetraNome(letra, contatos, MAX_USUARIOS);
      break;
    case '5':
      if (ehListaVazia(contatos, MAX_USUARIOS)) {
        printf("\nNenhum contato cadastrado.\n");
        printf("Digite 1 no MENU para cadastrar.\n\n");

        break;
      }

      printf("> Digite o numero correspondente ao mes: ");
      scanf("%d", &mes);
      limpaBuffer();

      listarAniversariantesDoMes(mes, contatos, MAX_USUARIOS);
      break;
    case '6':
      if (ehListaVazia(contatos, MAX_USUARIOS)) {
        printf("\nNenhum contato cadastrado.\n");
        printf("Digite 1 no MENU para cadastrar.\n\n");

        break;
      }

      printf("> Digite o nome do contato a ser alterado: ");
      gets(nome);

      alterarContato(nome, contatos, MAX_USUARIOS);
      break;
    case '7':
      if (ehListaVazia(contatos, MAX_USUARIOS)) {
        printf("\nNenhum contato cadastrado.\n");
        printf("Digite 1 no MENU para cadastrar.\n\n");

        break;
      }

      printf("> Digite o nome do contato a ser removido: ");
      gets(nome);

      excluirContato(nome, contatos, MAX_USUARIOS);
      break;
    case '8':
      if (!ehListaVazia(contatos, MAX_USUARIOS)) {
        escreverContatosNoArquivo(contatos, MAX_USUARIOS);
        printf(">> Contatos salvos no arquivo.\n");
      }
      exit(0);
    default:
      exit(0);
    }
  }
}
#endif

#ifdef ex
int main() {
  char res = '0';

  while (res == '0') {

    printf("\n\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif
