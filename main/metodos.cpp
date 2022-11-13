#include "structs.h"
#include <math.h>

//Função que lista o menu
int listaMenu(bool firstExec)
{
    int resposta;
    if (firstExec) {
        printf("0: Ler dados de entrada (única execução);\n");
    }
    printf("1: Gerar arquivo contendo informações gerais;\n");
    printf("2: Imprimir na tela as informações de um candidato;\n");
    printf("3: Gerar arquivo contendo listagem dos candidatos que não passaram no vestibular;\n");
    printf("4: Alterar notas de redeção;\n");
    printf("5: Terminar o programa.\n");
    scanf("%d", &resposta);
    return resposta;
}
//Fim do escopo da funçãom que lista ao menu

//Função que ordena um vetor a partir do método Quicksort
void troca(int &a, int &b)
{
  int aux;
  aux = a;
  a = b;
  b = aux;
}

int separa(int p, int r, int *v)
{
  int x, i, j;
  x = v[p];
  i = p - 1;
  j = r + 1;
  while (1) {
    do {
      j--;
    } while (v[j] > x);
    do {
      i++;
    } while (v[i] < x);
    if (i < j)
      troca(v[i], v[j]);
    else
      return j;
  }
}

void quicksort(int p, int r, int *v)
{
  int q;
  if (p < r) {
    q = separa(p, r, v);
    quicksort(p, q, v);
    quicksort(q+1, r, v);
  }
}
//Fim do escopo da função de ordenação

//Função que imprime vetor
void imprimeVetorAcertos(Acertos *vetor, int tam)
{
  if (vetor == NULL)
  {
    printf("Vetor vazio, nao ha o que ser impresso!\n");
  }
  else
  {
    printf("\nConteudo do vetor:\n");
    for (int i=0; i<tam; i++)
    {
      printf("Insc: %d; Pontuacao lin: %d; Pontuacao mat: %d; Pontuacao nat: %d; Pontuacao hum: %d; Pontuacao red: %.2f; Escore Padronizado Mat: %.1f; Escore Padronizado Nat: %.1f; Escore Padronizado Lin: %.1f; Escore Padronizado Hum: %.1f\n", vetor[i].inscricaoCandidato, vetor[i].lin, vetor[i].mat, vetor[i].nat,vetor[i].hum, vetor[i].red, vetor[i].epMat, vetor[i].epNat, vetor[i].epLin, vetor[i].epHum);
      if (i == tam-1) printf("\n");
    }
  }
}
//Fim da função que imprime vetor

void imprimeVetorMediaDP(int *lin, int *mat, int *nat, int *hum, int tam)
{
  if (lin == NULL)
  {
    printf("Vetor vazio, nao ha o que ser impresso!\n");
  }
  else
  {
    printf("\nConteudo do vetor media e desvio padrao:\n");
    printf("\nVetor lin:\n");
    for (int i=0; i<tam; i++)
    {
      printf("%d\n", lin[i]);
      if (i == tam-1) printf("\n");
    }
    printf("\nVetor mat:\n");
    for (int i=0; i<tam; i++)
    {
      printf("%d\n", mat[i]);
      if (i == tam-1) printf("\n");
    }
    printf("\nVetor nat:\n");
    for (int i=0; i<tam; i++)
    {
      printf("%d\n", nat[i]);
      if (i == tam-1) printf("\n");
    }
    printf("\nVetor hum:\n");
    for (int i=0; i<tam; i++)
    {
      printf("%d\n", hum[i]);
      if (i == tam-1) printf("\n");
    }
  }
}

//Função que adiciona nós numa lista encadeada do tipo fila
void addInscrito(Candidato *&listaI, Candidato *&listaF, Candidato candidato)
{
    Candidato *novo;
    novo = (Candidato*) calloc(1, sizeof(Candidato));
    novo->inscricao = candidato.inscricao;
    strcpy(novo->nome, candidato.nome);
    novo->dataNasc.dia = candidato.dataNasc.dia;
    novo->dataNasc.mes = candidato.dataNasc.mes;
    novo->dataNasc.ano = candidato.dataNasc.ano;
    strcpy(novo->tipoVaga, candidato.tipoVaga);
    novo->codigoCurso = candidato.codigoCurso;

    if (listaI == NULL)
    {
        listaI = listaF = novo;
    }
    else
    {
        listaF->prox = novo;
        listaF = novo;
    }
}
//Fim da função que adiciona na fila

//Função que carrega os candidatos
void carregaCandidato(Candidato *&listaCandidatosI , Candidato *&listaCandidatosF)
{
    FILE* arquivo;
    int codCurso, qtdInscritos;
    arquivo = fopen("../arquivos/dados.txt", "r");

    if (!arquivo)
    {
        printf("\nArquivo não pode ser aberto.\n");
    }
    else
    {
        do
        {
            fscanf(arquivo, "%d", &codCurso);
            fscanf(arquivo, "%d", &qtdInscritos);
            if (!feof(arquivo))
            {
                for (int i=0; i<qtdInscritos; i++)
                {
                    Candidato inscrito;
                    fscanf(arquivo, "%d", &inscrito.inscricao);
                    fscanf(arquivo, "%[^0-9]", inscrito.nome);
                    fscanf(arquivo, "%d/%d/%d", &inscrito.dataNasc.dia, &inscrito.dataNasc.mes, &inscrito.dataNasc.ano);
                    fscanf(arquivo, "%s", inscrito.tipoVaga);
                    inscrito.codigoCurso = codCurso;
                    addInscrito(listaCandidatosI, listaCandidatosF, inscrito);
                }
            }
        } while(!feof(arquivo));
    }
    fclose(arquivo);
}
//Fim do escopo que carrega candidatos

void adicionarCurso(Curso *&inicioListaCursos, Curso *&fimListaCursos, Curso curso)
{
    Curso *novoCurso = (Curso*) calloc(1, sizeof(Curso));
    novoCurso->codigo = curso.codigo;
    strcpy(novoCurso->nome, curso.nome);
    novoCurso->pesoRedacao = curso.pesoRedacao;
    novoCurso->pesoMatematica = curso.pesoMatematica;
    novoCurso->pesoLinguagens = curso.pesoLinguagens;
    novoCurso->pesoHumanas = curso.pesoHumanas;
    novoCurso->pesoNatureza = curso.pesoNatureza;

    if (inicioListaCursos == NULL)
    {
        inicioListaCursos = novoCurso;
        fimListaCursos = novoCurso;
    } else
    {
        fimListaCursos->proximo = novoCurso;
        fimListaCursos = novoCurso;
    }
}

void imprimirListaCursos(Curso *inicioListaCursos)
{
    Curso *ponteiro = inicioListaCursos;

    if (inicioListaCursos == NULL)
    {
        printf("\nLista de cursos vazia!\n");
        return;
    }

    while (ponteiro != NULL)
    {
        printf("Codigo: %d, Nome: %s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", ponteiro->codigo,
               ponteiro->nome, ponteiro->vagasAC, ponteiro->vagasL1, ponteiro->vagasL3, ponteiro->vagasL4,
               ponteiro->vagasL5, ponteiro->vagasL7, ponteiro->vagasL8, ponteiro->vagasL9, ponteiro->vagasL11,
               ponteiro->vagasL13, ponteiro->vagasL15);
        ponteiro = ponteiro->proximo;
    }
}

void atualizarVagasCursos(Curso *&inicioListaCursos, int codigoCurso, int ac, int l1, int l3, int l4, int l5, int l7,
                          int l8, int l9, int l11, int l13, int l15)
{
    Curso *ponteiro = inicioListaCursos;

    if (inicioListaCursos == NULL) return;

    while (ponteiro != NULL)
    {
        if (ponteiro->codigo == codigoCurso)
        {
            ponteiro->vagasAC = ac;
            ponteiro->vagasL1 = l1;
            ponteiro->vagasL3 = l3;
            ponteiro->vagasL4 = l4;
            ponteiro->vagasL5 = l5;
            ponteiro->vagasL7 = l7;
            ponteiro->vagasL8 = l8;
            ponteiro->vagasL9 = l9;
            ponteiro->vagasL11 = l11;
            ponteiro->vagasL13 = l13;
            ponteiro->vagasL15 = l15;
            break;
        }
        ponteiro = ponteiro->proximo;
    }
}

void carregarVagasCursos(Curso *&inicioListaCursos)
{
    FILE *arquivo;
    int quantidadeCursos, codigoCurso, ac, l1, l3, l4, l5, l7, l8, l9, l11, l13, l15, i;

    arquivo = fopen("../arquivos/cursos_e_vagas.txt", "r");

    if (!arquivo)
    {
        printf("\nArquivo de vagas de cursos não pôde ser aberto.\n");
        return;
    }

    fscanf(arquivo, "%d", &quantidadeCursos);
    do
    {
        fscanf(arquivo, "%d %d %d %d %d %d %d %d %d %d %d %d", &codigoCurso, &ac, &l1, &l3, &l4, &l5,
               &l7, &l8, &l9, &l11, &l13, &l15);
        atualizarVagasCursos(inicioListaCursos, codigoCurso, ac, l1, l3, l4, l5, l7, l8, l9, l11, l13, l15);
        i++;
    } while (i < quantidadeCursos);

    fclose(arquivo);
}

void carregarCursos(Curso *&inicioListaCursos, Curso *&fimListaCursos)
{
    FILE* arquivo;
    Curso curso;
    int quantidadeCursos = 0, i = 0;

    arquivo = fopen("../arquivos/cursos_e_pesos.txt", "r");

    if (!arquivo)
    {
        printf("\nArquivo de cursos não pôde ser aberto.\n");
        return;
    }

    fscanf(arquivo, "%d", &quantidadeCursos);
    do
    {
        fscanf(arquivo, "%d %[^0-9] %d %d %d %d %d", &curso.codigo, curso.nome, &curso.pesoRedacao,
               &curso.pesoMatematica, &curso.pesoLinguagens, &curso.pesoHumanas, &curso.pesoNatureza);
        adicionarCurso(inicioListaCursos, fimListaCursos, curso);
        i++;
    } while(i < quantidadeCursos);

    carregarVagasCursos(inicioListaCursos);
    fclose(arquivo);
}

//Função que calcula Escore Padronizado
float calcularEscorePadronizado(int qtdAcertos, float media, float desvioPadrao)
{
  float ep = 0.0;
  ep = (2*qtdAcertos) - media;
  ep = ep/desvioPadrao;
  ep = ep*100;
  return ep + 500;
}
//Fim da função que calcula Escore Padronizado

//Funcao que altera notas de redacao de um candidato
void alteraNotaRedacao(char nomeArquivo[], Acertos *&vetor, int tam)
{
  float notaAnterior = 0, novaNota = 0;
  int insc = 0;
  char caminhoArquivo[strlen("../arquivos/")+strlen(nomeArquivo)] = "../arquivos/";
  strncat(caminhoArquivo, nomeArquivo, strlen(nomeArquivo));
  FILE *arquivo = fopen(caminhoArquivo, "r");
  if (!arquivo)
  {
    printf("Arquivo nao pode ser aberto!\n");
  }
  else
  {
    while (!feof(arquivo))
    {
      fscanf(arquivo, "%d", &insc);
      fscanf(arquivo, "%f", &notaAnterior);
      fscanf(arquivo, "%f", &novaNota);
      for (int i=0; i<tam; i++)
      {
        if (vetor[i].inscricaoCandidato == insc)
        {
          vetor[i].red = novaNota;
          break;
        }
      }
    }
  }
}
//Fim da funcao que altera notas de redacao de um candidato

void showCandidato(Candidato *lista, int insc)
{
  bool achou = false;
  if (lista == NULL)
  {
    printf("Candidato não cadastrado!\n");
  }
  else
  {
    while(lista != NULL)
    {
      if (lista->inscricao == insc)
      {
        printf("Informações do candidato %d:\n", insc);
        printf("Inscrição: %d\n", insc);
        printf("Nome: %s\n", lista->nome);
        printf("Data de nascimento: %d/%d/%d\n", lista->dataNasc.dia, lista->dataNasc.mes, lista->dataNasc.ano);
        // printf("Curso desejado: %");
        achou = true;
        break;
      }
      lista = lista->prox;
    }
  }
  if (!achou)
    printf("Candidato não cadastrado!\n");
}

//Função que calcula média e desvio padrão
void calculaMediaDesvioPadrao(int *vetor, int tam, float &nMedia, float &nDesv)
{
  for(int i=0; i<tam; i++)
    nMedia = nMedia + vetor[i];
  nMedia = nMedia/tam;
  for(int i=0; i<tam; i++)
    nDesv = nDesv + pow(vetor[i] - nMedia, 2);
  nDesv = sqrt(nDesv/(tam-1));
}
//Fim da função que calcula média e desvio padrão

//Função que conta acertos dos candidatos
Acertos* carregaAcertosCandidatos(Candidato *&listaCandidatosI, Candidato *&listaCandidatosF,
float &mMat, float &dMat, float &mNat, float &dNat, float &mLin, float &dLin, float &mHum, float &dHum, int &qtd)
{
  FILE *arquivo;
  int inscCand, *acertosLin, *acertosMat, *acertosNat, *acertosHum;
  float acertosRed, media, desvioPadrao;
  Acertos *acertos = NULL;
  arquivo = fopen("../arquivos/acertos.txt", "r");
  if (!arquivo)
  {
    printf("Arquivo nao pode ser aberto.\n");
  }
  else
  {
    fscanf(arquivo, "%d", &qtd);
    acertos = (Acertos *) malloc(qtd * sizeof(Acertos));
    acertosLin = (int *) malloc(qtd * sizeof(int));
    acertosMat = (int *) malloc(qtd * sizeof(int));
    acertosNat = (int *) malloc(qtd * sizeof(int));
    acertosHum = (int *) malloc(qtd * sizeof(int));
    for (int i=0; i<qtd; i++)
      {
        fscanf(arquivo, "%d", &acertos[i].inscricaoCandidato);
        fscanf(arquivo, "%d", &acertos[i].lin);
        fscanf(arquivo, "%d", &acertos[i].mat);
        fscanf(arquivo, "%d", &acertos[i].nat);
        fscanf(arquivo, "%d", &acertos[i].hum);
        fscanf(arquivo, "%f", &acertos[i].red);
      }
    fclose(arquivo);
    arquivo = fopen("../arquivos/acertos.txt", "r");
    fscanf(arquivo, "%d", &qtd);
     for (int i=0; i<qtd; i++)
      {
        fscanf(arquivo, "%d", &inscCand);
        fscanf(arquivo, "%d", &acertosLin[i]);
        fscanf(arquivo, "%d", &acertosMat[i]);
        fscanf(arquivo, "%d", &acertosNat[i]);
        fscanf(arquivo, "%d", &acertosHum[i]);
        fscanf(arquivo, "%f", &acertosRed);
      }
    calculaMediaDesvioPadrao(acertosLin, qtd, mLin, dLin);
    calculaMediaDesvioPadrao(acertosMat, qtd, mMat, dMat);
    calculaMediaDesvioPadrao(acertosNat, qtd, mNat, dNat);
    calculaMediaDesvioPadrao(acertosHum, qtd, mHum, dHum);
    for (int i=0; i<qtd; i++)
      {
        acertos[i].epMat = calcularEscorePadronizado(acertos[i].mat, mMat, dMat);
        acertos[i].epNat = calcularEscorePadronizado(acertos[i].nat, mNat, dNat);
        acertos[i].epLin = calcularEscorePadronizado(acertos[i].lin, mLin, dLin);
        acertos[i].epHum = calcularEscorePadronizado(acertos[i].hum, mHum, dHum);
      }
    fclose(arquivo);
  }
  return acertos;
}
//Fim da função que conta acertos

//Função que imprime a lista
void imprimeLista(Candidato *lst)
{
    if (lst == NULL)
    {
        printf("Lista vazia! Nao ha o que imprimir.\n");
    }
    else
    {
    Candidato *p = lst;
      printf("\nConteúdo da lista:\n");
      do{
          printf("Insc cand: %d; Cod curso: %d; Data nasc: %d/%d/%d; Tipo vaga: %s; Nota Final: %.2f\n", p->inscricao, p->codigoCurso, p->dataNasc.dia, p->dataNasc.mes, p->dataNasc.ano, p->tipoVaga, p->notaFinal);
          if (p->prox == NULL) printf ("\n");
          p = p->prox;
      }while(p != NULL);
  }
}
//Fim da função que imprime a lista