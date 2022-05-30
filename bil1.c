#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10 // limite de cadastro
#include "bil.h"
typedef struct
{
    int pontos;
    char nome[10];
} reg_jogador;        // guardar os dados do jogador
reg_jogador reg[max]; // vetor principal usado
int findUser(char name[10], int untilPos);
void ordenacao(int l);
////////////////////////
int registro(int l)
{
    if (l >= max)
    {
        printf("-max de jogadores-\n");
        return 1;
    }
    char nomeaux[10];            // nome auxiliar
    int pontosaux, userRepeated; // ponto auxiliar e variavel para confirmar o return
    printf("nome e pontuacao\nnome=");
    fgets(nomeaux, 10, stdin); // guarda o nome no nme aux
    printf("pontos=");
    scanf("%d", &pontosaux); // guarda os pontos no
    getchar();
    system("clear");
    userRepeated = findUser(nomeaux, l);
    if (userRepeated > -1)
    {
        reg[userRepeated].pontos = pontosaux; // faz com q os pontos do registro ja existente ejao substituidos
        return 1;
    }

    // novo V
    reg_jogador novUser = {pontosaux, " "};
    strcpy(novUser.nome, nomeaux);
    reg[l] = novUser;
    return 0;
}
//////////////////////////////////////////////////////////////////
void rank(int l) // ordenacao
{
    int opc;
    ordenacao(l);
    printf("pos\tpontos\t\tnome\n");
    FILE *f; 
     f = fopen("jogadores.txt","w");
    
    for (int i = 0; i < l; i++)
    {
        printf("%d\t%d\t\t%s\n", i + 1, reg[i].pontos, reg[i].nome);
        fprintf(f,"%d\t%d\t\t%s\n", i + 1, reg[i].pontos, reg[i].nome);
    }
    fclose(f);

    printf("deseja jogar com algum save ou criar novo jogo=");
    scanf("%d",&opc);
    if(opc==1){

        // escolher o jogador 

    }else{
        registro(l);

    }




}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void criadores()
{
    printf("criadores do jogo\n-Lay's\n-Pablo\n-Hassan\n-Lucas\n");
}

int findUser(char name[10], int untilPos) // procura no vetor se ja existe um registro com o mesmo nome
{
    for (int i = 0; i < untilPos; i++)
    {
        if (strcmp(reg[i].nome, name) == 0)
        {

            return i;
        }
    }
    return -1;
}
void ordenacao(int l)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - 1; j++)
        {
            if (reg[j].pontos < reg[j + 1].pontos)
            {
                char tnome[10];
                strcpy(tnome, reg[j].nome);
                strcpy(reg[j].nome, reg[j + 1].nome);
                strcpy(reg[j + 1].nome, tnome);
                int aux = reg[j].pontos;
                reg[j].pontos = reg[j + 1].pontos;
                reg[j + 1].pontos = aux;
            }
        }
    }
}