#include <stdio.h>

#define ex4

#ifdef ex1
/* 1 - Escreva um programa que receba via teclado um tempo em segundos
 * e converta para horas, minutos e segundos.
 * Ex.: recebe 3850 segundos que converte para 1h 4min 10s. */
int main() {
  int tempoEmSegundos = 0, segundos = 0, minutos = 0, horas = 0;

  printf("Digite o tempo em segundos: ");
  scanf("%d", &tempoEmSegundos);

  segundos = tempoEmSegundos % 60;
  minutos = (tempoEmSegundos / 60) % 60;
  horas = (tempoEmSegundos / 60) / 60;

  printf("%ds = %dh %dmin %ds\n", tempoEmSegundos, horas, minutos, segundos);

  return 0;
}
#endif

#ifdef ex2
/* 2 - Escreva um programa que receba dados via teclado para variaveis do tipo
   short, long, int, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char */
int main() {
  short sh = 0;
  long l = 0;
  int i = 0;
  float f = 0.0;
  double db = 0.0;
  char c;

  printf("Digite valores para variáveis dos seguintes tipos:\n");
  printf("1. short: ");
  scanf("%hd", &sh);

  printf("2. long: ");
  scanf("%ld", &l);

  printf("3. int: ");
  scanf("%d", &i);

  printf("4. float: ");
  scanf("%f", &f);

  printf("5. double: ");
  scanf("%lf", &db);
  getchar();

  printf("6. char: ");
  scanf("%c", &c);

  printf("\n        10        20        30        40        50        60\n");
  printf("12345678901234567890123456789012345678901234567890123456789012345\n");
  printf("%9hd %9.2f %9ld %9.2lf %9d %5c\n", sh, f, l, db, i, c);
  printf("    short               long                int\n");
  printf("              float               double              char\n");

  return 0;
}
#endif

#ifdef ex3
/* 3 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar
   uma variável auxiliar. */
int main() {
  int var_1 = 10, var_2 = 20;

  printf("var_1: %d, var_2: %d\n", var_1, var_2);

  var_1 += var_2;
  var_2 = var_1 - var_2;
  var_1 -= var_2;

  printf("var_1: %d, var_2: %d\n", var_1, var_2);

  return 0;
}
#endif

#ifdef ex4
/* 4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e
   gerar outro número formado pelos dígitos invertidos do número lido. Ex:
   NúmeroLido = 123 NúmeroGerado = 321 */
int main() {
  char x1 = 0;
  char x2 = 0;
  char x3 = 0;

  printf("Digite um numero inteiro, positivo de três digitos: ");

  x1 = getchar();
  x2 = getchar();
  x3 = getchar();

  printf("%c%c%c\n", x3, x2, x1);

  return 0;
}
#endif

#ifdef ex5
/* 5 - Escreva um programa que determine o menor multiplo de um numero inteiro.
   Este multiplo deve ser maior que o limite minimo recebido. Recebe os 2
   numeros via teclado. Ex: menor multiplo de 13 maior que 100. Resultado: 104
 */
int main() {
  int n = 0, limiteMinimo = 0, x = 0;

  printf("Menor multiplo de ");
  scanf("%d", &n);
  printf(" maior que ");
  scanf("%d", &limiteMinimo);

  for (x = limiteMinimo + 1; x % n != 0; x++)
    ;

  printf("Resultado: %d\n", x);

  return 0;
}
#endif
