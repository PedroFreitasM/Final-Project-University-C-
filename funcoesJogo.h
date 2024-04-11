#ifndef FUNCOES_JOGO_H
#define FUNCOES_JOGO_H

#include "funcoesAuxiliares.h"

int pontuacaoJogador(JOGADOR jogadorAnalisado){//vai dando uma pontuacao conforme o valor da sequencia
    if(royalFlush(jogadorAnalisado.cartasSequenciaAux) != NULL){
        return 21;
    }else if(straightFlush(jogadorAnalisado.cartasSequenciaAux)!= NULL){
        return 20;
    }else if(quadra(jogadorAnalisado.cartasSequenciaAux)!=NULL){
        return 19;
    }else if(fullHouse(jogadorAnalisado.cartasSequenciaAux)){
        return 18;
    }else if(flush(jogadorAnalisado.cartasSequenciaAux)!=NULL){
        return 17;
    }else if(straight(jogadorAnalisado.cartasSequenciaAux)!=NULL){
        return 16;
    }else if(trinca(jogadorAnalisado.cartasSequenciaAux)!= NULL){
        return 15;
    }else if(pares(jogadorAnalisado.cartasSequenciaAux)!=NULL){
        return 14;
    }else{
        return jogadorAnalisado.cartasSequenciaAux[0].id;
    }
}

void statusTurno (PONTj pAux, MESA mesaJogo, int viradasPraCima, LISTA mesaJogadores, int poteMesa){
    
    //Limpa o terminal.
    system ("clear");
    
    //Informa ao jogador da vez que é o turno dele.
    printf ("\n%s é o seu turno.", pAux->jogador.nome);
    
    exibirCartasMao (pAux->jogador.cartasMao);
    
    exibirCartasMesa (mesaJogo, viradasPraCima);
    
    exibirApostasMesa (mesaJogadores, poteMesa);
    
    //Informa ao jogador quanto ele ainda tem em banca.
    printf ("\nNo momento a sua banca é de: %d fichas\n\n\n", pAux->jogador.banca);
    
} //Exibe o que está acontecendo na mesa nesse turno.

void distribuiCartas (PILHA *pilha, LISTA *lista)                       {
    
    //Cria ponteiros auxiliares para facilitar a manipulação da pilha e da lista.
    PONTj pontJogadorAux = lista->inicio;
    
    //Cria uma carta auxiliar para que sirva de temporária para ser atribuída depois.
    CARTA cartaAux;
    
    //Loop que passa por todos os jogadores da mesa.
    for (int indice1 = 0; indice1 < lista->tamanho; indice1++){
        
        //Loop que serve para distribuir as duas cartas para a mão do jogador.
        for (int indice2 = 0; indice2 < 2; indice2++){
            
            //Coloca na mão do jogador a carta puxada do topo pela função.
            pontJogadorAux->jogador.cartasMao[indice2] = puxaCartas(pilha);
            
        }
        
        //Passa para distribuir para o próximo jogador.
        pontJogadorAux = pontJogadorAux->prox; 
        
    }
    
    //Aponta o ponteiro para o NULL.
    pontJogadorAux = NULL;
    
    //Libera o ponteiro depois de usá-lo.
    free (pontJogadorAux);
    
} //Distribui as cartas para as mãos dos jogadores.

void colocaCartasMesa (PILHA *pilha, MESA *mesa, int *viradasPraCima)   {
    
    //Puxa as cartas do topo do baralho e as coloca na mesa.
    mesa->cartasMesa[*viradasPraCima] = puxaCartas (pilha);
    
    //Incrementa em um o número de cartas viradas pra cima.
    *viradasPraCima += 1;
    
} //Coloca as cartas na mesa.

void exibirCartasMesa (MESA mesa, int viradasPraCima)                   {

    printf ("\n\nMesa:\n\n");

    for (int indice = 0; indice < viradasPraCima; indice++){
        
        exibirCarta (mesa.cartasMesa[indice]);
        
        printf ("\n");
        
    }
    
} //Exibe as cartas viradas pra cima da mesa.

void exibirCartasMao (CARTA cartasMao[])                                {
    
    printf ("\n\nMão:\n\n");
    
    for (int indice = 0; indice < 2; indice++){
        
        exibirCarta(cartasMao[indice]);
        
        printf ("\n");
        
    }
    
} //Exibe as cartas da mão do jogador.

void exibirApostasMesa (LISTA lista, int poteMesa)                      {
    
    printf ("\n\nApostas da mesa: ");
    
    //Usa a função exibeJogadores, com a condição de
    //Somente exibir as apostas desse jogador.
    exibeJogadores (lista, false, false, true);

    printf ("\n\nO pote é de: %d fichas\n", poteMesa);

} //Exibe as apostas da mesa.

void combinaMaoMesa (LISTA *lista, MESA *mesa)                          {
    
    PONTj pAux = lista->inicio;
    
    for (int indice = 0; indice < lista->tamanho; indice++){
        
        for (int indice = 0; indice < 7; indice++){
        
            if (indice < 5)
                pAux->jogador.cartasSequenciaAux[indice] = mesa->cartasMesa[indice];
                
            else
                pAux->jogador.cartasSequenciaAux[indice] = pAux->jogador.cartasMao[indice - 5];
        
        }
        
        bubbleSortCombinacao(pAux->jogador.cartasSequenciaAux, 7);
        
        pAux = pAux->prox;
        
    } //Atribui as combinações possíveis aos jogadores.
    
    pAux = lista->inicio;
    
    for (int indice = 0; indice < lista->tamanho; indice++){
    
        printf ("\n\nCombinação do %s:\n", pAux->jogador.nome);
    
        for (int indice = 0; indice < 7; indice++){
            
            printf ("\nID da carta: %d\t\t%s de %c", pAux->jogador.cartasSequenciaAux[indice].id, pAux->jogador.cartasSequenciaAux[indice].simbolo, pAux->jogador.cartasSequenciaAux[indice].naipe);
            
        }
     
        pAux = pAux->prox;
        
    } //Exibe as combinações.
    
    pAux = pAux->prox = NULL;
    free(pAux);
    
} //A lapidar

JOGADOR partida(LISTA mesaJogadoresPartida)                             {
    
    MESA mesaJogo;
    PILHA baralho;
    CARTA cartasBaralho[52];
    int cartasPraCima = 0;
    
    int aumentoAposta = 0;
    int apostaAux = 0;
    int poteMesa = 0;
    
    int maiorPontos = 0;
    
    char turnoAcao[MAX];
    JOGADOR partidaVencedor;
    
    inicializaBaralho (cartasBaralho, &baralho);
    
    embaralharCartas (cartasBaralho, 52);
    
    preencherBaralho (cartasBaralho, &baralho);
    
    distribuiCartas (&baralho, &mesaJogadoresPartida); 

    preencherMesa (&baralho, &mesaJogo, &cartasPraCima);
    
    PONTj pAux = mesaJogadoresPartida.inicio;
    
    avisoInicioPartida();

    for (int rodada = 0; rodada < 3; rodada++){
        
        if (mesaJogadoresPartida.tamanho == 1){
            
            avisoVencedor(pAux->jogador.nome);
            break;
            
        }
        
        for (int rodada = 0; rodada < mesaJogadoresPartida.tamanho; rodada++) {
            
            statusTurno(pAux, mesaJogo, cartasPraCima, mesaJogadoresPartida, poteMesa);
            
            printf ("Qual será sua ação: ");
            scanf ("%s", turnoAcao);
            
            turnoAcao[0] = toupper(turnoAcao[0]);
            
            //aposta, fazer isso em uma funcao colocando a mesajogadores com passagem por copia representando cada partida.
            
            if (strcmp(turnoAcao, "Apostar") == 0){
                
                do{
                    
                    printf ("\n");
                    printf ("Entre com a sua aposta: ");
                    scanf ("%d", &apostaAux);
                    
                    if (apostaAux < pAux->ant->jogador.aposta)
                        defesaAposta();
                    
                }while (apostaAux < pAux->ant->jogador.aposta);
            }
                
            if (strcmp(turnoAcao, "Cobrir") == 0){
                
                apostaAux = pAux->ant->jogador.aposta;
                
            }    
            
            if (strcmp(turnoAcao, "Sair") == 0){
                
                excluiJogador (&mesaJogadoresPartida, pAux->jogador.id);
                
            }
            
            else{
                
                aumentoAposta = apostaAux - pAux->jogador.aposta;
                poteMesa += aumentoAposta;
                
            }
            
            //passar nao rola nada feijoada codigo escrito em aula.
            
            pAux->jogador.aposta = apostaAux;
            
            pAux->jogador.banca -= aumentoAposta;
            
            pAux = pAux->prox;
            
            printf ("\n");
            
            avisoTrocaTurnos(pAux->jogador.nome);
            
        }
        
        colocaCartasMesa (&baralho, &mesaJogo, &cartasPraCima);
        
    }

    PONTj Auxilio = mesaJogadoresPartida.inicio;
    JOGADOR Vencedor;
    int maior = -1;

    for(int jogadores = 0; jogadores < mesaJogadoresPartida.tamanho; jogadores++){
        Auxilio->jogador.cartasSequenciaAux[0] = mesaJogo.cartasMesa[0];
        Auxilio->jogador.cartasSequenciaAux[1] = mesaJogo.cartasMesa[1];
        for(int i = 2; i < 7; i++){
            Auxilio->jogador.cartasSequenciaAux[i] = Auxilio->jogador.cartasSequencia[i-2];
        }
        bubbleSortCombinacao(Auxilio->jogador.cartasSequenciaAux, 7);
        if(pontuacaoJogador(Auxilio->ogador) > maior){
            Vencedor = Auxilio->jogador;
            maior = pontuacaoJogador(Auxilio->jogador)
        }
        Auxilio = Auxilio->prox;

    }
    avisoVencedor(Vencedor.nome);


    //determina quem eh o vencedor da partida
    
    //Compoe uma partida
    
    return partidaVencedor;
    

} //A lapidar

#endif

