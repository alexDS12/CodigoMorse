#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Código não totalmente atualizado, pode conter algum problema*/
 
int verificar(char *morse){
    int i, flag=0;
    for(i=0; *(morse+i)!='\0'; i++){
        if( *(morse+i)!='.' && *(morse+i)!='-' && *(morse+i)!=' '){
            flag = 1;
            return flag;
        }
    }
    return flag;
} 
 
void traducao(char *morse){
	FILE *fp;
	int i, j, x;
	char indices[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char **string, aux[6];	
	
	if((fp=fopen("CMorse.txt", "r"))==NULL){
		printf("Erro ao abrir o arquivo");
		return -1;
	}
	
	
	string = (char **) malloc(36*sizeof(char *));
	for(i=0; i<36; i++){
		string[i] = (char *) malloc(6*sizeof(char));
	}
		
	for(i=0; i<36; i++){
		fscanf(fp, "%s\n", string[i]);
	}
	
	for(i=0; i<36; i++){
		printf("%d ", i);
		puts(*(string+i));
	}
	
	do{
		for(i=0; *(morse+i)!=' '; i++){
			aux[i] = *(morse+i);
		}
		aux[i]='\0';
		printf("\n%s", aux);
		/*for(i=0; *(string); i++){
			if(strcmp(aux, string[i])==0){
				j=i;
			}
		}*/
		//printf("J: %d %c ", j, indices[j]);
		//printf("\n%s\n", aux);
		morse++;
	}while(*(morse+i)!='\0');
}
 
int main(){
    char morse[100];
    int i, erro;
    printf("Informe o codigo morse: ");
    gets(morse);
    erro=verificar(&morse);
    while(erro==1){
        printf("\nFoi informado um caracter invalido, informe codigo novamente: ");
        gets(morse);
        erro=verificar(&morse);
    }
    traducao(&morse);
    return 0;
}
