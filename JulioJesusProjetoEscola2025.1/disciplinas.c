#include <stdio.h>
#include "disciplinas.h"
#define lista_Cheia -13
int menuDisciplina() {
    int opcaoDisc;
    printf("0 - Exit\t\n1 - Cadastrar disciplina\t\n2 - Listar disciplina\t\n3 - Atualizar disciplina\t\n4 - Excluir disciplina\t\n");
    scanf("%d", &opcaoDisc);
    return opcaoDisc;
}

int cadastrar_disciplina(Disc listaDisc[], int qtdDisc, int qtdProf) {
    printf("Cadastrar Disciplina\n");
    if (qtdDisc == tam_Prof) {
        return lista_Cheia;
    }

    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", listaDisc[qtdDisc].nome);

    printf("Digite o codigo da disciplina: ");
    int codigo;
    scanf("%d", &codigo);

    if (codigo < 0) {
        return disciplina_invalida;
    }

    printf("Digite o semestre: ");
    scanf("%d", &listaDisc[qtdDisc].semestre);

    printf("Digite o codigo do professor: ");
    int professor;
    scanf("%d", &professor);

    if (professor < 0 || professor >= qtdProf) {
        return disciplina_invalida;
    }

    listaDisc[qtdDisc].codigo = codigo;
    listaDisc[qtdDisc].professor = professor;
    listaDisc[qtdDisc].ativo = 1;

    return CAD_Aluno_sucesso;
}

void listarDisc(Disc listaDisc[], int qtdDisc) {
    printf("Listar Disciplinas\n");
    if (qtdDisc == 0) {
        printf("Lista de disciplinas vazia\n");
    } else {
        for (int i = 0; i < qtdDisc; i++) {
            if (listaDisc[i].ativo) {
                printf("Nome: %s\n", listaDisc[i].nome);
                printf("Codigo: %d\n", listaDisc[i].codigo);
                printf("Semestre: %d\n", listaDisc[i].semestre);
                printf("Professor: %d\n", listaDisc[i].professor);
                printf("-------------\n");
            }
        }
    }
}

int atualizarDisc(Disc listaDisc[], int qtdDisc) {
    printf("Atualizar Disciplina\n");
    printf("Digite o codigo da disciplina: ");
    int codigo;
    scanf("%d", &codigo);

    if (codigo < 0) {
        return disciplina_invalida;
    }

    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigo && listaDisc[i].ativo) {
            printf("Digite o novo nome da disciplina: ");
            scanf(" %[^\n]", listaDisc[i].nome);

            printf("Digite o novo semestre: ");
            scanf("%d", &listaDisc[i].semestre);

            printf("Digite o novo codigo do professor: ");
            scanf("%d", &listaDisc[i].professor);

            return atualizacao_Disc_sucesso;
        }
    }

    return disciplina_inexistente;
}

int excluir_disciplina(Disc listaDisc[], int qtdDisc) {
    printf("Excluir Disciplina\n");
    printf("Digite o codigo da disciplina: ");
    int codigo;
    scanf("%d", &codigo);

    if (codigo < 0) {
        return disciplina_invalida;
    }

    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigo && listaDisc[i].ativo) {
            listaDisc[i].ativo = 0;
            return exclusao_Disc;
        }
    }

    return disciplina_inexistente;
}