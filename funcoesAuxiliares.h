#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

#include "tiposJogadores.h"
#include "tiposCartas.h"
#include "tiposJogo.h"

#include "funcoesJogadores.h"
#include "funcoesCartas.h"
#include "funcoesJogo.h"
#include "sequenciasCartas.h"
#include "avisosDefesas.h"

void leTotalJogadores (int *totalJogador)                                   {
    
    do{
        
        //Lê o total de jogadores da mesa.
        printf ("Entre com um número válido de jogadores: ");
        scanf ("%d", totalJogador);
        
        //Caso o valor seja inválido ele avisará a invalidez.
        if ((*totalJogador < 2) || (*totalJogador > 8)){
            
            defesaTotalJogadores();
            
        }
    
    //E loopará até que o usuário entre com um total de jogadores válido.
    }while((*totalJogador < 2) || (*totalJogador > 8));
    
} //Lê o total de jogadores que vão participar da partida.

void leInfoJogadores (LISTA *mesaJogadores, int totalJogador)               {
    
    //Lê as informações de todos os jogadores e os insere na mesa.
    for (int indice = 0; indice < totalJogador; indice++){ 
        
        //Cria a variável jogador que será inserida na mesa posterioramente.
        JOGADOR *jogador = malloc(sizeof(JOGADOR));
        
        //Lê o nome do jogador e o atribui a variável.
        printf ("\n");
        printf ("Entre com o seu nome: ");
        scanf ("%s", jogador->nome);
        
        //Gera o ID do jogador em questão e o atribui a variável.
        geradorIdJogadores(jogador->nome, jogador->id); 
        
        //Atribui os valores de banca inicial e aposta iniciais.
        //Sendo respectivamente 1000 fichas e 0 fichas.
        jogador->banca = 1000;
        jogador->aposta = 0;
        //jogador->jogandoPartida = true;
        
        //Informa ao jogador o seu ID gerado aleatoriamente.
        printf ("Seu ID é: %s", jogador->id);
        printf ("\n");
        
        //Coloca os jogadores na mesa de jogo (Lista).
        insereJogador (mesaJogadores, *jogador); 
        
        /*
        Faz com que o próximo jogador espere um segundo dar suas informações.
        Devido ao fato que caso essas informações não podem passar no mesmo segundo.
        Por conta da função presente no gerador de ID, que usa o tempo em segundos,
        Para gerar valores aleatórios.
        */ //Descreve o uso da função a baixo.
        sleep(1);
        
    }
    
    //Quebra de linha.
    printf ("\n");
    
    //Faz com que os usuários ao fim do preenchimento de informações.
    //Aguardem 3 segundos para que eles leiam os nomes e os ID's dos jogadores.
    sleep(3);
    
} //Lê as informações dos jogadores.

void trocaCartasLugar (CARTA *posicao1, CARTA *posicao2)                    {

    CARTA aux = *posicao1;

    *posicao1 = *posicao2;
    *posicao2 = aux;

    
} //Faz com que cartas troquem de local globalmente, devido a passagem por referência.

void trocaInteirosLugar (int *posicao1, int *posicao2)                      {
    
    int aux = *posicao1;
    
  	*posicao1 = *posicao2;
   	*posicao2 = aux;
   	
} //Faz com que inteiros troquem de local globalmente, devido a passagem por referência.

void bubbleSortCombinacao(CARTA *sequenciaAux, int tam)                     {
    
    int sequenciaValores[tam];
    
    for (int indice = 0; indice < tam; indice++){
        
        sequenciaValores[indice] = converteValorCarta(sequenciaAux[indice]);
        
    } //Atribui valores inteiros às cartas simbolizadas.
    
    for (int indice1 = tam-1; indice1 > 0; indice1--){
    
        for (int indice2 = 0; indice2 < indice1; indice2++){
        
            if (sequenciaValores[indice2] > sequenciaValores[indice2+1]) {
                
                //Faz com que as cartas da sequência recebida troquem de lugar, com base em seus valores.
                trocaCartasLugar (&sequenciaAux[indice2], &sequenciaAux[indice2+1]);
                trocaInteirosLugar (&sequenciaValores[indice2], &sequenciaValores[indice2+1]);
                
            }
            
        }
        
    } //BubbleSort crescente.
    
} //Resolver sobre a parte da organização em ordem crescente.

void inicializaPilha (PILHA *pilha)                                         { 

    pilha = (PILHA *)malloc(sizeof(PILHA));
    
    pilha->topo = NULL;
    
    pilha->tamanho = 0;
    
} //Inicializa a pilha.

void incializaLista (LISTA *lista)                                          { 
    
    lista = (LISTA *)malloc(sizeof(LISTA));
    
    lista->inicio = NULL;
    
    lista->fim = NULL;
    
    lista->tamanho = 0;
    
} //Inicializa a lista.

void preencherBaralho (CARTA cartasBaralho[], PILHA *baralho)               {
    
    for (int indice = 0; indice < 52; indice++){
        
        insereCarta (baralho, cartasBaralho[indice]);
        
    }

} //Preenche o baralho com as 52 cartas, que representam as 13 dos 4 naipes.

void preencherMesa (PILHA *baralho, MESA *mesaJogo, int *viradasPraCima)    {
    
    for (int indice = 0; indice < 3; indice++){
        
        colocaCartasMesa (baralho, mesaJogo, viradasPraCima);
        
    }
    
} //Preenche a mesa com as três cartas iniciais.

#endif