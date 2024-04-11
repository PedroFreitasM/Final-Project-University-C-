#ifndef FUNCOES_JOGADORES_H
#define FUNCOES_JOGADORES_H

#define MAX 120

#include "funcoesAuxiliares.h"

void geradorIdJogadores (char nome[], char idAux[])                             { 
    
    int aleatorio;
    
    //Função utilizada para randomizar os últimos 7 dígitos dos ID's.
    srand(time(NULL)); 
    
    for (int indice = 0; indice < 10; indice++)
        
        //Atribui as 3 primeiras letras do nome em maiúsculo ao ID.
        if (indice < 3){
            
            idAux[indice] = toupper(nome[indice]);
            
        }
        
        //Atribui 7 últimos dígitos aleatórios ao ID.
        else{
            
            //Aqui, aleatoriamente, são escolhidos os dígitos que serão atribuídos ao id.
            //Dígitos esses que variarão apenas entre letras e números.
            while ( (aleatorio = rand() % 42) >= 10 && aleatorio <= 16 ) {};
            
            //Atribui os dígitos à variável que foi passada por passagem de referência
            idAux[indice] =  aleatorio + '0';
            
        }
        
} //Gera ID's aleatórios aos jogadores.

void insereJogador (LISTA *lista, JOGADOR jogadorAux)                           {
    
    //Dicionário de dados.
    PONTj novoJogador = (ELEMENTOj *)malloc(sizeof(ELEMENTOj));
    novoJogador->jogador = jogadorAux;
    
    if (lista->inicio == NULL){ //Quando não há jogadores na lista o jogador adicionado se torna o primeiro e o último.
        
        lista->inicio = novoJogador;
        lista->fim = novoJogador;
        
    }
    else{ //Quando há jogadores na lista o jogador é adicionado depois do último.
        
        //Aponta o novo jogador como  o posterior ao último.
        lista->fim->prox = novoJogador; 
        
        //Aponta o último jogador como o anterior ao novo a ser inserido.
        novoJogador->ant = lista->fim; 
        
        //Torna o novo jogador o último da lista.
        lista->fim = novoJogador; 
        
    }
    
    novoJogador = NULL;
    free (novoJogador);
    
    //Torna a lista circular.
    lista->inicio->ant = lista->fim; //Aponta o último jogador como anterior ao primeiro.
    lista->fim->prox = lista->inicio; //Aponta o primeiro jogador como posteriro ao último.
    
    //Incrementa o tamanho da lista.
    lista->tamanho++;
    
    
} //Registra os jogadores na mesa.

void excluiJogador (LISTA *lista, char idAux[])                                 { 
    
    //Cria um ponteiro auxiliar para facilitar a administração da lista.
    PONTj pAux = lista->inicio;

    while (pAux != NULL){
        
        if (strcmp(idAux, pAux->jogador.id) == 0){
            
            if (pAux == lista->inicio){ //Exclui o primeiro jogador da lista e redireciona suas conexões.
                
                lista->inicio = pAux->prox;
                lista->inicio->ant = lista->fim;
                
            }
            else if (pAux == lista->fim){ //Exclui o último jogador da lista e redireciona suas conexões.
                
                lista->fim = pAux->ant;
                lista->fim->prox = lista->inicio;
                
            }
            else { //Exclui um jogador entre o ínicio e o fim da lista e redireciona suas conexões.
                
                pAux->ant->prox = pAux->prox;
                pAux->prox->ant = pAux->ant;
                
            }

            //Redireciona as conexões do ponteiro auxiliar para que ele possa ser apagado.
            pAux = NULL;
            free (pAux);
            
        }
        else pAux = pAux->prox;
        
    }
    
    //Decresce o tamanho da lista.
    lista->tamanho--;
    
} //Exclui o jogador da partida através do seu id.

void exibeJogadores (LISTA lista, bool condId, bool condCarta, bool condAposta) {
 
    /*
    Os parâmetros, bool condId, bool condCarta e bool condAposta.
    Servem para quando a função precisa ser utilizada mostrando,
    Apenas algumas informações dos jogadores, mostrando apenas o ID, por exemplo.
    */ //Descrição dos parâmetros além da lista de jogadores, presentes na chamada da função.
    
    //Cria um ponteiro auxiliar para facilitar a administração da lista.
    PONTj pAux = lista.inicio;
    
    if (!(condAposta)) printf("\n\nJogadores:");
    
    //Exibe as informações dos jogadores.
    for(int indice = 0; indice < lista.tamanho; indice++){ 
        
        //Informa ao jogador como o seu nome foi registrado.
        printf ("\n\n");
        printf ("Nome: %s", pAux->jogador.nome);
        
        //Informa o ID gerado aleatoriamente ao jogador.
        if (condId){
            
            printf ("\t");
            printf ("ID: %s", pAux->jogador.id);
            
        }
        
        //Informa ao jogador as cartas que ele possui na mão.
        if (condCarta){
            
            printf ("\t");
            printf ("Cartas: ");
            exibirCarta (pAux->jogador.cartasMao[0]);
            printf (" e ");
            exibirCarta (pAux->jogador.cartasMao[1]);
        
        }   
        
        //Informa ao jogador o quanto ele já apostou na partida.
        if (condAposta){
            
            printf ("\t");
            printf ("%d fichas", pAux->jogador.aposta);
            
        }
        
        //Passa para o próximo jogador.
        pAux = pAux->prox;        
        
    }
    
    //Quebra de linha.
    printf ("\n");
    
    //Aponta o ponteiro para o nada.
    pAux = NULL;
    
    //Libera o ponteiro após usá-lo.
    free (pAux);
    
} //Exibe os jogadores que estão na mesa.

#endif