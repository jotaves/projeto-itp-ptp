/**
 *  \file filtros.h
 *  \brief Filtros.
 *  Arquivo com todos os filtros utilizadas no programa.
 */

void thr(RGB px[alt][lar]){
    /**
    *   \brief Função para filtro Thresholding.
    *   Binariza a imagem. Faz a média de R, G e B de cada pixel.
    *   Se a média for maior que 127, o pixel fica branco, e se for menor, fica preto.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

    RGB edit[alt][lar];
	int media, l, c;
	for(l=0; l<alt; l++){
		for(c=0; c<lar; c++){
			media=(px[l][c].r+px[l][c].g+px[l][c].b)/3;
			if(media>127){
				edit[l][c].r=255;
				edit[l][c].g=255;
				edit[l][c].b=255;
			}
			else{
				edit[l][c].r=0;
				edit[l][c].g=0;
				edit[l][c].b=0;
			}
		}
	}
	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_thr.ppm");
	saida(edit);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void rot_aux(RGB px[alt][lar]){
    /**
    *   \brief Função auxiliar de rotação.
    *   Auxilia no processo de rotação, encaminhando para as funções de 90, 180 ou 270 graus.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

	printf("Insira o grau de rotacao (90, 180 ou 270): ");
	scanf("%i", &rot);

	while(rot != 90 && rot != 180 && rot != 270){
		printf("Insira o grau de rotacao (90, 180 ou 270): ");
		scanf("%i", &rot);
	}

	if(rot==90) rot_90(px);
	if(rot==180) rot_180(px);
	if(rot==270) rot_270(px);
}

void rot_180(RGB px[alt][lar]){
    /**
    *   \brief Função para rotação de 180 graus.
    *   Função que rotaciona a imagem em 180 graus, ou seja, duas vezes 90.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

	int l, c;
    RGB edit[lar][alt];

    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            edit[alt-c-1][l].r=px[l][c].r;
            edit[alt-c-1][l].g=px[l][c].g;
            edit[alt-c-1][l].b=px[l][c].b;
        }
    }

    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            px[alt-c-1][l].r=edit[l][c].r;
            px[alt-c-1][l].g=edit[l][c].g;
            px[alt-c-1][l].b=edit[l][c].b;
        }
    }
	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_rot.ppm");
    saida(px);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void rot_270(RGB px[alt][lar]){
    /**
    *   \brief Função para rotação de 270 graus.
    *   Função que rotaciona a imagem em 270 graus, ou seja, três vezes 90.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

	int l, c;
    RGB edit[lar][alt];

    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            edit[alt-c-1][l].r=px[l][c].r;
            edit[alt-c-1][l].g=px[l][c].g;
            edit[alt-c-1][l].b=px[l][c].b;
        }
    }
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            px[alt-c-1][l].r=edit[l][c].r;
            px[alt-c-1][l].g=edit[l][c].g;
            px[alt-c-1][l].b=edit[l][c].b;
        }
    }
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            edit[alt-c-1][l].r=px[l][c].r;
            edit[alt-c-1][l].g=px[l][c].g;
            edit[alt-c-1][l].b=px[l][c].b;
        }
    }
    /** Variável temporária para armazenas altura. */
    int temp=alt;
    alt=lar;
    lar=temp;

    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            px[l][c].r=edit[l][c].r;
            px[l][c].g=edit[l][c].g;
            px[l][c].b=edit[l][c].b;
        }
    }

	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_rot.ppm");
    saida(px);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void rot_90(RGB px[alt][lar]){
    /**
    *   \brief Função para rotação de 90 graus.
    *   Rotaciona a imagem em 90 graus. Em uma imagem rotacionada 90 graus, a largura recebe o valor de altura e a largura recebe o valor de altura.
    *   Os pixels que antes ficavam na primeira linha, agora ficam no último, o segundo, o penúltimo.
    *   Sendo assim: altura - número da coluna da posição original do pixel = nova posição.
    *   Como esse número vai de 0 a n-1, subtraímos 1 da altura da imagem, ficando 'altura-1-numero da coluna original'.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */
	int l, c;
	/** Matriz criada para receber a imagem editada. */
    RGB edit[lar][alt];

    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            edit[alt-c-1][l].r=px[l][c].r;
            edit[alt-c-1][l].g=px[l][c].g;
            edit[alt-c-1][l].b=px[l][c].b;
        }
    }
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            px[l][c].r=edit[l][c].r;
            px[l][c].g=edit[l][c].g;
            px[l][c].b=edit[l][c].b;
        }
    }

    int temp=alt;
    alt=lar;
    lar=temp;

	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_rot.ppm");
    saida(px);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void blu(RGB px[alt][lar]){
    /**
    *   \brief Função para filtro Blurring.
    *   Borra a imagem.
    *   Para esse filtro, é feita a média aritmética de 9 elementos e adicionado o valor da média no pixel central.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */
	int l, c;
    RGB edit[alt][lar];

    /**
    *   Ao utilizar esse filtro, temos casos especiais, pois o pixel central também pode estar na borda da imagem.
    *   Sendo assim, para cada caso é feita uma média sem os pixels que ultrapassam essa borda.
    */
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            /** Primeiro pixel da primeira coluna. */
			if(l==0 && c==0){
				edit[l][c].r=(px[l][c].r+px[l][c+1].r+px[l+1][c].r+px[l+1][c+1].r)/4;
				edit[l][c].g=(px[l][c].g+px[l][c+1].g+px[l+1][c].g+px[l+1][c+1].g)/4;
				edit[l][c].b=(px[l][c].b+px[l][c+1].b+px[l+1][c].b+px[l+1][c+1].b)/4;
			}
            /** Último pixel da primeira coluna. */
			else if(l==alt-1 && c==0){
				edit[l][c].r=(px[l][c].r+px[l-1][c].r+px[l-1][c+1].r+px[l][c+1].r)/4;
				edit[l][c].g=(px[l][c].g+px[l-1][c].g+px[l-1][c+1].g+px[l][c+1].g)/4;
				edit[l][c].b=(px[l][c].b+px[l-1][c].b+px[l-1][c+1].b+px[l][c+1].b)/4;
			}
			/** Último pixel da última coluna. */
			else if(l==alt-1 && c==lar-1){
				edit[l][c].r=(px[l][c].r+px[l-1][c].r+px[l-1][c-1].r+px[l][c-1].r)/4;
				edit[l][c].g=(px[l][c].g+px[l-1][c].g+px[l-1][c-1].g+px[l][c-1].g)/4;
				edit[l][c].b=(px[l][c].b+px[l-1][c].b+px[l-1][c-1].b+px[l][c-1].b)/4;
			}
			/** Primeiro pixel da última coluna. */
			else if(l==0 && c==lar-1){
				edit[l][c].r=(px[l][c].r+px[l][c-1].r+px[l+1][c-1].r+px[l+1][c].r)/4;
				edit[l][c].g=(px[l][c].g+px[l][c-1].g+px[l+1][c-1].g+px[l+1][c].g)/4;
				edit[l][c].b=(px[l][c].b+px[l][c-1].b+px[l+1][c-1].b+px[l+1][c].b)/4;
			}
			/** Pixels da primeira linha, mas que não são o primeiro/último. */
			else if(l==0){
				edit[l][c].r=(px[l][c-1].r+px[l][c].r+px[l][c+1].r+px[l+1][c-1].r+px[l+1][c].r+px[l+1][c+1].r)/6;
				edit[l][c].g=(px[l][c-1].g+px[l][c].g+px[l][c+1].g+px[l+1][c-1].g+px[l+1][c].g+px[l+1][c+1].g)/6;
				edit[l][c].b=(px[l][c-1].b+px[l][c].b+px[l][c+1].b+px[l+1][c-1].b+px[l+1][c].b+px[l+1][c+1].b)/6;
			}
			/** Pixels da última linha, mas que não são o primeiro/último. */
			else if(l==alt-1){
				edit[l][c].r=(px[l-1][c-1].r+px[l-1][c].r+px[l-1][c+1].r+px[l][c-1].r+px[l][c].r+px[l][c+1].r)/6;
				edit[l][c].g=(px[l-1][c-1].g+px[l-1][c].g+px[l-1][c+1].g+px[l][c-1].g+px[l][c].g+px[l][c+1].g)/6;
				edit[l][c].b=(px[l-1][c-1].b+px[l-1][c].b+px[l-1][c+1].b+px[l][c-1].b+px[l][c].b+px[l][c+1].b)/6;
			}
			else if(c==0){
            /** Pixels da primeira coluna, mas que não são o primeiro/último. */
				edit[l][c].r=(px[l-1][c].r+px[l-1][c+1].r+px[l][c].r+px[l][c+1].r+px[l+1][c].r+px[l+1][c+1].r)/6;
				edit[l][c].g=(px[l-1][c].g+px[l-1][c+1].g+px[l][c].g+px[l][c+1].g+px[l+1][c].g+px[l+1][c+1].g)/6;
				edit[l][c].b=(px[l-1][c].b+px[l-1][c+1].b+px[l][c].b+px[l][c+1].b+px[l+1][c].b+px[l+1][c+1].b)/6;
			}
			/** Pixels da última coluna, mas que não são o primeiro/último. */
			else if(c==lar-1){
				edit[l][c].r=(px[l-1][c-1].r+px[l-1][c].r+px[l][c-1].r+px[l][c].r+px[l+1][c-1].r+px[l+1][c].r)/6;
				edit[l][c].g=(px[l-1][c-1].g+px[l-1][c].g+px[l][c-1].g+px[l][c].g+px[l+1][c-1].g+px[l+1][c].g)/6;
				edit[l][c].b=(px[l-1][c-1].b+px[l-1][c].b+px[l][c-1].b+px[l][c].b+px[l+1][c-1].b+px[l+1][c].b)/6;
			}
			/** Pixels que não estão na borda da imagem. */
			else{
				edit[l][c].r=(px[l-1][c-1].r+px[l-1][c].r+px[l-1][c+1].r+px[l][c-1].r+px[l][c].r+px[l][c+1].r+px[l+1][c-1].r+px[l+1][c].r+px[l+1][c+1].r)/9;
				edit[l][c].g=(px[l-1][c-1].g+px[l-1][c].g+px[l-1][c+1].g+px[l][c-1].g+px[l][c].g+px[l][c+1].g+px[l+1][c-1].g+px[l+1][c].g+px[l+1][c+1].g)/9;
				edit[l][c].b=(px[l-1][c-1].b+px[l-1][c].b+px[l-1][c+1].b+px[l][c-1].b+px[l][c].b+px[l][c+1].b+px[l+1][c-1].b+px[l+1][c].b+px[l+1][c+1].b)/9;
			}
	}
}
	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_blu.ppm");
	saida(edit);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void sha(RGB px[alt][lar]){
    /**
    *   \brief Função para filtro Sharpening.
    *   Essa função aumenta a nitidez da imagem.
    *   Nesse filtro, em uma matriz 3x3, são multiplicados por -1 as posições 0x1, 1x0, 2x1 e 1x2 e multiplicado por 5 a posição 1x1.
    *   É feita então a soma dessas multiplicações e o resultado armazenado no pixel do meio da matriz (1x1).
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

	int l, c;
    RGB edit[alt][lar];

    /**
    *   Ao utilizar esse filtro, também temos casos especiais, pois o pixel central também pode estar na borda da imagem.
    *   Sendo assim, para cada caso é feita uma média sem os pixels que ultrapassam essa borda.
    */
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            /** Primeiro pixel da primeira coluna. */
			if(l==0 && c==0){
				edit[l][c].r=px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);
			}
			/** Último pixel da primeira coluna. */
			else if(l==alt-1 && c==0){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1);
			}
			/** Último pixel da última coluna. */
			else if(l==alt-1 && c==lar-1){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5);
			}
			/** Primeiro pixel da última coluna. */
			else if(l==0 && c==lar-1){
				edit[l][c].r=px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l+1][c].b*(-1);
			}
			/** Pixels da primeira linha, mas que não são o primeiro/último. */
			else if(l==0){
				edit[l][c].r=px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);
			}
			/** Pixels da última linha, mas que não são o primeiro/último. */
			else if(l==alt-1){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1);
			}
			/** Pixels da primeira coluna, mas que não são o primeiro/último. */
			else if(c==0){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);
			}
			/** Pixels da última coluna, mas que não são o primeiro/último. */
			else if(c==lar-1){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l+1][c].b*(-1);
			}
			/** Pixels que não estão na borda da imagem. */
			else{
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);
			}
            /** Caso o resultado da soma dê maior ou menor que 0 e 255, o valor é levado para o máximo possível. */
			if(edit[l][c].r>255) edit[l][c].r=255;
			if(edit[l][c].r<0) edit[l][c].r=0;
			if(edit[l][c].g>255) edit[l][c].g=255;
			if(edit[l][c].g<0) edit[l][c].g=0;
			if(edit[l][c].b>255) edit[l][c].b=255;
			if(edit[l][c].b<0) edit[l][c].b=0;
		}
	}
	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_sha.ppm");
	saida(edit);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void bor(RGB px[alt][lar]){
    /**
    *   \brief Função para detecção de borda.
    *   Essa função determina pontos de uma imagem em que a intensidade luminosa muda repentinamente.
    *   Nesse filtro, em uma matriz 3x3, são multiplicados por 1 as posições 0x1, 1x0, 2x1 e 1x2 e multiplicado por -4 a posição 1x1.
    *   É feita então a soma dessas multiplicações e o resultado armazenado no pixel do meio da matriz (1x1).
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

	int l, c;
    RGB edit[alt][lar];

    /**
    *   Ao utilizar esse filtro, temos casos especiais, pois o pixel central também pode estar na borda da imagem.
    *   Sendo assim, para cada caso é feita uma média sem os pixels que ultrapassam essa borda.
    */
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
            /** Primeiro pixel da primeira coluna. */
			if(l==0 && c==0){
				edit[l][c].r=px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);
			}
			/** Último pixel da primeira coluna. */
			else if(l==alt-1 && c==0){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1);
			}
			/** Último pixel da última coluna. */
			else if(l==alt-1 && c==lar-1){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4);
			}
			/** Primeiro pixel da última coluna. */
			else if(l==0 && c==lar-1){
				edit[l][c].r=px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l+1][c].r*(1);
				edit[l][c].g=px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l+1][c].g*(1);
				edit[l][c].b=px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l+1][c].b*(1);
			}
			/** Pixels da primeira linha, mas que não são o primeiro/último. */
			else if(l==0){
				edit[l][c].r=px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);

			}
			/** Pixels da última linha, mas que não são o primeiro/último. */
			else if(l==alt-1){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1);
			}
			/** Pixels da primeira coluna, mas que não são o primeiro/último. */
			else if(c==0){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);
			}
			/** Pixels da última coluna, mas que não são o primeiro/último. */
			else if(c==lar-1){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l+1][c].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l+1][c].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l+1][c].b*(1);
			}
			/** Pixels que não estão na borda da imagem. */
			else{
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);
			}
			/** Caso o resultado da soma dê maior ou menor que 0 e 255, o valor é levado para o máximo possível. */
			if(edit[l][c].r>255) edit[l][c].r=255;
			if(edit[l][c].r<0) edit[l][c].r=0;
			if(edit[l][c].g>255) edit[l][c].g=255;
			if(edit[l][c].g<0) edit[l][c].g=0;
			if(edit[l][c].b>255) edit[l][c].b=255;
			if(edit[l][c].b<0) edit[l][c].b=0;
		}
	}
	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_bor.ppm");
	saida(edit);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void amp(RGB px[alt][lar]){
    /**
    *   \brief Função para ampliar imagem.
    *   Essa função amplia uma imagem a quantidade de vezes digitada pelo usuário.
    *   Para uma imagem ser ampliada, é necessário multiplicar sua altura e largura pela quantidade de vezes aumentada.
    *   Também é necessário duplicar, triplicar, quadruplicar (dependendo do valor a ser ampliado)... um mesmo pixel na linha.
    *   Essa mesma linha também precisa ser multiplicada a quantidade de vezes que a imagem for ampliada.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */

    /** Variável que armazena o valor de zoom da imagem. */
	int x;
	printf("Insira a quantidade de vezes para aumentar a imagem: ");
	scanf("%i", &x);
	int l, c, rl, rc;
    /** Variável para armazenar a nova imagem gerada. */
    FILE *saida;
	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_amp.ppm");
    saida=fopen(nome_da_foto_final, "w");
    fprintf(saida, "%s\n%i %i\n%i\n", tipo, alt*x, lar*x, qua);

	for(l = 0; l < alt; l++)
		for (rl = 0; rl < x; rl++) //repete linhas x vezes
			for(c = 0; c < lar; c++)
				for(rc = 0; rc < x; rc++) //repete colunas x vezes
					fprintf(saida, "%i %i %i\n", px[l][c].r, px[l][c].g, px[l][c].b);
	fclose(saida);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}

void red(RGB px[alt][lar]){
    /**
    *   \brief Função para reduzir tamanho da imagem.
    *   Essa função reduz uma imagem a quantidade de vezes digitada pelo usuário (somente para múltiplos dos valores de altura e largura).
    *   Nesse filtro, é feito o processo inverso ao feito para ampliar. É retirada a quantidade de linhas que foi multiplicada.
    *   Também é retirada a quantidade de vezes que um mesmo pixel foi repetido na mesma linha.
    *   \param px - Matriz utilizada para salvar a imagem.
    *   \return Nada
    */
	int x;
	printf("Insira o valor da reducao (multiplo dos valores de altura e largura): ");
	scanf("%i", &x);

	while (alt%x!=0 && lar%x!=0){
		printf("O valor inserido nao e multiplo dos valores de altura e largura. Tente novamente: ");
		scanf("%i", &x);
	}

	int l, c;
	RGB edit[(alt/x)][(lar/x)];

	for(l = 0; l < alt; l+=x)
		for(c = 0; c < lar; c+=x){
			edit[(l/x)][(c/x)].r=px[l][c].r;
			edit[(l/x)][(c/x)].g=px[l][c].g;
			edit[(l/x)][(c/x)].b=px[l][c].b;
		}
	alt/=x;
	lar/=x;

	strcpy (nome_da_foto_final, nome_da_foto_sppm);
	strcat(nome_da_foto_final, "_red.ppm");
	saida(edit);
	system("clear");
	printf("A imagem %s foi gerada.\n", nome_da_foto_final);
}
