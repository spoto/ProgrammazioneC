#include <stdio.h>
#define M 10
#define L 8//lunghezza standard di una targa


/*legge le targhe da stdin e le memorizza in una matrice di caratteri*/
void leggiTarghe(char [][L] );
 /*memorizza le targhe pari in una matrice di caratteri e resituisce il numero di targhe pari*/
int trovaTarghePari(char [][L], char [][L] );


void mystrcpy(char dest[], char source[]) {
	for(int i=0;i<=L;i++) {
		dest[i]=source[i];
	}
}

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

	for (int i=0;i<M;i++){
		printf("Inserisci una targa: ");
		scanf("%7s",targhe[i]);
		
 	}	
 }

int trovaTarghePari(char targhe[][L], char targhePari [][L] ){
 	int k=0;
	for(int i=0;i<M;i++){
 		if( (targhe[i][4]-'\0')%2==0){
 			mystrcpy(targhePari[k],targhe[i]);//qui potrebbero usare strncpy ma non lo abbiamo visto a lezione
 			k++;}//if	
 			
 	} //for	
	return k;
 }	
