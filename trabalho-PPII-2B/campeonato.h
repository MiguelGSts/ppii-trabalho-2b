#ifndef CAMPEONATO_H
#define CAMPEONATO_H

void title();

void limpaTela();

void limpa_title();

int validaEquip(int equips);

int validaPartidas(int partidas);

int menu();

int validaOp(int valOp);

void zerar(int *totVitorias, int *totDerrotas, int *totEmpates, float *somaPontos, int *qntExcelente, int *qntBoa, int *qntRegular, int *qntRuim, int *qntEmpatadosMaior, int *qntEmpatadosMenor);

void registroEquip(int equip, int partidas, int *vitorias, int *derrotas, int *empates, float *somaPontos);

void situacaoCamp(int pontos);

void atualizaEstatisticas(int equip, int v, int d, int e, int *qntExcelente, int *qntBoa, int
*qntRegular, int *qntRuim, int *maiorPontuacao, int *equipeMaior, int *qntEmpatadosMaior, int *menorPontuacao, int *equipeMenor, int *qntEmpatadosMenor);

void printTotais(int totV, int totD, int totE);

void printQntSituacao(int qntExc, int qntBoa, int qntReg, int qntRuim);

void regulamento();

void simulaCampanha(int partidas);

#endif