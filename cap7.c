#include <stdio.h>
#include <stdlib.h>

#define ex3

void limpaBuffer() {
  while (getchar() != '\n')
    ;
}

/*
1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int             long          float           double
              unsigned char       unsigned int        unsigned long

*/
#ifdef ex1
struct Estrutura {
  char c;
  int i;
  long l;
  float f;
  double d;
  unsigned char uc;
  unsigned int ui;
  unsigned long ul;
};

struct Estrutura x;

void recebeDados() {
  printf("Digite um valor para cada tipo:\n");
  printf("char: ");
  scanf("%c", &x.c);
  printf("int: ");
  scanf("%d", &x.i);
  printf("long: ");
  scanf("%ld", &x.l);
  printf("float: ");
  scanf("%f", &x.f);
  printf("double: ");
  scanf("%lf", &x.d);
  printf("unsigned char: ");
  scanf("%s", &x.uc);
  printf("unsigned int: ");
  scanf("%u", &x.ui);
  printf("unsigned long: ");
  scanf("%lu", &x.ul);
  limpaBuffer();
}

void imprimeDados() {
  printf("        10        20        30        40        50        60        "
         "70\n");
  printf("123456789012345678901234567890123456789012345678901234567890123456789"
         "0\n");

  printf("%5c", x.c);
  printf("%10d", x.i);
  printf("%16ld", x.l);
  printf("%17.2f", x.f);
  printf("%16.2lf\n", x.d);
  printf("%11c", x.uc);
  printf("%20u", x.ui);
  printf("%20lu\n", x.ul);
}

int main() {
  char res = '0';

  while (res == '0') {
    recebeDados();
    imprimeDados();

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif

/*
2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faca um menu com uma opcao para saida do programa.
                estrutura: nome, end, cidade, estado, cep
*/
#ifdef ex2
struct Cadastro {
  char nome[21];
  char end[51];
  char cidade[21];
  char estado[3];
  char cep[11];
};

struct Cadastro usuarios[4] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

char menu() {
  char res;

  printf("===================================\n");
  printf("                MENU               \n");
  printf("===================================\n");
  printf("\t1. Preencher Dados\n");
  printf("\t2. Exibir Dados\n");
  printf("\t0. Encerrar\n");
  printf("Digite uma das opções [1/2/0]: ");
  scanf("%c", &res);
  limpaBuffer();

  return res;
}

void preencherDados() {
  for (int i = 0; i < 4; i++) {
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

void exibirDados() {
  if (usuarios[0].nome[0] == 0) {
    printf("\nNenhum usuário cadastrado.\n");
    printf("Digite 1 no MENU para cadastrar.\n\n");

    return;
  }

  for (int i = 0; i < 4; i++) {
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

  while (1) {
    res = menu();

    switch (res) {
    case '1':
      preencherDados();
      break;
    case '2':
      exibirDados();
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
3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano

*/
#ifdef ex3
struct Data {
  int dia;
  int mes;
  int ano;
};

struct Data data_1;
struct Data data_2;

void receberDatas() {
  int entradasValidas = 0;

  for (int i = 0; i < 2; i++) {
    printf("\nDigite a %dª data no formato dd/mm/aaaa: ", i + 1);
    switch (i) {
    case 0:
      entradasValidas =
          scanf("%d/%d/%d", &data_1.dia, &data_1.mes, &data_1.ano);
      break;
    case 1:
      entradasValidas =
          scanf("%d/%d/%d", &data_2.dia, &data_2.mes, &data_2.ano);
      break;
    }
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

void imprimeTotalDeDias(int total) {
  printf("\n\t%d dias entre ", total);
  printf("%d/%d/%d e ", data_1.dia, data_1.mes, data_1.ano);
  printf("%d/%d/%d\n", data_2.dia, data_2.mes, data_2.ano);
}


int calcularDiasEntreDatas() {
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
    receberDatas();
    imprimeTotalDeDias(calcularDiasEntreDatas());

    printf("\nDigite 0 para para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif

/*
4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/
#ifdef ex4
struct Pessoa {
  char nome[21];
  float peso;
  float altura;
};

struct Pessoa pessoas[4] = {
    {"", 0, 0},
    {"", 0, 0},
    {"", 0, 0},
    {"", 0, 0},
};

const int TOTAL_DE_REGISTROS = 4;

void imprimirSeparador(int i) {
  if (i != TOTAL_DE_REGISTROS - 1) {
    printf("\n-------------------------------------\n\n");
  } else {
    printf("\n\n");
  }
}

void receberDados() {
  printf("\n");
  printf("====================================\n");
  printf("           ENTRADA DE DADOS         \n");
  printf("====================================\n\n");

  for (int i = 0; i < TOTAL_DE_REGISTROS; i++) {
    printf("%.2d.\n", i + 1);
    printf("> NOME: ");
    gets(pessoas[i].nome);
    printf("> PESO (Kg): ");
    scanf("%f", &pessoas[i].peso);
    limpaBuffer();
    printf("> ALTURA (m): ");
    scanf("%f", &pessoas[i].altura);
    limpaBuffer();

    imprimirSeparador(i);
  }
}

void imprimirDados() {
  if (pessoas[0].nome[0] == 0) {
    printf("\n>> Nenhum registro para exibir.\n");
    printf(">> Digite 1 no MENU para cadastrar.\n\n");

    return;
  }

  printf("\n");
  printf("====================================\n");
  printf("           EXIBIR REGISTROS         \n");
  printf("====================================\n\n");

  for (int i = 0; i < TOTAL_DE_REGISTROS; i++) {
    printf("%.2d. %s\n", i + 1, pessoas[i].nome);
    printf("> PESO: %.2f Kg\n", pessoas[i].peso);
    printf("> ALTURA: %.2f m\n", pessoas[i].altura);

    imprimirSeparador(i);
  }
}

void calcularIMC() {
  printf("\n");
  printf("====================================\n");
  printf("              EXIBIR IMC            \n");
  printf("====================================\n\n");
  for (int i = 0; i < TOTAL_DE_REGISTROS; i++) {
    printf("%.2d. %s\n", i + 1, pessoas[i].nome);
    printf("> IMC: %.2f\n",
           pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura));

    imprimirSeparador(i);
  }
}

char menu() {
  char res;

  printf("===================================\n");
  printf("                MENU               \n");
  printf("===================================\n");
  printf("\t1. Preencher Dados\n");
  printf("\t2. Exibir Registros\n");
  printf("\t3. Exibir IMC\n");
  printf("\t0. Encerrar\n");
  printf("Digite uma das opções [1/2/3/0]: ");
  scanf("%c", &res);
  limpaBuffer();

  return res;
}

int main() {
  char res;

  while (1) {
    res = menu();

    switch (res) {
    case '1':
      receberDados();
      break;
    case '2':
      imprimirDados();
      break;
    case '3':
      calcularIMC();
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
