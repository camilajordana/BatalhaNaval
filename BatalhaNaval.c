#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Camila Jordana Ribeiro Teixeira
 */


int tabuleiro[10][10]; // Armazena as posições das embarcações geradas aleatorimente
int tabuleiroCopia[10][10]; // Armazena as posições informadas pelo jogador
int pontos = 0; // serve para contabilizar os pontos obtidos pelo jogador
int tiros = 60; // armazena a quantidade de tiros restantes
int estado = 5; // serve para informar se a posiçao informada pelo jogador e valida 

/*
 A variavel estado pode ter 4 valores:
    * 0: quando a posição já foi bombardeada
    * 1: quando a jogada é válida 
    * 2: posição inválida (quando o usuário informa uma posição que não existe)
    * 5: valor de inicialização 
 */



void carregarEmbarcacoes (){
    int i, j, k, posicaoColuna, posicaoLinha, vertHori;
    int teste = 1;
    //Inicializa todas as posições dos tabuleiros com 0
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
            tabuleiroCopia[i][j] = 0;
        }
    }
    
    // GERANDO A POSIÇÃO DO PORTA-AVIÃO
    posicaoColuna = gerarNumeroAleatorio(0, 10); // gera um número entre 0 e 9
    if((10-posicaoColuna) < 4){
        //Nesse caso o porta-avião só pode ficar na vertical
        posicaoLinha = gerarNumeroAleatorio(0, 7); // gera entre 0 e 6
        tabuleiro[posicaoLinha][posicaoColuna] = 1;
        tabuleiro[posicaoLinha+1][posicaoColuna] = 1;
        tabuleiro[posicaoLinha+2][posicaoColuna] = 1;
        tabuleiro[posicaoLinha+3][posicaoColuna] = 1;
    } else {
        //Nesse caso o porta-aviao pode ficar na vertical (0) ou na horizontal(1))
        vertHori = gerarNumeroAleatorio(0,2); //gera numero entre 0 e 1;
        if(vertHori == 0){
            //Fica na vertical
            posicaoLinha = gerarNumeroAleatorio(0, 7); // gera entre 0 e 6
            tabuleiro[posicaoLinha][posicaoColuna] = 1;
            tabuleiro[posicaoLinha+1][posicaoColuna] = 1;
            tabuleiro[posicaoLinha+2][posicaoColuna] = 1;
            tabuleiro[posicaoLinha+3][posicaoColuna] = 1;
        } else{
            //Fica na horizontal
            posicaoLinha = gerarNumeroAleatorio(0, 10); // gera entre 0 e 9
            tabuleiro[posicaoLinha][posicaoColuna] = 1;
            tabuleiro[posicaoLinha][posicaoColuna+1] = 1;
            tabuleiro[posicaoLinha][posicaoColuna+2] = 1;
            tabuleiro[posicaoLinha][posicaoColuna+3] = 1;
        }
    }
    
    
    
    
    // GERANDO AS POSIÇÕES DAS FRAGATAS
    for(k = 0; k < 2; k++){
        posicaoColuna = gerarNumeroAleatorio(0, 10); // gera um número entre 0 e 9
        if((10-posicaoColuna) < 3){
            //Nesse caso a fragata só pode ficar na vertical
            posicaoLinha = gerarNumeroAleatorio(0, 8); // gera entre 0 e 7
            while(teste != 0){
                if(tabuleiro[posicaoLinha][posicaoColuna] == 0 && tabuleiro[posicaoLinha+1][posicaoColuna] == 0 && tabuleiro[posicaoLinha+2][posicaoColuna] == 0){
                    tabuleiro[posicaoLinha][posicaoColuna] = 2;
                    tabuleiro[posicaoLinha+1][posicaoColuna] = 2;
                    tabuleiro[posicaoLinha+2][posicaoColuna] = 2;
                    teste = 0;
                }else{
                    posicaoLinha = gerarNumeroAleatorio(0, 8); // gera entre 0 e 7
                }
            }
            teste = 1;
        } else{
            //Nesse caso a fragata pode ficar na vertical (0) ou na horizontal(1))
            vertHori = gerarNumeroAleatorio(0,2); //gera numero entre 0 e 1;
            if(vertHori == 0){
                //Fica na vertical
                posicaoLinha = gerarNumeroAleatorio(0, 8); // gera entre 0 e 7
                while(teste != 0){
                    if(tabuleiro[posicaoLinha][posicaoColuna] == 0 && tabuleiro[posicaoLinha+1][posicaoColuna] == 0 && tabuleiro[posicaoLinha+2][posicaoColuna] == 0){
                        tabuleiro[posicaoLinha][posicaoColuna] = 2;
                        tabuleiro[posicaoLinha+1][posicaoColuna] = 2;
                        tabuleiro[posicaoLinha+2][posicaoColuna] = 2;
                        teste = 0;
                    }else{
                        posicaoLinha = gerarNumeroAleatorio(0, 8); // gera entre 0 e 7
                    }
                }
                teste = 1;
            } else {
                //Fica na horizontal
                posicaoLinha = gerarNumeroAleatorio(0, 8); // gera entre 0 e 7
                while(teste != 0){
                    if(tabuleiro[posicaoLinha][posicaoColuna] == 0 && tabuleiro[posicaoLinha][posicaoColuna+1] == 0 && tabuleiro[posicaoLinha][posicaoColuna+2] == 0){
                        tabuleiro[posicaoLinha][posicaoColuna] = 2;
                        tabuleiro[posicaoLinha][posicaoColuna+1] = 2;
                        tabuleiro[posicaoLinha][posicaoColuna+2] = 2;
                        teste = 0;
                    } else {
                        posicaoLinha = gerarNumeroAleatorio(0, 8); // gera entre 0 e 7
                    }                
                }
                teste = 1;
            }
        }
    }
    
    
    
    
    
    // GERANDO AS POSIÇÕES DOS SUBMARINOS
    for(k = 0; k < 2; k++){
        posicaoColuna = gerarNumeroAleatorio(0, 10); // gera um número entre 0 e 9
        if((10-posicaoColuna) < 2){
            //Nesse caso o submarino só pode ficar na vertical
            posicaoLinha = gerarNumeroAleatorio(0, 9); // gera entre 0 e 8
            while(teste != 0){
                if(tabuleiro[posicaoLinha][posicaoColuna] == 0 && tabuleiro[posicaoLinha+1][posicaoColuna] == 0){
                    tabuleiro[posicaoLinha][posicaoColuna] = 3;
                    tabuleiro[posicaoLinha+1][posicaoColuna] = 3;
                    teste = 0;
                }else{
                    posicaoLinha = gerarNumeroAleatorio(0, 9); // gera entre 0 e 8
                }
            }
            teste = 1;
        } else{
            //Nesse caso o submarino pode ficar na vertical (0) ou na horizontal(1))
            vertHori = gerarNumeroAleatorio(0,2); //gera numero entre 0 e 1;
            if(vertHori == 0){
                //Fica na vertical
                posicaoLinha = gerarNumeroAleatorio(0, 9); // gera entre 0 e 8
                while(teste != 0){
                    if(tabuleiro[posicaoLinha][posicaoColuna] == 0 && tabuleiro[posicaoLinha+1][posicaoColuna] == 0){
                        tabuleiro[posicaoLinha][posicaoColuna] = 3;
                        tabuleiro[posicaoLinha+1][posicaoColuna] = 3;
                        teste = 0;
                    }else{
                        posicaoLinha = gerarNumeroAleatorio(0, 9); // gera entre 0 e 8
                    }
                }
                teste = 1;
            } else {
                //Fica na horizontal
                posicaoLinha = gerarNumeroAleatorio(0, 9); // gera entre 0 e 8
                while(teste != 0){
                    if(tabuleiro[posicaoLinha][posicaoColuna] == 0 && tabuleiro[posicaoLinha][posicaoColuna+1] == 0){
                        tabuleiro[posicaoLinha][posicaoColuna] = 3;
                        tabuleiro[posicaoLinha][posicaoColuna+1] = 3;
                        teste = 0;
                    } else {
                        posicaoLinha = gerarNumeroAleatorio(0, 9); // gera entre 0 e 8
                    }                
                }
                teste = 1;
            }
        }
    }
}

int gerarNumeroAleatorio(int inicioDoIntervalo, int fimDoIntervalo){
    srand((unsigned)time(NULL));
    int numero = rand() % fimDoIntervalo;
    return numero;
}



void desenharInterface (int mostrarEmbarcacoes){
    int i, j;
    if(mostrarEmbarcacoes == 0){
        printf("#################################################\n");
        printf("#####             BATALHA NAVAL             #####\n");
        printf("#################################################\n\n");
        printf("      A  B  C  D  E  F  G  H  I  J\n");
        printf("     -----------------------------\n");
        for(i = 0; i <= 9 ; i++){
            printf("%i  |", i);
            for(j = 0; j <= 9; j++){
                if(tabuleiroCopia[i][j] == 0) printf("  #");
                if(tabuleiroCopia[i][j] == 1) printf("  P");
                if(tabuleiroCopia[i][j] == 2) printf("  F");
                if(tabuleiroCopia[i][j] == 3) printf("  S");
                if(tabuleiroCopia[i][j] == 5) printf("   ");
            }
            printf("\n");
        }
        printf("\n");
        if(estado == 0) printf("> Posição já ocupada!\n");
        if(estado == 2) printf("> Jogada inválida!\n");
        printf("> Tentativas Restantes: %i\n", tiros);
        printf("> Entre com uma jogada: ");
    } else {
        printf("#################################################\n");
        printf("#####             BATALHA NAVAL             #####\n");
        printf("#################################################\n\n");
        printf("      A  B  C  D  E  F  G  H  I  J\n");
        printf("     -----------------------------\n");
        for(i = 0; i <= 9 ; i++){
            printf("%i  |", i);
            for(j = 0; j <= 9; j++){
                if(tabuleiro[i][j] == 0) printf("   ");
                if(tabuleiro[i][j] == 1) printf("  P");
                if(tabuleiro[i][j] == 2) printf("  F");
                if(tabuleiro[i][j] == 3) printf("  S");
            }
            printf("\n");
        }
        printf("\n");
        
        if(pontos == 14) printf("> Parabéns! Você venceu o jogo!\n");
        if(tiros == 0) printf("> Ainda não foi dessa vez...\n");
    }
    
}


int registrarJogada(char c, int l){
    int coluna;
    tiros--;
    
    if((c != 'A' && c != 'B' && c != 'C' && c != 'D' && c != 'E' && c != 'F' && c != 'G' && c != 'H' && c != 'I' && c != 'J') || (l != 0 && l != 1 && l != 2 && l != 3 && l != 4 && l != 5 && l != 6 && l != 7 && l != 8 && l != 9)){
        //retorna estado = 2 inválido (a posicao nao existe no tabuleiro)
        return 2;
    } else {
        //a posição é válida
        if(c == 'A') coluna = 0; // armazena na variável coluna (int)
        if(c == 'B') coluna = 1; // o valor correspondente do tipo char
        if(c == 'C') coluna = 2;
        if(c == 'D') coluna = 3;
        if(c == 'E') coluna = 4;
        if(c == 'F') coluna = 5;
        if(c == 'G') coluna = 6;
        if(c == 'H') coluna = 7;
        if(c == 'I') coluna = 8;
        if(c == 'J') coluna = 9;
        
        //Se já tiver bombardeado a posição
        if(tabuleiroCopia[l][coluna] != 0){ 
            return 0;
        }else {
            //Se na posição tiver uma embarcação
            if(tabuleiro[l][coluna] != 0){ 
                pontos++;
                
                
                
                if((tabuleiro[l][coluna]) == 1) tabuleiroCopia[l][coluna] = 1;
                if((tabuleiro[l][coluna]) == 2) tabuleiroCopia[l][coluna] = 2;
                if((tabuleiro[l][coluna]) == 3) tabuleiroCopia[l][coluna] = 3;
                
                
            }else{
                //Acertou a água
                tabuleiroCopia[l][coluna] = 5;
                
            }
            return 1;
            
        }
        
    }
    
    
}


int main() {
    int i, j;
    int linha;
    char coluna;
    carregarEmbarcacoes(); //Gera as posições aleatórias das embarcações
    while(pontos != 14  && tiros > 0){
        desenharInterface(0);
        estado = 5; 
        scanf("%c", &coluna);
        scanf("%i", &linha);
        getchar(); //Limpar o buffer, NAO CONSIDERA O ESPAÇO
        estado = registrarJogada(coluna, linha);
        system("clear");
    } 
    desenharInterface(1);
    return 0;
}

