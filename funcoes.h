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

void entrada(){
    //pega o nome da foto e checa se o arquivo existe. Caso não exista, pede para inserir novamente
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
    fscanf(foto, "%s %i %i %i", tipo, &alt, &lar, &qua);
    alt_s=alt; //salvando para que a altura e largura da imagem original seja restaurada após o filtro de reduçao
	lar_s=lar;
}

void remover_novalinha(char *linha){
    int nova_linha = strlen(linha) -1;
    if (linha[nova_linha] == '\n') // Caso haja \n no final da string,
        linha[nova_linha] = '\0'; // é colocado \0.
}

void processamento(RGB px[alt][lar]){
    //pegando colunas com informações de RGB de cada px
    int l, c;
    for (l=0; l<alt; l++){
        for(c=0; c<lar; c++){
            fscanf(foto, "%i", &px[l][c].r);
            fscanf(foto, "%i", &px[l][c].g);
            fscanf(foto, "%i", &px[l][c].b);
        }
    }
}

void ran(RGB px[alt][lar]){
	/*escolhe um efeito aleatoriamente*/
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
		printf("Digite o comando do filtro: ");
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
