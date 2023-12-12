#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#define max 15


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i,opcao, tipo, setor, estrati[max], aleatorio[max], numero[1000], j;
    int passoInt;
    char ja_consta, chopcao;
    float populacao,margem, n , no, cont, cont1, passo, proporcao, passoFloat;
    srand(time(0));

    do
    {
        system("cls");

        printf("Menu");
        printf("\nQual o tamanho popula��o?\n");
        printf("\n[1] Finita");
        printf("\n[2] Infinita");
        printf("\n\nPor favor, selecione uma op��o: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            printf("\n-------POPULA��O FINITA-------\n");
            printf("\nQual o tamanho da popula��o? ");
            scanf("%f", &populacao);
            printf("Voc� deseja inserir o n�mero de amostras?\n[S]Sim\n[N]N�o\nSelecione uma op��o: ");
            scanf(" %c", &chopcao);
            chopcao = toupper(chopcao);

            if (chopcao == 'S')
            {
                printf("Insira o n�mero de amostras desejado: ");
                scanf("%f", &n);
                //printf("%.0f", n);
            }
            else if (chopcao == 'N')
            {
                printf("Qual a margem de erro? ");
                scanf("%f", &margem);

                no = 1 / pow((margem/100),2);
                n = (populacao * no)/(populacao + no);

                printf("O numero de amostras �: %.0f\n", n);
            }
            /*printf("Qual a margem de erro? ");
            scanf("%f", &margem);

            no = 1 / pow((margem/100),2);*/
            //n = (populacao * no)/(populacao + no) + 1;

            //printf("O numero de amostras �: %.0f\n", n);

            printf("\nQual o tipo de amostragem?\n");
            printf("[1] - ALEAT�RIA\n");
            printf("[2] - ESTRATIFICADA\n");
            printf("[3] - SISTEM�TICA\n");
            printf("\nQual o tipo de amostragem voc� deseja? ");
            scanf("%d", &tipo);
            int populacao1 = populacao;

            if (tipo == 1){
                printf("------AMOSTRAGEM ALEAT�RIA------\n");
                // imprime numeros aleat�rios, mas as vezes algum n�mero se repete
                //for(i=0; i<n; i++){
                  //  printf(" %d", rand() % populacao1 + 1);
                for (i=0; i<n; i++) {
                    numero[i] = rand() % populacao1 + 1;
                    ja_consta = 'N';
                    for (j=0; j<i && ja_consta == 'N'; j++) {
                        if (numero[i] == numero[j]){
                            ja_consta = 'S';
                        }
                    }
                    if (ja_consta == 'S'){
                        i--;
                    }
                }
                for (i=0; i<n; i++){
                    printf(" %d", numero[i]);

                }
            }


            if (tipo == 2){
                proporcao = n / populacao;
                printf("------AMOSTRAGEM ESTRATIFICADA------\n");
                printf("A propor��o �: %.4f\n", proporcao);
                printf("\nQuantos setores ir� ter? ");
                scanf("%d", &setor);
                for (i=1; i<=setor; i++){
                    printf("Qual o valor do setor %d? ", i);
                    scanf("%d", &estrati[i]);
                }
                printf("\n");
                for (i=1; i<=setor; i++){
                    printf("O resultado do setor %d � %.0f\n", i, (estrati[i] * proporcao));
                }
            }

            if (tipo == 3){
                printf("------AMOSTRAGEM SISTEM�TICA------\n");
                cont = rand()% 5 ;
                passo = populacao / n;
                passoInt = passo;
                passoFloat = passoInt;
                printf("O passo �: %.0f\n", passoFloat);
                for(i=1; i<=n; i++){
                    printf(" %.0f", cont);
                    cont += passoFloat;
                    if(cont>populacao1){
                        cont1 = cont-populacao1;
                        cont = cont1;
                    }
                }
            }


            printf("\n");
            system("pause");
            break;

        case 2:
            printf("\n-------POPULA��O INFINITA-------\n");
            printf("Para os testes com popula��o infinita, a unica amostragem poss�vel � a aleat�ria!!\n");
            printf("\nQual a margem de erro? ");
            scanf("%f", &margem);
            no = 1 / pow((margem/100),2);
            int no2 = no;
            printf("%d", no2);

            printf("\n------AMOSTRAGEM ALEAT�RIA------\n");
            for (i=0; i<no2; i++) {
                numero[i] = rand() % no2 + 1;
                ja_consta = 'N';
                for (j=0; j<i && ja_consta == 'N'; j++) {
                    if (numero[i] == numero[j]){
                        ja_consta = 'S';
                    }
                }
                if (ja_consta == 'S'){
                    i--;
                }
            }
            for (i=0; i<no2; i++){
                printf(" %d", numero[i]);
            }

            printf("\n");
            system("pause");
            break;

        default:
            printf("\nOp��o Inv�lida\n");
            system("pause");
        }

    }
    while (opcao <= 2);

    return 0;
}
