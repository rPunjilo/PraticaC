#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//3 alunos e 5 matérias!!!

int main(){
    int i,j, idade[3];
    int codigo[5];
    int disciplina[5][20];
    int cont = 0, contB = 0, contC=0, somaIdade=0;
    char resposta;
    float media;

    for(i=0; i<3; i++){
        printf("Digite a idade do aluno %d: ", i+1);
        scanf("%d", &idade[i]);
    }

    for(i=0; i<3; i++){
        printf("\nO aluno %d chegou a realizar alguma prova? ", i+1);
        scanf(" %c", &resposta);
        resposta = toupper(resposta);
        if(resposta == 'S'){
            for(i=0; i<5; i++){
                printf("\nQual o codigo da disciplina %d: ", i+1);
                scanf("%d", &codigo[i]);
                for(j=0; j<3; j++){
                    printf("Qual a quantidade de provas que o aluno %d fez na disciplina %d? ", j+1, codigo[i]);
                    scanf("%d", &disciplina[i][j]);
                    if(idade[j]>=18 && idade[j]<=25 && disciplina[i][j]>2){
                        cont++;
                    }
                }
            }
        }
        else{
            contC++;
            somaIdade += idade[i];
        }
    }



    printf("\nA quantidade de alunos entre 18 e 25 anos e que fizeram mais de 2 provas eh: %d\n", cont);

    for(i=0; i<5; i++){
        contB = 0;
        for(j=0; j<3; j++){
            if(disciplina[i][j]<3){
                contB++;
            }
        }
        printf("\n%d alunos na disciplina %d fizeram menos de 3 provas\n", contB, codigo[i]);
    }

    media = somaIdade / contC;

    printf("\nA media de idade dos alunos que não fizeram nenhuma prova eh: %.2f\n", media);

    return 0;
}
