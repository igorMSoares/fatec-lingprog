#include <stdio.h>

#define ex5

#ifdef ex1
/* Ex.1
 Escreva um programa que receba um numero N via teclado.
 Escreva uma funcao que retorne a soma dos algarismos do resultado de N!.
 O resultado deve ser mostrado na funcao main().

 Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.
*/
int fatorial_de(int n) {
  int fatorial = 1;

  for (int i = 1; i <= n; i++) {
    fatorial *= i;
  }

  return fatorial;
}

int main() {
  int n = 0, fatorial = 0, soma = 0;

  for (char resposta = 's'; resposta == 's' || resposta == 'S';) {
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    getchar();

    fatorial = fatorial_de(n);

    printf("Fatorial de %d = %d\n", n, fatorial);

    while (fatorial != 0) {
      soma += fatorial % 10;
      fatorial /= 10;
    }

    printf("Soma dos algarismos de %d! = %d\n", n, soma);

    printf("Deseja executar o programa novamente? (s/n): ");
    resposta = getchar();
    printf("\n");
  }

  return 0;
}
#endif

#ifdef ex2
/* Ex. 2
* Escreva um programa que receba dois numeros inteiros e
* execute as seguintes funçoes:
    - Verificar se o numero digitado e' positivo ou negativo.
        Sendo que o valor de retorno sera' 1 se positivo,
        0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos,
        retorne a soma dos N numeros existentes entre eles.
    - Se os 2 numeros sao negativos,
        retorne a multiplicacao dos N numeros existente entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.
*/
int eh_positivo(int n) {
  if (n == 0)
    return -1;

  if (n > 0)
    return 1;

  return 0;
}

int soma_numeros_entre(int x, int y) {
  // retorna soma dos N numeros existentes entre x e y
  int resposta = 0;

  if (x > y) {
    // troca x <-> y
    x += y;
    y = x - y;
    x -= y;
  }

  for (int i = x + 1; i < y; i++) {
    resposta += i;
  }

  return resposta;
}

int multiplica_numeros_entre(int x, int y) {
  // retorna multiplicacao dos N numeros existentes entre x e y
  int resposta = 1;

  if (x > y) {
    // troca x <-> y
    x += y;
    y = x - y;
    x -= y;
  }

  for (int i = x + 1; i < y; i++) {
    resposta *= i;
  }

  return resposta;
}

float divide(float x, float y) {
  if (y == 0)
    return 0;

  return x / y;
}

int main() {
  int x = 0, y = 0;

  for (char resposta = 's'; resposta == 's' || resposta == 'S';) {
    printf("Digite dois numeros inteiros, separados por um espaço em branco: ");
    scanf("%d %d", &x, &y);
    getchar();

    printf("\nx: %d, y: %d\n", x, y);

    if (eh_positivo(x) == 1 && eh_positivo(y) == 1) {
      printf("Resultado: %d\n", soma_numeros_entre(x, y));
    } else if (eh_positivo(x) == 0 && eh_positivo(y) == 0) {
      printf("Resultado: %d\n", multiplica_numeros_entre(x, y));
    } else if ((eh_positivo(x) == 1 && eh_positivo(y) == 0) ||
               (eh_positivo(x) == 0 && eh_positivo(y) == 1)) {
      printf("Resultado: %.2f\n", divide(x, y));
    }

    printf("Deseja executar o programa novamente? (s/n): ");
    resposta = getchar();
    printf("\n");
  }

  return 0;
}
#endif

#ifdef ex3
/* Ex3.
  Escreva um programa que receba na funcao main() 2 valores inteiro.
  Escreva uma funcao para cada operacoes aritmeticas e passe como parametro
    os 2 valores recebidos na funcao main().
  Retorne os resultados usando o comando return e
    imprima os 4 resultados no video na funcao main().
*/
int soma(int x, int y) { return x + y; }

int subtrai(int x, int y) { return x - y; }

int multiplica(int x, int y) { return x * y; }

float divide(float x, float y) {
  if (y == 0)
    return 0;

  return x / y;
}

int main() {
  int x = 0, y = 0;

  for (char resposta = 's'; resposta == 's' || resposta == 'S';) {
    printf("Digite dois numeros inteiros, separados por um espaço em branco: ");
    scanf("%d %d", &x, &y);
    getchar();

    printf("%d + %d = %d\n", x, y, soma(x, y));
    printf("%d - %d = %d\n", x, y, subtrai(x, y));
    printf("%d * %d = %d\n", x, y, multiplica(x, y));
    printf("%d / %d = %.2f\n", x, y, divide(x, y));

    printf("Deseja executar o programa novamente? (s/n): ");
    resposta = getchar();
    printf("\n");
  }

  return 0;
}
#endif

#ifdef ex4
/* Ex. 4
 Reescreva o programa do exercicio anterior para receber via teclado n valores.
 Os n valores nao sao definidos previamente.
*/
int soma(int x, int y) { return x + y; }

int subtrai(int x, int y) { return x - y; }

int multiplica(int x, int y) { return x * y; }

float divide(float x, float y) {
  if (y == 0)
    return 0;

  return x / y;
}

int main() {
  int soma_total = 0, subtracao_total = 0, multiplicacao_total = 0, n = 0;
  float divisao_total = 0;
  char resposta = '\0';

  printf("Digite um numero inteiro:\n");
  scanf("%d", &n);
  soma_total = n;
  subtracao_total = n;
  multiplicacao_total = n;
  divisao_total = (float)n;

  while (1) {
    printf("Digite outro numero inteiro ou digite x para encerrar:\n");
    scanf("%d", &n);
    resposta = getchar();

    if (resposta == 'x' || resposta == 'X') {
      break;
    }

    soma_total = soma(soma_total, n);
    subtracao_total = subtrai(subtracao_total, n);
    multiplicacao_total = multiplica(multiplicacao_total, n);
    divisao_total = divide(divisao_total, n);
  }

  printf("Soma total = %d\n", soma_total);
  printf("Subtracao total = %d\n", subtracao_total);
  printf("Multiplicacao total = %d\n", multiplicacao_total);
  printf("Divisao total = %.2f\n", divisao_total);

  return 0;
}
#endif

#ifdef ex5
/* Ex. 5
 Escreva um programa que receba n valores inteiros via teclado na funcao main().
 Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
 As operacoes aritmeticas devem ser funcoes.
 O resultado acumulado deve ser mostrado na funcao main().
*/
#include <math.h>

float soma(float x, float y) { return x + y; }

float subtrai(float x, float y) { return x - y; }

float multiplica(float x, float y) { return x * y; }

float divide(float x, float y) {
  if (y == 0)
    return 0;

  // retorna resultado com precisao de apenas duas casas decimais
  return trunc((x / y) * 100) / 100;
}

void limpa_buffer() {
  for (char c = getchar(); c != '\n'; c = getchar())
    ;
}

void imprime_total_parcial(float total) {
  // omite casas decimais quando forem iguais a 0
  if ((int)total == total) {
    printf("\n%.0f\n", total);
  } else {
    printf("\n%.2f\n", total);
  }
}

void imprime_total_final(float total) {
  // omite casas decimais quando forem iguais a 0
  if ((int)total == total) {
    printf("\tTotal: %.0f\n", total);
  } else {
    printf("\tTotal: %.2f\n", total);
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
  printf("4. Digite o proximo numero para continuar calculando\n");
  scanf("%f", &total);
  limpa_buffer();

  while (operador != '=') {
    scanf("%c", &operador);
    limpa_buffer();

    if (operador != '=') {
      scanf("%f", &n);
      limpa_buffer();
    }

    switch (operador) {
    case '+':
      total = soma(total, n);
      break;
    case '-':
      total = subtrai(total, n);
      break;
    case '*':
      total = multiplica(total, n);
      break;
    case '/':
      total = divide(total, n);
      break;
    case '=':
      imprime_total_final(total);
      return 0;
    default:
      printf("\nOperador invalido.\n");
      printf("Digite um operador valido (+, -, *, / ou =)\n");
    }

    imprime_total_parcial(total);
  }
}
#endif
