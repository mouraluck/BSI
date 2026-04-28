#include <stdio.h>
#include <conio.h>

int main(){
	
	int x[12];
	bool trocou = false;
	int a;
	printf("Escreva 12 numeros inteiros do primeiro vetor (desordenado): \n");
	
	for(int i = 0; i<12 ; i++){
		scanf("%d", &x[i]);
	}
	
	do {
		trocou = false;
        for(int i = 0; i < 11; i++) {
            if(x[i] > x[i + 1]) {
                a = x[i];
                x[i] = x[i + 1];
                x[i + 1] = a;
                trocou = true;
            }
        }
	} while(trocou);

	for(int i=0; i<12; i++){
			printf("%d ", x[i]);
	} 
	
}
