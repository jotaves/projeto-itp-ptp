#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    char nome_da_foto[100], tipo[2], comando[20], nome_da_foto_sppm[100], nome_da_foto_final[100];
    int alt, lar, qua, rot;
	FILE *foto;
	
    typedef struct {
        int r;
        int g;
        int b;
    }RGB;

#include "funcoes.h"
#include "filtros.h"

int main (void){
    entrada();
    RGB px[alt][lar];
    processamento(px);
	comandos(px);
	fclose(foto);
    return 0;
}
