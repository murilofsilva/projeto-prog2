#include "structs.h"

//void carregarArquivos(Curso* listaCursos);

int listaMenu(bool firstExec);

void quicksort(int p, int r, int *v);

void addInscrito(Candidato *&listaI, Candidato *&listaF, Candidato candidato);

void imprimeLista(Candidato *lst);

void carregaCandidato(Candidato *&listaCandidatosI , Candidato *&listaCandidatosF);

void carregaAcertosCandidatos(Candidato *&listaCandidatosI, Candidato *&listaCandidatosF,
float &mMat, float &dMat, float &mNat, float &dNat, float &mLin, float &dLin, float &mHum, float &dHum);

float calculaNotaFial(int lin, int mat, int nat, int hum, float red, float &media, float &desvioPadrao);

void imprimeVetorAcertos(Acertos *vetor, int tam);

void imprimeVetorMediaDP(int *lin, int *mat, int *nat, int *hum, int tam);

void calculaMediaDesvioPadrao(int *vetor, int tam, float &nMedia, float &nDesv);

void calcularEscorePadronizado(int qtdAcertos, float media, float desvioPadrao);