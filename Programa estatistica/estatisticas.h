//
// Created by Pedro on 12/12/2024.
//

#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#define MAX_ALUNOS 100

float calcMedia(float notas[], int quantAlunos);

void maiorMenor(float notas[], int quantAlunos, float *maior, float *menor);

int acimaMedia(float notas[], int quantAlunos, float media);

void ordenarNotas(float notas[], int quantAlunos);

int validarNotas(float notas[]);

void adicionarNota(float notas[], int *quantAlunos);

#endif //ESTATISTICAS_H