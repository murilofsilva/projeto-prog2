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
        do{
            p->prox != NULL ? printf("%s, ", p->nome) : printf("%s\n", p->nome);
            p = p->prox;
        }while(p != NULL);
    }
}
//Fim da função que imprime a lista