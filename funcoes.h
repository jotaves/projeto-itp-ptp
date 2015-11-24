// Declarando funções para serem utilizadas abaixo.
void sha();
void blu();
void rot_90();
void rot_180();
void rot_270();
void thr();
int main();
char nome_da_foto_final[20];
int cont;
void rot_aux();

void entrada(){
    printf("Insira o nome do arquivo (sem a extensao): ");
    
    setbuf(stdin, 0);
    scanf("%s", nome_da_foto);
    
    strcpy (nome_da_foto_sppm, nome_da_foto);
    strcpy (nome_da_foto_final, nome_da_foto);
    strcat(nome_da_foto, ".ppm");
    
    foto = fopen(nome_da_foto, "r");

    while (foto==NULL){
        printf("Arquivo nao encontrado. Tente novamente: ");
		setbuf(stdin, 0);
		scanf("%s", nome_da_foto);
		
		strcpy (nome_da_foto_sppm, nome_da_foto);
		strcpy (nome_da_foto_final, nome_da_foto);
		strcat(nome_da_foto, ".ppm");
		
		foto = fopen(nome_da_foto, "r");
    }
    fscanf(foto, "%s %i %i %i", tipo, &alt, &lar, &qua);
}

void processamento(RGB px[alt][lar]){
    //pegando ls com informações de RGB de cada px
    int l, c;
    for (l=0; l<alt; l++){
        for(c=0; c<lar; c++){
            fscanf(foto, "%i", &px[l][c].r);
            fscanf(foto, "%i", &px[l][c].g);
            fscanf(foto, "%i", &px[l][c].b);
        }
    }
}

void comandos(RGB px[alt][lar]){
   	while(strcmp (comando, "fim") != 0){
		printf("Os comandos possiveis do programa sao: 'sha' para thresholding, 'rot' para rotacionar, 'sha' para sharpening e 'blu' para blurring.\n");
		printf("Digite o comando do filtro: ");
		scanf("%s", comando);
		
		// Compara se 'comando' é igual ou diferente de 'edit'.
		// Se for igual, vai para o efeito edit, se não for, pede novamente o comando.
		while(strcmp (comando, "thr") != 0 && strcmp (comando, "fim") != 0 && strcmp (comando, "rot") != 0 && strcmp (comando, "outra") != 0 && strcmp (comando, "blu") != 0 && strcmp (comando, "sha") != 0){
			printf("Comando inexistente. Tente novamente: \n");
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
		
		if (strcmp (comando, "outra") == 0){
			main();
		}
	}
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
}
