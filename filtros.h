void thr(RGB px[alt][lar]){
	/*binariza a imagem. Faz a media de red, green e blue de cada pixel. Se for maior que 127, o pixel fica branco, e se for menor, fica preto*/
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
	printf("Insira o grau de rotação (90, 180 ou 270): ");
	scanf("%i", &rot);
	
	while(rot != 90 && rot != 180 && rot != 270){
		printf("Insira o grau de rotação (90, 180 ou 270): ");
		scanf("%i", &rot);
	}
	
	if(rot==90) rot_90(px);
	if(rot==180) rot_180(px);
	if(rot==270) rot_270(px);
}

void rot_180(RGB px[alt][lar]){
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
	int l, c;
    RGB edit[alt][lar];
    
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
			if(l==0 && c==0){
				edit[l][c].r=(px[l][c].r+px[l][c+1].r+px[l+1][c].r+px[l+1][c+1].r)/4;
				edit[l][c].g=(px[l][c].g+px[l][c+1].g+px[l+1][c].g+px[l+1][c+1].g)/4;
				edit[l][c].b=(px[l][c].b+px[l][c+1].b+px[l+1][c].b+px[l+1][c+1].b)/4;
			}
			else if(l==alt-1 && c==0){
				edit[l][c].r=(px[l][c].r+px[l-1][c].r+px[l-1][c+1].r+px[l][c+1].r)/4;
				edit[l][c].g=(px[l][c].g+px[l-1][c].g+px[l-1][c+1].g+px[l][c+1].g)/4;
				edit[l][c].b=(px[l][c].b+px[l-1][c].b+px[l-1][c+1].b+px[l][c+1].b)/4;
			}
			else if(l==alt-1 && c==lar-1){
				edit[l][c].r=(px[l][c].r+px[l-1][c].r+px[l-1][c-1].r+px[l][c-1].r)/4;
				edit[l][c].g=(px[l][c].g+px[l-1][c].g+px[l-1][c-1].g+px[l][c-1].g)/4;
				edit[l][c].b=(px[l][c].b+px[l-1][c].b+px[l-1][c-1].b+px[l][c-1].b)/4;
			}
			else if(l==0 && c==lar-1){
				edit[l][c].r=(px[l][c].r+px[l][c-1].r+px[l+1][c-1].r+px[l+1][c].r)/4;
				edit[l][c].g=(px[l][c].g+px[l][c-1].g+px[l+1][c-1].g+px[l+1][c].g)/4;
				edit[l][c].b=(px[l][c].b+px[l][c-1].b+px[l+1][c-1].b+px[l+1][c].b)/4;
			}
			else if(l==0){
				edit[l][c].r=(px[l][c-1].r+px[l][c].r+px[l][c+1].r+px[l+1][c-1].r+px[l+1][c].r+px[l+1][c+1].r)/6;
				edit[l][c].g=(px[l][c-1].g+px[l][c].g+px[l][c+1].g+px[l+1][c-1].g+px[l+1][c].g+px[l+1][c+1].g)/6;
				edit[l][c].b=(px[l][c-1].b+px[l][c].b+px[l][c+1].b+px[l+1][c-1].b+px[l+1][c].b+px[l+1][c+1].b)/6;
			}
			else if(l==alt-1){
				edit[l][c].r=(px[l-1][c-1].r+px[l-1][c].r+px[l-1][c+1].r+px[l][c-1].r+px[l][c].r+px[l][c+1].r)/6;
				edit[l][c].g=(px[l-1][c-1].g+px[l-1][c].g+px[l-1][c+1].g+px[l][c-1].g+px[l][c].g+px[l][c+1].g)/6;
				edit[l][c].b=(px[l-1][c-1].b+px[l-1][c].b+px[l-1][c+1].b+px[l][c-1].b+px[l][c].b+px[l][c+1].b)/6;
			}
			else if(c==0){
				edit[l][c].r=(px[l-1][c].r+px[l-1][c+1].r+px[l][c].r+px[l][c+1].r+px[l+1][c].r+px[l+1][c+1].r)/6;
				edit[l][c].g=(px[l-1][c].g+px[l-1][c+1].g+px[l][c].g+px[l][c+1].g+px[l+1][c].g+px[l+1][c+1].g)/6;
				edit[l][c].b=(px[l-1][c].b+px[l-1][c+1].b+px[l][c].b+px[l][c+1].b+px[l+1][c].b+px[l+1][c+1].b)/6;
			}
			else if(c==lar-1){
				edit[l][c].r=(px[l-1][c-1].r+px[l-1][c].r+px[l][c-1].r+px[l][c].r+px[l+1][c-1].r+px[l+1][c].r)/6;
				edit[l][c].g=(px[l-1][c-1].g+px[l-1][c].g+px[l][c-1].g+px[l][c].g+px[l+1][c-1].g+px[l+1][c].g)/6;
				edit[l][c].b=(px[l-1][c-1].b+px[l-1][c].b+px[l][c-1].b+px[l][c].b+px[l+1][c-1].b+px[l+1][c].b)/6;
			}
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
	int l, c;
    RGB edit[alt][lar];
    
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
			if(l==0 && c==0){
				edit[l][c].r=px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);
			}
			else if(l==alt-1 && c==0){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1);			
			}
			else if(l==alt-1 && c==lar-1){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5);
			}
			else if(l==0 && c==lar-1){
				edit[l][c].r=px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l+1][c].b*(-1);
			}
			else if(l==0){
				edit[l][c].r=px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);		
			}
			else if(l==alt-1){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1);			
			}
			else if(c==0){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);				
			}
			else if(c==lar-1){
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l+1][c].b*(-1);
			}
			else{
				edit[l][c].r=px[l-1][c].r*(-1)+px[l][c-1].r*(-1)+px[l][c].r*(5)+px[l][c+1].r*(-1)+px[l+1][c].r*(-1);
				edit[l][c].g=px[l-1][c].g*(-1)+px[l][c-1].g*(-1)+px[l][c].g*(5)+px[l][c+1].g*(-1)+px[l+1][c].g*(-1);
				edit[l][c].b=px[l-1][c].b*(-1)+px[l][c-1].b*(-1)+px[l][c].b*(5)+px[l][c+1].b*(-1)+px[l+1][c].b*(-1);
			}
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
	int l, c;
    RGB edit[alt][lar];
    
    for(l=0; l < alt; l++){
        for(c=0; c < lar; c++){
			if(l==0 && c==0){
				edit[l][c].r=px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);
			}
			else if(l==alt-1 && c==0){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1);			
			}
			else if(l==alt-1 && c==lar-1){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4);
			}
			else if(l==0 && c==lar-1){
				edit[l][c].r=px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l+1][c].r*(1);
				edit[l][c].g=px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l+1][c].g*(1);
				edit[l][c].b=px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l+1][c].b*(1);
			}
			else if(l==0){
				edit[l][c].r=px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);		
			
			}
			else if(l==alt-1){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1);
			}
			else if(c==0){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);				
			}
			else if(c==lar-1){
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l+1][c].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l+1][c].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l+1][c].b*(1);				
			}
			else{
				edit[l][c].r=px[l-1][c].r*(1)+px[l][c-1].r*(1)+px[l][c].r*(-4)+px[l][c+1].r*(1)+px[l+1][c].r*(1);
				edit[l][c].g=px[l-1][c].g*(1)+px[l][c-1].g*(1)+px[l][c].g*(-4)+px[l][c+1].g*(1)+px[l+1][c].g*(1);
				edit[l][c].b=px[l-1][c].b*(1)+px[l][c-1].b*(1)+px[l][c].b*(-4)+px[l][c+1].b*(1)+px[l+1][c].b*(1);
			}
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
	int x;
	printf("Insira: ");
	scanf("%i", &x);
	int l, c, rl, rc;
	
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
