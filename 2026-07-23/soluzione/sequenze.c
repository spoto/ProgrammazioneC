#include<stdio.h>
#include<string.h>
#define DIM 25

/*prototipi delle funzioni*/
int contaseq(char *);
int conta(char *, int);

int main(){
	char nome[100];
	int soglia;
	int num;
	
	scanf("%s",nome);
	scanf("%d",&soglia);
	num=conta(nome, soglia);
	printf("%d\n",num);
	return 0;

}


int contaseq(char *s) {
    if (s[0] == '\0')
        return 0;

    if (s[1] == '\0')
        return 1;

    if (s[1] == s[0] + 1)
        return 1 + contaseq(s + 1);
    else
        return 1;
}


int conta(char *nome, int soglia){
	FILE *fid;
	char str[DIM+1];
	int cont=0;
	
	fid=fopen(nome,"r");
	if(fid==NULL)
		return -1;
	else{
		fscanf(fid,"%s",str);
		while(!feof(fid)){
			if(contaseq(str)>soglia){
				cont++;
			}
			fscanf(fid,"%s",str);
		}
		return cont;
	}
}

