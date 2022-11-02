#include <stdio.h>
#include "structs.h"
#include "interfaces.h"

int main() {
    Candidato *listaCandidatosI = NULL, *listaCandidatosF = NULL;
    int respostaMenu;
    bool firstExec = true;

//    Curso* listaCursos;

    do {
        respostaMenu = listaMenu(firstExec);

        if (firstExec && respostaMenu == 0) {
            carregaCandidato(listaCandidatosI, listaCandidatosF);
            imprimeLista(listaCandidatosI);
//            carregarArquivos(listaCursos);
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