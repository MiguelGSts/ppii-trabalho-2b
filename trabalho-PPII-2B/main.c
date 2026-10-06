#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "campeonato.h"
#ifdef _WIN32
    #include <windows.h>
#endif

int main(){
    setlocale(LC_ALL, ".UTF8");
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int op, qntEquip, qntPartidas;
    
    title();
    printf("=> Informe quantas equipes participarão do campeonato (3 a 10): ");
    scanf("%d", &qntEquip);
    qntEquip = validaEquip(qntEquip);
    printf("=> Informe quantas partidas serão disputadas por cada equipe (1 a 10): ");
    scanf("%d", &qntPartidas);
    qntPartidas = validaPartidas(qntPartidas);

    do{
    limpa_title();
    op = menu();
    }while(op != 5);

    printf("Sistema encerrado com sucesso.\n");
    printf("Obrigado por utilizar o sistema!\n");
    return 0;
}