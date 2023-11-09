#define ex5
#include <locale.h>
#include <math.h>
#include <stdio.h>

void limpaBuffer() {
  for (char c = getchar(); c != '\n'; c = getchar())
    ;
}

// 1 - Escreva um programa que receba via teclado 2 numeros inteiros e
// imprima-os no video com o resultado das 4 operacoes aritmeticas.
#ifdef ex1

void main() {
  int a, b;
  char tecla;
  setlocale(LC_ALL, "Portuguese");

  do {

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    printf("\nA soma dos números é: %d\n", a + b);
    printf("A subtração entre os dois números é: %d\n", a - b);
    printf("O produto entre os dois números é: %d\n", a * b);
    printf("O quociente da divisão é: %d\n", a / b);

    printf("\nDeseja continuar? (s/n): ");

    limpaBuffer();
    tecla = getchar();
    limpaBuffer();
  } while ((tecla != 'n') && (tecla != 'N'));

  printf("\nfim\n");
}

#endif // ex1

/*2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.*/

#ifdef ex2

void main() {
  int a, b;
  char tecla;
  setlocale(LC_ALL, "Portuguese");

  do {

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    printf("\nA soma dos números é: %d\n", a += b);
    printf("A subtração entre os dois números é: %d\n", a -= b);
    printf("O produto entre os dois números é: %d\n", a *= b);
    printf("O quociente da divisão é: %d\n", a /= b);

    printf("\nDeseja continuar? (s/n): ");

    limpaBuffer();
    tecla = getchar();
    limpaBuffer();
  } while ((tecla != 'n') && (tecla != 'N'));

  printf("\nfim\n");
}
#endif // ex2

/*3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses
   e dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/

#ifdef ex3

void main() {
  setlocale(LC_ALL, "Portuguese");

  int dianasc = 10, mesnasc = 1, anonasc = 2000, diaatual = 1, mesatual = 1,
      anoatual = 2001, idadeanos, idademeses, idadedias;
  char tecla = 's';

  do {
    printf("Digite o dia do seu nascimento: ");
    scanf("%d", &dianasc);
    printf("Digite o mês do seu nascimento: ");
    scanf("%d", &mesnasc);
    printf("Digite o ano de seu nascimento: ");
    scanf("%d", &anonasc);

    printf("\nDigite que dia é hoje: ");
    scanf("%d", &diaatual);
    printf("Digite o mês no qual estamos: ");
    scanf("%d", &mesatual);
    printf("Digite o ano atual: ");
    scanf("%d", &anoatual);

    do {
      if (anonasc > anoatual) {
        printf(
            "\nO ano de nascimento precisa ser menor do que o ano atual.\n\n");
        printf("Digite o ano de seu nascimento: ");
        scanf("%d", &anonasc);
        printf("Digite o ano atual: ");
        scanf("%d", &anoatual);
      }
    } while (anonasc > anoatual);

    if (mesnasc <= mesatual && dianasc <= diaatual) {
      // já fez aniversário
      idadedias = diaatual - dianasc;
      idademeses = mesatual - mesnasc;
      idadeanos = anoatual - anonasc;
    } else if (mesnasc > mesatual && dianasc > diaatual) {
      idadedias = 30 - (dianasc - diaatual);
      idademeses = 12 - (mesnasc - mesatual) - 1;
      idadeanos = anoatual - anonasc - 1;
    } else if (mesnasc > mesatual && dianasc <= diaatual) {
      idadedias = diaatual - dianasc;
      idademeses = 12 - (mesnasc - mesatual);
      idadeanos = anoatual - anonasc - 1;
    } else if (mesnasc <= mesatual && dianasc > diaatual) {
      idadedias = 30 - (dianasc - diaatual);
      idademeses = mesatual - mesnasc - 1;
      idadeanos = anoatual - anonasc;
    }

    printf("\n\tVocê tem %d ano%s, %d mes%s e %d dia%s.\n", idadeanos,
           idadeanos == 1 ? "" : "s", idademeses, idademeses == 1 ? "" : "es",
           idadedias, idadedias == 1 ? "" : "s");

    printf("\nDeseja continuar? (s/n): ");

    limpaBuffer();
    tecla = getchar();
    limpaBuffer();
  } while ((tecla != 'n') && (tecla != 'N'));

  printf("\nfim\n");
}
#endif // ex3

/*
4 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.
*/

#ifdef ex4
int ehAnoBissexto(int ano) {
  if (ano % 4 != 0) {
    // não é divisivel por 4, logo não é bissexto
    return 0;
  }

  if (ano % 100 != 0) { // divisivel por 4 e não divisivel por 100: bissexto
    return 1;
  }

  if (ano % 400 == 0) { // divisivel por 100 e por 400: bissexto
    return 1;
  }

  return 0; // divisivel por 4 e por 100 mas não por 400: não bissexto
}

void main() {
  setlocale(LC_ALL, "Portuguese");

  const int diareferencia = 1, mesreferencia = 1, anoreferencia = 2000;
  const int diadasemanareferencia = 0; // sábado
  int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char tecla = 's';

  while (tecla != 'n' && tecla != 'N') {
    int diasDeDiferenca = 0;
    int anosDeDiferenca = 0;
    int totalDeAnosBissexto = 0;

    int dia, mes, ano, diadasemana = 0;

    printf("Digite uma data.\nDia: ");
    scanf("%d", &dia);

    printf("Mes: ");
    scanf("%d", &mes);

    printf("Ano: ");
    scanf("%d", &ano);

    if (ano >= anoreferencia) {
      for (int i = 0; i < 12 && i + 1 != mes; i++) {
        diasDeDiferenca += diasNoMes[i];
      }

      anosDeDiferenca = ano - anoreferencia;

      diasDeDiferenca += (dia - diareferencia);
    } else {
      for (int i = 11; i >= 0 && i + 1 != mes; i--) {
        diasDeDiferenca += diasNoMes[i];
      }

      anosDeDiferenca = anoreferencia - ano - 1;

      diasDeDiferenca += ((diasNoMes[mes - 1] - dia) + 1);
    }

    totalDeAnosBissexto += (anosDeDiferenca / 4);
    if (ano > anoreferencia ||
        (ano == anoreferencia && (mes > 2 || mes == 2 && dia == 29))) {
      totalDeAnosBissexto += 1; // ano de referencia é bissexto
    }

    diasDeDiferenca += 365 * anosDeDiferenca;

    // um dia a mais para cada ano bissexto
    diasDeDiferenca += totalDeAnosBissexto;

    diadasemana = diasDeDiferenca % 7;

    if (ano < anoreferencia && diadasemana != 0) {
      // inverte a ordem dos dias da semana para contar de trás pra frente
      diadasemana = 7 - diadasemana;
    }

    printf("\n\tO dia da semana da data informada é ");
    switch (diadasemana) {
    case 0:
      printf("Sábado.\n");
      break;
    case 1:
      printf("Domingo.\n");
      break;
    case 2:
      printf("Segunda-feira.\n");
      break;
    case 3:
      printf("Terça-feira.\n");
      break;
    case 4:
      printf("Quarta-feira.\n");
      break;
    case 5:
      printf("Quinta-feira.\n");
      break;
    case 6:
      printf("Sexta-feira.\n");
      break;
    }
    printf("\n");

    printf("\nDeseja continuar? (s/n): ");

    limpaBuffer();
    tecla = getchar();
    limpaBuffer();
  }
}
#endif // ex4

/*
5 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
        as operacoes logicas bit a bit AND,
    OU,
    OU EXCLUSIVO e imprima - os no video no formato decimal e hexadecimal.
*/
#ifdef ex5

void main() {
  int a, b;
  char tecla;
  setlocale(LC_ALL, "Portuguese");

  while ((tecla != 'n') && (tecla != 'N')) {

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    printf("\n%d & %d = %d (%#x)\n", a, b, a & b, a & b);
    printf("%d | %d = %d (%#x)\n", a, b, a | b, a | b);
    printf("%d ^ %d = %d (%#x)\n", a, b, a ^ b, a ^ b);

    printf("\nDeseja continuar? (s/n): ");

    limpaBuffer();
    tecla = getchar();
    limpaBuffer();
  }

  printf("\nfim\n");
}
#endif // ex5
