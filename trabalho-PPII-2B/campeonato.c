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

void zerar(int *totVitorias, int *totDerrotas, int *totEmpates, float *somaPontos, int *qntExcelente, int *qntBoa, int *qntRegular, int *qntRuim, int *qntEmpatadosMaior, int *qntEmpatadosMenor){

    totVitorias = 0;
    totDerrotas = 0;
    totEmpates = 0;
    somaPontos = 0;
    qntExcelente = 0;
    qntBoa = 0;
    qntRegular = 0;
    qntRuim = 0; 
    qntEmpatadosMaior = 0;
    qntEmpatadosMenor = 0;
}

void registroEquip(int equip, int partidas, int *vitorias, int *derrotas, int *empates, float *somaPontos){
    int v, d, e, c;
    int pontos = 0;

    do{
        limpa_title();
        printf("\n--- Equipe %d ---\n", equip);
        printf("Vitórias: ");
        scanf("%d", &v);
        while((c = getchar()) != '\n' && c != EOF);
        pontos += (v*3);

        printf("Derrotas: ");
        scanf("%d", &d);
        while((c = getchar()) != '\n' && c != EOF);

        printf("Empates: ");
        scanf("%d", &e);
        while((c = getchar()) != '\n' && c != EOF);
        pontos += e;
        if(v<0 || d<0 || e<0){
            printf("![ERRO]! Não são permitidos números negativos no registro.");
            getchar();
            goto exit;
        }
        if((v+d+e)!=partidas){
            printf("![ERRO]! Soma das participações em partidas incorreta.");
            getchar();
            goto exit;
        }
        printf("Pontos: %d\n", pontos);
        printf("Situação:");
        situacaoCamp(pontos);
        somaPontos += pontos;
        getchar();

        exit:
    }while(v<0 || d<0 || e<0 || (v+d+e)!=partidas);

    *vitorias = v;
    *derrotas = d;
    *empates = e;

}

void situacaoCamp(int pontos){
    if(pontos >= 15){
        printf(" Excelente campanha\n");
    }else if(pontos >= 10){
        printf(" Boa campanha\n");
    }else if(pontos >= 5){
        printf(" Campanha regular\n");
    }else{
        printf(" Campanha ruim\n");
    }
}

void atualizaEstatisticas(int equip, int v, int d, int e, int *qntExcelente, int *qntBoa, int
*qntRegular, int *qntRuim, int *maiorPontuacao, int *equipeMaior, int *qntEmpatadosMaior, int *menorPontuacao, int *equipeMenor, int *qntEmpatadosMenor){

    int pontos = (v*3) + (e*1);

    if(pontos >= 15){
        (*qntExcelente)++;
    }else if(pontos >= 10){
        (*qntBoa)++;
    }else if(pontos >= 5){
        (*qntRegular)++;
    }else{
        (*qntRuim)++;
    }

    if(pontos > *maiorPontuacao){
        *maiorPontuacao = pontos;
        *equipeMaior = equip;
        *qntEmpatadosMaior = 1;
    }else if(pontos == *maiorPontuacao){
        (*qntEmpatadosMaior)++;
    }

    if(pontos < *menorPontuacao){
        *menorPontuacao = pontos;
        *equipeMenor = equip;
        *qntEmpatadosMenor = 1;
    }else if(pontos == *menorPontuacao){
        (*qntEmpatadosMenor)++;
    }
}

void printTotais(int totV, int totD, int totE){
    printf("Total de vitórias: %d\n", totV);
    printf("Total de derrotas: %d\n", totD);
    printf("Total de empates: %d\n", totE);
}

void printQntSituacao(int qntExc, int qntBoa, int qntReg, int qntRuim){
    printf("Quantidade de campanhas excelentes: %d", qntExc);
    printf("Quantidade de campanhas boas: %d", qntBoa);
    printf("Quantidade de campanhas regulares: %d", qntReg);
    printf("Quantidade de campanhas ruins: %d", qntRuim);
}


void regulamento(int equips, int partidas){
    limpa_title();
    printf("==== REGULAMENTO ====\n");
    printf("Vitória: 3 pontos\n");
    printf("Empate: 1 ponto\n");
    printf("Derrota: 0 pontos\n\n");
    printf("15 ou mais pontos: Excelente campanha\n");
    printf("De 10 a 14 pontos: Boa campanha\n");
    printf("De 5 a 9 pontos: Campanha regular\n");
    printf("Menos de 5 pontos: Campanha ruim\n\n");
    printf("Equipes: de 3 a 10\n");
    printf("Partidas por equipe: de 1 a 10\n");
}

void simulaCampanha(int partidas){
    int qtdSimul, i;
    int vitorias, empates, derrotas, pontos;
    int valido;

    limpa_title();
    printf("==== SIMULAR CAMPANHA ====\n");

    qtdSimul = 0;
    while(qtdSimul < 1 || qtdSimul > 5){
        printf("=> Quantas simulações deseja realizar (1 a 5)? ");
        scanf("%d", &qtdSimul);
        if(qtdSimul < 1 || qtdSimul > 5){
            printf("![VALOR INSERIDO INVÁLIDO]!\n");
        }
    }

    for(i = 1; i <= qtdSimul; i++){
        printf("\n--- Simulação %d ---\n", i);

        valido = 0;
        while(!valido){
            printf("Vitórias: ");
            scanf("%d", &vitorias);
            printf("Empates: ");
            scanf("%d", &empates);
            printf("Derrotas: ");
            scanf("%d", &derrotas);

            if(vitorias < 0 || empates < 0 || derrotas < 0){
                printf("![VALOR INSERIDO INVÁLIDO]! Nenhum resultado pode ser negativo.\n");
            }else if(vitorias + empates + derrotas != partidas){
                printf("![VALOR INSERIDO INVÁLIDO]! A soma deve ser igual a %d partidas.\n", partidas);
            }else{
                valido = 1;
            }
        }

        pontos = vitorias * 3 + empates * 1 + derrotas * 0;

        printf("Pontuação: %d pontos\n", pontos);
        if(pontos >= 15){
            printf("Situação: Excelente campanha\n");
        }else if(pontos >= 10){
            printf("Situação: Boa campanha\n");
        }else if(pontos >= 5){
            printf("Situação: Campanha regular\n");
        }else{
            printf("Situação: Campanha ruim\n");
        }
    }
}
