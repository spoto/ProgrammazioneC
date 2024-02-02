#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 10
#define L 8//lunghezza standard di una targa
				
/*legge le targhe da stdin e le memorizza in una matrice di caratteri*/
void leggiTarghe(char [][L] );

/*memorizza le targhe pari in una matrice di caratteri e resituisce il numero di targhe pari*/
int trovaTarghePari(char [][L], char [][L] );

int main(void){
	char targhe[M][L];
	leggiTarghe(targhe);
			
	char targhePari[M][L];	
	int k = trovaTarghePari(targhe,targhePari);
	printf("Le seguenti targhe sono pari:\n");
	for (int i=0;i<k;i++){
		printf("%s\n",targhePari[i]);
	}
	return -1;
}
void leggiTarghe(char targhe[M][L] ){
	// da completare	
}
		
int trovaTarghePari(char targhe[][L], char targhePari [][L] ){
	// da completare
}	
		
