#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bil.h"
int main()
{
    FILE *f;
    
    f = fopen("jogadores.txt", "r");
    if(f==NULL){
        f = fopen("jogadores.txt", "w");
    fclose(f);
    }
        save(f);
    
    fclose(f);

    int opc, loop = 0;
    do
    {
        system("clear");
        printf("-The Escapist Game-\n1-jogar\n2-Ranking\n3-Creditos\n0-Sair\nescolha uma das opcoes=");
        scanf("%d", &opc);
        getchar();
        system("clear");
        switch (opc)
        {
        case 1:
            if (loop < 3)
            {
                if (registro(loop) == 0) // caso o resgistro retorne como 0 ele add um loop
                {
                    loop++;
                }
                printf("---Em construcao---\n");
            }
            else
            {
                printf("numero limite de jogador = 3\n");
            }
            break;
        case 2:
            rank(loop); // mostrara o ranking do jogo ordenado
            break;
        case 3:
            criadores();
            break;
        case 0:
            continue;
            opc = 2;
        }
        printf("voltar=");
        scanf("%d", &opc);
    } while (opc == 1);
}
