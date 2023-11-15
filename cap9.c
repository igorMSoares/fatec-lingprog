#include <stdio.h>

#define ex2

void limpaBuffer() {
  while (getchar() != '\n')
    ;
}

/*
1 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().
*/
#ifdef ex1
void recebeStrings(char *a, char *b, int maximo) {
  printf("Digite palavras com no máximo %d caracteres.\n", maximo);
  printf("> 1ª palavra: ");
  scanf("%s", a);
  limpaBuffer();
  a[maximo] = '\0';

  printf("> 2ª palavra: ");
  scanf("%s", b);
  limpaBuffer();
  b[maximo] = '\0';
}

int comparaStrings(char *a, char *b) {
  for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  char s1[11], s2[11];

  recebeStrings(s1, s2, 10);
  printf("\n>> \"%s\" e \"%s\" são ", s1, s2);
  printf("%s.\n", comparaStrings(s1, s2) ? "IGUAIS" : "DIFERENTES");

  return 0;
}
#endif

/*
2 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().
*/
#ifdef ex2
#include <math.h>

void soma(float *x, float *y) { *x += *y; }

void subtrai(float *x, float *y) { *x -= *y; }

void multiplica(float *x, float *y) { *x *= *y; }

void divide(float *x, float *y) {
  if (*y == 0) {
    *x = 0;
    return;
  }

  // retorna resultado com precisao de apenas duas casas decimais
  *x = trunc((*x / *y) * 100) / 100;
}

void imprime_total_parcial(float *total) {
  // omite casas decimais quando forem iguais a 0
  if ((int)*total == *total) {
    printf("\n%.0f\n", *total);
  } else {
    printf("\n%.2f\n", *total);
  }
}

void imprime_total_final(float *total) {
  // omite casas decimais quando forem iguais a 0
  if ((int)*total == *total) {
    printf("\tTotal: %.0f\n", *total);
  } else {
    printf("\tTotal: %.2f\n", *total);
  }
}

void entradaDeDados(char *operador, float *n) {
  scanf("%c", operador);
  limpaBuffer();

  if (*operador != '=') {
    scanf("%f", n);
    limpaBuffer();
  }
}

int main() {
  float total = 0, n;
  char operador = '\0';

  printf("-------------------------------\n");
  printf("          CALCULADORA          \n");
  printf("-------------------------------\n");

  printf("1. Digite um numero e aperte Enter\n");
  printf("2. Em seguida digite um operador matematico (+, -, *, / ou =)\n");
  printf("3. Aperte Enter novamente\n");
  printf("4. Digite o proximo numero para continuar calculando\n\n");
  scanf("%f", &total);
  limpaBuffer();

  while (operador != '=') {
    entradaDeDados(&operador, &n);

    switch (operador) {
    case '+':
      soma(&total, &n);
      break;
    case '-':
      subtrai(&total, &n);
      break;
    case '*':
      multiplica(&total, &n);
      break;
    case '/':
      divide(&total, &n);
      break;
    case '=':
      imprime_total_final(&total);
      return 0;
    default:
      printf("\nOperador invalido.\n");
      printf("Digite um operador valido (+, -, *, / ou =)\n");
    }

    // imprime_total_parcial(&total);
  }
}
#endif

/*
3 - Escreva um programa que receba uma letra via teclado usando ponteiro.
Escreva uma funcao que pesquise se esta letra existe no vetor abaixo usando
ponteiros. Imprima o resultado da pesquisa no video na funcao main(). Passe como
informacao para a funcao a letra digitada e o vetor usando ponteiros e faca a
pesquisa usando ponteiros.(utilize o comando return). O vetor deve ser declarado
como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/
#ifdef ex3
void recebeLetra(char *x) { *x = getchar(); }

int procuraLetra(char *c, char *letras) {
  for (int i = 0; i < 13; i++) {
    if (letras[i] == *c) {
      return 1;
    }
  }

  return 0;
}

int main() {
  char res = '0';

  while (res == '0') {
    char c;
    char letras[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm',
                     'o', 'q', 's', 'u', 'w', 'y'};

    printf("> Digite uma letra: ");
    recebeLetra(&c);
    limpaBuffer();
    printf(">> '%c' %s esta presente no vetor.\n", c,
           procuraLetra(&c, letras) ? "\b" : "nao");

    printf("\n> Digite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
  return 0;
}
#endif

/*
4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/
#ifdef ex4
typedef struct Estrutura {
  char c;
  int i;
  long l;
  float f;
  double d;
  unsigned char uc;
  unsigned int ui;
  unsigned long ul;
} Estrutura;

void recebeDados(Estrutura *x) {
  printf("Digite um valor para cada tipo:\n");
  printf("char: ");
  scanf("%c", &x->c);
  printf("int: ");
  scanf("%d", &x->i);
  printf("long: ");
  scanf("%ld", &x->l);
  printf("float: ");
  scanf("%f", &x->f);
  printf("double: ");
  scanf("%lf", &x->d);
  printf("unsigned char: ");
  scanf("%s", &x->uc);
  printf("unsigned int: ");
  scanf("%u", &x->ui);
  printf("unsigned long: ");
  scanf("%lu", &x->ul);
  limpaBuffer();
}

void imprimeDados(Estrutura *x) {
  printf("        10        20        30        40        50        60        "
         "70\n");
  printf("123456789012345678901234567890123456789012345678901234567890123456789"
         "0\n");

  printf("%5c", x->c);
  printf("%10d", x->i);
  printf("%10ld", x->l);
  printf("%23.2f", x->f);
  printf("%20.2lf\n", x->d);
  printf("%11c", x->uc);
  printf("%20u", x->ui);
  printf("%20lu\n", x->ul);
}

int main() {
  char res = '0';

  Estrutura x;

  while (res == '0') {
    recebeDados(&x);
    imprimeDados(&x);

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif

/*
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep
*/
#ifdef ex5
#include <stdlib.h>

typedef struct Cadastro {
  char nome[21];
  char end[51];
  char cidade[21];
  char estado[3];
  char cep[11];
} Cadastro;

void menu(char *res) {

  printf("===================================\n");
  printf("                MENU               \n");
  printf("===================================\n");
  printf("\t1. Preencher Dados\n");
  printf("\t2. Exibir Dados\n");
  printf("\t0. Encerrar\n");
  printf("Digite uma das opções [1/2/0]: ");
  scanf("%c", res);
  limpaBuffer();
}

void preencherDados(Cadastro *usuarios, int max) {
  for (int i = 0; i < max; i++) {
    printf("\n");
    printf("====================================\n");
    printf("            NOVO CADASTRO           \n");
    printf("====================================\n");

    printf("\n%d:\n", i + 1);
    printf("\tNome: ");
    gets(usuarios[i].nome);
    printf("\tEndereço: ");
    gets(usuarios[i].end);
    printf("\tCEP: ");
    gets(usuarios[i].cep);
    printf("\tCidade: ");
    gets(usuarios[i].cidade);
    printf("\tEstado (apenas a sigla): ");
    gets(usuarios[i].estado);
  }

  printf("\n");
}

void exibirDados(Cadastro *usuarios, int max) {
  if (usuarios[0].nome[0] == 0) {
    printf("\nNenhum usuário cadastrado.\n");
    printf("Digite 1 no MENU para cadastrar.\n\n");

    return;
  }

  for (int i = 0; i < max; i++) {
    printf("\n%d:\n", i + 1);
    printf("\t%s\n", usuarios[i].nome);
    printf("\tEndereço: %s\n", usuarios[i].end);
    printf("\tCEP: %s\n", usuarios[i].cep);
    printf("\t%s/%s\n", usuarios[i].cidade, usuarios[i].estado);
  }

  printf("\n");
}

int main() {
  char res;
  int MAX_USUARIOS = 4;
  Cadastro usuarios[4] = {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
  };

  while (1) {
    menu(&res);

    switch (res) {
    case '1':
      preencherDados(usuarios, MAX_USUARIOS);
      break;
    case '2':
      exibirDados(usuarios, MAX_USUARIOS);
      break;
    case '0':
      exit(0);
    default:
      exit(0);
    }
  }

  return 0;
}
#endif

/*
6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.
*/
#ifdef ex6
#include <stdlib.h>

typedef struct Cadastro {
  char nome[21];
  char end[51];
  char cidade[21];
  char estado[3];
  char cep[11];
} Cadastro;

void menu(char *res) {

  printf("===================================\n");
  printf("                MENU               \n");
  printf("===================================\n");
  printf("\t1. Preencher Dados\n");
  printf("\t2. Exibir Dados\n");
  printf("\t3. Procurar Usuário\n");
  printf("\t4. Alterar Cadastro de Usuário\n");
  printf("\t5. Deletar Cadastro de Usuário\n");
  printf("\t0. Encerrar\n");
  printf("Digite uma das opções [1/2/3/4/5/0]: ");
  scanf("%c", res);
  limpaBuffer();
}

void preencherDados(Cadastro *usuarios, int max) {
  for (int i = 0; i < max; i++) {
    printf("\n");
    printf("====================================\n");
    printf("            NOVO CADASTRO           \n");
    printf("====================================\n");

    printf("\n%d:\n", i + 1);
    printf("\tNome: ");
    gets(usuarios[i].nome);
    printf("\tEndereço: ");
    gets(usuarios[i].end);
    printf("\tCEP: ");
    gets(usuarios[i].cep);
    printf("\tCidade: ");
    gets(usuarios[i].cidade);
    printf("\tEstado (apenas a sigla): ");
    gets(usuarios[i].estado);
  }

  printf("\n");
}

void exibirDados(Cadastro *usuarios, int max) {
  if (usuarios[0].nome[0] == 0) {
    printf("\nNenhum usuário cadastrado.\n");
    printf("Digite 1 no MENU para cadastrar.\n\n");

    return;
  }

  int n = 1;

  for (int i = 0; i < max; i++) {
    if (usuarios[i].nome[0] == '\0') {
      continue;
    }

    printf("\n%d:\n", n++);
    printf("\t%s\n", usuarios[i].nome);
    printf("\tEndereço: %s\n", usuarios[i].end);
    printf("\tCEP: %s\n", usuarios[i].cep);
    printf("\t%s/%s\n", usuarios[i].cidade, usuarios[i].estado);
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

void apagarString(char *s) {
  for (int i = 0; s[i] != '\0'; i++) {
    s[i] = '\0';
  }
}

// copia a para b
void copiarStrings(char *a, char *b) {
  int i;

  for (i = 0; a[i] != '\0'; i++) {
    b[i] = a[i];
  }

  b[i] = '\0';
}

int procurarUsuario(char *nome, Cadastro *usuarios, int max) {
  for (int i = 0; i < max; i++) {
    if (comparaStrings(usuarios[i].nome, nome)) {
      return i;
    }
  }

  return -1;
}

void exibirUsuario(char *nome, Cadastro *usuarios, int max) {
  int id = procurarUsuario(nome, usuarios, max);

  printf("\n");
  if (id != -1) {
    printf("====================================\n");
    printf("             USUARIO #%.2d            \n", id);
    printf("====================================\n");

    printf("\t%s\n", usuarios[id].nome);
    printf("\tEndereço: %s\n", usuarios[id].end);
    printf("\tCEP: %s\n", usuarios[id].cep);
    printf("\t%s/%s\n\n", usuarios[id].cidade, usuarios[id].estado);
    return;
  }

  printf(">> \"%s\" nao esta cadastrado no sistema.\n\n", nome);
}

void excluirUsuario(char *nome, Cadastro *usuarios, int max) {
  int id = procurarUsuario(nome, usuarios, max);

  printf("\n");
  if (id != -1) {
    apagarString(usuarios[id].nome);
    apagarString(usuarios[id].end);
    apagarString(usuarios[id].cep);
    apagarString(usuarios[id].cidade);
    apagarString(usuarios[id].estado);

    printf(">> Cadastrado do usuario \"%s\" removido do sistema.\n\n", nome);
    return;
  }

  printf(">> \"%s\" nao esta cadastrado no sistema.\n\n", nome);
}

void alterarUsuario(char *nome, Cadastro *usuarios, int max) {
  int id = procurarUsuario(nome, usuarios, max);

  printf("\n");
  if (id != -1) {
    char buffer[51];
    printf("\n");
    printf("====================================\n");
    printf("             NOVOS DADOS            \n");
    printf("====================================\n");

    printf("\tNome: ");
    gets(buffer);
    copiarStrings(buffer, usuarios[id].nome);

    printf("\tEndereço: ");
    gets(buffer);
    copiarStrings(buffer, usuarios[id].end);

    printf("\tCEP: ");
    gets(buffer);
    copiarStrings(buffer, usuarios[id].cep);

    printf("\tCidade: ");
    gets(buffer);
    copiarStrings(buffer, usuarios[id].cidade);

    printf("\tEstado (apenas a sigla): ");
    gets(buffer);
    copiarStrings(buffer, usuarios[id].estado);

    printf("\n");
    return;
  }

  printf(">> \"%s\" nao esta cadastrado no sistema.\n\n", nome);
}

int main() {
  char res;
  char nome[21];
  int MAX_USUARIOS = 4;
  Cadastro usuarios[4] = {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
  };

  while (1) {
    menu(&res);

    switch (res) {
    case '1':
      preencherDados(usuarios, MAX_USUARIOS);
      break;
    case '2':
      exibirDados(usuarios, MAX_USUARIOS);
      break;
    case '3':

      printf("> Digite o nome a ser buscado: ");
      gets(nome);

      exibirUsuario(nome, usuarios, MAX_USUARIOS);
      break;
    case '4':
      printf("> Digite o nome do usuario a alterar: ");
      gets(nome);

      alterarUsuario(nome, usuarios, MAX_USUARIOS);
      break;
    case '5':
      printf("> Digite o nome do usuario a ser removido: ");
      gets(nome);

      excluirUsuario(nome, usuarios, MAX_USUARIOS);
      break;
    case '0':
      exit(0);
    default:
      exit(0);
    }
  }

  return 0;
}
#endif
