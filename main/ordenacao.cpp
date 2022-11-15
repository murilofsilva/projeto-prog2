#include "structs.h"

int separaCursos(int inicioLista, int fimLista, Curso **vetor){
    char pivot[80];
    strcpy(pivot, vetor[fimLista]->nome);
    int i = inicioLista;
    for (int j = inicioLista; j < fimLista; j++)
    {
        if (strcmp(vetor[j]->nome, pivot) < 0)
        {
            Curso *auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
            i++;
        }
    }

    Curso *auxiliar = vetor[i];
    vetor[i] = vetor[fimLista];
    vetor[fimLista] = auxiliar;
    return i;
}

void ordenarCursosPorNome(int inicioVetor, int fimVetor, Curso **vetor)
{
    int q;
    if (inicioVetor < fimVetor) 
    {
        q = separaCursos(inicioVetor, fimVetor, vetor);
        ordenarCursosPorNome(inicioVetor, q - 1, vetor);
        ordenarCursosPorNome(q + 1, fimVetor, vetor);
    }
}

int separaCandidatosPorCota(int inicioVetor, int fimVetor, Candidato **vetor)
{
    char pivot[3];
    strcpy(pivot, vetor[fimVetor]->tipoVaga);
    int i = inicioVetor;
    for (int j = inicioVetor; j < fimVetor; j++)
    {
        if (strcmp(vetor[j]->tipoVaga, pivot) < 0)
        {
            Candidato *auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
            i++;
        }
    }

    Candidato *auxiliar = vetor[i];
    vetor[i] = vetor[fimVetor];
    vetor[fimVetor] = auxiliar;
    return i;
}

void ordenarCandidatosPorCota(int inicioVetor, int fimVetor, Candidato **vetor)
{
    int q;
    if (inicioVetor < fimVetor)
    {
        q = separaCandidatosPorCota(inicioVetor, fimVetor, vetor);
        ordenarCandidatosPorCota(inicioVetor, q - 1, vetor);
        ordenarCandidatosPorCota(q + 1, fimVetor, vetor);
    }
}

int separaCandidatosPorNota(int inicioVetor, int fimVetor, Candidato **vetor)
{
    float pivot = vetor[fimVetor]->notaFinal;
    int i = inicioVetor;
    for (int j = inicioVetor; j < fimVetor; j++)
    {
        if (vetor[j]->notaFinal > pivot)
        {
            Candidato *auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
            i++;
        }
    }
    Candidato *auxiliar = vetor[i];
    vetor[i] = vetor[fimVetor];
    vetor[fimVetor] = auxiliar;
    return i;
}

void quicksortNotas(int inicioVetor, int fimVetor, Candidato **vetor)
{
    int q;
    if (inicioVetor < fimVetor)
    {
        q = separaCandidatosPorNota(inicioVetor, fimVetor, vetor);
        quicksortNotas(inicioVetor, q - 1, vetor);
        quicksortNotas(q + 1, fimVetor, vetor);
    }
}

void ordenarCandidatosPorNota(int inicioVetor, int fimVetor, Candidato **vetor)
{
    int n = 1, ini = 0;
    char anterior[3], atual[3];
    strcpy(anterior, vetor[0]->tipoVaga);
    while(n < fimVetor){
        strcpy(atual, vetor[n]->tipoVaga);
        if(strcmp(anterior, atual) != 0){
            quicksortNotas(ini, n - 1, vetor);
            ini = n;
            strcpy(anterior, atual);
        }
        n++;
    }
}