void thr(RGB pixel[altura][largura]){
	int media, linha, coluna;
	for(linha=0; linha<altura; linha++){
		for(coluna=0; coluna<largura; coluna++){
			media=(pixel[linha][coluna].vermelho+pixel[linha][coluna].verde+pixel[linha][coluna].azul)/3;
			if (media>127){
				pixel[linha][coluna].vermelho=255;
				pixel[linha][coluna].verde=255;
				pixel[linha][coluna].azul=255;
			}else{
				pixel[linha][coluna].vermelho=0;
				pixel[linha][coluna].verde=0;
				pixel[linha][coluna].azul=0;
			}
		}
	}
	saida(pixel);
}
