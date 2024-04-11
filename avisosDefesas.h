#ifndef AVISOS_DEFESAS_H
#define AVISOS_DEFESAS_H

#include "funcoesAuxiliares.h"

void avisoTrocaTurnos (char nomeJogador[])                                  {
    
    char nomeJogadorAux[strlen(nomeJogador)];
    
    //Torna o nome do jogador todo maiúsculo.
    for (int indice = 0; indice < strlen(nomeJogador); indice++){
        
        nomeJogadorAux[indice] = toupper(nomeJogador[indice]);
        
    }
    
    //Limpa o terminal
    system("clear");
    
    //Quebra de linha
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n");
    
    //Centraliza o texto no terminal
    printf ("\t\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("TROCANDO DE TURNO...\n");
    
    //Imprime o nome do jogador todo em maiúsculo.
    printf ("\t\t\t\t\t\t");
    printf ("\t\t\t\t");
    printf ("O PRÓXIMO A JOGAR É O/A %s", nomeJogadorAux);
    
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n\n");

    //Dá 5 segundos para que o próximo jogador se prepare para o seu turno.
    sleep (5);
    
} //Avisa que o turno será trocador.

void avisoInicioPartida ()                                                  {
    
    //Limpa o terminal.
    system("clear");
    
    //Quebra de linha.
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n");
    
    //Centraliza o texto no terminal.
    printf ("\t\t\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("A PARTIDA\n");
    
    printf ("\t\t\t\t\t\t\t");
    printf ("\t\t\t\t  ");
    printf ("VAI COMEÇAR...");
    
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n\n");
    
    //Avisa aos jogadores o ínicio da partida.
    sleep (5);
    
} //Avisa que a partida se iniciará.

void avisoVencedor (char nomeVencedor[])                                    {
    
    system("clear");
    
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n");
    
    printf ("\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("PARABÉNS, %s!\n", nomeVencedor);
    
    printf ("\t\t\t\t\t");
    printf ("\t\t\t\t  ");
    printf ("VOCÊ É O VENCEDOR!");
    
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n\n");
    

    sleep (5);
    
} //Avisa o vencedor da partida.

void defesaAposta ()                                                        {
    
    //Limpa o terminal.
    system("clear");
    
    //Quebra de linha.
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n");
    
    //Centraliza o texto no terminal.
    printf ("\t\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("POR FAVOR! ENTRE COM UMA APOSTA\n");
    
    printf ("\t\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("MAIOR OU IGUAL A MAIOR DA MESA!");
    
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n\n");
    
    //Dá 3 segundos para que o jogador leia a mensagem.
    sleep (3);
    
    system("clear");
    
} //Defende que haja alguma aposta menor do que a maior da mesa.

void defesaTotalJogadores ()                                                {
    
    //Limpa o terminal.
    system("clear");
    
    //Quebra de linha.
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n");

    //Centraliza o texto no terminal.    
    printf ("\t\t\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("POR FAVOR! ENTRE COM\n");
    
    printf ("\t\t\t\t\t\t");
    printf ("\t\t\t\t    ");
    printf ("NO MÍNIMO 2 E NO MÁXIMO 8 JOGADORES!");
    
    printf ("\n\n\n\n\n\n\n\n");
    printf ("\n\n\n\n\n\n\n\n");
    
    //Dá 3 segundos para queo jogador o usuário leia a mensagem.
    sleep (3);
    
    system("clear");
    
} //Defende que haja um número de jogadores menor que 2 ou maior que 8.

#endif