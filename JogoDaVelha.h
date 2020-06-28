#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include<iostream>
#include<clocale>
#include<stdlib.h> //BIBLIOTECA PARA O USO DA FUNÇÃO RAND( ).
#include<time.h> //RELOGIO
#include<stdio.h> //NULL
#include<string.h> // NOMES DOS JOGADORES
#include<fstream>//ARQUIVOS
#include<iomanip>//SETW

using namespace std;


	struct jogadores{
        string player;
        int pontos[3];
    };

	int armazenaRankingArquivo(string jogador1,string jogador2, int vitoria1, int vitoria2, int empate1, int empate2, int  derrota1, int derrota2); //FUNÇÃO DO RANKING, ARMAZENA OS DADOS EM UM ARQUIVO
	void imprimeRankingArquivo();// ABRIR O ARQUIVO E IMPRIMIR O CONTEÚDO
	void iniciarJogo();//FUNÇÃO PARA INICIAR O JOGO
	void dadosDoJogo(char op); //FUNÇÃO PARA PEGAR DADOS DOS JOGADORES
	char escolheSimbolo(string jogador1);//FUNÇÃO PARA DETERMINAR O SIMBOLO DO JOGADOR 1
	int quemComeca (string jogador1, string jogador2);//FUNÇÃO QUE DETERMINA QUEM COMEÇARA O JOGO
	void oJogoDaVelha(string jogador1, string jogador2, char simbolo1, char simbolo2, int comeca, char opJogo);//FUNÇÃO DAS JOGADAS
	char escolhePosicao(char opJogo, int comeca, char jogo[9], char simbolo1, char simbolo2);//FUNÇÃO PARA DETERMINAR POSIÇÃO EM QUE O JOGADOR DESEJA JOGAR
	char jogadaDoPc(char simbolo1 ,char simbolo2, char jogo[9]);//FUNÇÃO EXCLUSIVA PARA JOGADAS DO COMPUTADOR
	void verificaGanhador(char jogo[9], char simbolo1, char simbolo2, bool& finaliza);//VERIFICA SE HÁ ALGUM GANHADOR OU SE SEU VELHA

#endif