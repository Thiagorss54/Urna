#ifndef CANDIDATOS_H_INCLUDED
#define CANDIDATOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <conio.h>


#define MAX 100
#define MAX_ELEI 60
#define MAX_CAND 64
#define LEGENDA 0
#define NULO 1
#define BRANCO 2
#define NORMAL 3



struct candidato {
    int votosCand;
    char nome[64];
    char numero[8];
};
struct partido {
    int votosTotal;
    int votosLegenda;
    char nome[64];
    char numero[3];
    char sigla[8];
};
struct eleicao {
    int brancos;
    int nulos;
};
struct partido part[8];
struct candidato depEstadual[MAX_CAND];
struct candidato depFederal[MAX_CAND];
struct candidato governador[MAX_CAND];
struct candidato senador[MAX_CAND];
struct candidato presidente[MAX_CAND];
struct eleicao braNul[1];
int validarEleitor(char []);
void preencherStructs ();
void printarCandidatos(int );
void limpartela();
int botoes(char [],int );
void votoFederal();
void votoEstadual();
void votoGovernador();
void votoSenador();
void votoPresidente();
void zerarVetor(char []);
int vencedor(int );

#endif // CANDIDATOS_H_INCLUDED
