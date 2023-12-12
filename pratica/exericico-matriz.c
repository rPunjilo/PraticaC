#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    int idadealuno[8], disciplinacodigo[5];
    int linha, coluna, contador;
    int matrizdisciplinas[8][5];
    setlocale(LC_ALL, "Portuguese");


    //receber idade de 8 alunos;
    for (contador = 0; contador < 8; contador ++)
    {
        printf("\nPor favor, insira a idade do aluno %d: ", contador + 1);
        scanf("%d", &idadealuno[contador]);
    }

    /*
    //verificação se o programa está recebendo as idades
    for (contador = 0; contador < 8; contador ++)
    {
        printf("Idade do aluno %d: %d\n", contador + 1, idadealuno[contador]);
    }
    */

    //receber código de disciplina
    for (coluna = 0; coluna < 5; coluna ++)
    {
        printf("Por favor, insira o codigo da disciplina: \n");
        scanf("%d", &disciplinacodigo[coluna]);
        for (linha = 0; linha < 8; linha ++)
        {
            printf("Por favor, insira a quantidade de provas da disciplina %d que o aluno %d fez: ", disciplinacodigo[coluna], linha + 1);
            scanf("%d", &matrizdisciplinas[linha][coluna]);
        }
    }

    //vai imprimir o cabeçalho
    system("cls");

    printf("IDADE ALUNO DISCIPLINA1 DISCIPLINA2 DISCIPLINA3 DISCIPLINA4 DISCIPLINA5");

    for (linha = 0; linha < 8; linha ++)
    {
        printf("\n\n");
        //vai exibir idade dos alunos
        printf("%d      ", idadealuno[linha]);
        //vai exibir o ID de cada aluno
        printf("%d      ", linha + 1);
        for (coluna = 0; coluna < 5; coluna ++)
        {
            printf("%d            ", matrizdisciplinas[linha][coluna]);
        }
    }

    return 0;
}
