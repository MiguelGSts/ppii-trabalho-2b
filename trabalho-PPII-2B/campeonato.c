#include <stdio.h>
#include <stdlib.h>
#include "campeonato.h"

void title(){
    printf("===============================\n");
    printf("=== CONTROLE DE CAMPEONATOS ===\n");
    printf("===============================\n\n");
}

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpa_title(){
    limpaTela();
    title();
}

int validaEquip(int equips){
    if(equips < 3 || equips > 10){
        do{
        printf("![VALOR INSERIDO INVÁLIDO]!\n");
        printf("=> Insira novamente a quantidade de equipes participantes: ");
        scanf("%d", &equips);
        }while(equips < 3 || equips > 10);
    }
    return equips;
}

int validaPartidas(int partidas){
    if(partidas < 1 || partidas > 10){
        do{
        printf("![VALOR INSERIDO INVÁLIDO]!\n");
        printf("=> Insira novamente quantas partidas cada equipe irá jogar: ");
        scanf("%d", &partidas);
        }while(partidas < 3 || partidas > 10);
    }
    return partidas;
}

int menu(){
    int opcao;

    printf("==== MENU ====\n");
    printf("[1] Registrar resultados do campeonato\n");
    printf("[2] Mostrar resumo do campeonato\n");
    printf("[3] Mostrar regulamento\n");
    printf("[4] Simular campanha de equipe\n");
    printf("[5] Encerrar sessão\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOp(opcao);
    return opcao;
}

int validaOp(int valOp){
    if(valOp < 1 || valOp > 5){
        do{
            printf("![VALOR INSERIDO INVÁLIDO]!\n");
            printf("Escolha novamente uma opção: ");
            scanf("%d", &valOp);
        }while(valOp < 1 || valOp > 5);
    }
    return valOp;
}