//Faça um programa que receba o nome de um arquivo de entrada e outro de saída. O
//arquivo de entrada contem em cada linha o nome de uma cidade ocupando 40 caracte- ´
//res e o seu numero de habitantes. O programa deverá ler o arquivo de entrada e gerar ´
//um arquivo de saída onde aparece o nome da cidade mais populosa seguida pelo seu
//numero de habitantes.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

typedef struct dados{
    char nomeCidade[40];
    int habitantes;
}CIDADE;

int main(){
    int i, achou = 0, maior = 0; // p achou é usado na linha 74 e 82
    char resposta;
    char pesquisa[40];
    //char numstr[20]; foi usado na linha 41
    setlocale(LC_ALL, "Portuguese");

    //abertura do ponteiro
    FILE *ftpr;
    CIDADE cidade;

    //abertura do arquivo, para apenas escrita, em binário
    ftpr = fopen("ex6", "wb+");
    if(ftpr == NULL){ //sempre ao abrir algum arquivo, colocar essa tratativa
        printf("Erro ao abrir o arquivo\n"); //Boas praticas ao lidar com arquivos
    }

    do{
        fflush(stdin);
        printf("\nQual o nome da cidade? ");
        gets(cidade.nomeCidade);//comando semelhante ao scanf. O tony usou também
        fflush(stdin);
        for(i=0; i<cidade.nomeCidade[i] != '\0'; i++){
            // laço para converter o nome da cidade todo para maisculo
            cidade.nomeCidade[i] = toupper(cidade.nomeCidade[i]);
        }
        printf("Qual a quantidade de habitantes? ");
        //fgets(numstr,20,stdin); O tony usou esses comandos, porém com scanf funcionou normalmente
        //cidade.habitantes = atoi(numstr);
        scanf("%d", &cidade.habitantes);
        if(cidade.habitantes > maior){
            maior = cidade.habitantes;//cidade com maior numero de habitantes
        }
        fflush(stdin);
        fwrite(&cidade,sizeof(cidade),1,ftpr); //escrita da struct no arquivo
        printf("Deseja continuar? S-Sim ou N-Nao ");
        scanf(" %c", &resposta);
        resposta = toupper(resposta);
    }while(resposta == 'S');

    fclose(ftpr); //fechamento do ponteiro, poderia utilizar o rewind da linha 87

    ftpr = fopen("ex6", "rb+");//abertura do arquivo, para escrita em binário
    if(ftpr == NULL){
        printf("Erro ao abrir o arquivo\n");
    }

    fflush(stdin);
    printf("\nQual o nome da cidade a ser pesquisada? ");
    gets(pesquisa);//cidade a ser pesquisada
    fflush(stdin);
    for(i=0; i< pesquisa[i] != '\0'; i++){//conversão para maiusculo
        pesquisa[i] = toupper(pesquisa[i]);
    }

    //Pesquisa pelo nome da cidade no arquivo
    while(fread(&cidade,sizeof(cidade),1,ftpr)){ //leitura do arquivo
        if(strcmp(pesquisa,cidade.nomeCidade)== 0){ //Se a cidade informada estiver no arquivo
            achou =1;
            printf("\n Cidade ........:%s", cidade.nomeCidade);
            printf("\n Habitantes .....:%d", cidade.habitantes);
            printf("\n\n");
            break;
        }
    }
    if(achou ==0){//Se não encontrar a cidade no arquivo
        printf("\n Registro não consta na Base de Dados");
        printf("\n\n");
        system("pause");
    }

    rewind(ftpr); // Retorna ao início do arquivo para reler todas as cidades.
    //Poderiamos fechar o ponteiro e abrir novamente também, igual a linha 57

    while (fread(&cidade, sizeof(cidade), 1, ftpr)) {//leitura do arquivo
        if(cidade.habitantes == maior) { //informarndo a cidade com o maior numero de habitantes
            printf("A cidade com o maior numero de habitantes é %s, com %d habitantes\n", cidade.nomeCidade, cidade.habitantes);
            break;
        }
    }

    fclose(ftpr);
    return 0;
}
