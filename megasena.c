#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define LIN 5000
#define COL 6


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

int main() {
    int l, c, i, op=0;
    int j, num, igual=0;
    int concurso[LIN][COL];
    int dezenas[60];

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
            printf("Menu Principal\n\n");
            printf("1 - IMPRIMIR SORTEIOS\n");
            printf("2 - LISTAR QUANTAS VEZES CADA NUMERO SAIU\n");
            printf("3 - LISTAR 15 DUPLAS QUE MAIS SAIRAM NOS SORTEIOS\n");
            printf("4 - LISTAR OS 15 NUMEROS UNICOS QUE MAIS SAIRAM NOS SORTEIOS\n");
            printf("5 - QUANTIDADE DE JOGADAS DESDE A ULTIMA VEZ QUE UM NUMERO FOI SORTEADO\n");
            printf("6 - LISTAR TODAS AS ESTATISTICAS\n");
            printf("0 - SAIR\n");
            scanf("%d", &op);
        }while(op<0 || op>6);

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
        }//switch
        if(op!=0){
            getch();
        }

    }while(op!=0);

    printf("\nfim do programa\n");
    return 0;

}
