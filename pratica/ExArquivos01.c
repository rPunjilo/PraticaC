#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//Fa�a um programa que crie um arquivo TEXTO em disco, com o nome �dados.txt�, e escreva neste
//arquivo em disco uma contagem que v� de 1 at� 100, com um n�mero em cada linha.

int main(){

    int i;

    FILE *ftpr;

    ftpr = fopen("dados.txt", "w");

    if(ftpr == NULL){
        printf("\n Erro na Abertura do Arquivo\n");
        system("pause");
    }

    for(i=0; i<100; i++){
        fprintf(ftpr,"%d\n", i+1);
    }

    fclose(ftpr);
    return 0;
}
