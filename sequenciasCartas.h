#ifndef SEQUENCIAS_CARTAS_H
#define SEQUENCIAS_CARTAS_H

#include "funcoesAuxiliares.h"

CARTA* straight(CARTA sequencia[])      {
   
    //Dicionário de dados.
    int contador;
    int totalCartasConsecutivas = 0;
    int indiceInicioStraight;
    
    int valorAux1, valorAux2;
    
    /*
    Verifica as três primeiras posições da sequência. Isso porque:
    Caso o Flush não se inicie a partir de nenhuma delas, significa que não há um straight.
    Pois, como a sequência está organizada em ordem crescente, a partir da quarta posição
    É impossível haver cinco cartas sequenciadas, pois há sete cartas e a partir da quarta posição
    Restarão apenas três posições, impossibilitando o straight sequência de cinco cartas.
    */ //Descrição do for abaixo.
    for (int indice1 = 0; indice1 < 3; indice1++){
        
        contador = 0;
        
        /*
        Simplifica a sintaxe, atribuindo o valor da carta da vez à uma variável auxiliar.
        Carta essa que pode ser a primeira carta de uma sequência straight.
        */ //Descrição da atriuição abaixo.
        valorAux1 = converteValorCarta(sequencia[indice1]);
        
        /*
        Faz uma verificação em toda a sequência de cartas.
        Para saber se dentre as sete cartas há pelo menos cinco que possam formar um straight.
        */ //Descrição do for abaixo.
        for (int indice2 = indice1; indice2 < (sizeof(sequencia)/sizeof(sequencia[0])); indice2++){
            
            //Novamente simplifica a sintaxe.
            valorAux2 = converteValorCarta(sequencia[indice2]);
            
            /*
            Para encontrar um straight podemos fazer da seguinte formar, exemplificando:
            Temos uma sequência assim           {  4  ,  5  ,  6  ,  7  ,  8  , 10 , K }
            Que pode ser representada por       { 4+0 , 4+1 , 4+2 , 4+3 , 4+4 , 10 , K }
            Portanto comparamos a carta da vez com a carta inicial somada a um contador,
            Que se atualiza a cada vez que a condição é satisfeita.
            
            Caso haja uma sequência assim       {  2  ,  3  ,  3  ,  4  ,  4  ,  5  ,  6  }
            Ela poderá ser representada assim   { 2+0 , 2+1 , 2+1 , 2+2 , 2+2 , 2+3 , 2+4 }
            
            Nesse caso também há um straight, porém mesclado com cartas repetidas. Logo, em casos como esse: não há problema,
            Isso porque o contador se incrementira uma vez e na carta seguinte a soma não seria mais a mesma, evitando repetição.
            */ //Descrição da condição abaixo
            if (valorAux2 == (valorAux1 + contador))
                contador++;
            
            /*
            Funciona de uma forma que dentro do for, o programa buscará  omaior contador possível
            E o encontrado, será atribuído ao totalCartasConsecutivas, variável representante do
            Número de cartas consecutivas na sequência.
            */ //Descrição da condição abaixo
            if ((contador + 1) == 5){
                
                //Incrementa em um o contador, pois representará a quantidade de cartas.
                totalCartasConsecutivas = contador + 1;
                
                /*
                Atribui o índice da possível primeira carta da sequência a essa variável auxiliar
                Que servirá para orientar quais serão as cartas atribuídas à sequência que será retornada.
                */ //Descrição da atribuição abaixo
                indiceInicioStraight = indice1;
                
            }
            
        }
       
    }
   
    if (totalCartasConsecutivas == 5){
        
        int contadorFinal = 0;
        CARTA sequenciaStraight[totalCartasConsecutivas];
        
        for (int indice = indiceInicioStraight; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
           
            //Caso o valor da carta da vez seja imediatamente menor que o seu posterior.
            //Usa a função converteValorCarta para saber o valor da carta.
           
            if (converteValorCarta(sequencia[indice]) == (converteValorCarta(sequencia[indiceInicioStraight]) + contadorFinal)){
               
                //Atribui essa carta a sequência que será retornada.
                sequenciaStraight[contadorFinal] = sequencia[indice];
               
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
               
            }
           
        }//Caso hajam 5 ou mais cartas consecutivas, um straight, elas serão atribuídas a sequência que será retornada pela função.
        
        //Retorna a melhor Straight possível.
        return sequenciaStraight;
       
    }
   
    else return NULL;
   
} //Função que serve para saber se o jogador possui um straight em posse, e no caso o retorna.

CARTA* flush(CARTA sequencia[])         {
   
    //Dicionário de dados.
    int contadorCopas = 0;
    int contadorEspadas = 0;
    int contadorOuros = 0;
    int contadorPaus = 0;
   
    for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
       
        if (sequencia[indice].naipe == 'C') //Verifica se a carta da vez é de copas.
            contadorCopas++;
           
        if (sequencia[indice].naipe == 'E') //Verifica se a carta da vez é de espadas.
            contadorEspadas++;
           
        if (sequencia[indice].naipe == 'O') //Verifica se a carta da vez é de ouros.
            contadorOuros++;
           
        if (sequencia[indice].naipe == 'P') //Verifica se a carta da vez é de paus.
            contadorPaus++;
            
    } //Verifica se há um flush na sequência.

    /*
    Caso hajam 5 cartas ou mais do mesmo naipe temos um flush.
    Essas cartas serão atribuídas a sequência que será retornad pela função
    Abaixo estão a estrutura que será a mesma para os cinco naipes.
    */ //Descrição das estruturas abaixo.
    
    if (contadorCopas >= 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaAux[contadorCopas];
        CARTA sequenciaFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
           
            if (sequencia[indice].naipe == 'C'){
               
                //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                sequenciaAux[contadorFinal] = sequencia[indice];
               
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
               
            }
        }
        
        contadorFinal = 0;
        
        for (int indice = contadorCopas - 5; indice < contadorCopas; indice++){
            
            sequenciaFlush[contadorFinal] = sequenciaAux[indice];
            contadorFinal++;
            
        }
        
        //Retorna o endereço do vetor na qual está a sequência que satisfaz a condição de Flush, a qual nesse caso será um Flush de paus.
        return sequenciaFlush;
   
    }
   
    else if (contadorEspadas >= 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaAux[contadorEspadas];
        CARTA sequenciaFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
           
            if (sequencia[indice].naipe == 'E'){
               
                //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                sequenciaAux[contadorFinal] = sequencia[indice];
               
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
               
            }
        }
        
        contadorFinal = 0;
        
        for (int indice = contadorEspadas - 5; indice < contadorEspadas; indice++){
            
            sequenciaFlush[contadorFinal] = sequenciaAux[indice];
            contadorFinal++;
            
        }
        
        //Retorna o endereço do vetor na qual está a sequência que satisfaz a condição de Flush, a qual nesse caso será um Flush de paus.
        return sequenciaFlush;
   
    }
   
    else if (contadorOuros >= 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaAux[contadorOuros];
        CARTA sequenciaFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
           
            if (sequencia[indice].naipe == 'O'){
               
                //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                sequenciaAux[contadorFinal] = sequencia[indice];
               
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
               
            }
        }
        
        contadorFinal = 0;
        
        for (int indice = contadorOuros - 5; indice < contadorOuros; indice++){
            
            sequenciaFlush[contadorFinal] = sequenciaAux[indice];
            contadorFinal++;
            
        }
        
        //Retorna o endereço do vetor na qual está a sequência que satisfaz a condição de Flush, a qual nesse caso será um Flush de paus.
        return sequenciaFlush;
   
    }
   
    else if (contadorPaus >= 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaAux[contadorPaus];
        CARTA sequenciaFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
           
            if (sequencia[indice].naipe == 'P'){
               
                //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                sequenciaAux[contadorFinal] = sequencia[indice];
               
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
               
            }
        }
        
        contadorFinal = 0;
        
        for (int indice = contadorPaus - 5; indice < contadorPaus; indice++){
            
            sequenciaFlush[contadorFinal] = sequenciaAux[indice];
            contadorFinal++;
            
        }
        
        //Retorna o endereço do vetor na qual está a sequência que satisfaz a condição de Flush, a qual nesse caso será um Flush de paus.
        return sequenciaFlush;
   
    }
   
    //Caso nenhuma das condições seja satisfeita e a sequência não possua 5 cartas de um mesmo naipe,
    //A função retornará uma sequência sem cartas.
   
    else return NULL;
   
} //Função que serve para saber se o jogador possui um flush em posse, e no caso o retorna.

CARTA* pares(CARTA sequencia[])         {
    
    //Dicionário de dados.
    int contador;
    
    //Na sequência recebida como parâmetro, que é a junção das cartas da mesa com as cartas do mão.
    //É possível que haja no máximo 3 pares, pois são no total 7 cartas.
    //Dessa forma, em casos assim, retornaremos as duas duplas de maior valor.
    int totalPares = 0;
    bool par = false;
    
    CARTA cartasAux[2];
    
    for (int indice1 = 0; indice1 < 6; indice1++){
        
        contador = 0;
        
        for (int indice2 = 0; indice2 < (sizeof(sequencia)/sizeof(sequencia[0])); indice2++){
            
            if ((sequencia[indice1].simbolo) == (sequencia[indice2].simbolo))
                contador++;
            
        }
        
        if (contador == 2){
            
            par = true;
            
            //Incrementa em um toda vez que o contador de cartas, indicando o número de pares atual.
            totalPares++;
            
            if (totalPares == 1){
                
                //Atribui a carta que possui um par a variável auxiliar.
                //A qual orientará quais cartas serão retornadas na sequência. 
                cartasAux[0] = sequencia[indice1];
                
            }
            
            else if (totalPares == 2){
                
                cartasAux[1] = sequencia[indice1];
                
            }
            
            //Reorganiza emt ordem crescente as cartas na sequência que será retornada.
            else if (totalPares == 3){
                
                cartasAux[0] = cartasAux[1];
                cartasAux[1] = sequencia[indice1];
                
                totalPares--;
                
            }
            
            //Caso o contador seja igual a dois significa que há um par de símbolos iguais.
            //Sabendo que a sequência está ordenada, sabemos que a próxima carta dela será igual a atual.
            //Portanto, incremetamos o indice1 para que ele passe direto para a próxima carta diferente.
            indice1++;
            
        } //Se o número de cartas iguais for igual a 2 há um par.
        
    } //Verifica se há pares na sequência recebida pela funçção.
    
    if (par){
        
        int contadorFinal = 0;
        CARTA sequenciaPares[totalPares * 2];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
            
            //Caso a carta da vez da sequência seja a mesma das cartas que possui pares.
            if ((cartasAux[0].simbolo == sequencia[indice].simbolo) || (cartasAux[1].simbolo == sequencia[indice].simbolo)){
                
                //Atribui essa carta a sequência que será retornada.
                sequenciaPares[contadorFinal] = sequencia[indice];
                
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
                
            }
            
        }
        
        //Retorna a sequência com os pares.
        return sequenciaPares;
        
    } //Caso haja pelo menos um par de cartas com símbolos iguais.
    
    //Caso não haja pares na sequência a função retorna uma sequência vazia.
    else return NULL;
    
} //Função que serve para saber se o jogador possui uma ou mais pares em posse, e no caso retorna a maior.

CARTA* trinca(CARTA sequencia[])        {
    
    int contador;
    bool trinca = false;
    
    CARTA cartaAux;
    
    for (int indice1 = 0; indice1 < 5; indice1++){
        
        contador = 0;
        
        for (int indice2 = 0; indice2 < (sizeof(sequencia)/sizeof(sequencia[0])); indice2++){
            
            if ((sequencia[indice1].simbolo) == (sequencia[indice2].simbolo))
                contador++;
            
        }
        
        if (contador == 3){
            
            trinca = true;
            cartaAux = sequencia[indice1];
            indice1 += 2;
            
        }
        
    }
    
    if (trinca){
        
        int contadorFinal = 0;
        
        CARTA sequenciaTrinca[3];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++)
        
            if (cartaAux.simbolo == sequencia[indice].simbolo){
                
                sequenciaTrinca[contadorFinal] = sequencia[indice];
                contadorFinal++;
                
            }
            
        
        return sequenciaTrinca;
        
    }
    
    else return NULL;
    
} //Função que serve para saber se o jogador possui uma ou mais trincas em posse, e no caso retorna a maior.

CARTA* quadra(CARTA sequencia[])        {
    
    int contador;
    bool quadra = false;
    
    CARTA cartaAux;
    
    for (int indice1 = 0; indice1 < 4; indice1++){
        
        contador = 0;
        
        for (int indice2 = 0; indice2 < (sizeof(sequencia)/sizeof(sequencia[0])); indice2++){
            
            if ((sequencia[indice1].simbolo) == (sequencia[indice2].simbolo))
                contador++;
            
        }
        
        if (contador == 4){
            
            quadra = true;
            cartaAux = sequencia[indice1];
            break;
            
        }
        
    }
    
    if (quadra){
        
        int contadorFinal = 0;
        
        CARTA sequenciaQuadra[4];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++)
        
            if (cartaAux.simbolo == sequencia[indice].simbolo){
                
                sequenciaQuadra[contadorFinal] = sequencia[indice];
                contadorFinal++;
                
            }
            
        
        return sequenciaQuadra;
        
    }
    
    else return NULL;
    
} //Função que serve para saber se o jogador possui uma quadra em posse, e no caso a retorna.

CARTA* fullHouse(CARTA sequencia[])     {
    
    //Dicionário de dados.
    int contadorFinal = 0;
    
    CARTA *sequenciaTrinca;
    CARTA *sequenciaPar;
    CARTA sequenciaFullHouse[7];
    
    //Caso o endereço retornada pelas funções trinca e pares seja NULL.
    //O que significa que não tem nenhuma trinca ou nenhum par.
    //Impossibilitando um Full House.
    if ((trinca(sequencia)==NULL) || (pares(sequencia)==NULL))
        
        return NULL;
        
    else{
        
        //Atribui os endereços dos pares e da trinca a ponteiros locais.
        //Para que seja possível a manipulação para juntá-los em uma sequência só.
        sequenciaTrinca = trinca(sequencia);
        sequenciaPar = pares(sequencia);
        
        for (int indice = 0; indice < 2; indice++){
            
            //Verifica se há mais de um par no endereço, ao verificar o que seria a "terceira posição do vetor". 
            if ((sequenciaPar + 2) == NULL){
                
                //Atribui o par de cartas à sequência que será o Full House.
                sequenciaFullHouse[contadorFinal] = *(sequenciaPar + indice);
                
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
                
            }
            else{
                
                //Atribui o par de cartas à sequência que será o Full House.
                sequenciaFullHouse[contadorFinal] = *(sequenciaPar + (indice + 2));
                
                //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                contadorFinal++;
                
            }
            
        }//Atribui o maior par de cartas, caso exista mais de um, à sequência que será retornada.
        
        for (int indice = 0; indice < 3; indice++){
            
            //Atribui o par de cartas à sequência que será o Full House.
            sequenciaFullHouse[contadorFinal] = *(sequenciaTrinca+indice);
            
            //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
            contadorFinal++;
            
        }//Atribui a trinca à sequência que será retornada.
        
        //Reorganiza em ordem crescente as cartas do Full House.
        bubbleSortCombinacao(sequenciaFullHouse, 5);
        
        //Retorna o endereço do vetor que representa o Full House.
        return sequenciaFullHouse;
        
    }
    
} //Função que serve para saber se o jogador possui um full house, e no caso o retorna.

CARTA* straightFlush(CARTA sequencia[]) {
   
    //Caso não haja um straight ou um flush a função retorna o endereço NULL.
    if ((straight(sequencia)==NULL) || (flush(sequencia)==NULL))
        
        return NULL;
        
    else{
        
        int contadorCopas = 0;
        int contadorEspadas = 0;
        int contadorOuros = 0;
        int contadorPaus = 0;
       
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
           
            if (sequencia[indice].naipe == 'C') //Verifica se a carta da vez é de copas.
                contadorCopas++;
               
            if (sequencia[indice].naipe == 'E') //Verifica se a carta da vez é de espadas.
                contadorEspadas++;
               
            if (sequencia[indice].naipe == 'O') //Verifica se a carta da vez é de ouros.
                contadorOuros++;
               
            if (sequencia[indice].naipe == 'P') //Verifica se a carta da vez é de paus.
                contadorPaus++;
                
        } //Verifica se há um flush na sequência.
        
        if      (contadorCopas >= 5)    {
            
            int contadorFinal = 0;
            
            CARTA sequenciaAux[contadorCopas];
            
            for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
               
                if (sequencia[indice].naipe == 'C'){
                   
                    //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                    sequenciaAux[contadorFinal] = sequencia[indice];
                   
                    //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                    contadorFinal++;
                   
                }
            }
            
            CARTA *sequenciaStraightFlush;
            
            sequenciaStraightFlush = straight(sequenciaAux);
            
            return sequenciaStraightFlush;
            
        }
        
        else if (contadorEspadas >= 5)  {
            
            int contadorFinal = 0;
            
            CARTA sequenciaAux[contadorCopas];
            
            for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
               
                if (sequencia[indice].naipe == 'E'){
                   
                    //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                    sequenciaAux[contadorFinal] = sequencia[indice];
                   
                    //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                    contadorFinal++;
                   
                }
            }
            
            CARTA *sequenciaStraightFlush;
            
            sequenciaStraightFlush = straight(sequenciaAux);
            
            return sequenciaStraightFlush;
            
        }
        
        else if (contadorOuros >= 5)    {
            
            int contadorFinal = 0;
            
            CARTA sequenciaAux[contadorCopas];
            
            for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
               
                if (sequencia[indice].naipe == 'O'){
                   
                    //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                    sequenciaAux[contadorFinal] = sequencia[indice];
                   
                    //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                    contadorFinal++;
                   
                }
            }
            
            CARTA *sequenciaStraightFlush;
            
            sequenciaStraightFlush = straight(sequenciaAux);
            
            return sequenciaStraightFlush;
            
        }
        
        else if (contadorPaus >= 5)     {
            
            int contadorFinal = 0;
            
            CARTA sequenciaAux[contadorCopas];
            
            for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
               
                if (sequencia[indice].naipe == 'P'){
                   
                    //Aqui atribuimos as cartas que fazem parte do Flush a sequência que será retornada.
                    sequenciaAux[contadorFinal] = sequencia[indice];
                   
                    //Utiliza esse contador final para que a sequência que será retornada, não possua posições vazias.
                    contadorFinal++;
                   
                }
            }
            
            CARTA *sequenciaStraightFlush;
            
            sequenciaStraightFlush = straight(sequenciaAux);
            
            return sequenciaStraightFlush;
            
        }
        
        else return NULL;
        
    }
   
} //Função que serve para saber se o jogador possui um straight flush em posse, e no caso o retorna.

CARTA* royalFlush(CARTA sequencia[])    {

    int contadorCopas = 0;
    int contadorEspadas = 0;
    int contadorOuros = 0;
    int contadorPaus = 0;
    
    for(int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++){
        
        if((sequencia[indice].id == 1) || (sequencia[indice].id == 10) || (sequencia[indice].id == 11) || (sequencia[indice].id == 12) || (sequencia[indice].id == 13))
            contadorCopas++;
        
        if((sequencia[indice].id == 14) || (sequencia[indice].id == 23) || (sequencia[indice].id == 24) || (sequencia[indice].id == 25) || (sequencia[indice].id == 26))
            contadorEspadas++;
        
        if((sequencia[indice].id == 27) || (sequencia[indice].id == 36) || (sequencia[indice].id == 37) || (sequencia[indice].id == 38) || (sequencia[indice].id == 39))
            contadorOuros++;
        
        if((sequencia[indice].id == 40) || (sequencia[indice].id == 49) || (sequencia[indice].id == 50) || (sequencia[indice].id == 51) || (sequencia[indice].id == 52))
            contadorPaus++;
        
    }
    
    if (contadorCopas == 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaRoyalFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++)
        
            if((sequencia[indice].id == 1) || (sequencia[indice].id == 10) || (sequencia[indice].id == 11) || (sequencia[indice].id == 12) || (sequencia[indice].id == 13)){
                
                sequenciaRoyalFlush[contadorFinal] = sequencia[indice];
                contadorFinal++;
                
            }
        
        return sequenciaRoyalFlush;
        
    }
    
    else if (contadorEspadas == 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaRoyalFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++)
        
            if((sequencia[indice].id == 14) || (sequencia[indice].id == 23) || (sequencia[indice].id == 24) || (sequencia[indice].id == 25) || (sequencia[indice].id == 26)){
                
                sequenciaRoyalFlush[contadorFinal] = sequencia[indice];
                contadorFinal++;
                
            }
        
        return sequenciaRoyalFlush;
        
    }
    
    else if (contadorOuros == 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaRoyalFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++)
        
            if((sequencia[indice].id == 27) || (sequencia[indice].id == 36) || (sequencia[indice].id == 37) || (sequencia[indice].id == 38) || (sequencia[indice].id == 39)){
                
                sequenciaRoyalFlush[contadorFinal] = sequencia[indice];
                contadorFinal++;
                
            }
        
        return sequenciaRoyalFlush;
        
    }
    
    else if (contadorPaus == 5){
        
        int contadorFinal = 0;
        
        CARTA sequenciaRoyalFlush[5];
        
        for (int indice = 0; indice < (sizeof(sequencia)/sizeof(sequencia[0])); indice++)
        
            if((sequencia[indice].id == 40) || (sequencia[indice].id == 49) || (sequencia[indice].id == 50) || (sequencia[indice].id == 51) || (sequencia[indice].id == 52)){
                
                sequenciaRoyalFlush[contadorFinal] = sequencia[indice];
                contadorFinal++;
                
            }
        
        return sequenciaRoyalFlush;
        
        
    }
    
    else return NULL;

    
} //Função que serve para saber se o jogador possui um royal flush, e no caso o retorna.

#endif
