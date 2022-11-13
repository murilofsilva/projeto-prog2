#include <stdio.h>
#include "structs.h"
#include "interfaces.h"

int main() {
    Candidato *listaCandidatosI = NULL, *listaCandidatosF = NULL;
    Acertos *acertos;
    int respostaMenu, qtd=0, insc;
    bool firstExec = true;
    float mMat=0.0, dMat=0.0, mNat=0.0, dNat=0.0, mLin=0.0, dLin=0.0, mHum=0.0, dHum=0.0;
    float epLin=0.0, epMat=0.0, epNat=0.0, epHum=0.0;
    char arquivoAlteraNotasRedacao[150];

    do {
        respostaMenu = listaMenu(firstExec);

        if (firstExec && respostaMenu == 0) {
            carregaCandidato(listaCandidatosI, listaCandidatosF);
            acertos = carregaAcertosCandidatos(listaCandidatosI, listaCandidatosF, mMat, dMat, mNat, dNat, mLin, dLin, mHum, dHum, qtd);
            firstExec = false;
        } else if (!firstExec && respostaMenu == 0) {
            printf("Impossivel executar esta acao mais de uma vez! Por favor, digite uma opcao valida.\n");
        } else if (respostaMenu == 1) {
             //chamar função relacionada
        } else if (respostaMenu == 2) {
            printf("***VISUALIZAR CANDIDATO***\n");
            printf("Digite a inscricao do candidato que desejas visualizar: ");
            scanf("%d", &insc);
            showCandidato(listaCandidatosI, insc);
        } else if (respostaMenu == 3) {
             //chamar função relacionada
        } else if (respostaMenu == 4) {
            printf("***ALTERAR NOTAS DE REDACAO***\n");
            printf("Informe o nome do arquivo que contem os dados para efetuar a troca: ");
            scanf("%s", arquivoAlteraNotasRedacao);
            printf("\n");
            alteraNotaRedacao(arquivoAlteraNotasRedacao, acertos, qtd);  
        } else if (respostaMenu != 5) {
            printf("Favor digitar uma opção válida.\n");
        }
    } while(respostaMenu != 5);

    return 0;
}