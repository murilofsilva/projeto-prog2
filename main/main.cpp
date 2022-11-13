#include "interfaces.h"

int main() {
    Candidato *listaCandidatosI = NULL, *listaCandidatosF = NULL;
    Curso *inicioListaCursos = NULL, *fimListaCursos = NULL;
    int respostaMenu;
    bool firstExec = true;
    float mMat=0.0, dMat=0.0, mNat=0.0, dNat=0.0, mLin=0.0, dLin=0.0, mHum=0.0, dHum=0.0;
    float epLin=0.0, epMat=0.0, epNat=0.0, epHum=0.0;

//    Curso* listaCursos;

    do {
        respostaMenu = listaMenu(firstExec);

        if (firstExec && respostaMenu == 0) {
            carregaCandidato(listaCandidatosI, listaCandidatosF);
            carregaAcertosCandidatos(listaCandidatosI, listaCandidatosF, mMat, dMat, mNat, dNat, mLin, dLin, mHum, dHum);
            imprimeLista(listaCandidatosI);
            carregarCursos(inicioListaCursos, fimListaCursos);
            firstExec = false;
        } else if (!firstExec && respostaMenu == 0) {
            printf("Impossivel executar esta acao mais de uma vez! Por favor, digite uma opcao valida.\n");
        } else if (respostaMenu == 1) {
             //chamar função relacionada
        } else if (respostaMenu == 2) {
             //chamar função relacionada
        } else if (respostaMenu == 3) {
             //chamar função relacionada
        } else if (respostaMenu == 4) {
             //chamar função relacionada    
        } else if (respostaMenu != 5) {
            imprimeLista(listaCandidatosI);
            printf("Favor digitar uma opção válida.\n");
        }
    } while(respostaMenu != 5);

    return 0;
}