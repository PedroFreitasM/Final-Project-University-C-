#include "funcoesAuxiliares.h"
#include "funcoesJogadores.h"
#include "funcoesCartas.h"
#include "funcoesJogo.h"

int main(){
    
    //Dicionário de dados.
    int totalJogador;
    LISTA mesaJogadores;
    
    //Permite o uso de acentuação.
    setlocale (LC_ALL, "Portuguese"); 
    
    system ("clear");
    
    leTotalJogadores (&totalJogador); 
    
    incializaLista (&mesaJogadores); 
    
    leInfoJogadores (&mesaJogadores, totalJogador); 
    
    partida (mesaJogadores);
    
    //Encerra o programa.
    return 0; 
    
}

