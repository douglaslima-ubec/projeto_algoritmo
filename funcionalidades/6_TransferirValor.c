//importa os arquivos de cabeçalho, nesses arquivos estão todas as definições de variáveis, structs e funções
#include "../headers/conta.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void TransferirValor(){
// Função para transferir valor de uma conta para outra

    //VARIÁVEIS
    int i;
    char numContaOrigem[9];
    char numContaDestino[9];
    char dirContaOrigem[255];
    char dirContaDestino[255];
    double valor;
    FILE *fcontaOrigem;
    FILE *fcontaDestino;
    conta contaOrigem;
    conta contaDestino;

    // Solicitar informações da transferência ao usuário
    printf("Digite o número da conta de origem: ");
    scanf("%s", numContaOrigem);

    printf("Digite o número da conta de destino: ");
    scanf("%s", numContaDestino);

    printf("Digite o valor a ser transferido: ");
    scanf("%lf", &valor);

    //diretório da conta origem
    strcpy(dirContaOrigem,"./contas/");
    strcat(dirContaOrigem,numContaOrigem);
    strcat(dirContaOrigem,".csv");
    //diretório da conta destino
    strcpy(dirContaDestino,"./contas/");
    strcat(dirContaDestino,numContaDestino);
    strcat(dirContaDestino,".csv");

    printf("\n%s\n",dirContaOrigem);

    //verifica se a conta origeme existe
    if(access(dirContaOrigem,F_OK) != 0){
        printf("A conta %s não existe!\n",numContaOrigem);
        return;
    }else{
        fcontaOrigem = fopen(dirContaOrigem,"r");
        fscanf(fcontaOrigem,"%[^,],%[^,],%lf",contaOrigem.numero,contaOrigem.titular,contaOrigem.saldo);
    }
    //verifica se a conta destino existe
    if(access(dirContaDestino,F_OK) != 0){
        printf("A conta %s não existe!\n",numContaDestino);
        return;
    }else{
        fcontaDestino = fopen(dirContaDestino,"r");
        fscanf(fcontaDestino,"%[^,],%[^,],%lf",contaDestino.numero,contaDestino.titular,contaDestino.saldo);
    }

    printf("%s\n",contaOrigem.numero);
    printf("%s\n",contaOrigem.titular);
    printf("%lf\n",contaOrigem.saldo);
    printf("%s\n",contaDestino.numero);
    printf("%s\n",contaDestino.titular);
    printf("%lf\n",contaDestino.saldo);
/*
        // Defina o número inicial de contas
        int numContas = 0;

        // Alocar dinamicamente espaço para um array de contas
        Conta *contas = NULL;

        // Solicitar ao usuário o número de contas
        printf("Digite o número de contas: ");
        scanf("%d", &numContas);

        // Alocar dinamicamente espaço para as contas
        contas = (Conta *)malloc(numContas * sizeof(Conta));

        // Inicializar contas
        for (int i = 0; i < numContas; i++) {
            // Solicitar informações da conta ao usuário
            printf("Digite o número da conta %d: ", i);
            scanf("%d", &contas[i].numeroConta);

            // Alocar dinamicamente espaço para o titular
            printf("Digite o nome do titular da conta %d: ", i);
            char titularBuffer[50];
            scanf("%s", titularBuffer);
            contas[i].titular = strdup(titularBuffer);

            printf("Digite o saldo da conta %d: ", i);
            scanf("%f", &contas[i].saldo);
        }

        // Chame a função para transferir valor
        transferirValor(contas, numContas);

        // Liberar a memória alocada dinamicamente para os titulares
        for (int i = 0; i < numContas; i++) {
            free(contas[i].titular);
        }

        // Liberar a memória alocada dinamicamente para o array de contas
        free(contas);
*/
}

