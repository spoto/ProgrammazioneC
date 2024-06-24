#include <stdio.h>

int isSubstring(char*b, char *a){
	//da completare
}
int main(void){

	printf("%s%s è sottostringa di %s\n", "am", isSubstring( "am","amici")==0? " non": "", "amici");
	printf("%s%s è sottostringa di %s\n", "pia", isSubstring("pia", "amici")==0? " non": "", "amici");
	printf("%s%s è sottostringa di %s\n", "riva", isSubstring("riva", "arrivare")==0	? " 	non": "",  "arrivare");
	return 0;
}

