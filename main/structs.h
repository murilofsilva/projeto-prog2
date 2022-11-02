#ifndef LIST_H_
#define LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct Curso
//{
//    int codigo;
//    char nome[80];
//    int pesoRedacao;
//    int pesoMatematica;
//    int pesoLinguagens;
//    int pesoHumanas;
//    int pesoNatureza;
//    int vagasAC;
//    int vagasL1;
//    int vagasL3;
//    int vagasL4;
//    int vagasL5;
//    int vagasL7;
//    int vagasL8;
//    int vagasL9;
//    int vagasL11;
//    int vagasL13;
//    int vagasL15;
//};

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
int acertosLin;
int acertosMat;
int acertosNat;
int acertosHum;
int acertosRed;
float notaFinal;
Candidato *prox;
};

#endif