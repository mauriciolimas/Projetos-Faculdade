#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LIN 5000
#define COL 6

void sorteio(int *concurso[LIN][COL]){
    int c, l, i, j, num, igual=0;

    srand(time(NULL));

    for(l=0;l<LIN;l++){
        for(c=0;c<COL;){
            while(igual!=1){
               num = rand()%61;
               for(i=0;i<6;i++){
                    if(num == concurso[l][i] || num == 0){
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

}//sorteio

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

void estatistica(int dezenas[], int matriz[LIN][COL]){
    int i /*dezenas[60]*/;
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
}//estatistica

void listarDuplas(int matriz[LIN][COL]){
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
    printf("---- DUPLAS QUE MAIS SAIRAM ----\n\n");
    for(i=1769;i>1754;i--){
        printf("Numeros %02d e %02d = %d vezes.\n", maisSorteados[i].numero1, maisSorteados[i].numero2, maisSorteados[i].quant);
    }
    printf("\n\n");

}//LISTAR DUPLAS

void numerosUnicos(int vetor[LIN][COL]){
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
    /*Impress�o do vetor*/
    for(i=60;i>45;i--){
        //printf("%d = %d\n", i, numMaisSorteados[i]);
        printf("Numero %02d = %2d vezes\n", numSorteados[i].numero, numSorteados[i].quant);
    }
    printf("\n\n");
}

void quantidadeJogadas(int vetor[LIN][COL]){
    int i, j, l, c, num[61];

    /*ZERA O VETOR NUM*/
    for(i=0;i<61;i++){
        num[i]=0;
    }


}

int main() {
    int l, c, i, op=0;
    int concurso[LIN][COL];
    int dezenas[60];

    /*SORTEIA OS NUMEROS*/
    sorteio(concurso);
    bubleSort(concurso);

    do{
        system("cls");
        printf("Menu Principal\n\n");
        printf("1 - IMPRIMIR SORTEIOS\n");
        printf("2 - ESTATISTICAS DE NUMEROS\n");
        printf("3 - LISTAR 15 DUPLAS QUE MAIS SAIRAM\n");
        printf("4 - LISTAR OS 15 NUMEROS MAIS SORTEADOS\n");
        scanf("%d", &op);
    }while(op<1 || op>4);



    switch(op){
        case 1:
            for(l=0;l<LIN;l++){
                for(c=0;c<COL;c++){
                    printf("|%02d| ",concurso[l][c]);
                }
                printf("\n\n");
            }
            listarDuplas(concurso);
            break;
        case 2:
            estatistica(dezenas, concurso);
            for(i=0;i<60;i++){
                printf("Numero: %02d = %2d vezes\n",i+1, dezenas[i]);
            }
            break;
        case 3:
            listarDuplas(concurso);
            break;
        case 4:
            numerosUnicos(concurso);
            break;
    }//switch

    system("pause");
    return 0;
}
