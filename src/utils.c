#include <stdio.h>
#include <string.h>
#include "utils.h"

#define TAM_LINHA 100

int lerInt(const char *mensagem){
    char linha[TAM_LINHA] = "";
    char extra;
    int valor = 0, valido;

    do {
        printf("%s", mensagem);
        fgets(linha, sizeof(linha), stdin);
        valido = (sscanf(linha, "%d %c", &valor, &extra) == 1);

        if (!valido) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
        }
    } while (!valido);

    return valor;
}

int lerIntMin(const char *mensagem, int minimo){
    int valor;

    do {
        valor = lerInt(mensagem);

        if (valor < minimo) {
            printf("Valor invalido! O minimo permitido e %d.\n", minimo);
        }
    } while (valor < minimo);

    return valor;
}

float lerFloatMin(const char *mensagem, float minimo){
    char linha[TAM_LINHA] = "";
    char extra;
    float valor = 0;
    int valido;

    do {
        printf("%s", mensagem);
        fgets(linha, sizeof(linha), stdin);
        valido = (sscanf(linha, "%f %c", &valor, &extra) == 1);

        if (!valido) {
            printf("Entrada invalida! Use ponto decimal (ex: 4.50).\n");
        } else if (valor < minimo) {
            printf("Valor invalido! O minimo permitido e %.2f.\n", minimo);
            valido = 0;
        }
    } while (!valido);

    return valor;
}

void lerTexto(const char *mensagem, char *destino, int tamanho){
    char linha[TAM_LINHA] = "";
    int tam, valido;

    do {
        printf("%s", mensagem);
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        tam = strlen(linha);
        valido = (tam > 0 && tam < tamanho);

        if (!valido) {
            printf("Texto invalido! Digite de 1 a %d caracteres.\n", tamanho - 1);
        }
    } while (!valido);

    strcpy(destino, linha);
}