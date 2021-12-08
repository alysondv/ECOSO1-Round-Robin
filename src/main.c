#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define QUANTUM 3

// estrutura para armazenar a informação do processo
typedef struct no{
    int processo; //armazena o numero do processo
    int data_criacao;
    int duracao; // tempo
    int priodade; 
    struct no* prox; // aponta para o próximo processo 
}noProcesso;

int processos = 0; // Quantidade de processos 
noProcesso *prim = NULL; // O primeiro processo lido
noProcesso *ult = NULL; // Último processo lido

int insere_Fila_circular(noProcesso *processo){ 
    noProcesso *novo = NULL;

    // aloca o novo no na memoria
    novo = (noProcesso *) malloc (sizeof(noProcesso));

    novo = processo;

    // verifica se a lista esta vazia
    if(prim == NULL){
        prim = novo;
        ult = novo;
    } else{
        // atualizando quem é o último da fila
        ult->prox = novo;
        ult = novo;
        novo->prox = prim;
    }
    processos++;
    return 1;
}

noProcesso *transforma_Data(char *info){ 

    noProcesso *p;
    p = (noProcesso *) malloc (sizeof(noProcesso));
    
    p->data_criacao = atoi(&info[0]);
    p->duracao = atoi(&info[2]);
    p->priodade = atoi(&info[4]);
    p->processo = processos + 1;
    p->prox = NULL;

    return p;
}

void insereEsperaDepois(noProcesso *processo, FILE *arq, int sinal){
    noProcesso *aux;
    aux = (noProcesso *)malloc(sizeof(noProcesso));
    aux =  processo;

    do{
        if((aux->duracao == 1) && (aux->prox->duracao > 0) && (aux->prox->prox->duracao > 0)){
            fprintf(arq,"%-6s%-6s" ,"--","--");
            aux = aux->prox;
        }else{
            if(aux->prox->duracao > 0){
                fprintf(arq,"%-6s" ,"--");
            }else{
                fprintf(arq,"%-6s" ," ");
            }
        }
        if(sinal != 1){
                break;
        }
        aux = aux->prox;
    }while(aux != ult);
    fprintf(arq, "\n");
    return;
}

void insereEsperaAntes(noProcesso *processo, FILE *arq){
    noProcesso *aux;
    int j;
    aux = (noProcesso *)malloc(sizeof(noProcesso));
    aux = prim;
    

    while(aux != processo){
        if(aux->duracao > 0){
            fprintf(arq, "%-6s", "--");
        }else{
            fprintf(arq, "%-6s"," ");
        }
        aux = aux->prox;
    }
    return;
}

void cabecalho(FILE *arq_saida){
    int i;
    // faz a linha de cabeçalho
    fprintf(arq_saida, "%-7s%3s", "tempo", "");
    for(i = 1; i <= processos; i++){
        fprintf(arq_saida, "%1s%-5d", "P", i);
    }
    fprintf(arq_saida, "\n");
}

int gera_saida(){
    // criando a variável ponteiro para o arquivo
    FILE *arq_saida;
    noProcesso *aux;
    int i, j, tempo = 0;
    int cont = 0;
    int sinal = 0; // sinal para saber se já foi mais de 1 rodada de loop
    aux = (noProcesso *) malloc (sizeof(noProcesso));
    aux = prim;
    //abrindo o arquivo
    arq_saida = fopen("saida.txt", "a");

    // verifica se houve erro ao abrir arquivo
    if(arq_saida == NULL){
        printf("Erro ao gerar saida!\n");
        return 0;
    }
    // faz a linha de cabeçalho
    cabecalho(arq_saida);

    if(prim != NULL){
        do{
            if(aux->duracao > 0){
                for(i = 0; i < QUANTUM; i++){
                    fprintf(arq_saida,  "%-3d%-1s%3d%-3s" , tempo,"-", tempo+1, "");
                    insereEsperaAntes(aux, arq_saida);
                    fprintf(arq_saida, "%-6s", "##");
                    insereEsperaDepois(aux, arq_saida, sinal);
                    aux->duracao--;
                    tempo++;
                     if(aux->duracao <= 0){
                        cont++;
                        break;
                    }
                }
                if(aux == ult){
                    sinal = 1;
                }
            }
            aux = aux->prox;
        }while(cont < processos);
    }

    // fechando arquivo
    fclose(arq_saida);
  
    return 1;    
}

int main(){
    FILE *arq_processo;
    noProcesso *aux;
    char dados[7];

    // aloca memoria pra struct auxiliar
    aux = (noProcesso *) malloc (sizeof(noProcesso));

    // abrindo o arquivo para leitura somente
    arq_processo = fopen("entrada.txt", "r");

    // percorre todos os processos (linhas) do arquivo e insere cada processo na fila
    while(fgets(dados, 7, arq_processo) != NULL){
        aux =  transforma_Data(dados);
        insere_Fila_circular(aux);
    }

    fclose(arq_processo);
    gera_saida();
    return 0;
}
