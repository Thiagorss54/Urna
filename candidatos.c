#include "candidatos.h"
int vCand=0;
int a=0,b=0,c=0,d=0,e=0,i=0;

int validarEleitor(char titulo[])
{
    //os contadores sao as letras do alfabeto
    int t=0,est=0;
    a=0;
    b=0;
    char eleitor[MAX_ELEI][MAX],num[MAX_ELEI][MAX],nome[MAX_ELEI][MAX],titulosUtilizados[MAX_ELEI][MAX];

    FILE *Releitor= fopen("Eleitores.txt","r");
    FILE *Avalidar = fopen("validarEleitor.txt", "a");

    while(!feof(Releitor))
    {
        fgets(eleitor[a],MAX,Releitor);
        sscanf(eleitor[a],"%[^,],%[^,]",num[a],nome[a]);
        a++;
    }
     for(b=0;b<60;b++)
        {
            if(strcmp(titulo,titulosUtilizados[b])==0)
            {
                printf("ERROR\n\n\n");
                est = 1;

                printf("TITULO INVALIDO.\nDIGITE SEU TITULO NOVAMENTE:");
                scanf("%s",titulo);
                validarEleitor(titulo);
                break;
            }
        }
    for(b=0;b<60;b++)
        {


            if(strcmp(titulo,num[b])==0)
            {
            strcpy(titulosUtilizados[t],titulo);
            limpartela();
            printf("BEM VINDO A URNA %s\n",nome[b]);
            fprintf(Avalidar,"%s",nome[b]);
            t++;
            est=0;
            break;
            }
           else if(b==59)
            {
                limpartela();
                printf("TITULO INVALIDO.\nDIGITE SEU TITULO NOVAMENTE:");
                scanf("%s",titulo);
                validarEleitor(titulo);
            }
        }


    fclose(Releitor);
    fclose(Avalidar);
return est;
}
void preencherStructs ()
{
    //abrindo arquivos

    FILE *Rpartidos= fopen("listaPartidos.txt","r");
    FILE *Restadual= fopen("listaDeputadoEstadual.txt","r");
    FILE *Rfederal= fopen("listaDeputadoFederal.txt","r");
    FILE *Rsenador= fopen("listaSenador.txt","r");
    FILE *Rgovernador= fopen("listaGovernador.txt","r");
    FILE *Rpresidente= fopen("listaPresidente.txt","r");

    int a=0;
    char p[MAX_ELEI][MAX];

    //preenchendo struct dos partidos

    for (a=0;(!feof(Rpartidos));a++)
    {
        fgets(p[a],MAX,Rpartidos);
        sscanf(p[a],"%[^,],%[^,],%[^,]",part[a].numero,part[a].sigla,part[a].nome);
    }

    //preenchendo struct dos Deputados Estaduais

    for (a=0;(!feof(Restadual));a++)
    {
        fgets(p[a],MAX,Restadual);
        sscanf(p[a],"%[^,],%[^,]",depEstadual[a].numero,depEstadual[a].nome);
    }

    //preenchendo struct dos Deputados federal

    for (a=0;(!feof(Rfederal));a++)
    {
        fgets(p[a],MAX,Rfederal);
        sscanf(p[a],"%[^,],%[^,]",depFederal[a].numero,depFederal[a].nome);
    }

    //preenchendo struct dos senadores

    for (a=0;(!feof(Rsenador));a++)
    {
        fgets(p[a],MAX,Rsenador);
        sscanf(p[a],"%[^,],%[^,]",senador[a].numero,senador[a].nome);
    }

    //preenchendo struct dos governadores

    for (a=0;(!feof(Rgovernador));a++)
    {
        fgets(p[a],MAX,Rgovernador);
        sscanf(p[a],"%[^,],%[^,]",governador[a].numero,governador[a].nome);
    }

    //preenchendo struct dos Presidentes

    for (a=0;(!feof(Rpresidente));a++)
    {
        fgets(p[a],MAX,Rpresidente);
        sscanf(p[a],"%[^,],%[^,]",presidente[a].numero,presidente[a].nome);
    }

    //fechando arquivos abertos

    fclose(Restadual);
    fclose(Rfederal);
    fclose(Rsenador);
    fclose(Rgovernador);
    fclose(Rpresidente);
    fclose(Rpartidos);
}
void printarCandidatos(int n){
    int i=0;
    if (n==1)
    {
        printf("Deputados Estaduais: \n");
        for (i=0;i<19;i++)
            printf("%s %s\n",depEstadual[i].nome,depEstadual[i].numero);
    }
    if (n==2)
    {
        printf("\nDeputados Federais: \n");
        for (i=0;i<25;i++)
            printf("%s %s\n",depFederal[i].nome,depFederal[i].numero);
    }
    if (n==3)
    {
        printf("\nSenador: \n");
        for (i=0;i<5;i++)
            printf("%s %s\n",senador[i].nome,senador[i].numero);
    }
    if (n==4)
    {
        printf("\nGovernador: \n");
        for (i=0;i<5;i++)
            printf("%s %s\n",governador[i].nome,governador[i].numero);
    }
    if (n==5)
    {
        printf("\nPresidentes:\n ");
        for (i=0;i<5;i++)
            printf("%s %s\n",presidente[i].nome,presidente[i].numero);
    }
    if (n==6)
    {
        printf("\nPartidos\n");
        for (i=0;i<5;i++)
            printf("%s %s %s\n",part[i].numero,part[i].sigla,part[i].nome);
    }
}
void limpartela()
{
    system("cls");
}
int botoes(char voto[],int i)
{
    int tamanho,a=0;
    tamanho =strlen(voto);
    if(voto[tamanho-1]== 'n' || voto[tamanho-1]=='N')
    {
        for(a=0;a<tamanho;a++)
            voto[a]='\0';
        printf ("%s\n\n\n",voto);
        return 0;
    }
    else if(voto[tamanho-1]== 'c' || voto[tamanho-1]=='C')
    {
        voto[tamanho-1]='\0';

        return 1;//para sair do looping nas funcoes voto
    }
    else if(voto[tamanho-1]== 'b' || voto[tamanho-1]=='B')
    {
        if(i ==0)
        {
            voto[0]='b';
            for(a=1;a<tamanho;a++)
                voto[a]='0';
            if (tamanho>1)
                voto[tamanho-1]='\0';
            return 2;//para sair do looping nas funcoes voto
        }
        else
        {
            voto[tamanho-1]='\0';
            return 3;
        }
    }
    else
        return 9;
}
void votoFederal()
{
    int vBotao=0,vLeg=0,vNulo=0,estado=0;//verificadores
    char voto[6];
     printf ("Seu voto para \n\n\t\tDeputado Federal\n\n NÚMERO:   ");
    zerarVetor(voto);
    for(i=0;i<5;i++)
    {
        voto[i]=getch();
        if ((voto[i] >= 'a' && voto[i] <= 'z') || (voto[i] >= 'A' && voto[i] <= 'Z'))
        if ((voto[i] != 'b' && voto[i] != 'B') && (voto[i] != 'c' && voto[i] != 'C') && (voto[i] != 'n' && voto[i] != 'N'))
            {//faz o char n receber letras alem de b,c e n
                voto[i] = '\0';
                i--;
                continue;
            }
        if ((voto[4]!='c') && (voto[4]!='n'))
            if (i==4)
            {
                i--;
                continue;
            }
        if (i==1 && voto[0] == 'b')
            if ((voto[i]!='c') && (voto[i]!='n'))
            {
                i--;
                continue;
            }
        printf("\a");
        vBotao=botoes(voto,i);
        limpartela();
        if (vBotao!=2 && vBotao!=3)
            printf ("Seu voto para \n\n\t\tDeputado Federal\n\n NÚMERO:   ");
        if(vBotao==0)
        {
            i=-1;
            vLeg=0;
            vCand=0;
        }
        else if ((vBotao==1 && i>1) || (vBotao==1 && voto[0]=='b'))
        {
            limpartela();
            break;
        }
        else if (vBotao==1 && i<=1 && voto[0]!='b')
            i--;
        else if (vBotao==2)
        {
            printf ("Seu voto para \n\n\t\tDeputado Federal\n\n VOTO EM BRANCO");
            estado=2;
        }
        else if(vBotao==3)
        {
            printf ("Seu voto para \n\n\t\tDeputado Federal\n\n Para votar em branco o campo de voto deve estar vazio \n\nNUMERO:   ");
            i--;
        }
        if (voto[0]!='b')
            printf("%s",voto);
        for(c=0;c<5;c++)
        {
            if(strcmp(voto, part[c].numero)==0)
                {
                    printf("\t\t\tVOTO DE LEGENDA...");
                    vLeg=1;
                    estado=LEGENDA;
                    break;
                }
            else if((i>=1) && (c==4) && (vLeg==0)){
                printf("\t\t\tVOTO NULO");
                estado=1;
                vNulo = NULO;
                break;
            }
        }
        if (i==3)
            for (a=0;a<25;a++)
            {
                if (voto[0]=='b')
                        break;
                if (strcmp(voto,depFederal[a].numero) == 0)
                 {
                     vCand=1;
                     printf ("\n\n   NOME:   %s",depFederal[a].nome);
                     estado=NORMAL;
                     break;
                 }
                 else if(a==24 && vNulo == NULO)
                 {
                     printf ("\n\nNúmero Errado\n");
                     continue;
                 }
                 else if (a==24)
                 {
                     printf("\n\n Candidato inexistente\n");
                 }
            }
        if(i>=1)
            for(b=0;b<5;b++)
                    {
                        if (strncmp(voto,part[b].numero,2)==0)
                        {
                                printf ("\nPARTIDO:   %s",part[b].sigla);
                            break;
                        }
                    }
        if(i>=1)
            printf("\n\n\nDigite 'c' para confirmar\nDigite 'n' para corrigir\nDigite 'b' para branco\n\n\n\n\n\n\n\n\n");
    }
    system("cls");
    if (estado==LEGENDA)
        part[b].votosLegenda += 1;
    else if (estado==NULO)
        braNul[0].nulos += 1;
    else if (estado==BRANCO)
        braNul[0].brancos += 1;
    else if (estado==NORMAL)
        depFederal[a].votosCand += 1;
    zerarVetor(voto);
}
void zerarVetor(char voto[])
{
    int tamanho =strlen(voto);
    for(e=0;e<tamanho;e++)
            voto[e]='\0';
}
void votoEstadual()
{
    int vBotao=0,vLeg=0,vNulo=0,estado=0;//verificadores
    char voto[7];
     printf ("Seu voto para \n\n\t\tDeputado Estadual\n\n NÚMERO:   ");

    for(i=0;i<6;i++)
    {
        voto[i]=getch();
        if ((voto[i] >= 'a' && voto[i] <= 'z') || (voto[i] >= 'A' && voto[i] <= 'Z'))
            if ((voto[i] != 'b' && voto[i] != 'B') && (voto[i] != 'c' && voto[i] != 'C') && (voto[i] != 'n' && voto[i] != 'N'))
                {//faz o char n receber letras alem de b,c e n
                    voto[i] = '\0';;
                    i--;
                    continue;
                }
        if ((voto[5]!='c') && (voto[5]!='n'))
            if (i==5)
            {
                i--;
                continue;
            }
        if (i==1 && voto[0] == 'b')
            if ((voto[i]!='c') && (voto[i]!='n'))
            {
                i--;
                continue;
            }
        printf("\a");
        vBotao=botoes(voto,i);
        limpartela();
        if (vBotao!=2 && vBotao!=3)
            printf ("Seu voto para \n\n\t\tDeputado Estadual\n\n NÚMERO:   ");
        if(vBotao==0)
        {
            i=-1;
            vLeg=0;
            vNulo=0;
            vCand=0;
        }
        else if ((vBotao==1 && i>1) || (vBotao==1 && voto[0]=='b'))
        {
            limpartela();
            break;
        }
        else if (vBotao==1 && i<=1 && voto[0]!='b')
            i--;
        else if (vBotao==2)
        {
            printf ("Seu voto para \n\n\t\tDeputado Estadual\n\n VOTO EM BRANCO");
            estado=2;
        }
        else if(vBotao==3)
        {
            printf ("Seu voto para \n\n\t\tDeputado Estadual\n\n Para votar em branco o campo de voto deve estar vazio \n\nNUMERO:   ");
            i--;
        }
        if (voto[0]!='b')
            printf("%s",voto);
        for(c=0;c<5;c++)
        {
            if(strcmp(voto, part[c].numero)==0)
                {
                    printf("\t\t\tVOTO DE LEGENDA...");
                    vLeg=1;
                    estado=LEGENDA;
                    break;
                }
            else if((i>=1) && (c==4) && (vLeg==0)){
                printf("\t\t\tVOTO NULO");
                estado=1;
                vNulo = NULO;
                break;
            }
        }
        if (i==4)
            for (a=0;a<19;a++)
            {
            if (voto[0]=='b')
                    break;
            if (strcmp(voto,depEstadual[a].numero) == 0)
             {
                 vCand=1;
                 printf ("\n\n   NOME:   %s",depEstadual[a].nome);
                 estado=NORMAL;
                 break;
             }
             else if(a==18 && vNulo == NULO)
             {
                 printf ("\n\nNúmero Errado\n");
                 continue;
             }
             else if (a==18)
             {
                 printf("\n\n Candidato inexistente\n");
             }
        }
        if(i>=1)
            for(b=0;b<6;b++)
                    {
                        if (strncmp(voto,part[b].numero,2)==0)
                        {
                                printf ("\nPARTIDO:   %s",part[b].sigla);
                            break;
                        }
                    }
        if(i>=1)
            printf("\n\n\nDigite 'c' para confirmar\nDigite 'n' para corrigir\nDigite 'b' para branco\n\n\n\n\n\n\n\n\n");
    }
    system("cls");
    if (estado==LEGENDA)
        part[b].votosLegenda += 1;
    else if (estado==NULO)
        braNul[0].nulos += 1;
    else if (estado==BRANCO)
        braNul[0].brancos += 1;
    else if (estado==NORMAL)
        depEstadual[a].votosCand += 1;
    //printf ("%d %d %d %d",part[b].votosLegenda,braNul[0].nulos,braNul[0].brancos,depEstadual[a].votosCand);
    zerarVetor(voto);
}
void votoSenador()
{
    int vBotao=0,vLeg=0,vNulo=0,estado=0;//verificadores
    char voto[4];
     printf ("Seu voto para \n\n\t\tSenador\n\n NÚMERO:   ");

    for(i=0;i<3;i++)
    {
        voto[i]=getch();
        if ((voto[i] >= 'a' && voto[i] <= 'z') || (voto[i] >= 'A' && voto[i] <= 'Z'))
            if ((voto[i] != 'b' && voto[i] != 'B') && (voto[i] != 'c' && voto[i] != 'C') && (voto[i] != 'n' && voto[i] != 'N'))
                {//faz o char n receber letras alem de b,c e n
                    voto[i] = '\0';
                    i--;
                    continue;
                }
        if ((voto[2]!='c') && (voto[2]!='n'))
            if (i==2)
            {
                i--;
                continue;
            }
        if (i==1 && voto[0] == 'b')
            if ((voto[i]!='c') && (voto[i]!='n'))
            {
                i--;
                continue;
            }
        printf("\a");
        vBotao=botoes(voto,i);
        limpartela();
        if (vBotao!=2 && vBotao!=3)
            printf ("Seu voto para \n\n\t\tSenador\n\n NÚMERO:   ");
        if(vBotao==0)
        {
            i=-1;
            vLeg=0;
            vNulo=0;
            vCand=0;
        }
        else if ((vBotao==1 && i>1) || (vBotao==1 && voto[0]=='b'))
        {
            limpartela();
            break;
        }
        else if (vBotao==1 && i<=1 && voto[0]!='b')
            i--;
        else if (vBotao==2)
        {
            printf ("Seu voto para \n\n\t\tSenador\n\n VOTO EM BRANCO");
            estado=2;
        }
        else if(vBotao==3)
        {
            printf ("Seu voto para \n\n\t\tSenador\n\n Para votar em branco o campo de voto deve estar vazio \n\nNUMERO:   ");
            i--;
        }
        if (voto[0]!='b')
            printf("%s",voto);
        for(c=0;c<5;c++)
        {
                if(strcmp(voto, part[c].numero)==0)
                {
                    vLeg=1;
                    estado=LEGENDA;
                    break;
                }
            else if((i>=1) && (c==4) && (vLeg==0)){
                printf("\t\t\tVOTO NULO");
                estado=1;
                vNulo = NULO;
                break;
            }
        }
        if (i==1)
            for (a=0;a<5;a++)
            {
            if (voto[0]=='b')
                    break;
            if (strcmp(voto,senador[a].numero) == 0)
             {
                 vCand=1;
                 printf ("\n\n   NOME:   %s",senador[a].nome);
                 estado=NORMAL;
                 break;
             }
             else if(a==4 && vNulo == NULO)
             {
                 printf ("\n\nNúmero Errado\n");
                 continue;
             }
             else if (a==4)
             {
                 printf("\n\n Candidato inexistente\n");
             }
        }
        if(i>=1)
            for(b=0;b<6;b++)
                    {
                        if (strncmp(voto,part[b].numero,2)==0)
                        {
                                printf ("\nPARTIDO:   %s",part[b].sigla);
                            break;
                        }
                    }
        if(i>=1)
            printf("\n\n\nDigite 'c' para confirmar\nDigite 'n' para corrigir\nDigite 'b' para branco\n\n\n\n\n\n\n\n\n");
    }
    system("cls");
    if (estado==LEGENDA)
        part[b].votosLegenda += 1;
    else if (estado==NULO)
        braNul[0].nulos += 1;
    else if (estado==BRANCO)
        braNul[0].brancos += 1;
    else if (estado==NORMAL)
        senador[a].votosCand += 1;
    //printf ("%d %d %d %d",part[b].votosLegenda,braNul[0].nulos,braNul[0].brancos,depEstadual[a].votosCand);
    zerarVetor(voto);
}
void votoGovernador ()
{
 int vBotao=0,vLeg=0,vNulo=0,estado=0;//verificadores
    char voto[4];
     printf ("Seu voto para \n\n\t\tGovernador\n\n NÚMERO:   ");

    for(i=0;i<3;i++)
    {
        voto[i]=getch();
        if ((voto[i] >= 'a' && voto[i] <= 'z') || (voto[i] >= 'A' && voto[i] <= 'Z'))
            if ((voto[i] != 'b' && voto[i] != 'B') && (voto[i] != 'c' && voto[i] != 'C') && (voto[i] != 'n' && voto[i] != 'N'))
                {//faz o char n receber letras alem de b,c e n
                    voto[i] = '\0';
                    i--;
                    continue;
                }
        if ((voto[2]!='c') && (voto[2]!='n'))
            if (i==2)
            {
                i--;
                continue;
            }
        if (i==1 && voto[0] == 'b')
            if ((voto[i]!='c') && (voto[i]!='n'))
            {
                i--;
                continue;
            }
        printf("\a");
        vBotao=botoes(voto,i);
        limpartela();
        if (vBotao!=2 && vBotao!=3)
            printf ("Seu voto para \n\n\t\tGovernador\n\n NÚMERO:   ");
        if(vBotao==0)
        {
            i=-1;
            vLeg=0;
            vNulo=0;
            vCand=0;
        }
        else if ((vBotao==1 && i>1) || (vBotao==1 && voto[0]=='b'))
        {
            limpartela();
            break;
        }
        else if (vBotao==1 && i<=1 && voto[0]!='b')
            i--;
        else if (vBotao==2)
        {
            printf ("Seu voto para \n\n\t\tGovernador\n\n VOTO EM BRANCO");
            estado=2;
        }
        else if(vBotao==3)
        {
            printf ("Seu voto para \n\n\t\tGovernador\n\n Para votar em branco o campo de voto deve estar vazio \n\nNUMERO:   ");
            i--;
        }
        if (voto[0]!='b')
            printf("%s",voto);
        for(c=0;c<5;c++)
        {
                if(strcmp(voto, part[c].numero)==0)
                {
                    vLeg=1;
                    estado=LEGENDA;
                    break;
                }
            else if((i>=1) && (c==4) && (vLeg==0)){
                printf("\t\t\tVOTO NULO");
                estado=1;
                vNulo = NULO;
                break;
            }
        }
        if (i==1)
            for (a=0;a<5;a++)
            {
            if (voto[0]=='b')
                    break;
            if (strcmp(voto,governador[a].numero) == 0)
             {
                 vCand=1;
                 printf ("\n\n   NOME:   %s",governador[a].nome);
                 estado=NORMAL;
                 break;
             }
             else if(a==4 && vNulo == NULO)
             {
                 printf ("\n\nNúmero Errado\n");
                 continue;
             }
             else if (a==4)
             {
                 printf("\n\n Candidato inexistente\n");
             }
        }
        if(i>=1)
            for(b=0;b<6;b++)
                    {
                        if (strncmp(voto,part[b].numero,2)==0)
                        {
                                printf ("\nPARTIDO:   %s",part[b].sigla);
                            break;
                        }
                    }
        if(i>=1)
            printf("\n\n\nDigite 'c' para confirmar\nDigite 'n' para corrigir\nDigite 'b' para branco\n\n\n\n\n\n\n\n\n");
    }
    system("cls");
    if (estado==LEGENDA)
        part[b].votosLegenda += 1;
    else if (estado==NULO)
        braNul[0].nulos += 1;
    else if (estado==BRANCO)
        braNul[0].brancos += 1;
    else if (estado==NORMAL)
        governador[a].votosCand += 1;
    zerarVetor(voto);
}
void votoPresidente()
{
    int vBotao=0,vLeg=0,vNulo=0,estado=0;//verificadores
    char voto[4];
     printf ("Seu voto para \n\n\t\tPresidente\n\n NÚMERO:   ");

    for(i=0;i<3;i++)
    {
        voto[i]=getch();
        if ((voto[i] >= 'a' && voto[i] <= 'z') || (voto[i] >= 'A' && voto[i] <= 'Z'))
            if ((voto[i] != 'b' && voto[i] != 'B') && (voto[i] != 'c' && voto[i] != 'C') && (voto[i] != 'n' && voto[i] != 'N'))
                {//faz o char n receber letras alem de b,c e n
                    voto[i] = '\0';
                    i--;
                    continue;
                }
        if ((voto[2]!='c') && (voto[2]!='n'))
            if (i==2)
            {
                i--;
                continue;
            }
        if (i==1 && voto[0] == 'b')
            if ((voto[i]!='c') && (voto[i]!='n'))
            {
                i--;
                continue;
            }
        printf("\a");
        vBotao=botoes(voto,i);
        limpartela();
        if (vBotao!=2 && vBotao!=3)
            printf ("Seu voto para \n\n\t\tPresidente\n\n NÚMERO:   ");
        if(vBotao==0)
        {
            i=-1;
            vLeg=0;
            vNulo=0;
            vCand=0;
        }
        else if ((vBotao==1 && i>1) || (vBotao==1 && voto[0]=='b'))
        {
            limpartela();
            break;
        }
        else if (vBotao==1 && i<=1 && voto[0]!='b')
            i--;
        else if (vBotao==2)
        {
            printf ("Seu voto para \n\n\t\tPresidente\n\n VOTO EM BRANCO");
            estado=2;
        }
        else if(vBotao==3)
        {
            printf ("Seu voto para \n\n\t\tPresidente\n\n Para votar em branco o campo de voto deve estar vazio \n\nNUMERO:   ");
            i--;
        }
        if (voto[0]!='b')
            printf("%s",voto);
        for(c=0;c<5;c++)
        {
                if(strcmp(voto, part[c].numero)==0)
                {
                    vLeg=1;
                    estado=LEGENDA;
                    break;
                }
            else if((i>=1) && (c==4) && (vLeg==0)){
                printf("\t\t\tVOTO NULO");
                estado=1;
                vNulo = NULO;
                break;
            }
        }
        if (i==1)
            for (a=0;a<5;a++)
            {
            if (voto[0]=='b')
                    break;
            if (strcmp(voto,presidente[a].numero) == 0)
             {
                 vCand=1;
                 printf ("\n\n   NOME:   %s",presidente[a].nome);
                 estado=NORMAL;
                 break;
             }
             else if(a==4 && vNulo == NULO)
             {
                 printf ("\n\nNúmero Errado\n");
                 continue;
             }
             else if (a==4)
             {
                 printf("\n\n Candidato inexistente\n");
             }
        }
        if(i>=1)
            for(b=0;b<6;b++)
                    {
                        if (strncmp(voto,part[b].numero,2)==0)
                        {
                                printf ("\n\nPARTIDO:   %s",part[b].sigla);
                            break;
                        }
                    }
        if(i>=1)
            printf("\n\n\nDigite 'c' para confirmar\nDigite 'n' para corrigir\nDigite 'b' para branco\n\n\n\n\n\n\n\n\n");
    }
    system("cls");
    if (estado==LEGENDA)
        part[b].votosLegenda += 1;
    else if (estado==NULO)
        braNul[0].nulos += 1;
    else if (estado==BRANCO)
        braNul[0].brancos += 1;
    else if (estado==NORMAL)
        presidente[a].votosCand += 1;
    zerarVetor(voto);
}
int vencedorFederal()
{
    int venc=0;
    for (a=0;a<25;a++)
        if (a==0)
            venc = a;
        else if (depFederal[a].votosCand>depFederal[venc].votosCand)
            venc = a;
    return venc;
}int vencedorEstadual()
{
    int venc=0;
    for (a=0;a<19;a++)
        if (a==0)
            venc = a;
        else if (depEstadual[a].votosCand>depEstadual[venc].votosCand)
            venc = a;
    return venc;
}int vencedorSenador()
{
    int venc=0;
    for (a=0;a<5;a++)
        if (a==0)
            venc = a;
        else if (senador[a].votosCand>senador[venc].votosCand)
            venc = a;
    return venc;
}int vencedorGovernador()
{
    int venc=0;
    for (a=0;a<5;a++)
        if (a==0)
            venc = a;
        else if (governador[a].votosCand>governador[venc].votosCand)
            venc = a;
    return venc;
}int vencedorPresidente()
{
    int venc=0;
    for (a=0;a<5;a++)
        if (a==0)
            venc = a;
        else if (presidente[a].votosCand>presidente[venc].votosCand)
            venc = a;
    return venc;
}
