#ifndef FUNCOES_CARTAS_H
#define FUNCOES_CARTAS_H

#define MAX 120

#include "funcoesAuxiliares.h"

void insereCarta (PILHA *pilha, CARTA cartaAux)             {
    
    //Cria um ponteiro auxiliar para facilitar a manipulação da pilha.
    PONTc novaCarta = (ELEMENTOc *)malloc(sizeof(ELEMENTOc));
    novaCarta->carta = cartaAux;
    
    //Torna a carta inserida o topo da pilha, tendo como seguinte o topo anterior.
    novaCarta->prox = pilha->topo;
    pilha->topo = novaCarta;

    novaCarta = NULL;
    free (novaCarta);
    
    //Incrementa o tamanho da pilha.
    pilha->tamanho++;
    
} //Insere as cartas no baralho.

void exibirCarta (CARTA cartaAux)                           {
    
    //Dicionário de dados.
    //Cria duas variáveis que servirão de gatilhos pra outra funções.
    int codSimbolo;
    int codNaipe;

    //Atribui códigos a cada carta com um tipo de naipe.
    if      (cartaAux.naipe == 'C') codNaipe = 1;
    else if (cartaAux.naipe == 'E') codNaipe = 2;
    else if (cartaAux.naipe == 'O') codNaipe = 3;
    else    codNaipe = 4;
    
    //Atribui códigos a cada carta com um tipo de símbolo.
    if      (cartaAux.simbolo[0] == 'A') codSimbolo = 14;
    else if (cartaAux.simbolo[0] == 'J') codSimbolo = 11;
    else if (cartaAux.simbolo[0] == 'Q') codSimbolo = 12;
    else if (cartaAux.simbolo[0] == 'K') codSimbolo = 13;
    
    //Exceto às cartas que são numerais.
    else    codSimbolo = 0;
    
    /*
    De acordo com o código atribuído ao símbolo da carta.
    No terminal será escrito como ela é escrita por extenso.
    { J = Valete , Q = Rainha , K = Rei , A = Ás }
    */ //Descrição do switch case abaixo.
    switch(codSimbolo){
        
        case 14: printf ("Ás de ");    break;
        case 11: printf ("Valete de "); break;
        case 12: printf ("Rainha de "); break;
        case 13: printf ("Rei de ");    break;
        default: printf ("%s de ", cartaAux.simbolo); break;
        
    }
    
    /*
    O mesmo vale para o código relativo aos naipes.
    Porém dessa vez a representação por extenso é assim:
    { C = Copas , E = Espadas , O = Ouros, P = Paus }
    */ //Descrição do switch case abaixo.
    switch(codNaipe){
        
        case 1: printf ("Copas");   break;
        case 2: printf ("Espadas"); break;
        case 3: printf ("Ouros");   break;
        case 4: printf ("Paus");    break;
        default: break;
        
    }
    
} //Exibe as cartas escrevendo-as por extenso, exceto numerais.

int converteValorCarta (CARTA cartaAux)                     {
    
    //Cria uma variável que servirá para indicar o valor de cada carta.
    int cartaValor;
    
    /*
    Verifica os símbolos da carta recebida e atribui um valor relacionado a esse símbolo:
    Aos que não são números temos então: { J = 11 , Q = 12 , K = 13 , A = 14 }
    */ //Descrição dos if's e else's abaixo.
    if      (cartaAux.simbolo[0] == 'A') cartaValor = 14;
    else if (cartaAux.simbolo[0] == 'J') cartaValor = 11;
    else if (cartaAux.simbolo[0] == 'Q') cartaValor = 12;
    else if (cartaAux.simbolo[0] == 'K') cartaValor = 13;
    else if ((cartaAux.simbolo[0] == '1') && (cartaAux.simbolo[1] == '0')) cartaValor = 10;
    
    //Caso o símbolo da carta seja um numeral comum é preciso fazer essa "subtração". Pois,
    //Ela funcionaria com base na tabela ASCII, transformando o número em um valor inteiro.
    else    cartaValor = cartaAux.simbolo[0] - '0';
    
    //Retorna o valor que foi atribuído a carta.
    return cartaValor;
    
} //Converte o valor das cartas.

void inicializaBaralho (CARTA cartas[], PILHA *pilhaAux)    { 
    
    int idAux = 0; //Variável auxiliar para atribuir o ID às cartas.
    
    for (int indice1 = 1; indice1 <= 4; indice1++){
        
        for (int indice2 = 1; indice2 <= 13; indice2++, idAux++){
            
            //De acordo com os valores do indice2, atribui diferentes símbolos às cartas.
            switch (indice2){ 
            
                case 1: //Atribui o Ás a carta.
                    cartas[idAux].simbolo[0] = 'A';
                    break;
                
                case 10: //Atribui o 10 a carta.
                    cartas[idAux].simbolo[0] = '1';
                    cartas[idAux].simbolo[1] = '0';
                    break;
                
                case 11: //Atribui o Valete a carta.
                    cartas[idAux].simbolo[0] = 'J';
                    break;
                
                case 12: //Atribui a Rainha a carta.
                    cartas[idAux].simbolo[0] = 'Q';
                    break;
                
                case 13: //Atribui o Rei a carta.
                    cartas[idAux].simbolo[0] = 'K';
                    break;
                
                default:
                    cartas[idAux].simbolo[0] = indice2 + '0';
                    break;
            
            } //Designa os símbolos das cartas: 1~10, A, K, Q, J.
            
            //De acordo com os valores do indice1, atribui diferentes naipes às cartas.
            switch (indice1){
                
                case 1: //Atribui Copas à carta.
                
                    cartas[idAux].naipe = 'C';
                    break;
                    
                case 2: //Atribui Espadas à carta.
                
                    cartas[idAux].naipe = 'E';
                    break;
                    
                case 3: //Atribui Ouros à carta.

                    cartas[idAux].naipe = 'O';
                    break;
                    
                case 4: //Atribui Paus à carta.
                
                    cartas[idAux].naipe = 'P';
                    break;
                
                default:
                
                    break;
                    
            } //Designa os naipes das cartas: Copas, Espadas, Ouros, Paus.
            
            cartas[idAux].id = idAux+1; //Atribui o valor do idAux ao ID da carta.
            
        }
        
    } //Criação das cartas.
    
    inicializaPilha (pilhaAux);
    
} //Monta o baralho, cria as cartas e as empilha.

void exibirBaralho (PILHA pilha)                            {
    
    //Cria um ponteiro auxiliar para facilitar a manipulação da pilha.
    PONTc pAux = pilha.topo;
    
    printf ("\n\n");
    printf ("Cartas:");
    printf ("\n\n");
    
    //Exibe as informações das cartas.
    for(int indice = 0; indice < pilha.tamanho; indice++){ 
        
        //Utiliza do ponteiro para passear pela pilha e dar as informações sobre as cartas.
        printf ("%s de %c\tID: %d\n", pAux->carta.simbolo, pAux->carta.naipe, pAux->carta.id);
        
        //Passa para a próxima carta da pilha.
        pAux = pAux->prox;
        
    }
    
    //Aponta o ponteiro auxiliar para o nada.
    pAux = NULL;
    
    //Libera o ponteiro após usá-lo.
    free (pAux);
    
} //Imprime o baralho.

void embaralharCartas (CARTA baralho[], int totalCartas)    {
    
    //Utiliza a função de aleatoriedade.
	srand (time(NULL));

    //Percorre todo o baralho trocando as cartas de lugar de forma aleatória.
	for (int indice1 = 0; indice1 < totalCartas; indice1++){
        
		//Utiliza da ferramenta da aleatoriedade.
		int indice2 = rand() % (indice1+1);
        
        //Permitindo a geração de valores aleatórios que permitem o embaralhamento das cartas.
		trocaCartasLugar(&baralho[indice1], &baralho[indice2]);
        
	}
	
} //Embaralha as cartas do baralho.

CARTA puxaCartas (PILHA *pilha)                             {
    
    //Cria um ponteiro auxiliar para facilitar a manipulação da pilha.
    PONTc pontCartaAux = pilha->topo;
    
    //Cria uma variável auxiliar que simboliza a carta que será "puxadad".
    CARTA cartaPuxada = pontCartaAux->carta;
    
    //Torna o topo da pilha a carta de baixo.
    pilha->topo = pilha->topo->prox;
    pontCartaAux->prox = NULL;

    //Retira a carta do topo do baralho.
    free (pontCartaAux);
    
    //Decresce o tamanho do baralho na mesa.
    pilha->tamanho--; 
    
    //Retorna a carta puxada do topo do baralho.
    return cartaPuxada;
    
} //Retorna a carta puxada do topo do baralho.

#endif