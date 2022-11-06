#include "structs.h"

//void carregarArquivos(Curso* listaCursos)
//{
//    carregarCursos(listaCursos);
//}
//
//void carregarCursos(Curso* listaCursos)
//{
//
//}

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
      printf("Insc: %d; Pontuacao lin: %d; Pontuacao mat: %d; Pontuacao nat: %d; Pontuacao hum: %d; Pontuacao red: %.2f\n", vetor[i].inscricaoCandidato, vetor[i].lin, vetor[i].mat, vetor[i].nat,vetor[i].hum, vetor[i].red);
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
    arquivo = fopen("../arquivos/muriloTest.txt", "r");

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

//Função que calcula nota final
// float calculaNotaFinal(int lin, int mat, int nat, int hum, float red, float &media, float &desvioPadrao)
// {
//   calculaMediaDesvioPadrao(media, desvioPadrao);
// }
//Fim da função que calcula nota final

//Função que conta acertos dos candidatos
void carregaAcertosCandidatos(Candidato *&listaCandidatosI, Candidato *&listaCandidatosF)
{
  FILE *arquivo;
  int inscCand, qtd, *acertosLin, *acertosMat, *acertosNat, *acertosHum;
  float acertosRed, media, desvioPadrao;
  Acertos *acertos;
  arquivo = fopen("../arquivos/muriloTestAcertos.txt", "r");
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
    arquivo = fopen("../arquivos/muriloTestAcertos.txt", "r");
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
    //A partir daqui estou fazendo um vinculo entre o candidato e seus acertos
    // arquivo = fopen("../arquivos/muriloTestAcertos.txt", "r");
    // fscanf(arquivo, "%d", &qtd);
    // do
    // {
    //   fscanf(arquivo, "%d", &inscCand);
    //   if (listaCandidatosI == NULL)
    //   {
    //     printf("Nao ha candidatos para receberem atribuicao de notas.\n");
    //   }
    //   else
    //   {
    //     Candidato *p = listaCandidatosI;
    //     do
    //     {
    //       if (p->inscricao == inscCand)
    //       {
    //         fscanf(arquivo, "%d", &acertosLin);
    //         fscanf(arquivo, "%d", &acertosMat);
    //         fscanf(arquivo, "%d", &acertosNat);
    //         fscanf(arquivo, "%d", &acertosHum);
    //         fscanf(arquivo, "%f", &acertosRed);
    //         // p->notaFinal = calculaNotaFinal(acertosLin, acertosMat, acertosNat, acertosHum, acertosRed, media, desvioPadrao);
    //       }
    //       p = p->prox;
    //     } while (p != NULL);
        
    //   }
    // } while (!feof(arquivo));
    fclose(arquivo);
    imprimeVetorAcertos(acertos, qtd);
    imprimeVetorMediaDP(acertosLin, acertosMat, acertosNat, acertosHum, qtd);
    // free(vetor);
  }
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