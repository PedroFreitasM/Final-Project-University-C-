#ifndef TIPO_JOGADORES_H
#define TIPO_JOGADORES_H

#define MAX 120

#include "tiposCartas.h"

typedef struct {
    
    char nome[MAX];
    char id[MAX];
    
    int banca;
    int aposta;
    int pontos;
    
    CARTA cartasMao[2];
    CARTA cartasSequencia[5];
    CARTA cartasSequenciaAux[7];
    
    //bool jogandoPartida;
    
}JOGADOR;

typedef struct ligacaoj {
    
    JOGADOR jogador;
    struct ligacaoj *prox;
    struct ligacaoj *ant;
    
}ELEMENTOj;

typedef ELEMENTOj* PONTj;

typedef struct {
    
    PONTj inicio;
    PONTj fim;
    int tamanho;
    
}LISTA;

#endif