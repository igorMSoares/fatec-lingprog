#include <stdio.h>

#define ex5

/*
1 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o
programa deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.
*/
void limpaBuffer() {
  // limpar o buffer caso usuario tenha digitado valor invalido
  for (char c = getchar(); c != '\n'; c = getchar())
    ;
}

void recebeNumeros(int n, int v[]) {
  for (int i = 0; i < n; i++) {
    printf("Digite o %do numero: ", i + 1);
    scanf("%d", &v[i]);
    limpaBuffer();
  }
}

#ifdef ex1
int main() {
  int v[10];
  int u[5], w[5];
  int j = 0, k = 0;
  char res = 's';

  while (res == 's' || res == 'S') {
    recebeNumeros(10, v);

    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        u[j] = v[i];
        j++;
        continue;
      }

      w[k] = v[i];
      k++;
    }

    printf("Ordem par: \t[");
    for (int i = 0; i < j; i++) {
      if (i == 0) {
        printf("%d", u[i]);
      } else {
        printf(", %d", u[i]);
      }
    }
    printf("]\n");

    printf("Ordem impar: \t[");
    for (int i = 0; i < k; i++) {
      if (i == 0) {
        printf("%d", w[i]);
      } else {
        printf(", %d", w[i]);
      }
    }
    printf("]\n");

    printf("\n\nDigite s para rodar o programa novamente: ");
    scanf("%c", &res);
    limpaBuffer();

    j = 0;
    k = 0;
  }

  return 0;
}
#endif

#ifdef ex2
/*
2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.
*/
int main() {
  int v[10];
  int u[10], w[10];
  int j = 0, k = 0;
  char res = 's';

  while (res == 's' || res == 'S') {
    recebeNumeros(10, v);

    for (int i = 0; i < 10; i++) {
      if (v[i] % 2 == 0) {
        u[j] = v[i];
        j++;
        continue;
      }

      w[k] = v[i];
      k++;
    }

    printf("Pares: \t\t[");
    for (int i = 0; i < j; i++) {
      if (i == 0) {
        printf("%d", u[i]);
      } else {
        printf(", %d", u[i]);
      }
    }
    printf("]\n");

    printf("Impares: \t[");
    for (int i = 0; i < k; i++) {
      if (i == 0) {
        printf("%d", w[i]);
      } else {
        printf(", %d", w[i]);
      }
    }
    printf("]\n");

    printf("\n\nDigite s para rodar o programa novamente: ");
    scanf("%c", &res);
    limpaBuffer();

    j = 0;
    k = 0;
  }

  return 0;
}
#endif

#ifdef ex3
/*
3 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.
*/
int main() {
  int a[2][3], b[2][3], soma_a[3], soma_b[3];
  char res = 's';

  while (res == 's' || res == 'S') {
    printf("Vetor A:\n");
    for (int i = 0; i < 2; i++) {
      printf("=============A.%d=============\n", i + 1);
      recebeNumeros(3, a[i]);
      printf("=============================\n");
    }

    printf("\nVetor B:\n");
    for (int i = 0; i < 2; i++) {
      printf("=============B.%d=============\n", i + 1);
      recebeNumeros(3, b[i]);
      printf("=============================\n");
    }

    for (int j = 0; j < 3; j++) {
      soma_a[j] = a[0][j] + a[1][j];
      soma_b[j] = b[0][j] + b[1][j];
    }

    printf("Vetor A:\n");
    printf("\t0\t1\t3\n");
    for (int i = 0; i < 2; i++) {
      printf("%d", i);
      printf("\t%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);
    }
    printf("+\t%d\t%d\t%d\n", soma_a[0], soma_a[1], soma_a[2]);

    printf("\nVetor B:\n");
    printf("\t0\t1\t3\n");
    for (int i = 0; i < 2; i++) {
      printf("%d", i);
      printf("\t%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
    printf("+\t%d\t%d\t%d\n", soma_b[0], soma_b[1], soma_b[2]);

    printf("\n\nDigite s para rodar o programa novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
  return 0;
}
#endif

#ifdef ex4
/*
4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.
*/
int main() {
  int v[10];
  int n;
  char res = 's';

  while (res == 's' || res == 'S') {
    int total = 0;
    for (int i = 0; i < 10; i++) {
      printf("Digite o %do numero: ", i + 1);
      scanf("%d", &n);
      limpaBuffer();

      if (i == 0) {
        v[i] = n;
        total++;
        continue;
      }

      for (int j = 0; j < total; j++) {
        if (v[j] <= n) {
          if (j == total - 1) {
            v[total] = n;
            total++;
            break;
          }
          continue;
        }

        if (j == total - 1) {
          v[total] = v[j];
          v[j] = n;
          total++;
          break;
        }

        for (int x = total; x > j; x--) {
          v[x] = v[x - 1];
        }
        v[j] = n;
        total++;
        break;
      }

      for (int k = 0; k < total; k++) {
        if (k == 0) {
          printf("%d", v[k]);
        } else {
          printf(", %d", v[k]);
        }
      }
      printf("\n");
    }

    printf("\n\nDigite s para rodar o programa novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }
}
#endif

#ifdef ex5
/*
5 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/
int main() {
  int vInt[3];
  long int vLong[3];
  unsigned int vUnsigned[3];
  float vFloat[3];
  double vDouble[3];
  int i;
  char res = 's';

  while (res == 's' || res == 'S') {
    printf("[INT]\n");
    for (i = 0; i < 3; i++) {
      printf("Digite o %do numero: ", i + 1);
      scanf("%d", &vInt[i]);
      limpaBuffer();
    }

    printf("\n[LONG]\n");
    for (i = 0; i < 3; i++) {
      printf("Digite o %do numero: ", i + 1);
      scanf("%ld", &vLong[i]);
      limpaBuffer();
    }

    printf("\n[UNSGINED]\n");
    for (i = 0; i < 3; i++) {
      printf("Digite o %do numero: ", i + 1);
      scanf("%u", &vUnsigned[i]);
      limpaBuffer();
    }

    printf("\n[FLOAT]\n");
    for (i = 0; i < 3; i++) {
      printf("Digite o %do numero: ", i + 1);
      scanf("%f", &vFloat[i]);
      limpaBuffer();
    }

    printf("\n[DOUBLE]\n");
    for (i = 0; i < 3; i++) {
      printf("Digite o %do numero: ", i + 1);
      scanf("%lf", &vDouble[i]);
      limpaBuffer();
    }

    printf("\n        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");

    for (i = 0; i < 3; i++) {
      printf("%2c%-20d", ' ', vInt[i]);
      printf("%-20ld", vLong[i]);
      printf("%-20u\n", vUnsigned[i]);
      printf("%12c%-20.2f", ' ', vFloat[i]);
      printf("%-20.2lf\n", vDouble[i]);
    }

    printf("\n\nDigite s para rodar o programa novamente: ");
    scanf("%c", &res);
    limpaBuffer();
  }

  return 0;
}
#endif
