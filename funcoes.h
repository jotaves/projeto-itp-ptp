/**
 *  \file funcoes.h
 *  \brief Funções
 *  Arquivo com todas as funções utilizadas no programa.
 */

/** Declaração de todas as sub-rotinas que serão utilizadas durante o programa. */
int main();
void remover_novalinha();
void thr();
void sha();
void blu();
void bor();
void amp();
void red();
void rot_aux();
void rot_90();
void rot_180();
void rot_270();
void ran();

//pega o nome da foto e checa se o arquivo existe. Caso não exista, pede para inserir novamente
void entrada(){
    /**
    *   \brief Selecionar imagem.
    *   Função para selecionar imagem a ser utilizada e pegar informações iniciais para manipulação.
    *   \return Nada
    */
    printf("### Bem-vindo(a)! ###\n");
    printf("Insira o nome da imagem a ser modificada (sem a extensao): ");

    setbuf(stdin, 0);
    fgets(nome_da_foto, sizeof(nome_da_foto), stdin);
    remover_novalinha(nome_da_foto);

    strcpy (nome_da_foto_sppm, nome_da_foto);
    strcpy (nome_da_foto_final, nome_da_foto);
    strcat(nome_da_foto, ".ppm");

    foto = fopen(nome_da_foto, "r");

    while (foto==NULL){
        printf("Arquivo nao encontrado. Tente novamente: ");
		setbuf(stdin, 0);
		fgets(nome_da_foto, sizeof(nome_da_foto), stdin);
		remover_novalinha(nome_da_foto);

		strcpy (nome_da_foto_sppm, nome_da_foto);
		strcpy (nome_da_foto_final, nome_da_foto);
		strcat(nome_da_foto, ".ppm");

		foto = fopen(nome_da_foto, "r");
    }
    /** São armazenadas informações de tipo, altura, largura e qualidade da imagem. */
    fscanf(foto, "%s %i %i %i", tipo, &alt, &lar, &qua);
    /** Também é feito o backup da altura e da largura. */
    alt_s=alt;
	lar_s=lar;
}

void remover_novalinha(char *linha){
    /**
    *   \brief Remover '\n'.
    *   Função retirada do site
    *   http://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input.
    *   Utilizada para remover a nova linha que aparece no final do comando fgets.
    *   \param *linha - Ponteiro de uma string.
    *   \return Nada
    */
    int nova_linha = strlen(linha) -1;
    if (linha[nova_linha] == '\n') // Caso haja \n no final da string,
        linha[nova_linha] = '\0'; // é colocado \0.
}

//pegando colunas com informações de RGB de cada px
void processamento(RGB px[alt][lar]){
    /**
    *   \brief Armazenar RGB.
    *   Função para armazenar informações RGB de cada pixel da imagem na struct.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */
    int l, c;
    for (l=0; l<alt; l++){
        for(c=0; c<lar; c++){
            fscanf(foto, "%i", &px[l][c].r);
            fscanf(foto, "%i", &px[l][c].g);
            fscanf(foto, "%i", &px[l][c].b);
        }
    }
}

/*escolhe um efeito aleatoriamente*/
void ran(RGB px[alt][lar]){
    /** \brief Aleatório.
    *   Função para escolher um filtro aleatoriamente.
    *   \param px - Matriz com a imagem para alteração.
    *   \return Nada
    */
	int x;
	srand( (unsigned)time(NULL) );
	x = rand() % 10;
	if(x == 0 || x == 1 || x == 8){
		thr(px);
	}
	if(x == 2 || x == 3 || x == 9){
		sha(px);
	}
	if(x == 4 || x == 5){
		blu(px);
	}
	if(x == 6 || x == 7){
		bor(px);
	}
}

void comandos(RGB px[alt][lar]){
    /**
    *   \brief Comandos.
    *   Função para selecionar um filtro escolhido pelo usuário.
    *   \param px - Matriz com a imagem para alteração.
    *   \return Nada
    */
   	while(strcmp (comando, "fim") != 0){
		printf("--------------------------------------------\n");
		printf("|| Os comandos possiveis do programa sao: ||\n");
		printf("||        'thr' para thresholding         ||\n");
		printf("||         'rot' para rotacionar          ||\n");
		printf("||         'sha' para sharpening          ||\n");
		printf("||          'blu' para blurring           ||\n");
		printf("||           'amp' para ampliar           ||\n");
		printf("||           'red' para reduzir           ||\n");
		printf("||       'bor' para board detection       ||\n");
		printf("||       'ran' para efeito aleatorio      ||\n");
		printf("||   'outra' para escolher outra imagem   ||\n");
		printf("||          'fim' para finalizar          ||\n");
		printf("--------------------------------------------\n");
		printf("Digite o comando escolhido: ");
		scanf("%s", comando);

		// Compara se 'comando' é igual ou diferente de 'edit'.
		// Se for igual, vai para o efeito edit, se não for, pede novamente o comando.
		while(strcmp (comando, "thr") != 0 && strcmp (comando, "red") != 0 && strcmp (comando, "amp") != 0 && strcmp (comando, "bor") != 0 && strcmp (comando, "fim") != 0 && strcmp (comando, "rot") != 0 && strcmp (comando, "outra") != 0 && strcmp (comando, "blu") != 0 && strcmp (comando, "sha") != 0 && strcmp (comando, "ran") != 0){
			printf("Comando inexistente. Tente novamente: ");
			scanf("%s", comando);
		}
		if (strcmp (comando, "thr") == 0){
			thr(px);
		}
		if (strcmp (comando, "rot") == 0){
			rot_aux(px);
		}
		if (strcmp (comando, "sha") == 0){
			sha(px);
		}
		if (strcmp (comando, "blu") == 0){
			blu(px);
		}
		if (strcmp (comando, "bor") == 0){
			bor(px);
		}
		if (strcmp (comando, "amp") == 0){
			amp(px);
		}
		if (strcmp (comando, "red") == 0){
			red(px);
		}
		if (strcmp (comando, "ran") == 0){
			ran(px);
		}
		if (strcmp (comando, "outra") == 0){
			main();
		}
	}
	printf("Até logo!");
}

void saida(RGB px[alt][lar]){
    /**
    *   \brief Escrita da imagem alterada.
    *   Função para escrever a imagem alterada pelo usuário.
    *   \param px - Matriz com a imagem para salvamento.
    *   \return Nada
    */

    // l = linhas; c = colunas
	int l, c;
    FILE *saida;
    saida=fopen(nome_da_foto_final, "w");
    fprintf(saida, "%s\n%i %i\n%i\n", tipo, alt, lar, qua);

    for(l=0; l<alt; l++){
		for(c=0; c<lar; c++){
			fprintf(saida, "%i %i %i\n", px[l][c].r, px[l][c].g, px[l][c].b);
		}
	}
	fclose(saida);
	alt=alt_s;
	lar=lar_s;
}
