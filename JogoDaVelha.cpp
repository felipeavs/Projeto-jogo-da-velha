#include "JogoDaVelha.h"

//FUNÇÃO RANKING
int armazenaRankingArquivo(string jogador1,string jogador2, int vitoria1, int vitoria2, int empate1, int empate2, int  derrota1, int derrota2){

    bool aux;
    jogadores dadosDoArquivo[5], dadosDaRodada[2], trocaPosicao;


    dadosDaRodada[0].player=jogador1;
    dadosDaRodada[0].pontos[0]=vitoria1;
    dadosDaRodada[0].pontos[1]=empate1;
    dadosDaRodada[0].pontos[2]=derrota1;

    dadosDaRodada[1].player=jogador2;
    dadosDaRodada[1].pontos[0]=vitoria2;
    dadosDaRodada[1].pontos[1]=empate2;
    dadosDaRodada[1].pontos[2]=derrota2;

    for(int i=0; i<5; i++){
        dadosDoArquivo[i].player="0";
        for(int j=0; j<3; j++){                           //FOR PARA ZERAR O AS DO VETOR PARA NÃO IMPRIMIR LIXO PARA PODER SOMAR AO ARQUIVO
            dadosDoArquivo[i].pontos[j]=0;
        }
    }
    fstream file;
    file.open("velha.ini");

    if(file.fail()){
        cout<< "Erro\n";
        return 0;
    }

    for(int i=0; i<5; i++){
        file>>dadosDoArquivo[i].player;
        for(int j=0; j<3; j++){                           //RECEBE DADOS DO ARQUIVO PARA VERIFICAÇÃO
            file>>dadosDoArquivo[i].pontos[j];
        }
    }

    for(int i=0; i<2; i++){
        aux=true;
        for(int j=0; j<5; j++){
            if((dadosDoArquivo[j].player==dadosDaRodada[i].player)&&(aux)){
                for(int k=0; k<3; k++){
                    dadosDoArquivo[j].pontos[k]+=dadosDaRodada[i].pontos[k]; //RECEBE OS PONTOS DO JOGO E ACRESCENTA NA VARIAVEL PARA SALVAR NO ARQUIVO

                }
                aux=false;
            }
            else if((dadosDoArquivo[j].player=="0")&&(aux)){
                dadosDoArquivo[j].player=dadosDaRodada[i].player;
                for(int k=0; k<3; k++){
                    dadosDoArquivo[j].pontos[k]+=dadosDaRodada[i].pontos[k]; //RECEBE OS PONTOS DO JOGO E ACRESCENTA NA VARIAVEL PARA SALVAR NO ARQUIVO

                }
                aux=false;
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
	  //CRÍTERIOS DE CLASSIFICAÇÃO POR VITÓRIAS
	  if(dadosDoArquivo[i].pontos[0]<dadosDoArquivo[j].pontos[0]){
                trocaPosicao.player=dadosDoArquivo[i].player;
                for(int k=0; k<3; k++){
                        trocaPosicao.pontos[k]=dadosDoArquivo[i].pontos[k];//TROCA DE PONTOS
                }
                dadosDoArquivo[i].player=dadosDoArquivo[j].player;
                for(int k=0; k<3; k++){
                        dadosDoArquivo[i].pontos[k]=dadosDoArquivo[j].pontos[k];//TROCANDO PRIMEIRA = SEGUNDA COLOCAÇÃO
                }
                dadosDoArquivo[j].player=trocaPosicao.player;
                for(int k=0; k<3; k++){
                        dadosDoArquivo[j].pontos[k]=trocaPosicao.pontos[k];//TROCANDO SEGUNDA = PRIMEIRA COLOCAÇÃO;
                }
            }

	    //CLASSIFICAÇÃO DESEMPATE PELA PONTUAÇÃO DE EMPATES
            else if((dadosDoArquivo[i].pontos[0]==dadosDoArquivo[j].pontos[0])&&(dadosDoArquivo[i].pontos[1]<dadosDoArquivo[j].pontos[1])){
                trocaPosicao.player=dadosDoArquivo[i].player;
                for(int k=0; k<3; k++){
                        trocaPosicao.pontos[k]=dadosDoArquivo[i].pontos[k];//TROCA DE PONTOS
                }
                dadosDoArquivo[i].player=dadosDoArquivo[j].player;
                for(int k=0; k<3; k++){
                        dadosDoArquivo[i].pontos[k]=dadosDoArquivo[j].pontos[k];//TROCANDO PRIMEIRA = SEGUNDA COLOCAÇÃO
                }
                dadosDoArquivo[j].player=trocaPosicao.player;
                for(int k=0; k<3; k++){
                        dadosDoArquivo[j].pontos[k]=trocaPosicao.pontos[k];//TROCANDO SEGUNDA = PRIMEIRA COLOCAÇÃO;
                }
            }
        }
    }

    file.close();
    file.open("velha.ini", ios::out);

    for(int i=0; i<5; i++){
            file<<dadosDoArquivo[i].player<<endl;
            for(int j=0; j<3; j++){
                file<<dadosDoArquivo[i].pontos[j]<<endl;
            }
            cout<<endl;
    }
    file.close();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNÇÃO RANKING
void imprimeRankingArquivo(){

    jogadores dadosDoArquivo[5];

    for(int i=0; i<5; i++){
        dadosDoArquivo[i].player="0";
        for(int j=0; j<3; j++){                           //FOR PARA ZERAR O AS DO VETOR PARA NÃO IMPRIMIR LIXO PARA PODER SOMAR AO ARQUIVO
            dadosDoArquivo[i].pontos[j]=0;
        }
    }

    fstream file;

    //CASO NÃO HOUVER ARQUIVO, O PROGRAMA CRIA
    file.open("velha.ini");
    if(file.fail()){
        file.open("velha.ini",ios::out);
    }

    //PEGAR DADOS DO ARQUIVO
    for(int i=0; i<5; i++){
        file>>dadosDoArquivo[i].player;
        for(int j=0; j<3; j++){
                file>>dadosDoArquivo[i].pontos[j];
            }
        }

    //IMPRESSÃO DO RANKING
    cout<<endl<< "..::Ranking::.."<<endl;
    cout<<"Nome"<<setw(18)<<right<<"Vitórias"<<setw(15)<<"Empates"<<setw(15)<<"Derrotas"<<endl;
    cout<<"1."<<setw(15)<<left<<dadosDoArquivo[0].player<<setw(15)<<dadosDoArquivo[0].pontos[0]<<setw(15)<<dadosDoArquivo[0].pontos[1]<<setw(15)<<dadosDoArquivo[0].pontos[2]<<endl;
    cout<<"2."<<setw(15)<<left<<dadosDoArquivo[1].player<<setw(15)<<dadosDoArquivo[1].pontos[0]<<setw(15)<<dadosDoArquivo[1].pontos[1]<<setw(15)<<dadosDoArquivo[1].pontos[2]<<endl;
    cout<<"3."<<setw(15)<<left<<dadosDoArquivo[2].player<<setw(15)<<dadosDoArquivo[2].pontos[0]<<setw(15)<<dadosDoArquivo[2].pontos[1]<<setw(15)<<dadosDoArquivo[2].pontos[2]<<endl;
    cout<<"4."<<setw(15)<<left<<dadosDoArquivo[3].player<<setw(15)<<dadosDoArquivo[3].pontos[0]<<setw(15)<<dadosDoArquivo[3].pontos[1]<<setw(15)<<dadosDoArquivo[3].pontos[2]<<endl;
    cout<<"5."<<setw(15)<<left<<dadosDoArquivo[4].player<<setw(15)<<dadosDoArquivo[4].pontos[0]<<setw(15)<<dadosDoArquivo[4].pontos[1]<<setw(15)<<dadosDoArquivo[4].pontos[2]<<endl;

    file.close();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNÇÃO INICIAR JOGO
void iniciarJogo(){

    char opJogo;
    char sn='s';//determina se o jogador que jogar novamente

    cout<< "\nSELECIONE O MODO DE JOGO. ";
    cout<< "\n[C] Jogar contra o Computador (Jogador 2)";
    cout<< "\n[P] Jogar contra outra pessoa (Jogador 1 e Jogador 2)";
    do{
        cout<< "\nEscolha: ";
        cin>>opJogo;


        if((opJogo!='C')&&(opJogo!='c')&&(opJogo!='P')&&(opJogo!='p'))
            cout<< "OPÇÃO INVÁDIDA";

    }while((opJogo != 'C') && (opJogo != 'c') && (opJogo != 'P') && (opJogo != 'p'));

        dadosDoJogo(opJogo);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
void dadosDoJogo(char opJogo){

    char simbolo1, simbolo2;
    string jogador1, jogador2;
    int comeca;
    char sn='s';

    cout<< "\nDigite o nome do jogador 1: ";
    cin>> jogador1;


    if((opJogo=='c')||(opJogo=='C')){
        jogador2="Computador";

    }
    else{
        cout<< "\nDigite o nome do jogador 2: ";
	cin>> jogador2;

    }

    simbolo1=escolheSimbolo(jogador1);

    if(simbolo1=='X')
        simbolo2='O';
    else if(simbolo1=='O')
        simbolo2='X';

    cout<< endl << jogador1 << ": " << simbolo1;
    cout<< endl << jogador2 << ": " << simbolo2;

    while((sn=='s')||(sn=='S')){

        comeca=quemComeca(jogador1, jogador2);
        oJogoDaVelha(jogador1, jogador2, simbolo1, simbolo2, comeca, opJogo);

        cout<< "\nDeseja jogar novamente?";
        cout<< "\n[S] SIM";
        cout<< "\n[N] NÃO";
        do{
            cout<< "\nEscolha: ";
            cin>> sn;


            if((sn!='s')&&(sn!='S')&&(sn!='n')&&(sn!='N'))
                cout<< "\nOPÇÃO INVALIDA";
            }while((sn!='s')&&(sn!='S')&&(sn!='n')&&(sn!='N'));
        }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
char escolheSimbolo(string jogador1){

    char simbolo1;

    do{
        cout<< jogador1<< ", escolha o seu símbolo (O ou X): ";
        cin>>simbolo1;


        if((simbolo1=='X')||(simbolo1=='x')){
            return simbolo1='X';
        }
        else if((simbolo1=='O')||(simbolo1=='o')){
            return simbolo1='O';
        }
        else{
            cout<<"OPÇÃO INVÁLIDA";
        }
    }while((simbolo1!='X')&&(simbolo1!='x')&&(simbolo1!='O')&&(simbolo1!='o'));
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
int quemComeca (string jogador1, string jogador2){

    char comeca;


    do{
        cout<< "\n\nSELECIONE UMA DAS OPÇÕES ABAIXO ";
        cout<< "\n[1] " << jogador1 << " começa o jogo";
        cout<< "\n[2] " << jogador2 << " começa o jogo";
        cout<< "\n[3] Para mostrar o ranking.";
        cout<< "\nEscolha:";
        cin>>comeca;


        if(comeca=='3'){
            imprimeRankingArquivo();
        }
        else if((comeca!='1')&&(comeca!='2')&&(comeca!='3')){
            cout<< "OPÇÃO INVÁLIDA";
        }
    }while((comeca!='1')&&(comeca!='2'));

    if(comeca=='1')
        return 1;
    else
        return 2;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void oJogoDaVelha(string jogador1, string jogador2, char simbolo1, char simbolo2, int comeca, char opJogo){

    char jogo[9]= {'1','2','3','4','5','6','7','8','9'};
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
    char posicao;
    int ganhador1, ganhador2, velha;
    int jogada=0;
    bool finaliza=false;
    int vitoria1=0, vitoria2=0, empate1=0, empate2=0, derrota1=0, derrota2=0;

    jogada=comeca-1;

    cout<<"\n__________________________________________________"<<endl;
    cout<<"\nEsboço"<<endl;
    cout<<"\n\t\t "<<jogo[0]<<" | "<<jogo[1]<<" | "<<jogo[2]<<" "<<endl;
    cout<<"\t\t---+---+---"<<endl;
    cout<<"\t\t "<<jogo[3]<<" | "<<jogo[4]<<" | "<<jogo[5]<<" "<<endl;
    cout<<"\t\t---+---+---"<<endl;
    cout<<"\t\t "<<jogo[6]<<" | "<<jogo[7]<<" | "<<jogo[8]<<" "<<endl;

    while((finaliza!=true)&&(a+b+c+d+e+f+g+h+i!=9)){

        bool r=false;

        if((opJogo=='C')||(opJogo=='c')){
            cout<<"\n__________________________________________________"<<endl;
            if(comeca%2==0){
                cout<< "\nJogada do computador: ";
            }else{
                cout<< "\n" <<jogador1<< ", Digite a posição em que deseja jogar: ";
            }
        }
        else if((opJogo=='P')||(opJogo=='p')){

            cout<<"\n__________________________________________________"<<endl;
            if(comeca%2==0){
                cout<< "\n" <<jogador2<< ", Digite a posição em que deseja jogar: ";
            }
            else{
                cout<< "\n" <<jogador1<< ", Digite a posição em que deseja jogar: ";
            }
        }
        while(r!=true){

            posicao=escolhePosicao(opJogo, comeca, jogo, simbolo1, simbolo2); //FUNÇÃO PARA DEFINIR A POSIÇÃO DA JOGADA EM AMBAS OPÇÕES DE JOGO

            if((posicao=='1')&&(a==0)){
                if(comeca%2==0){
                    jogo[0]=simbolo2;
                }else{
                    jogo[0]=simbolo1;
                }
                r=true;
                a++;
            }
            else if((posicao=='2')&&(b==0)){
                if(comeca%2==0){
                    jogo[1]=simbolo2;
                }else{
                    jogo[1]=simbolo1;
                }
                r=true;
                b++;
            }

            else if((posicao=='3')&&(c==0)){
                if(comeca%2==0){
                    jogo[2]=simbolo2;
                }else{
                    jogo[2]=simbolo1;
                }
                r=true;
                c++;
            }
            else if((posicao=='4')&&(d==0)){
                if(comeca%2==0){
                    jogo[3]=simbolo2;
                }else{
                    jogo[3]=simbolo1;
                }
                r=true;
                d++;
            }
            else if((posicao=='5')&&(e==0)){
                if(comeca%2==0){
                    jogo[4]=simbolo2;
                }else{
                    jogo[4]=simbolo1;
                }
                r=true;
                e++;
            }
            else if((posicao=='6')&&(f==0)){
                if(comeca%2==0){
                    jogo[5]=simbolo2;
                }else{
                    jogo[5]=simbolo1;
                }
                r=true;
                f++;
            }
            else if((posicao=='7')&&(g==0)){
                if(comeca%2==0){
                    jogo[6]=simbolo2;
                }else{
                    jogo[6]=simbolo1;
                }
                r=true;
                g++;
            }
            else if((posicao=='8')&&(h==0)){
                if(comeca%2==0){
                    jogo[7]=simbolo2;
                }else{
                    jogo[7]=simbolo1;
                }
                r=true;
                h++;
            }
            else if((posicao=='9')&&(i==0)){
                if(comeca%2==0){
                    jogo[8]=simbolo2;
                }else{
                    jogo[8]=simbolo1;
                }
                r=true;
                i++;
            }
            else{
                if((opJogo=='C')||(opJogo=='c')){
                    if(comeca%2==0){

                    }
                    else{
                         if((posicao!='1')&&(posicao!='2')&&(posicao!='3')&&(posicao!='4')&&(posicao!='5')&&(posicao!='6')&&(posicao!='7')&&(posicao!='8')&&(posicao!='9')){
                            cout<< "Posição Invávida!Digite novamente: ";
                        }
                        else{
                            cout<< "Essa posição já está ocupada"<<endl;
                        }

                    }

                }else{
                    if((posicao!='1')&&(posicao!='2')&&(posicao!='3')&&(posicao!='4')&&(posicao!='5')&&(posicao!='6')&&(posicao!='7')&&(posicao!='8')&&(posicao!='9')){
                        cout<< "Posição Invávida!Digite novamente: ";
                    }
                    else{
                        cout<< "Essa posição já está ocupada"<<endl;
                    }
                }
            }
        }

        comeca++; // ASSIM PODE SE IDENTIFICAR SE É A VEZ DO JOGADOR 1 OU 2 SE O NUMERO FOR PAR OU IMPAR

        cout<<endl;
        cout<<"\n\t\t "<<jogo[0]<<" | "<<jogo[1]<<" | "<<jogo[2]<<" "<<endl;
        cout<<"\t\t---+---+---"<<endl;
        cout<<"\t\t "<<jogo[3]<<" | "<<jogo[4]<<" | "<<jogo[5]<<" "<<endl;        //IMPRIME A O JOGO APOS SUBSTITUIR A POSIÇÃO
        cout<<"\t\t---+---+---"<<endl;
        cout<<"\t\t "<<jogo[6]<<" | "<<jogo[7]<<" | "<<jogo[8]<<" "<<endl;

        jogada++; //SE A ULTIMA JOGADA FOR PAR REFERE AO JOGADO 2 E SE FOR IMPAR REFERE AO JOGADOR 1

        if(a+b+c+d+e+f+g+h+i>4){
            verificaGanhador(jogo,simbolo1,simbolo2,finaliza);
        }
    }

    if((finaliza==true)&&(a+b+c+d+e+f+g+h+i<=9)){
            if(jogada%2==0){
                cout<< "\n********Parabéns "<< jogador2 << ", você venceu!********";
                vitoria2++;
                derrota1++;
            }else{
                cout<< "\n********Parabéns "<< jogador1 << ", você venceu!********";
                vitoria1++;
                derrota2++;
            }
    }
    else{
        cout<< "\n**********!!!DEU VELHA!!!**********";
        empate1++;
        empate2++;
    }

    armazenaRankingArquivo(jogador1,jogador2,vitoria1, vitoria2, empate1, empate2, derrota1, derrota2);


}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
char escolhePosicao(char opJogo, int comeca, char jogo[9], char simbolo1, char simbolo2){

    char posicao;

    if((opJogo=='C')||(opJogo=='c')){
        if(comeca%2==0){
            posicao=jogadaDoPc(simbolo1 ,simbolo2,jogo);
            return posicao;
        }
        else{
            cin>>posicao;

            return posicao;
        }
    }
    else if((opJogo=='P')||(opJogo=='p')){

        if(comeca%2==0){
            cin>> posicao;

            return posicao;
        }
        else{
            cin>>posicao;

            return posicao;
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
char jogadaDoPc(char simbolo1 ,char simbolo2, char jogo[9]){

    srand(time(NULL));
    char posicao;
    int computador;

    //PC ATACA-----------------------------------------------------
    //PRIMEIRA LINHA
    if((jogo[0]==simbolo2)&&(jogo[1]==simbolo2)&&(jogo[2]=='3')){
        return '3';
    }
    else if((jogo[0]==simbolo2)&&(jogo[2]==simbolo2)&&(jogo[1]=='2')){
        return '2';
    }
    else if((jogo[1]==simbolo2)&&(jogo[2]==simbolo2)&&(jogo[0]=='1')){
        return '1';
    }
    //SEGUNDA LINHA
    else if((jogo[3]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[5]=='6')){
        return '6';
    }
    else if((jogo[3]==simbolo2)&&(jogo[5]==simbolo2)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo2)&&(jogo[5]==simbolo2)&&(jogo[3]=='4')){
        return '4';
    }
    //TERCEIRA LINHA
    else if((jogo[6]==simbolo2)&&(jogo[7]==simbolo2)&&(jogo[8]=='9')){
        return '9';
    }
    else if((jogo[6]==simbolo2)&&(jogo[8]==simbolo2)&&(jogo[7]=='8')){
        return '8';
    }
    else if((jogo[7]==simbolo2)&&(jogo[8]==simbolo2)&&(jogo[6]=='7')){
        return '7';
    }
    //PRIMEIRA COLUNA
    else if((jogo[0]==simbolo2)&&(jogo[3]==simbolo2)&&(jogo[6]=='7')){
        return '7';
    }
    else if((jogo[0]==simbolo2)&&(jogo[6]==simbolo2)&&(jogo[3]=='4')){
        return '4';
    }
    else if((jogo[3]==simbolo2)&&(jogo[6]==simbolo2)&&(jogo[0]=='1')){
        return '1';
    }
    //SEFUNDA COLUNA
    else if((jogo[1]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[7]=='8')){
        return '8';
    }
    else if((jogo[1]==simbolo2)&&(jogo[7]==simbolo2)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo2)&&(jogo[7]==simbolo2)&&(jogo[1]=='2')){
        return '2';
    }
    //TERCEIRA COLUNA
    else if((jogo[2]==simbolo2)&&(jogo[5]==simbolo2)&&(jogo[8]=='9')){
        return '9';
    }
    else if((jogo[2]==simbolo2)&&(jogo[8]==simbolo2)&&(jogo[5]=='6')){
        return '6';
    }
    else if((jogo[5]==simbolo2)&&(jogo[8]==simbolo2)&&(jogo[2]=='3')){
        return '3';
    }
    //DIAGONAL PRIMARIA
    else if((jogo[0]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[8]=='9')){
        return '9';
    }
    else if((jogo[0]==simbolo2)&&(jogo[8]==simbolo2)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo2)&&(jogo[8]==simbolo2)&&(jogo[0]=='1')){
        return '1';
    }
    //DIAGONAL SECUNDARIA
    else if((jogo[2]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[6]=='7')){
        return '7';
    }
    else if((jogo[2]==simbolo2)&&(jogo[6]==simbolo2)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo2)&&(jogo[6]==simbolo2)&&(jogo[2]=='3')){
        return '3';
    }

    //PC ATRAPAHA JOGADA-----------------------------------------------
    //PRIMEIRA LINHA
    if((jogo[0]==simbolo1)&&(jogo[1]==simbolo1)&&(jogo[2]=='3')){
        return '3';
    }
    else if((jogo[0]==simbolo1)&&(jogo[2]==simbolo1)&&(jogo[1]=='2')){
        return '2';
    }
    else if((jogo[1]==simbolo1)&&(jogo[2]==simbolo1)&&(jogo[0]=='1')){
        return '1';
    }
    //SEGUNDA LINHA
    else if((jogo[3]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[5]=='6')){
        return '6';
    }
    else if((jogo[3]==simbolo1)&&(jogo[5]==simbolo1)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo1)&&(jogo[5]==simbolo1)&&(jogo[3]=='4')){
        return '4';
    }
    //TERCEIRA LINHA
    else if((jogo[6]==simbolo1)&&(jogo[7]==simbolo1)&&(jogo[8]=='9')){
        return '9';
    }
    else if((jogo[6]==simbolo1)&&(jogo[8]==simbolo1)&&(jogo[7]=='8')){
        return '8';
    }
    else if((jogo[7]==simbolo1)&&(jogo[8]==simbolo1)&&(jogo[6]=='7')){
        return '7';
    }
    //PRIMEIRA COLUNA
    else if((jogo[0]==simbolo1)&&(jogo[3]==simbolo1)&&(jogo[6]=='7')){
        return '7';
    }
    else if((jogo[0]==simbolo1)&&(jogo[6]==simbolo1)&&(jogo[3]=='4')){
        return '4';
    }
    else if((jogo[3]==simbolo1)&&(jogo[6]==simbolo1)&&(jogo[0]=='1')){
        return '1';
    }
    //SEFUNDA COLUNA
    else if((jogo[1]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[7]=='8')){
        return '8';
    }
    else if((jogo[1]==simbolo1)&&(jogo[7]==simbolo1)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo1)&&(jogo[7]==simbolo1)&&(jogo[1]=='2')){
        return '2';
    }
    //TERCEIRA COLUNA
    else if((jogo[2]==simbolo1)&&(jogo[5]==simbolo1)&&(jogo[8]=='9')){
        return '9';
    }
    else if((jogo[2]==simbolo1)&&(jogo[8]==simbolo1)&&(jogo[5]=='6')){
        return '6';
    }
    else if((jogo[5]==simbolo1)&&(jogo[8]==simbolo1)&&(jogo[2]=='3')){
        return '3';
    }
    //DIAGONAL PRIMARIA
    else if((jogo[0]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[8]=='9')){
        return '9';
    }
    else if((jogo[0]==simbolo1)&&(jogo[8]==simbolo1)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo1)&&(jogo[8]==simbolo1)&&(jogo[0]=='1')){
        return '1';
    }
    //DIAGONAL SECUNDARIA
    else if((jogo[2]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[6]=='7')){
        return '7';
    }
    else if((jogo[2]==simbolo1)&&(jogo[6]==simbolo1)&&(jogo[4]=='5')){
        return '5';
    }
    else if((jogo[4]==simbolo1)&&(jogo[6]==simbolo1)&&(jogo[2]=='3')){
        return '3';
    }

    //PC JOGA ALEATORIO------------------------------------------------
    else{
        computador=rand()%9+1;
        posicao=computador+48;
        return posicao;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void verificaGanhador(char jogo[9], char simbolo1, char simbolo2, bool& finaliza){
    //VERIFICAÇÃO DAS HORIZONTAIS
    if(((jogo[0]==simbolo1)&&(jogo[1]==simbolo1)&&(jogo[2]==simbolo1))||((jogo[0]==simbolo2)&&(jogo[1]==simbolo2)&&(jogo[2]==simbolo2))){
        finaliza = true;
    }
    else if(((jogo[3]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[5]==simbolo1))||((jogo[3]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[5]==simbolo2))){
        finaliza = true;
    }
    else if(((jogo[6]==simbolo1)&&(jogo[7]==simbolo1)&&(jogo[8]==simbolo1))||((jogo[6]==simbolo2)&&(jogo[7]==simbolo2)&&(jogo[8]==simbolo2))){
         finaliza = true;
    }
    //VERIFICAÇÃO DAS VERTICAIS
    else if(((jogo[0]==simbolo1)&&(jogo[3]==simbolo1)&&(jogo[6]==simbolo1))||((jogo[0]==simbolo2)&&(jogo[3]==simbolo2)&&(jogo[6]==simbolo2))){
        finaliza = true;
    }
    else if(((jogo[1]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[7]==simbolo1))||((jogo[1]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[7]==simbolo2))){
        finaliza = true;
    }
    else if(((jogo[2]==simbolo1)&&(jogo[5]==simbolo1)&&(jogo[8]==simbolo1))||((jogo[2]==simbolo2)&&(jogo[5]==simbolo2)&&(jogo[8]==simbolo2))){
        finaliza = true;
    }
    //VERIFICAÇÃO DAS DIAGONAIS
    //PRIMARIA
    else if(((jogo[0]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[8]==simbolo1))||((jogo[0]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[8]==simbolo2))){
        finaliza = true;
    }
    //SECUNDÁRIA
    else if(((jogo[2]==simbolo1)&&(jogo[4]==simbolo1)&&(jogo[6]==simbolo1))||((jogo[2]==simbolo2)&&(jogo[4]==simbolo2)&&(jogo[6]==simbolo2))){
        finaliza = true;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

