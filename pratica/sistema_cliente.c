#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>



typedef struct dados
{
    char nome[20];
    char sobrenome[15];
    char depto[20];
    float salario;
    int idade;
    int telefone;
    int codigo;
} CLIENTE;

int atual = 0;

void Inserir()
{
    char numstr[20];
    char resp;

    system("cls");

    // tratando Arquivo

    FILE *fptr;

    CLIENTE fatec;

    fptr = fopen("ARQUIVO","ab+");

    fseek(fptr, 0,SEEK_END);
    atual++;
    fatec.codigo = atual;


    if (fptr == NULL)
    {
        printf("\n Erro na Abertura do Arquivo");
        system("pause");

    }
    else
    {

        do
        {

            system("cls");
            printf("\n ***********************************************");
            printf("\n ************* FATEC AMERICANA *****************");
            printf("\n ***************   CADASTRO   ******************");
            printf("\n ***********************************************");

            printf("\nCódigo do cliente: %d\n", fatec.codigo);
            fflush(stdin);
            printf("\n Informe o Nome do Cliente");
            gets(fatec.nome);
            fflush(stdin);

            printf("\n Informe o Sobrenome do Cliente");
            gets(fatec.sobrenome);
            fflush(stdin);

            printf("\n Informe o Depto do Cliente");
            gets(fatec.depto);
            fflush(stdin);

            printf("\n Informe o Salario do Cliente");
            gets(numstr);
            fatec.salario=atof(numstr);
            fflush(stdin);

            printf("\n Informe a Idade do Cliente");
            gets(numstr);
            fatec.idade = atoi(numstr);
            fflush(stdin);

            printf("\n Informe o Telefone do Cliente");
            gets(numstr);
            fatec.telefone=atoi(numstr);
            fflush(stdin);

            // linha de gravação de escrita de dados no Arquivo
            fwrite(&fatec,sizeof(fatec),1,fptr);


            printf("\n Deseja continuar o Cadastro [S]im ou [N]ão");
            resp=getchar();
            resp=toupper(resp);

        }
        while (resp == 'S');


    }

    fclose(fptr);

}



void Pesquisa()
{
    char numstr[20];
    int achou=0;

    FILE *fptr;

    CLIENTE fatec;

    fptr = fopen("ARQUIVO","rb");

    if (fptr == NULL)
    {
        printf("\n Erro na Abertura do Arquivo");
        system("pause");

    }
    else
    {
            system("cls");
            printf("\n ***********************************************");
            printf("\n ************* FATEC AMERICANA *****************");
            printf("\n ***************   PESQUISA   ******************");
            printf("\n ***********************************************");

            printf("\n Informe o nome a ser Pesquisado");
            gets(numstr);
            fflush(stdin);


            while(fread(&fatec,sizeof(fatec),1,fptr))
            {
                if(strcmp(numstr,fatec.nome)==0)
                {
                    achou =1;
                    printf("\n Codigo .....:%d", fatec.codigo);
                    printf("\n Nome ........:%s",fatec.nome);
                    printf("\n Sobrenome ...:%s",fatec.sobrenome);
                    printf("\n Depto........:%s",fatec.depto);
                    printf("\n Salario .....:%.2f",fatec.salario);
                    printf("\n Idade .......:%d",fatec.idade);
                    printf("\n\n");
                    system("pause");
                    break;
                }
            }

            if(achou ==0)
            {
                printf("\n Registro não consta na Base de Dados");
                printf("\n\n");
                system("pause");
            }

            fclose(fptr);

}
}


void Alterar()
{
    int c;
    char numstr[20];
    c=0;
    FILE *fptr;

    CLIENTE fatec;

    fptr = fopen("ARQUIVO","rb+");

    if (fptr == NULL)
    {
        printf("\n Erro na Abertura do Arquivo");
        system("pause");

    }
    else
    {
            system("cls");
            printf("\n ***********************************************");
            printf("\n ************* FATEC AMERICANA *****************");
            printf("\n ***************   ALTERAÇÃO  ******************");
            printf("\n ***********************************************");

            printf("\n Informe o nome a ser Alterado");
            gets(numstr);
            fflush(stdin);

            fread(&fatec,sizeof(fatec),1,fptr);

            while(!feof(fptr) && strcmp(numstr,fatec.nome)!=0)
            {
                fread(&fatec,sizeof(fatec),1,fptr);
                c++;
            }
            if(feof(fptr))
            {
                printf("\n Registro não consta na Base de Dados");
                printf("\n\n");
                system("pause");
            }else{

            fseek(fptr,c*sizeof(fatec),SEEK_SET);


                    printf("\n Nome ........:%s",fatec.nome);
                    printf("\n Redigite o nome ..... :");
                    gets(fatec.nome);
                    fflush(stdin);
                    printf("\n Sobrenome ...:%s",fatec.sobrenome);
                    printf("\n Redigite o Sobrenome....... :");
                    gets(fatec.sobrenome);
                    fflush(stdin);

                    printf("\n Depto........:%s",fatec.depto);
                    printf("\n Redigite o Depto ..... :");
                    gets(fatec.depto);
                    fflush(stdin);


                    printf("\n Salario .....:%.2f",fatec.salario);
                    printf("\n Redigite o Salario ..... :");
                    scanf("%f",&fatec.salario);
                    fflush(stdin);

                    printf("\n Idade .......:%d",fatec.idade);
                    printf("\n Redigite a Idade ..... :");
                    scanf("%d",&fatec.idade);
                    fflush(stdin);

                    fwrite(&fatec,sizeof(fatec),1,fptr);
                    printf("\n Gravado o Registro com Sucesso");
                    system("pause");

                }
            }

              fclose(fptr);
            }




void Exibir()
{

    FILE *fptr;

    CLIENTE fatec;

    fptr = fopen("ARQUIVO", "rb");

    if (fptr == NULL)
    {
        printf("\n Erro na Abertura do Arquivo");
        system("pause");

    }
    else

        system("cls");
    printf("\n ******************************************************");
    printf("\n ************* FATEC AMERICANA ************************");
    printf("\n ***************   CADASTRO   *************************");
    printf("\n Código \t Nome \t Sobrenome \t Depto \t  Salario \t Fone ");
    printf("\n ******************************************************");

    while(fread(&fatec,sizeof(fatec),1,fptr))
    {
        printf("\n %d %s \t %s \t %s \t %.2f \t %d", fatec.codigo,fatec.nome,fatec.sobrenome,fatec.depto,fatec.salario,fatec.telefone);

    }

    printf("\n\n");
    system("pause");
    fclose(fptr);



}

void main()
{
    int op;
    setlocale(LC_ALL, "Portuguese");

    do
    {

        system("cls");
        printf("\n **************  MENU PRINCIPAL ***************");
        printf("\n     [ 1 ] - CADASTRO DE CLIENTE.              ");
        printf("\n     [ 2 ] - RELATÓRIO                         ");
        printf("\n     [ 3 ] - PESQUISA PELO SOBRENOME           ");
        printf("\n     [ 4 ] - ALTERAÇÃO                         ");
        printf("\n     [ 5 ] - REMOÇÃO                           ");
        printf("\n **********************************************");
        printf("\n Escolha a opção ...");
        scanf("%d",&op);
        fflush(stdin);

        switch(op)
        {
        case 1:
            Inserir();
            break;

        case 2 :
            Exibir();
            break;
        case 3 :
            Pesquisa();
            break;
        case 4:
            Alterar();
            break;
        case 5:
            printf("\n Função a ser Desenvolvida");
            break;
        case 6:
            exit(0);
        default :
            printf("\n opção Invalida ... Tente Novamente");
            system("pause");
        }
    }
    while (op != 6);

}

