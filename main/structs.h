#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Curso
{
    int codigo;
    char nome[80+1];
    int pesoRedacao;
    int pesoMatematica;
    int pesoLinguagens;
    int pesoHumanas;
    int pesoNatureza;
    int vagasAC;
    int vagasL1;
    int vagasL3;
    int vagasL4;
    int vagasL5;
    int vagasL7;
    int vagasL8;
    int vagasL9;
    int vagasL11;
    int vagasL13;
    int vagasL15;
    Curso *proximo;
};

struct Data
{
    int dia, mes, ano;
};

struct Candidato
{
    int codigoCurso;
    int inscricao;
    char nome[80];
    Data dataNasc;
    char tipoVaga[2];
    float escoreMat, escoreRed, escoreHum, escoreLin, escoreNat, notaFinal;
    Candidato *prox;
};

struct MediaDP
{
    int acertos;
    float media, desvioPadrao;
};

struct Acertos
{
    int inscricaoCandidato;
    int lin, mat, nat, hum;
    float red, epLin, epMat, epNat, epHum;
};