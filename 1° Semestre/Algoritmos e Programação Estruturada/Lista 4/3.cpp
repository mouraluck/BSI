#include <stdio.h>
#include <conio.h>

int main(){
	
	int x[9];
	int y[9];
	
	printf("Escreva 9 numeros inteiros e positivos do primeiro RA: \n");
	
	for(int i = 0; i<9 ; i++){
		scanf("%d", &x[i]);
	}
	
	for(int i = 0; i<9 ; i++){
	  y[i] = x[i];
	}
		
	y[7] = x[8];
	y[8] = x[7];
	y[0] = x[1];
	y[1] = x[0];

	for(int i=0; i<9; i++){
			printf("%d", y[i]);
	} 
	
}
