// Declarando funções para serem utilizadas abaixo.
void entrada();
void remover_novalinha();
void filtro();
void processamento();
void comandos();
void thr();

void programa(){
    entrada();
    RGB pixel[altura][largura];
    filtro();
    processamento(pixel);
    comandos(pixel);
}

void entrada(){
    printf("Insira o nome da imagem a ser modificada (sem a extensao): ");

    #ifdef _WIN32
	fflush(stdin); // caso Windows
    #endif

    #ifdef __linux__
	__fpurge(stdin); // caso Linux
    #endif
    
    fgets(nome_da_foto, sizeof(nome_da_foto), stdin);
    remover_novalinha(nome_da_foto); // Remover \n que fica no final do fgets.

    strcpy (nome_da_foto_final, nome_da_foto); // A string é copiada para outra variável.
    strcat(nome_da_foto, ppm); // É adicionado .ppm no final de uma dessas strings, a outra será utilizada na função 'saida'.
    foto = fopen(nome_da_foto, "r");

    while (foto==NULL){ // Caso não seja encontrado nenhum arquivo.
        printf("Imagem nao encontrada. Tente novamente: ");

        fgets(nome_da_foto, sizeof(nome_da_foto), stdin);
        remover_novalinha(nome_da_foto);

        strcpy (nome_da_foto_final, nome_da_foto);
        strcat(nome_da_foto, ppm);
        foto = fopen(nome_da_foto, "r");
    }

    // Pegando informações do arquivo.
    fscanf(foto, "%s %i %i %i", tipo, &altura, &largura, &qualidade);

    if (strcmp (tipo, "P3") != 0){ // Caso o tipo de arquivo não seja P3.
        printf("A imagem utilizada nao eh do tipo correto.\n");
        entrada(); // Volta para o início da função.
    }
}

/* O código abaixo foi retirado do site
http://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
e é utilizado para remover a nova linha que fica no final do comando fgets.
*/
void remover_novalinha(char *linha)
{
    int nova_linha = strlen(linha) -1;
    if (linha[nova_linha] == '\n') // Caso haja \n no final da string,
        linha[nova_linha] = '\0'; // é colocado \0.
}

void filtro(){
	printf("Os comandos possiveis sao: 'thr' para Thresholding (deixar a imagem binarizada).\n");
	printf("Digite o comando do filtro: ");
	scanf("%s", comando);
}

void processamento(RGB pixel[altura][largura]){
    // Pegando linhas com informações de RGB de cada pixel.
    int linha, coluna;
    for (linha=0; linha<altura; linha++){
        for(coluna=0; coluna<largura; coluna++){
            fscanf(foto, "%i", &pixel[linha][coluna].vermelho);
            fscanf(foto, "%i", &pixel[linha][coluna].verde);
            fscanf(foto, "%i", &pixel[linha][coluna].azul);
        }
    }
    fclose(foto);
}

void comandos (RGB pixel[altura][largura]){
    // Compara se 'comando' é igual ou diferente de 'thr'.
    // Se for igual, vai para o efeito thr, se não for, pede novamente o comando.
    
    while(strcmp (comando, "thr") != 0){
        printf("Comando inexistente. Tente novamente: \n");
        filtro();
    }
    
    if (strcmp (comando, "thr") == 0){
        thr(pixel);
    }
}

void saida(RGB pixel[altura][largura]){
	char fim[5]=" thr"; // Como só há um filtro, por enquanto, não é necessário colocar outros nomes no final do arquivo.
	int escolha;

    // Nomeando a nova imagem a ser gerada.
	strcat(nome_da_foto_final, fim);
	strcat(nome_da_foto_final, ppm);

	printf("A imagem (%s) foi gerada.", nome_da_foto_final);

    FILE *saida;
    saida=fopen(nome_da_foto_final, "w");

    // Escrevendo dados da nova imagem gerada.
    fprintf(saida, "%s\n%i %i\n%i\n", tipo, altura, largura, qualidade);
	int linha, coluna;
    for(linha=0; linha<altura; linha++){
		for(coluna=0; coluna<largura; coluna++){
			fprintf(saida, "%i %i %i\n", pixel[linha][coluna].vermelho, pixel[linha][coluna].verde, pixel[linha][coluna].azul);
		}
	}
	fclose(saida);
	printf(" Deseja aplicar um filtro a outra imagem?\nDigite '1' para 'sim' e '0' para 'nao': ");
	scanf("%i", &escolha);
	if(escolha == 1){
		programa();
	}
}
