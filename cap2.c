#include <stdio.h>

#define ex5

void limpa_buffer() {
  for (char c = getchar(); c != '\n'; c = getchar())
    ;
}

#ifdef ex1
/*
        Ex. 1

- As ligacoes telefonicas são cobradas pela sua duracao.
- O sistema registra os instantes em que a ligacao foi iniciada e concluida.
- Escreva um programa que recebe via teclado dois instantes dados em
horas, minutos e segundo e determina o intervalo de tempo
(em horas, minutos e segundos) decorrido entre eles.
*/
#define INICIAL 'I'
#define FINAL 'F'

int hh_inicio = -1, mm_inicio = -1, ss_inicio = -1;
int hh_fim = -1, mm_fim = -1, ss_fim = -1;

void obter_instante(char inicial_ou_final) {
  if (inicial_ou_final != INICIAL && inicial_ou_final != FINAL) {
    return;
  }

  int hh = -1, mm = -1, ss = -1;

  while (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) {
    printf("Digite o instante %s no formato hh:mm:ss\n",
           inicial_ou_final == INICIAL ? "inicial" : "final");
    scanf("%d:%d:%d", &hh, &mm, &ss);
    limpa_buffer();

    if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) {
      printf("\n\tFormato invalido.\n");
      printf("\tDigite um instante entre 00:00:00 e 23:59:59\n\n");
    }
  }

  if (inicial_ou_final == INICIAL) {
    hh_inicio = hh;
    mm_inicio = mm;
    ss_inicio = ss;
  } else {
    hh_fim = hh;
    mm_fim = mm;
    ss_fim = ss;
  }
}

int transformar_instante_em_segundos(int hh, int mm, int ss) {
  int hh_em_segundos = hh * 60 * 60;
  int mm_em_segundos = mm * 60;

  return hh_em_segundos + mm_em_segundos + ss;
}

int main() {
  int opcao = -1;

  while (opcao != 0) {
    obter_instante(INICIAL);
    int instante_inicial_em_segundos =
        transformar_instante_em_segundos(hh_inicio, mm_inicio, ss_inicio);

    obter_instante(FINAL);
    int instante_final_em_segundos =
        transformar_instante_em_segundos(hh_fim, mm_fim, ss_fim);

    int total_de_segundos =
        instante_final_em_segundos - instante_inicial_em_segundos;

    // transforma total_de_segundos em horas, minutos e segundos
    int ss_total = total_de_segundos % 60;
    int mm_total = (total_de_segundos / 60) % 60;
    int hh_total = (total_de_segundos / 60) / 60;

    if (ss_total < 0) {
      // empresta 60 segundos do total de minutos (mm_total)
      ss_total = 60 + ss_total;
      mm_total--;
    }

    if (mm_total < 0) {
      // empresta 60 minutos do total de horas (hh_total)
      mm_total = 60 + mm_total;
      hh_total--;
    }

    if (hh_total < 0) {
      // ligacao comecou em um dia e terminou no dia seguinte
      hh_total = 24 + hh_total;
    }

    printf("\n\tTempo total decorrido: %.2d:%.2d:%.2d\n", hh_total, mm_total,
           ss_total);

    printf("\nDigite uma opcao para continuar:\n");
    printf("\t1) Executar o programa novamente.\n");
    printf("\t0) Encerrar o programa.\n");
    scanf("%d", &opcao);
    limpa_buffer();
  }

  return 0;
}
#endif

#ifdef ex2
/*
        Ex. 2

- Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
pensou.
- Digite via teclado os simbolos =, > ou < a cada pergunta.
- Utilize o comando if-else.
*/
int main() {
  int minimo = 1, maximo = 99, n = 0;
  char resposta = '\0';

  while (resposta != 'n' && resposta != 'N') {
    printf("Pense em um numero e irei adivinhar qual numero voce pensou!\n\n");

    printf("\t------------------------------------------\n");
    printf("\t                INSTRUCOES                \n");
    printf("\t------------------------------------------\n");
    printf("\tDigite '=' se for o número pensado.\n");
    printf("\tDigite '<' se o número pensado for menor.\n");
    printf("\tDigite '>' se o número pensado for maior.\n\n");

    while (1) {
      n = (maximo + minimo) / 2;

      printf("Você pensou no numero %d?\n", n);
      printf("[< | = | >]: ");
      resposta = getchar();
      limpa_buffer();

      if (resposta == '=') {
        printf("\n\tAcertei!\n");
        break;
      } else if (resposta == '<') {
        maximo = n;
      } else if (resposta == '>') {
        minimo = n;
      }
    }

    while (resposta != 's' && resposta != 'S' && resposta != 'n' &&
           resposta != 'N') {
      printf("Deseja jogar novamente? [s/n]: \n");
      resposta = getchar();
      limpa_buffer();
    }
  }

  return 0;
}
#endif

#ifdef ex3
/*
        Ex. 3

- Reescreva o programa do exercicio anterior agora utilizando o comando switch.
- Conte o n. de tentativas e imprima o resultado no video.
*/
int main() {
  int minimo = 1, maximo = 99, n = 0, tentativas = 1;
  char resposta = '\0';

  while (resposta != 'n' && resposta != 'N') {
    printf("Pense em um numero e irei adivinhar qual numero voce pensou!\n\n");

    printf("\t------------------------------------------\n");
    printf("\t                INSTRUCOES                \n");
    printf("\t------------------------------------------\n");
    printf("\tDigite '=' se for o número pensado.\n");
    printf("\tDigite '<' se o número pensado for menor.\n");
    printf("\tDigite '>' se o número pensado for maior.\n\n");

    int tentando = 1;

    while (tentando) {
      n = (maximo + minimo) / 2;

      printf("Você pensou no numero %d?\n", n);
      printf("[< | = | >]: ");
      resposta = getchar();
      limpa_buffer();

      switch (resposta) {
      case '=':
        if (tentativas > 1) {
          printf("\n\tAcertei em %d tentativas!\n", tentativas);
        } else {
          printf("\n\tAcertei em 1 tentativa!\n");
        }
        tentando = 0;
        break;
      case '<':
        maximo = n;
        tentativas++;
        break;
      case '>':
        minimo = n;
        tentativas++;
        break;
      }
    }

    while (resposta != 's' && resposta != 'S' && resposta != 'n' &&
           resposta != 'N') {
      printf("Deseja jogar novamente? [s/n]: \n");
      resposta = getchar();
      limpa_buffer();
    }
  }

  return 0;
}
#endif

#ifdef ex4
/* Ex. 4
- Receba via teclado a distancia em km e a quantidade de litros de gasolina
  consumidos por um carro em um percurso.
- Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
  abaixo:

  CONSUMO (km/l) MENSAGEM
  menor que 8    Venda o carro!
  entre 8 e 14   Economico!
  maior que 14   Super economico!
*/
int main() {
  int opcao = -1;

  while (opcao != 0) {
    float dist_em_km = 0, litros_consumidos = 0;

    printf("Qual a quilometragem total percorrida?\n");
    scanf("%f", &dist_em_km);
    limpa_buffer();

    printf("Quantos litros de gasolina foram consumidos neste percursso?\n");
    scanf("%f", &litros_consumidos);
    limpa_buffer();

    float consumo = dist_em_km / litros_consumidos;
    printf("\tO consumo deste carro foi de %.2f Km/L\n", consumo);

    if (consumo < 8) {
      printf("\tVenda o carro!\n");
    } else if (consumo <= 14) {
      printf("\tEconomico!\n");
    } else {
      printf("\tSuper economico!\n");
    }

    printf("\nDigite uma opcao para continuar:\n");
    printf("\t1) Executar o programa novamente\n");
    printf("\t0) Encerrar o programa\n");
    scanf("%d", &opcao);
    limpa_buffer();
  }

  return 0;
}
#endif

#ifdef ex5
/*
                Ex. 5
          - Escreva um programa que receba via teclado numeros inteiros
   positivos.
          - Quando o numero digitado for negativo o programa deve parar e
   calcula a media dos valores positivos digitados.
*/
int main() {
  int n = 0, qtd_numeros = 0, soma_positivos = 0;

  printf("\t==================================================\n");
  printf("\tDigite numeros positivos\n");
  printf("\tpara calcular a media dos numeros digitados\n");
  printf("\t                      ou                          \n");
  printf("\tDigite um numero negativo para encerrar o programa\n");
  printf("\t==================================================\n\n");

  while (1) {
    printf("Digite um numero e aperte Enter: ");
    scanf("%d", &n);
    limpa_buffer();

    if (n < 0) {
      break;
    } else if (n == 0) {
      continue;
    }

    qtd_numeros++;
    soma_positivos += n;
  }
  if (qtd_numeros > 0) {
    printf("\tMedia dos valores possitivos digitados: %.2f\n",
           (float)soma_positivos / (float)qtd_numeros);
  } else {
    printf("Nenhum numero positivo digitado.\n");
  }

  return 0;
}
#endif
