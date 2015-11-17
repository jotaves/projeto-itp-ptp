#include <stdio.h>
#include <string.h>
    char nome_da_foto[20], tipo[3], comando[10], nome_da_foto_final[20], ppm[5]=".ppm";
    int altura, largura, qualidade;
    FILE *foto;

    typedef struct {
        int vermelho;
        int verde;
        int azul;
    }RGB;

#include "funcoes.h"
#include "filtros.h"

int main (void){
    printf("Bem-vindo!\n");
    programa();
    return 0;
}
