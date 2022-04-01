#include "candidatos.h"


int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    int d=0,verifError=1,continuar = 1;
    preencherStructs();
    char titulo[15];
    while (continuar == 1)
    {
        limpartela();
        printf("DIGITE O TÍTULO DE ELEITOR\n");
        scanf("%s",titulo);
        verifError = validarEleitor(titulo);
        votoFederal();
        votoEstadual();
        votoSenador();
        votoGovernador();
        votoPresidente();
        printf("Aperte 1 para continuar e 2 para sair ");
        scanf("%d",&continuar);
        limpartela();
    }
        printf ("%s foi eleito deputado federal\n",depFederal[vencedorFederal()].nome);
        printf ("%s foi eleito deputado estadual\n",depEstadual[vencedorEstadual()].nome);
        printf ("%s foi eleito senador\n",senador[vencedorSenador()].nome);
        printf ("%s foi eleito governador\n",governador[vencedorGovernador()].nome);
        printf ("%s foi eleito presidente\n",presidente[vencedorPresidente()].nome);
return 0;
}
