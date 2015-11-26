/**
 *  \file variaveis.h
 *  \brief Variáveis globais utilizadas no programa
 *  Arquivo com todas as variáveis globais utilizadas no programa.
 */

/** Armazena o nome da imagem (sem extensão) digitado pelo usuário. */
char nome_da_foto[100];

/** Armazena o tipo da imagem. */
char tipo[2];

/** Armazena os comandos/filtros digitado pelo usuário. */
char comando[20];

/** Backup do nome da imagem sem a extensão. */
char nome_da_foto_sppm[100];

/** Nome da imagem no final do programa. */
char nome_da_foto_final[100];

/** Armazena a altura da imagem. */
int alt;

/** Armazena a largura da imagem. */
int lar;

/** Armazena a qualidade da imagem. */
int qua;

/** Armazena o grau de rotação utilizado na sub-rotina 'rot'. */
int rot;

/** Backup da altura da imagem. */
int alt_s;

/** Backup da largura da imagem. */
int lar_s;

/** Armazena a imagem. */
FILE *foto;

/** Struct para armazenar valores de vermelho (r), verde (g) e azul (b) de cada pixel da imagem. */
typedef struct {
    int r;
    int g;
    int b;
}RGB;
