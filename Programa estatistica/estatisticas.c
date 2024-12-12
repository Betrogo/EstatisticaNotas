//
// Created by Pedro on 12/12/2024.
//

#include "estatisticas.h"

#include <stdio.h>

float calcMedia(float notas[], const int quantAlunos) {
    float soma = 0;
    for (int i = 0; i < quantAlunos; i++) {
        soma += notas[i];
    }
    return soma / quantAlunos;
}

void maiorMenor(float notas[], const int quantAlunos, float *maior, float *menor) {
    *maior = *menor = notas[0];
    for (int i = 1; i < quantAlunos; i++) {
        if (notas[i] > *maior) {
            *maior = notas[i];
        }
        if (notas[i] < *menor) {
            *menor = notas[i];
        }
    }
}

int acimaMedia(float notas[], const int quantAlunos, float media) {
    int cont = 0;
    for (int i = 0; i < quantAlunos; i++) {
        if (notas[i] > media) {
            cont++;
        }
    }
    return cont;
}

void ordenarNotas(float notas[], const int quantAlunos) {
    for (int i = 0; i < quantAlunos - 1; i++) {
        for (int j = 0; j < quantAlunos - i - 1; j++) {
            if (notas[j] > notas[j + 1]) {
                const float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
}

int validarNotas(float notas[]) {
    int quantAlunos = 0;

    do {
        printf("Informe o numero de alunos (1-100): ");
        scanf("%d", &quantAlunos);
        if (quantAlunos < 1 || quantAlunos > MAX_ALUNOS) {
            printf("Numero de alunos invalido. Tente novamente.\n\n");
        }
    } while (quantAlunos < 1 || quantAlunos > MAX_ALUNOS);

    for (int i = 0; i < quantAlunos; i++) {
        float nota = 0;
        while (1) {
            printf("Informe a %da nota (0-10): ", i + 1);
            scanf("%f", &nota);
            if (nota >= 0 && nota <= 10) {
                notas[i] = nota;
                break;
            }
            printf("Nota invalida. Tente novamente.\n\n");
        }
    }
    printf("\n");
    return quantAlunos;
}

void adicionarNota(float notas[], int *quantAlunos) {
    if (*quantAlunos < MAX_ALUNOS) {
        float nota;
        while (1) {
            printf("Informe a nota do novo aluno (0-10): ");
            scanf("%f", &nota);
            if (nota >= 0 && nota <= 10) {
                notas[*quantAlunos] = nota;
                (*quantAlunos)++;
                break;
            }
            printf("Nota invalida. Tente novamente.\n\n");
        }
    } else {
        printf("Limite de alunos atingido.\n\n");
    }
}