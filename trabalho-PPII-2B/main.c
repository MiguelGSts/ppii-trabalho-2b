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
    int totVitorias, totDerrotas, totEmpates;
    float somaPontos;
    int qntExcelente = 0, qntBoa = 0, qntRegular = 0, qntRuim = 0;
    int maiorPontuacao = -1, equipeMaior, qntEmpatadosMaior = 0;
    int menorPontuacao = 9999, equipeMenor, qntEmpatadosMenor = 0;
    
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
    switch (op){
        case 1:
        zerar(&totVitorias, &totDerrotas, &totEmpates, &somaPontos, &qntExcelente, &qntBoa, &qntRegular, &qntRuim, &qntEmpatadosMaior, &qntEmpatadosMenor);

        for(int i = 1; i<=qntEquip; i++){
            int v, d, e;

            registroEquip(i, qntPartidas, &v, &d, &e, &somaPontos);

            totVitorias += v;
            totDerrotas += d;
            totEmpates += e;
            atualizaEstatisticas(i, v, d, e, &qntExcelente, &qntBoa, &qntRegular, &qntRuim, 
            &maiorPontuacao, &equipeMaior, &qntEmpatadosMaior, &menorPontuacao, &equipeMenor, &qntEmpatadosMenor);
        }
        break;

        case 2:
        if(somaPontos == 0){
            limpa_title();
            printf("\nRegistre os resultados primeiro.\n");
            getchar();
            break;
        }
        printf("Quantidade de equipes participantes: %d\n", qntEquip);
        printf("Quantidade de jogos por equipe: %d\n", qntPartidas);

        printTotais(totVitorias, totDerrotas, totEmpates);

        printf("Soma total dos pontos: %.0f\n", somaPontos);
        printf("Média dos pontos totais: %.2f\n", (somaPontos/qntEquip));

        printQntSituacao(qntExcelente, qntBoa, qntRegular, qntRuim);

        printf("Maior pontuação: %d", maiorPontuacao);
        printf("Número da equipe: %d", equipeMaior);

        printf("Menor pontuação: %d", menorPontuacao);
        printf("Número da equipe: %d", equipeMenor);

        printf("Quantidade de equipes empatadas na maior pontuação: %d", qntEmpatadosMaior);
        printf("Quantidade de equipes empatadas na menor pontuação: %d", qntEmpatadosMenor);
        getchar();
        break;

        case 3:
        regulamento();
        break;

        case 4:
        simulaCampanha(qntPartidas);
        break;

        default:
        break;
    }
    }while(op != 5);

    printf("Sistema encerrado com sucesso.\n");
    printf("Obrigado por utilizar o sistema!\n");
    return 0;
}