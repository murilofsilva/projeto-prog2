#include <stdio.h>
#include "structs.h"
#include "interfaces.h"

int listaMenu(bool firstExec);

int main() {
    int respostaMenu;
    bool firstExec = true;

    Curso* listaCursos;

    do {
        respostaMenu = listaMenu(firstExec);

        if (firstExec && respostaMenu == 0) {
            carregarArquivos(listaCursos);
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
            printf("Favor digitar uma opção válida.\n");
        }
    } while(respostaMenu != 5);

    return 0;
}

int listaMenu(bool firstExec) {
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