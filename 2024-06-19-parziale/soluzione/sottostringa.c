#include <stdio.h>
#include <string.h>

int isSubstring(char*b, char *a){
	int conta=0;
	int max=0;
	char *ia=a;
	char *ib=b;
	int trovato=1;
	if (strlen(b)>strlen(a)) return 0; 
	while (*ia!='\0'){
		trovato=1;//ottimismo
		ib=b;
		//printf("Sto confrontando %s %s\n",ia,ib);	
		for (int i=0;i<strlen(ib);i++)
			if( *(ia+i) != *(ib+i) )
				trovato=0;
		if (trovato){
		// 	printf("trovata %s",ib);
			return 1;
		}
		
		ia++;
		
	}//while
	return 0;	

}
int main(void){

	printf("%s%s è sottostringa di %s\n", "am", isSubstring( "am","amici")==0? " non": "", "amici");
	printf("%s%s è sottostringa di %s\n", "pia", isSubstring("pia", "amici")==0? " non": "", "amici");
	printf("%s%s è sottostringa di %s\n", "riva", isSubstring("riva", "arrivare")==0	? " non": "",  "arrivare");
	return 0;

}

