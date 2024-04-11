#ifndef TIPO_CARTAS_H
#define TIPO_CARTAS_H

typedef struct {
    
    int id;
    char naipe;
    char simbolo[2];
    
}CARTA;

typedef struct ligacaoc {
    
    CARTA carta;
    struct ligacaoc *prox;
    
}ELEMENTOc;

typedef ELEMENTOc* PONTc;

typedef struct {
    
    PONTc topo;
    int tamanho;
    
}PILHA;

#endif