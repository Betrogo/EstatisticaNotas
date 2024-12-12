#include <stdio.h>
#include "estatisticas.h"

int main() {
    float notas[MAX_ALUNOS];
    int quantAlunos = validarNotas(notas);
    int opcao;

    do {
        printf("----------- Menu -----------\n");
        printf("1. Adicionar nota\n");
        printf("2. Calcular media\n");
        printf("3. Maior e menor nota\n");
        printf("4. Alunos com nota acima da media\n");
        printf("5. Ordenar notas\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarNota(notas, &quantAlunos);
            break;
            case 2: {
                const float media = calcMedia(notas, quantAlunos);
                printf("\nMedia: %.2f\n\n", media);
                break;
            }
            case 3: {
                float maior, menor;
                maiorMenor(notas, quantAlunos, &maior, &menor);
                printf("\nMaior nota: %.2f\n", maior);
                printf("Menor nota: %.2f\n\n", menor);
                break;
            }
            case 4: {
                const float media = calcMedia(notas, quantAlunos);
                const int acima = acimaMedia(notas, quantAlunos, media);
                printf("\nAlunos com nota acima da media: %d\n\n", acima);
                break;
            }
            case 5:
                ordenarNotas(notas, quantAlunos);
            printf("\nNotas ordenadas:\n");
            for (int i = 0; i < quantAlunos-1; i++) {
                printf("%.2f, ", notas[i]);
            }
            printf("%.2f.", notas[quantAlunos-1]);
            printf("\n\n");
            break;
            case 6:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida. Tente novamente.\n\n");
        }
    } while (opcao != 6);

    return 0;
}