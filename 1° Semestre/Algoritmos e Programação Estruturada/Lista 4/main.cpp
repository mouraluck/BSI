#include <stdio.h>
#include <conio.h>

int main(){
	
	int x[9];
	int y[9];
	
	printf("Escreva 9 numeros inteiros e positivyos do primeiro RA: \n");
	
	for(int i = 0; i<9 ; i++){
		scanf("%d", &x[i]);
	}
	
	for(int i = 0; i<9 ; i++){
	  y[i] = x[i];
	}
		
	y[2] = x[7];
	y[3] = x[6];
	y[6] = x[2];
	y[7] = x[3];

	for(int i=0; i<9; i++){
			printf("%d", y[i]);
	} 
	
}
