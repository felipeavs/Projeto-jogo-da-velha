#include "JogoDaVelha.h"
#include <iostream>

int main(){
    
    setlocale(LC_ALL, "Portuguese");

    cout<< "**********!!!BEM VINDO AO JOGO DA VELHA!!!**********"<<endl;
    imprimeRankingArquivo();
    iniciarJogo();
    imprimeRankingArquivo();
    cout<< "\n\n**********!!!ATÉ LOGO!!!**********\n\n";

   return 0;
}
