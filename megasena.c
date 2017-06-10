#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

#define LIN 5000
#define COL 6
#define JOGADOR 3


void bubleSort(int *vetor[LIN][COL]){
    int i, j, k, aux;

    for(k=0;k<LIN;k++){
        for(j=0;j<6;j++){
            for(i=0;i<6-j-1;i++){
                if(vetor[k][i]>vetor[k][i+1]){
                    aux = vetor[k][i];
                    vetor[k][i] = vetor[k][i+1];
                    vetor[k][i+1] = aux;
                }//if
            }//for I
        }//for J
    }//for K

}//ordenaSorteio

void estatistica(int *dezenas[], int *matriz[LIN][COL]){
    int i;
    int l, c, num;

    //zerar o vetor
    for(i=0;i<60;i++){
        dezenas[i]=0;
    }

    //contagem de numeros
    for(l=0;l<LIN;l++){
        for(c=0;c<COL;c++){
            num = matriz[l][c];
            dezenas[num-1]++;
        }
    }
    /*IMPRIME A ESTATISTICA DE NUMEROS SORTEADOS*/
    printf("\n\n---- QUANTIDADE DE VEZES QUE UM NUMERO SAIU ----\n\n");
    for(i=0;i<60;i++){
        printf("Numero: %02d = %2d vezes\n",i+1, dezenas[i]);
    }
    printf("\n\n");
}//estatistica

void listarDuplas(int *matriz[LIN][COL]){
    int i, j, l, c, e, num1=0, num2=0, duplas[61][61], cont, aux1, aux2, aux3;
    struct numeros{
        int numero1;
        int numero2;
        int quant;
    };
    struct numeros maisSorteados[1770];

    /*ZERAR MATRIZ DUPLAS*/
    for(i=0;i<61;i++){
        for(j=0;j<61;j++){
            duplas[i][j] = 0;
        }
    }

    /*CONSTRUINDO MATRIZ DE DUPLAS*/
    for(l=0;l<LIN;l++){
        for(c=0;c<COL;c++){
            for(e=c+1;e<COL;e++){
                num1 = matriz[l][c];
                num2 = matriz[l][e];
                duplas[num1][num2] += 1;
            }
        }//FOR C
    }//FOR L

    /*PASSA A MATRIZ PARA A STRUCT*/
    cont=0;
    for(l=1;l<=60;l++){
        for(c=1;c<=60;c++){
            if(l != c){
                if(l <= c){
                    maisSorteados[cont].numero1 = l;
                    maisSorteados[cont].numero2 = c;
                    maisSorteados[cont].quant = duplas[l][c];
                    cont++;
                }
            }
        }//FOR C
    }//FOR L

    /*ORDERNAR A STRUCT*/
    for(j=0;j<1770;j++){
        for(i=0;i<1770-j-1;i++){
            if(maisSorteados[i].quant>maisSorteados[i+1].quant){
                aux1 = maisSorteados[i].numero1;
                aux2 = maisSorteados[i].numero2;
                aux3 = maisSorteados[i].quant;
                maisSorteados[i].numero1 = maisSorteados[i+1].numero1;
                maisSorteados[i].numero2 = maisSorteados[i+1].numero2;
                maisSorteados[i].quant = maisSorteados[i+1].quant;
                maisSorteados[i+1].numero1 = aux1;
                maisSorteados[i+1].numero2 = aux2;
                maisSorteados[i+1].quant = aux3;
            }
        }
    }

    /*IMPRIME A STRUCT*/
    printf("---- AS 15 DUPLAS QUE MAIS SAIRAM ----\n\n");
    for(i=1769;i>1754;i--){
        printf("Numeros %02d e %02d = %d vezes.\n", maisSorteados[i].numero1, maisSorteados[i].numero2, maisSorteados[i].quant);
    }
    printf("\n\n");

}//LISTAR DUPLAS

void numerosUnicos(int *vetor[LIN][COL]){
    int i, j, c, l, num, numMaisSorteados[61], maissort=0, aux1, aux2;
    struct numeros
    {
        int numero;
        int quant;
    };
    struct numeros numSorteados[61];

    /*Zera o vetor numMaisSorteados*/
    for(i=0;i<=60;i++){
        numMaisSorteados[i]=0;
    }

    /*Passa a quantidade de numeros para o vetor numMaisSorteados*/
    for(l=0;l<LIN;l++){
        for(c=0;c<COL;c++){
            num = vetor[l][c];
            numMaisSorteados[num]++;
        }
    }

    /*Passa os numeros para a struct*/
    for(i=1;i<=60;i++){
        numSorteados[i].numero = i;
        numSorteados[i].quant = numMaisSorteados[i];
    }

    /*Ordena a Struct*/
    for(j=1;j<=61;j++){
        for(i=1;i<=61-j-1;i++){
            if(numSorteados[i].quant>numSorteados[i+1].quant) {
                aux1 = numSorteados[i].numero;
                aux2 = numSorteados[i].quant;
                numSorteados[i].numero = numSorteados[i+1].numero;
                numSorteados[i].quant = numSorteados[i+1].quant;
                numSorteados[i+1].numero = aux1;;
                numSorteados[i+1].quant = aux2;
            }
        }
    }
    printf("\n\n---- OS 15 NUMEROS MAIS SORTEADOS ----\n\n");
    /*Impressão do vetor*/
    for(i=60;i>45;i--){
        //printf("%d = %d\n", i, numMaisSorteados[i]);
        printf("Numero %02d = %2d vezes\n", numSorteados[i].numero, numSorteados[i].quant);
    }
    printf("\n\n");
}

void quantidadeJogadas(int *vetor[LIN][COL]){
    int i, j, l, c, num[61], saiu=0;

    /*ZERA O VETOR NUM*/
    for(i=0;i<61;i++){
        num[i]=0;
    }

    for(i=1;i<=60;i++){
        for(l=LIN-1;l>=0;l--){
            for(c=0;c<COL;c++){
                if(vetor[l][c] == i){
                    saiu = 1;
                }//IF
            }//FOR C
            if(saiu == 0){
                num[i]+=1;
            }else{
                break;
            }
        }//FOR L
        if(saiu == 1){
            saiu = 0;
            continue;
        }
    }//FOR I
    /*IMPRESSAO NUMEROS QUE SAIRAM NA QUANT JOGADAS*/
    printf("\n\n---- QUANTIDADE DE JOGADAS QUE UM NUMERO DEMOROU A SAIR ----\n\n");
    for(i=1;i<=60;i++){
        if(num[i]==0){
            printf("N° %02d = saiu no ultimo sorteio.\n");
        }else{
            printf("N° %02d = nao sai a %d sorteios seguidos\n", i, num[i]);
        }
    }//FOR
    printf("\n\n");

}


void corrigirjogos(int *aposta[], int *sorteios[LIN][COL], char nome[]){
    int acertos = 0, melhorresultado = 0, melhorjogo = 0;
    int l, c, i;

    for(l=0;l<LIN;l++){
        acertos = 0;
        for(i=0;i<COL;i++){
            for(c=0;c<COL;c++){
                if(aposta[i]==sorteios[l][c]){
                    acertos += 1;
                }
            }//FOR C
            if(acertos > melhorresultado){
                melhorresultado = acertos;
                melhorjogo = l;
            }
        }//FOR I
    }//FOR L
    if(melhorresultado == 0){
        printf("\n%s, você acertou %d numeros\n", nome, melhorresultado);
    }else{
        if(melhorresultado==6){
            for(i=1;i<=10;i++){
                if(i%2==0){
                    Sleep(100);
                    system("color 07");
                }else{
                    Sleep(100);
                    system("color 47");
                }
            }
            printf("\nParabéns %s, você acertou %d numeros! Sorteio [%04d]\n", nome, melhorresultado, melhorjogo+1);
        }else{
            printf("\nParabéns %s, você acertou %d numeros! Sorteio [%04d]\n", nome, melhorresultado, melhorjogo+1);
        }
    }

}//CORRIGIR JOGOS

int main() {
    int l, c, i, k, op=0, teste=0, aux;
    int j, num, igual=0, resultadojogo = 0;
    int concurso[LIN][COL];
    int dezenas[60], numaposta[6];

    struct sena{
        char nome[50];
        char cpf[11];
        int jogo[6];
    };
    struct sena aposta[3];

     setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português

    /*SORTEIA OS NUMEROS*/
        srand(time(NULL));

    for(l=0;l<LIN;l++){
        for(c=0;c<COL;){
            while(igual!=1){
               num = rand()%61;
               for(i=0;i<6;i++){
                    if((num == concurso[l][i]) || (num == 0)){
                        igual=1;
                    }
               }//for i
               if(igual==0){
                concurso[l][c]=num;
                c++;
               }
            }//while
            igual=0;
        }
    }
    /*FIM SORTEIA OS NUMEROS*/
    bubleSort(concurso); //ORDENA OS NUMEROS NO SORTEIO
    /*MENU*/
    do{
        do{
            system("cls");
            printf("MENU PRINCIPAL\n\n");
            printf("\t1 - IMPRIMIR SORTEIOS\n");
            printf("\t2 - LISTAR QUANTAS VEZES CADA NUMERO SAIU\n");
            printf("\t3 - LISTAR 15 DUPLAS QUE MAIS SAIRAM NOS SORTEIOS\n");
            printf("\t4 - LISTAR OS 15 NUMEROS UNICOS QUE MAIS SAIRAM NOS SORTEIOS\n");
            printf("\t5 - QUANTIDADE DE JOGADAS DESDE A ULTIMA VEZ QUE UM NUMERO FOI SORTEADO\n");
            printf("\t6 - LISTAR TODAS AS ESTATISTICAS\n");
            printf("\t7 - FAZER JOGADAS\n");
            printf("\t8 - IMPRIMIR AS APOSTAS\n");
            printf("\t0 - SAIR\n");
            scanf("%d", &op);
        }while(op<0 || op>7);

        switch(op){
            case 1:
                for(l=0;l<LIN;l++){
                    for(c=0;c<COL;c++){
                        printf("|%02d| ",concurso[l][c]);
                    }
                    printf("\n\n");
                }
                break;
            case 2:
                estatistica(dezenas, concurso);
                break;
            case 3:
                listarDuplas(concurso);
                break;
            case 4:
                numerosUnicos(concurso);
                break;
            case 5:
                quantidadeJogadas(concurso);
                break;
            case 6:
                estatistica(dezenas, concurso);
                listarDuplas(concurso);
                numerosUnicos(concurso);
                quantidadeJogadas(concurso);
                break;
            case 7:
                /*CAPTURA AS APOSTAS*/
                for(i=0;i<JOGADOR;i++){
                    printf("Entre com o nome do jogador %d: ", i+1);
                    fflush(stdin);
                    gets(aposta[i].nome);
                    printf("Entre o seu CPF %s [só os numeros]: ", aposta[i].nome);
                    /*CAPTURA E TESTA O CPF*/
                    do{
                        fflush(stdin);
                        gets(aposta[i].cpf);
                        teste = strlen(aposta[i].cpf);
                        if(teste!=11){
                            printf("O CPF deve conter 11 digitos, insira um CPF valido: ");
                        }
                    }while(teste!=11);

                    for(j=0;j<6;j++){
                        printf("Entre com %d° numero: ", j+1);
                        /*TESTE E CAPTURA AS DEZENAS DO JOGO*/
                        do{
                            scanf("%d", &teste);
                            if(teste<1 || teste>60){
                                printf("\tSo sao aceitos numeros de 1 a 60 insira um numero valido: ");
                            }
                            /*VALIDAÇAO DE NUMEROS REPETIDOS*/
                            for(k=0;k<=j+1;k++){
                                if(teste==aposta[i].jogo[k]){
                                    printf("Numero nao pode ser repetido\n");
                                    j--;
                                    continue;
                                }
                            }
                        }while(teste<1 || teste>60);

                        aposta[i].jogo[j] = teste;
                    }
                    printf("\n\n");
                }//FOR I

                /*ORDERNAR OS NUMEROS DA JOGADA*/
                for(k=0;k<JOGADOR;k++){
                    for(j=0;j<6;j++){
                        for(i=0;i<6-j-1;i++){
                            if(aposta[k].jogo[i]>aposta[k].jogo[i+1]){
                                aux = aposta[k].jogo[i];
                                aposta[k].jogo[i] = aposta[k].jogo[i+1];
                                aposta[k].jogo[i+1] = aux;

                            }//if
                        }//for I
                    }//for J
                }
                /*FIM ORDERNAR OS NUMEROS DA JOGADA*/
                /*VERIFICA OS ACERTOS E O SORTEIO COM MAIOR PONTUAÇÃO*/
                for(i=0;i<JOGADOR;i++){
                    corrigirjogos(aposta[i].jogo, concurso, aposta[i].nome);
                    printf("\n");
                }
                printf("\n\n");

                break;
            case 8:
                /*IMPRIME AS JOGADAS*/
                for(i=0;i<JOGADOR;i++){
                    printf("Jogador %d: %s\n", i+1, aposta[i].nome);
                    printf("CPF: %s\n", aposta[i].cpf);
                    printf("Jogo: ");
                    for(j=0;j<6;j++){
                        printf("[%02d] ", aposta[i].jogo[j]);
                        numaposta[j] = aposta[i].jogo[j];
                    }
                    corrigirjogos(aposta[i].jogo, concurso, aposta[i].nome);
                    printf("\n\n");
                }
                printf("\n\n");
                break;
        }//SWITCH
        if(op!=0){
            getch();
        }

    }while(op!=0);

    printf("\nfim do programa\n");
    return 0;

}
