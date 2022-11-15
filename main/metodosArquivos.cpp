#include "structs.h"
#include "ordenacao.h"

void adicionarCandidatoCurso(Candidato candidato, Candidato *&listaInicio, Candidato *&listaFim)
{
    Candidato *novoCandidato = (Candidato*) calloc(1, sizeof(Candidato));
    novoCandidato->inscricao = candidato.inscricao;
    strcpy(novoCandidato->tipoVaga, candidato.tipoVaga);
    novoCandidato->notaFinal = candidato.notaFinal;
    novoCandidato->prox = NULL;

    if (listaInicio == NULL)
    {
        listaInicio = novoCandidato;
        listaFim = novoCandidato;
        return;
    }

    listaFim->prox = novoCandidato;
    listaFim = novoCandidato;
}

Candidato* obterCandidatosDoCurso(Candidato *lista, int codigoCurso, int &quantidadeCandidatosCurso)
{
    Candidato *candidatosCursoInicio = NULL, *candidatosCursoFim = NULL, *ponteiro = lista;
    
    while (ponteiro != NULL)
    {
        if (ponteiro->codigoCurso == codigoCurso)
        {
            adicionarCandidatoCurso(*ponteiro, candidatosCursoInicio, candidatosCursoFim);
            quantidadeCandidatosCurso++;
        }

        ponteiro = ponteiro->prox;
    }

    return candidatosCursoInicio;
}

Candidato* criarVetorCandidato(Candidato *lista, int tamanhoLista)
{
    Candidato *vetor = (Candidato*) calloc(tamanhoLista, sizeof(Candidato));
    for (int i = 0; i < tamanhoLista; i++)
    {
        vetor[i] = *lista;
        lista = lista->prox;
    }
    return vetor;
}

void gerarArquivoFinal(Curso **cursosOrdenados, int quantidadeCursos, Candidato *listaCadidatos)
{
    FILE *arquivo;
    arquivo = fopen("teste.txt", "w+");
    
    if (!arquivo)
    {
        printf("Arquivo final nao pode ser aberto para gravacao!\n");
        return;
    }

    int i = 0;
    while (i < quantidadeCursos)
    {
        int quantidadeCandidatosCurso = 0;
        Candidato *candidatosCurso = obterCandidatosDoCurso(listaCadidatos, cursosOrdenados[i]->codigo, quantidadeCandidatosCurso);

        fprintf(arquivo, "%s | Quantidade de candidatos do curso: %d\n", cursosOrdenados[i]->nome, quantidadeCandidatosCurso);
        fprintf(arquivo, "INSC	V_LIN	V_MAT	V_NAT	V_HUM	RED	COTA	NOTA FINAL	CLASSIFICAÇÃO\n");

        Candidato *vetorCandidatos = criarVetorCandidato(candidatosCurso, quantidadeCandidatosCurso),
                  **vetorCandidatosOrdenados = (Candidato**) calloc(quantidadeCandidatosCurso, sizeof(Candidato**));
        for (int candidato = 0; candidato < quantidadeCandidatosCurso; candidato++)
            vetorCandidatosOrdenados[candidato] = vetorCandidatos + candidato;

        // ordenarCandidatosPorCota(0, quantidadeCandidatosCurso - 1, vetorCandidatosOrdenados);
        // ordenarCandidatosPorNota(0, quantidadeCandidatosCurso, vetorCandidatosOrdenados);

        Candidato *candidato = listaCadidatos;
        if (candidato != NULL)
        {
            do
            {
                for (int i = 0; i < quantidadeCandidatosCurso; i++)
                {
                    if (vetorCandidatosOrdenados[i]->inscricao == candidato->inscricao)
                        vetorCandidatosOrdenados[i]->inscricao = candidato->inscricao;
                }
                candidato = candidato->prox;
            } while (candidato != NULL && candidato->prox != NULL);
            
        }

        for (int candidato = 0; candidato < quantidadeCandidatosCurso; candidato++)
            fprintf(arquivo, "%d %f %f %f %f %f %s %.2f\n", vetorCandidatosOrdenados[candidato]->inscricao,
                    vetorCandidatosOrdenados[candidato]->escoreLin, vetorCandidatosOrdenados[candidato]->escoreMat,
                    vetorCandidatosOrdenados[candidato]->escoreNat, vetorCandidatosOrdenados[candidato]->escoreHum,
                    vetorCandidatosOrdenados[candidato]->escoreRed, vetorCandidatosOrdenados[candidato]->tipoVaga,
                    vetorCandidatosOrdenados[candidato]->notaFinal);
        i++;
    }

    fclose(arquivo);
}