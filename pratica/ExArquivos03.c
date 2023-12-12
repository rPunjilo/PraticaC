//Faça 2 programas, um que leia o arquivo TEXTO criado no exercício 1 e outro que leia o arquivo
//BINÁRIO criado no exercício 2. Exibir na tela os dados lidos dos respectivos arquivos


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int main(){

    int i;
    char linha[100];

    printf("Texto:\n");

    FILE *ftpr;

    ftpr = fopen("dados.txt", "r");

    if(ftpr == NULL){
        printf("\n Erro na Abertura do Arquivo\n");
        system("pause");
    }

    while (fgets(linha, sizeof(linha), ftpr) != NULL) {
        printf("%s", linha);
    }

    fclose(ftpr);

    printf("\nBinario:\n");


    int numero;
    FILE *ftps;

    ftps = fopen("dados.bin", "rb");

    if(ftps == NULL){
        printf("\n Erro na Abertura do Arquivo\n");
        system("pause");
    }

    while (fread(&numero, sizeof(int), 1, ftps) == 1) {
        printf("%d\n", numero);
    }

    fclose(ftps);

    return 0;
}
