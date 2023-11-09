#include <stdio.h>

#define ex5

void limpaBuffer() {
  for (char c = getchar(); c != '\n'; c = getchar())
    ;
}

#ifdef ex1
/*
1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de
biblioteca)

*/
char s1[11], s2[11];

int s1IgualS2() {
  for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  char res = '1', c = '\0';
  int i;

  while (res == '1') {
    printf("1. Digite ate 10 caracteres: ");
    scanf("%s", s1);
    limpaBuffer();
    s1[10] = '\0';

    printf("\n2. Digite ate 10 caracteres: ");
    scanf("%s", s2);
    limpaBuffer();
    s2[10] = '\0';

    printf("\n<<>> ");
    if (s1IgualS2()) {
      printf("%s == %s", s1, s2);
    } else {
      printf("%s != %s", s1, s2);
    }
    printf(" <<>>\n");

    printf("\nDigite 1 para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
  return 0;
}

#endif /* ifdef ex1 */

#ifdef ex2
/*
2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:
    (Declare os 5 vetores como variaveis globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3

*/
char s1[8], s2[8], s3[8], s4[8], s5[8];

int main() {
  char res = '1';

  while (res == '1') {
    for (int i = 1; i <= 5; i++) {
      printf("Digite o %do nome (maximo 7 caracteres): ", i);
      switch (i) {
      case 1:
        scanf("%s", s1);
        s1[7] = '\0';
        break;
      case 2:
        scanf("%s", s2);
        s2[7] = '\0';
        break;
      case 3:
        scanf("%s", s3);
        s3[7] = '\0';
        break;
      case 4:
        scanf("%s", s4);
        s4[7] = '\0';
        break;
      case 5:
        scanf("%s", s5);
        s5[7] = '\0';
        break;
      }
      limpaBuffer();
    }

    printf("\n        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("%2c%-40s", ' ', s1);
    printf("%-s\n", s5);

    printf("%12c%-20s", ' ', s2);
    printf("%-s\n", s4);

    printf("%22c%-s\n", ' ', s3);

    printf("\nDigite 1 para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
    printf("\n");
  }
  return 0;
}

#endif /* ifdef ex2 */

#ifdef ex3
/*
3 - Escreva um programa que receba uma string na funcao main(). Faca uma
funcao que calcula o comprimento de uma string recebida via teclado. Mostre o
valor do comprimento na funcao main(). (Declare o vetor como variavel global)
(nao pode usar funcao de biblioteca)

*/
char s[101];

int comprimento() {
  int i;
  for (i = 0; i < 101 && s[i] != '\0'; i++) {
    ;
  }
  return i;
}

int main() {
  char res = '1';

  while (res == '1') {
    printf("Digite uma string (maximo 100 caracteres): ");
    scanf("%s", s);
    limpaBuffer();
    s[100] = '\0';

    printf(">> %d caracteres\n", comprimento());

    printf("\nDigite 1 para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
    printf("\n");
  }

  return 0;
}

#endif /* ifdef ex3 */

#ifdef ex4
/*
 4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os
 caracteres para letras maiusculas. (nao pode usar funcao de biblioteca)
*/
int main() {
  char s[11], res = '1';

  while (res == '1') {
    printf("Digite no maximo 10 caracteres: ");
    scanf("%s", s);
    limpaBuffer();
    s[10] = '\0';

    // a-z: 97-122
    // A-Z: 65-90
    for (int i = 0; i < 11 && s[i] != '\0'; i++) {
      if (s[i] >= 97 && s[i] <= 122) {
        s[i] -= 32;
      }
    }

    printf("\n%s\n", s);

    printf("\nDigite 1 para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
    printf("\n");
  }

  return 0;
}
#endif /* ifdef ex4 */

#ifdef ex5
/*
5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os
caracteres para letras minusculas. (nao pode usar funcao de biblioteca)
*/
int main() {
  char s[11], res = '1';

  while (res == '1') {
    printf("Digite no maximo 10 caracteres: ");
    scanf("%s", s);
    limpaBuffer();
    s[10] = '\0';

    // a-z: 97-122
    // A-Z: 65-90
    for (int i = 0; i < 11 && s[i] != '\0'; i++) {
      if (s[i] >= 65 && s[i] <= 90) {
        s[i] += 32;
      }
    }

    printf("\n%s\n", s);

    printf("\nDigite 1 para executar novamente: ");
    scanf("%c", &res);
    limpaBuffer();
    printf("\n");
  }

  return 0;
}
#endif /* ifdef ex5 */
