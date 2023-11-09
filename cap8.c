#include <stdio.h>

#define ex6

void limpaBuffer() {
  while (getchar() != '\n')
    ;
}

/*
1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
funcao para compara-las usando ponteiros e retorne como resultado se
sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
Imprima o resultado na funcao main(). Declare os vetores como variavel global
*/

#ifdef ex1
int comparaStrings(char *s1, char *s2) {
  while (*s1 == *s2 && (*s1 != '\0' || *s2 != '\0')) {
    s1++;
    s2++;
  }

  if (*s1 == '\0' && *s2 == '\0') {
    return 1;
  }

  return 0;
}

char string_1[11], string_2[11];

int main() {
  char res = '0';

  while (res == '0') {
    printf("Digite a 1ª string: ");
    scanf("%s", string_1);
    limpaBuffer();

    printf("Digite a 2ª string: ");
    scanf("%s", string_2);
    limpaBuffer();

    printf("\n>> \"%s\" e \"%s\" são %s", string_1, string_2,
           comparaStrings(string_1, string_2) ? "iguais" : "diferentes");

    printf("\n\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif

/*
2 - Escreva um programa que receba uma letra via teclado usando ponteiro.
Escreva uma funcao que pesquise esta letra existe no vetor abaixo usando
ponteiros. Imprima o resultado da pesquisa no video na funcao main(). Passe como
informacao para a funcao a letra digitada usando ponteiros.(utilize o comando
return). O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/
#ifdef ex2
char vetor[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm',
                'o', 'q', 's', 'u', 'w', 'y'};

void recebeLetra(char *l) {
  printf("Digite uma letra: ");
  *l = getchar();
  limpaBuffer();
}

int procuraLetra(char *l) {
  for (int i = 0; i < 13; i++) {
    if (vetor[i] == *l) {
      return 1;
    }
  }

  return 0;
}

int main() {
  char res = '0';
  char letra;

  while (res == '0') {
    recebeLetra(&letra);
    printf("\n>> '%c' %s encontrada no vetor.", letra,
           procuraLetra(&letra) ? "\b" : "não");

    printf("\n\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif

/*
3 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/
#ifdef ex3
void recebeDados(char *c, int *i, long *l, float *f, double *d,
                 unsigned char *uc, unsigned int *ui, unsigned long *ul) {
  printf("Digite um valor para cada tipo:\n");
  printf("char: ");
  scanf("%c", c);
  printf("int: ");
  scanf("%d", i);
  printf("long: ");
  scanf("%ld", l);
  printf("float: ");
  scanf("%f", f);
  printf("double: ");
  scanf("%lf", d);
  printf("unsigned char: ");
  scanf("%s", uc);
  printf("unsigned int: ");
  scanf("%u", ui);
  printf("unsigned long: ");
  scanf("%lu", ul);
  limpaBuffer();
}

void imprimeDados(char *c, int *i, long *l, float *f, double *d,
                  unsigned char *uc, unsigned int *ui, unsigned long *ul) {
  printf("        10        20        30        40        50        60        "
         "70\n");
  printf("123456789012345678901234567890123456789012345678901234567890123456789"
         "0\n");

  printf("%5d", *i);
  printf("%20ld", *l);
  printf("%20u\n", *ui);

  printf("%18.2f", *f);
  printf("%22.2lf", *d);
  printf("%15c\n", *c);

  printf("%10lu", *ul);
  printf("%20c\n", *uc);
}

int main() {
  char res = '0';
  char c;
  int i;
  long l;
  float f;
  double d;
  unsigned char uc;
  unsigned int ui;
  unsigned long ul;

  while (res == '0') {
    recebeDados(&c, &i, &l, &f, &d, &uc, &ui, &ul);
    imprimeDados(&c, &i, &l, &f, &d, &uc, &ui, &ul);

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
}
#endif

/*
4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
ponteiros. Quando o numero digitado for negativo o programa deve parar e
calcula a media dos valores digitados e mostrar o resultado. Todos os calculos
devem ser feitos usando ponteiro.
*/
#ifdef ex4
void recebeNumerosPositivos(float *num, float *med) {
  printf("\n");
  printf("===================================================\n");
  printf("                     INSTRUÇÕES                    \n");
  printf("===================================================\n");
  printf("Digite um número negativo para encerrar e \n");
  printf("calcular a média dos numeros positivos digitados.\n\n");

  for (int i = 1;; i++) {
    printf("Digite um número positivo: ");
    scanf("%f", num);
    limpaBuffer();

    if (*num < 0) {
      return;
    }

    if (i == 1) {
      *med = *num;
      continue;
    }

    if (i == 2) {
      *med = (*med + *num) / 2;
      continue;
    }

    *med = (*med * (i - 1) + *num) / i;
  }
}

int main() {
  char res = '0';

  while (res == '0') {
    float media = 0, n;
    recebeNumerosPositivos(&n, &media);
    printf("\nMédia dos números positivos: %.2f\n", media);

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
}
#endif

/*
5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/
#ifdef ex5
typedef struct Cadastro {
  char nome[21];
  char end[51];
  char cidade[21];
  char estado[3];
  char cep[11];
} Cadastro;

Cadastro cadastros[4] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

void preencherDados(Cadastro *pUsuarios, int total) {
  for (int i = 0; i < total; i++) {
    printf("\n");
    printf("====================================\n");
    printf("            NOVO CADASTRO           \n");
    printf("====================================\n");

    printf("\n%d:\n", i + 1);
    printf("\tNome: ");
    gets((pUsuarios + i)->nome);
    printf("\tEndereço: ");
    gets((pUsuarios + i)->end);
    printf("\tCEP: ");
    gets((pUsuarios + i)->cep);
    printf("\tCidade: ");
    gets((pUsuarios + i)->cidade);
    printf("\tEstado (apenas a sigla): ");
    gets((pUsuarios + i)->estado);
  }

  printf("\n");
}

void exibirDados(Cadastro *pUsuarios, int total) {
  printf("\n");
  printf("====================================\n");
  printf("               USUÁRIOS             \n");
  printf("====================================\n");

  if (pUsuarios[0].nome[0] == 0) {
    printf("\nNenhum usuário cadastrado.\n");

    return;
  }

  for (int i = 0; i < total; i++) {
    printf("\n%d:\n", i + 1);
    printf("\t%s\n", (pUsuarios + i)->nome);
    printf("\tEndereço: %s\n", (pUsuarios + i)->end);
    printf("\tCEP: %s\n", (pUsuarios + i)->cep);
    printf("\t%s/%s\n", (pUsuarios + i)->cidade, (pUsuarios + i)->estado);
  }

  printf("\n");
}

int main() {
  char res = '0';

  while (res == '0') {
    preencherDados(cadastros, 4);
    exibirDados(cadastros, 4);

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
}
#endif

/*
6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
        estrutura: dia, mes e ano
*/
#ifdef ex6
typedef struct Data {
  int dia;
  int mes;
  int ano;
} Data;

Data datas[2];

void receberDatas(Data *pData) {
  int entradasValidas = 0;

  for (int i = 0; i < 2; i++) {
    printf("\nDigite a %dª data no formato dd/mm/aaaa: ", i + 1);
    entradasValidas = scanf("%d/%d/%d", &(pData + i)->dia, &(pData + i)->mes,
                            &(pData + i)->ano);
    limpaBuffer();

    if (entradasValidas != 3) {
      printf("\tFormato inválido.\n");
      printf("\tExemplo de data válida: 1/12/1998\n");
      i--;
    }
  }
}

int ehAnoBissexto(int ano) {
  if (ano % 4 != 0) {
    // não divisível por 4: não bissexto
    return 0;
  }

  if (ano % 100 != 0 || ano % 400 == 0) {
    // divisível por 4 e não por 100
    // ou divisível por 100 e por 400
    // é bissexto
    return 1;
  }

  return 0;
}

int calcularTotalDeAnosBissextos(int ano_1, int ano_2) {
  int ano;
  int total = 0;
  if (ano_1 > ano_2) {
    for (ano = ano_2 + 1; !ehAnoBissexto(ano); ano++)
      ;

    while (ano < ano_1) {
      total++;
      ano += 4;
    }
  } else {
    for (ano = ano_1 + 1; !ehAnoBissexto(ano); ano++)
      ;

    while (ano < ano_2) {
      total++;
      ano += 4;
    }
  }

  if (ehAnoBissexto(ano_1)) {
    total++;
  }

  if (ehAnoBissexto(ano_2)) {
    total++;
  }

  return total;
}

int calcularDias(Data *pData) {
  Data data_1 = *pData;
  Data data_2 = *(pData + 1);

  int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (data_1.ano == data_2.ano && data_1.mes == data_2.mes) {
    int diaFinal = data_1.dia, diaInicial = data_2.dia;

    if (data_1.dia < data_2.dia) {
      diaInicial = data_1.dia;
      diaFinal = data_2.dia;
    }

    return diaFinal - diaInicial;
  }

  int totalDeDias = 0;
  int mesInicial, mesFinal, diaInicial, diaFinal;

  if (data_1.ano == data_2.ano) {
    if (data_1.mes < data_2.mes) {
      diaInicial = data_1.dia;
      mesInicial = data_1.mes;
      diaFinal = data_2.dia;
      mesFinal = data_2.mes;
    } else {
      diaInicial = data_2.dia;
      mesInicial = data_2.mes;
      diaFinal = data_1.dia;
      mesFinal = data_1.mes;
    }

    for (int mes = mesInicial + 1; mes != mesFinal; mes++) {
      totalDeDias += diasNoMes[mes - 1];
    }

    totalDeDias += diasNoMes[mesInicial - 1] - diaInicial;
    totalDeDias += diaFinal;

    return totalDeDias;
  }

  int anoInicial, anoFinal;

  if (data_1.ano < data_2.ano) {
    diaInicial = data_1.dia;
    mesInicial = data_1.mes;
    anoInicial = data_1.ano;

    diaFinal = data_2.dia;
    mesFinal = data_2.mes;
    anoFinal = data_2.ano;
  } else {
    diaInicial = data_2.dia;
    mesInicial = data_2.mes;
    anoInicial = data_2.ano;

    diaFinal = data_1.dia;
    mesFinal = data_1.mes;
    anoFinal = data_1.ano;
  }

  for (int ano = anoInicial; ano != anoFinal - 1; ano++) {
    totalDeDias += 365;
  }
  totalDeDias += calcularTotalDeAnosBissextos(anoInicial, anoFinal);

  for (int mes = mesInicial + 1; mes <= 12; mes++) {
    totalDeDias += diasNoMes[mes - 1];
  }
  totalDeDias += diasNoMes[12 - 1] - diaInicial;

  for (int mes = 1; mes < mesFinal; mes++) {
    totalDeDias += diasNoMes[mes - 1];
  }
  totalDeDias += diaFinal;

  return totalDeDias;
}

int main() {
  char res = '0';

  while (res == '0') {
    receberDatas(datas);
    printf("\n\t%d dias entre ", calcularDias(datas));
    printf("%d/%d/%d e ", datas[0].dia, datas[0].mes, datas[0].ano);
    printf("%d/%d/%d\n", datas[1].dia, datas[1].mes, datas[1].ano);

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif
