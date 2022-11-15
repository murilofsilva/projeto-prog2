#include "interfaces.h"

int main() {
    Candidato *listaCandidatosI = NULL, *listaCandidatosF = NULL;
    Curso *inicioListaCursos = NULL, *fimListaCursos = NULL;
    Acertos *acertos;
    int respostaMenu, qtd=0, insc;
    bool firstExec = true;
    float mMat=0.0, dMat=0.0, mNat=0.0, dNat=0.0, mLin=0.0, dLin=0.0, mHum=0.0, dHum=0.0;
    float epLin=0.0, epMat=0.0, epNat=0.0, epHum=0.0;
    char arquivoAlteraNotasRedacao[150];

    do {
        respostaMenu = listaMenu(firstExec);

        switch(respostaMenu)
        {
            case 0:
                if (firstExec)
                {
                    carregaCandidato(listaCandidatosI, listaCandidatosF);
                    carregarCursos(inicioListaCursos, fimListaCursos);
                    acertos = carregaAcertosCandidatos(listaCandidatosI, listaCandidatosF, mMat, dMat, mNat, dNat, mLin, dLin, mHum, dHum, qtd);
                    firstExec = false;
                } else
                    printf("Impossivel executar esta acao mais de uma vez! Por favor, digite uma opcao valida.\n");
                break;
            case 1:
                //TODO item 1 para gerar arquivo ordenado
                gerarArquivoInformacoesGerais(inicioListaCursos, listaCandidatosI);
                break;
            case 2:
                printf("***VISUALIZAR CANDIDATO***\n");
                printf("Digite a inscricao do candidato que desejas visualizar: ");
                scanf("%d", &insc);
                showCandidato(listaCandidatosI, insc);
                break;
            case 3:
                //TODO item 3 para gerar arquivo com candidatos que nao foram aprovados
                break;
            case 4:
                printf("***ALTERAR NOTAS DE REDACAO***\n");
                printf("Informe o nome do arquivo que contem os dados para efetuar a troca: ");
                scanf("%s", arquivoAlteraNotasRedacao);
                printf("\n");
                alteraNotaRedacao(arquivoAlteraNotasRedacao, acertos, qtd);
                break;
            case 5:
                //TODO desalocar as listas
                printf("\nEncerrando aplicação\n");
                break;
            default:
                printf("Favor digitar uma opção válida.\n");
                break;
        }
    } while(respostaMenu != 5);

    return 0;
}