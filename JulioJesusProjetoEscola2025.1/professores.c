#include <stdio.h>
#include "professores.h"
#include "predefinicoes.h"

int menuProf() {
    int opcaoProf;
    printf("0 - Exit\t\n1 - Cadastrar professor\t\n2 - Listar professor\t\n3 - Atualizar professor\t\n4 - Excluir professor\t\n");
    scanf("%d", &opcaoProf);
    return opcaoProf;
}

int cadastrarProf(professor listaProf[], int qtdProf) {
    printf("Cadastrar Professor\n");
    if (qtdProf == tam_Prof) {
        return lista_Cheia;
    }

    int matriculaProf;
    printf("Digite a matricula: ");
    scanf("%d", &matriculaProf);

    if (matriculaProf < 0) {
        return matricula_invalida;
    }
    while (getchar() != '\n');
    listaProf[qtdProf].infoProf.matriculaProf = matriculaProf;
    listaProf[qtdProf].infoProf.ativoProf = 1;


    printf("o nome do Professor: ");
    fgets(listaProf[qtdProf].infoProf.nomeProf, 250, stdin);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &listaProf[qtdProf].infoProf.sexoProf);

    printf("Digite o dia de nascimento: ");
    scanf("%d", &listaProf[qtdProf].infoProf.dia_NascProf);

    printf("Digite o mes de nascimento: ");
    scanf("%d", &listaProf[qtdProf].infoProf.mes_NascProf);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &listaProf[qtdProf].infoProf.ano_NascProf);

    if (!validarData(listaProf[qtdProf].infoProf.dia_NascProf, listaProf[qtdProf].infoProf.mes_NascProf, listaProf[qtdProf].infoProf.ano_NascProf)) {
        printf("Data de nascimento invalida!\n");
        return matricula_invalida;
    }

    return CAD_Prof_sucesso;
}

void lista_de_Prof(professor listaProf[], int qtdProf) {
    printf("Listar Professor\n");
    if (qtdProf == 0) {
        printf("Lista de professores vazia\n");
    } else {
        for (int i = 0; i < qtdProf; i++) {
            if (listaProf[i].infoProf.ativoProf) {
                printf("Matricula: %d\n", listaProf[i].infoProf.nomeProf);
                printf("Matricula: %d\n", listaProf[i].infoProf.matriculaProf);
                printf("Sexo: %c\n", listaProf[i].infoProf.sexoProf);
                printf("Data de Nascimento: %02d/%02d/%04d\n", listaProf[i].infoProf.dia_NascProf, listaProf[i].infoProf.mes_NascProf, listaProf[i].infoProf.ano_NascProf);
                printf("-------------\n");
            }
        }
    }
}

int atualizarProf(professor listaProf[], int qtdProf) {
    printf("Atualizar Professor\n");
    printf("Digite a matricula: ");
    int matriculaProf;
    scanf("%d", &matriculaProf);

    if (matriculaProf < 0) {
        return matricula_invalida;
    }

    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].infoProf.matriculaProf == matriculaProf && listaProf[i].infoProf.ativoProf) {
            printf("Digite a nova matricula: ");
            int novaMatriculaProf;
            scanf("%d", &novaMatriculaProf);

            if (novaMatriculaProf < 0) {
                return matricula_invalida;
            }

            listaProf[i].infoProf.matriculaProf = novaMatriculaProf;
            return atualizacao_aluno_sucesso;
        }
    }

    return matricula_inexistente;
}

int excluir_Prof(professor listaProf[], int qtdProf) {
    printf("Excluir Professor\n");
    printf("Digite a matricula: ");
    int matriculaProf;
    scanf("%d", &matriculaProf);

    if (matriculaProf < 0) {
        return matricula_invalida;
    }

    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].infoProf.matriculaProf == matriculaProf && listaProf[i].infoProf.ativoProf) {
            listaProf[i].infoProf.ativoProf = 0;
            return exclusao_Prof;
        }
    }

    return matricula_inexistente;
}

void listarProfessoresPorSexo(professor listaProf[], int qtdProf, char sexo) {
    printf("Listar Professores por Sexo (%c)\n", sexo);
    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].infoProf.ativoProf && listaProf[i].infoProf.sexoProf == sexo) {
            printf("Matricula: %d\n", listaProf[i].infoProf.matriculaProf);
            printf("Nome: %s\n", listaProf[i].infoProf.nomeProf);
            printf("Sexo: %c\n", listaProf[i].infoProf.sexoProf);
            printf("Data de Nascimento: %02d/%02d/%04d\n", listaProf[i].infoProf.dia_NascProf, listaProf[i].infoProf.mes_NascProf, listaProf[i].infoProf.ano_NascProf);
            printf("-------------\n");
        }
    }
}

void listarProfessoresOrdenadosPorNome(professor listaProf[], int qtdProf) {
    printf("Listar Professores Ordenados por Nome\n");
    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            if (strcmp(listaProf[j].infoProf.nomeProf, listaProf[j + 1].infoProf.nomeProf) > 0) {
                professor temp = listaProf[j];
                listaProf[j] = listaProf[j + 1];
                listaProf[j + 1] = temp;
            }
        }
    }
    lista_de_Prof(listaProf, qtdProf);
}

void listarProfessoresOrdenadosPorDataNascimento(professor listaProf[], int qtdProf) {
    printf("Listar Professores Ordenados por Data de Nascimento\n");
    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            if (listaProf[j].infoProf.ano_NascProf > listaProf[j + 1].infoProf.ano_NascProf ||
                (listaProf[j].infoProf.ano_NascProf == listaProf[j + 1].infoProf.ano_NascProf && listaProf[j].infoProf.mes_NascProf > listaProf[j + 1].infoProf.mes_NascProf) ||
                (listaProf[j].infoProf.ano_NascProf == listaProf[j + 1].infoProf.ano_NascProf && listaProf[j].infoProf.mes_NascProf == listaProf[j + 1].infoProf.mes_NascProf && listaProf[j].infoProf.dia_NascProf > listaProf[j + 1].infoProf.dia_NascProf)) {
                professor temp = listaProf[j];
                listaProf[j] = listaProf[j + 1];
                listaProf[j + 1] = temp;
            }
        }
    }
    lista_de_Prof(listaProf, qtdProf);
}