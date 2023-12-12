//Faca um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela ´
//quantas vezes aquele caractere ocorre dentro do arquivo.//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct dados{
    char texto[200];
}TEXTO;


int main(){

    FILE *ftpr;
    TEXTO ex5;

    int achou=0, cont=0, i;
    char caracter[2];

    ftpr = fopen("ex05", "wb+");
    if(ftpr == NULL){
        printf("Erro ao abrir o arquivo");
    }

    printf("Digite o texto que ira ser gravado no arquivo: ");
    gets(ex5.texto);
    for(i=0; i<ex5.texto[i] != '\0'; i++){
        ex5.texto[i] = toupper(ex5.texto[i]);
        fflush(stdin);
    }

    fwrite(&ex5,sizeof(ex5),1,ftpr);
    fclose(ftpr);

    ftpr = fopen("ex5", "rb+");
    if(ftpr == NULL){
        printf("Erro ao abrir o arquivo");
    }
    printf("\nQual caracter voce deseja procurar? ");
    gets(caracter);
    for(i=0; i<1; i++){
        caracter[i] = toupper(caracter[i]);
        fflush(stdin);
    }

    printf("%s\n", ex5.texto);
    while(fread(&ex5,sizeof(ex5),1,ftpr)){
        if(strcmp(caracter,ex5.texto)==0){
            achou = 1;
            cont++;
        }
    }

    printf("O caracter %s apareceu %d vezes no texto\n", caracter, cont);
    fclose(ftpr);

return 0;
}
