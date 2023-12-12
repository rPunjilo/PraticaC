//Faça um programa que leia (do teclado) um cadastro de 10 alunos, indicando o nome, nota1, nota2.
//Calcule a média aritmética simples dos 10 alunos e depois escreva em um arquivo texto os dados de
//cada aluno: nome, nota1, nota2 e média. Escreva no arquivo e depois mostre na tela as
//informações referentes aos alunos

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Dados{
    char nome[30];
    float nota1, nota2, media;
}ALUNO;

int main(){
    int i;
    char numstr[20];
    char linha[100];

    FILE *ftpr;
    ALUNO alunos;

    ftpr = fopen("medias", "wb+");
    if(ftpr == NULL){
        printf("Erro ao abrir o arquivo\n");
    }

    for(i=0; i<3; i++){
        printf("\nDigite o nome do %d aluno: ", i+1);
        gets(alunos.nome);
        fflush(stdin);
        printf("Digite a primeira nota: ");
        gets(numstr);
        alunos.nota1 = atof(numstr);
        fflush(stdin);
        printf("Digite a segunda nota: ");
        gets(numstr);
        alunos.nota2 = atof(numstr);
        fflush(stdin);
        alunos.media = (alunos.nota1 + alunos.nota2) / 2.0;
        fwrite(&alunos,sizeof(alunos),1,ftpr);
    }
    fclose(ftpr);

    ftpr = fopen("medias", "rb+");
    if(ftpr == NULL){
        printf("Erro ao abrir o arquivo\n");
    }

    for(i=0; i<3; i++){
        fread(&alunos,sizeof(alunos),1,ftpr);
        printf("\nAluno %d\n", i + 1);
        printf("Nome: %s\n", alunos.nome);
        printf("Nota 1: %.2f\n", alunos.nota1);
        printf("Nota 2: %.2f\n", alunos.nota2);
        printf("Média: %.2f\n\n", alunos.media);
    }
    fclose(ftpr);

    return 0;
}
