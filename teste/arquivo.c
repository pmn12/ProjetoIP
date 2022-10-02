#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float pReal;
    float pImag;
}Complexo;

void Empilhe(Complexo **cPilha, Complexo umC, int *tPilha) //==> cPilha = &Pilha -->*cPilha = *Pilha
                                                            //--> ponteiro que aponta para Pilha
{
    //aumenta o tamanho da pilha
    ++(*tPilha);

    //aloca
    *cPilha = (Complexo*) realloc(*cPilha, (*tPilha) * sizeof(Complexo));

    if(*cPilha==NULL){
        printf("Erro empilhando.\n");
        exit (1);
    }

    //coloca o num complexo no topo da pilha
    (*cPilha)[*tPilha - 1] = umC;
} 

Complexo Desempilhe(Complexo **cPilha, int *tPilha)
{
    Complexo desempilhado;
    desempilhado = (*cPilha)[*tPilha - 1];

    //retira o num complexo no topo da pilha
    //desaloca e diminui o tamanho
    -- *tPilha;

    *cPilha = (Complexo*) realloc(*cPilha, *tPilha * sizeof(Complexo));

    if(*cPilha==NULL && *tPilha !=0){
        printf("Erro desempilhando.\n");
        exit (1);
    }
    //retorna o complexo desempilhado
    return desempilhado;
}

Complexo Topo(Complexo *cPilha, int tPilha)
{
    Complexo topo;
    topo = cPilha[tPilha - 1];
    //retorna o complexo no topo
    return topo;
}

int PilhaVazia(Complexo *cPilha, int tPilha)
{
    if(cPilha==NULL || tPilha==0)
        return 1;
    else
        return 0;
}

void SalvePilha(Complexo *cPilha, int tPilha)
{
    //salva a pilha em arquivo pilha.bin (opcao w)
    FILE *fpilha;
    fpilha = fopen("pilha.bin", "wb");

    if(fpilha==NULL) {
        printf("Problema com o arquivo. SP\n");
        exit(1);
    }
    //1 registro do arquivo: tpilha
    fwrite(&tPilha, sizeof(int), 1, fpilha);
    //resto: conteudo da pilha
    for(int i=0; i<tPilha; i++)
    {
        fwrite(&cPilha[i].pReal, sizeof(float), 1, fpilha);
        fwrite(&cPilha[i].pImag, sizeof(float), 1, fpilha);
    }
    fclose(fpilha);
}

Complexo *RecuperePilha(int *tPilha)
{
    //le o conteudo de pilha.bin e o retorna
    FILE *fpilha;
    int TAM; Complexo *complexos=NULL;
    fpilha = fopen("pilha.bin", "rb");

    if(fpilha==NULL) {
        printf("Problema com o arquivo. RP\n");
        exit(1);
    }

    //atualiza o tam da pilha
    fread(&TAM, sizeof(4), 1, fpilha);
    *tPilha = TAM;

    complexos = (Complexo*) realloc(complexos, (*tPilha) * sizeof(Complexo));
    if(complexos==NULL)
    {
        printf("Erro alocando. RP\n");
        exit(1);
    }
    for(int i=0; i<*tPilha; i++)
    {
        fread(&complexos[i].pReal, sizeof(float), 1, fpilha);
        fread(&complexos[i].pImag, sizeof(float), 1, fpilha);
    }
    fclose(fpilha);
    return complexos;
}

int main ()
{
    Complexo *Pilha=NULL; int tamPilha=0;
    Complexo um = {2.5, 3.5}; 
    Complexo dois = {-1.5, 2.0};

    if(PilhaVazia(Pilha, tamPilha))
    {
        printf("Tudo certo com a pilha inicial\n");
        Empilhe(&Pilha, um, &tamPilha); 
        Empilhe(&Pilha, dois, &tamPilha);

        for(int i=0; i<tamPilha; i++)
            printf("Real: %.1f Imag: %.1f\n", Pilha[i].pReal, Pilha[i].pImag);
        printf("\n");
        Complexo topo;
        topo = Topo(Pilha, tamPilha);

        if(topo.pReal==dois.pReal && topo.pImag==dois.pImag)
        {
            SalvePilha(Pilha, tamPilha);
            
            for(int i=0; i<2; i++)
                Desempilhe(&Pilha, &tamPilha);

            Pilha = RecuperePilha(&tamPilha);

            for(int i=0; i<tamPilha; i++)
                printf("Real: %.1f Imag: %.1f\n", Pilha[i].pReal, Pilha[i].pImag);
        }
    }
    free(Pilha);
    return 0;
}