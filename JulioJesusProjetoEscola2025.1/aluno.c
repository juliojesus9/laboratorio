#include <stdio.h>
#include "aluno.h"
#include "predefinicoes.h"

int menuAluno() {
    int opcaoAluno;
    printf("0 - Exit\t\n1 - Cadastrar Aluno\t\n2 - Listar Aluno\t\n3 - Atualizar Aluno\t\n4 - Excluir Aluno\t\n");
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}
void listarAlunosPorSexo(Aluno listaAluno[], int qtdAluno, char sexo);
void listarAlunosOrdenadosPorNome(Aluno listaAluno[], int qtdAluno);
void listarAlunosOrdenadosPorDataNascimento(Aluno listaAluno[], int qtdAluno);
int cadastrarAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Cadastrar Aluno\n");
    if (qtdAluno == tam_aluno) {
        return lista_Cheia;
    }

    int matricula;
    printf("Digite a matricula: ");
    scanf("%d", &matricula);

    if (matricula < 0) {
        return matricula_invalida;
    }

    listaAluno[qtdAluno].info.matricula = matricula;
    listaAluno[qtdAluno].info.ativo = 1;


    while (getchar() != '\n');

    listaAluno[qtdAluno].info.matricula = matricula;
    listaAluno[qtdAluno].info.ativo = 1;

    printf("O nome do aluno: ");
    fgets(listaAluno[qtdAluno].info.nome, 250, stdin);


    printf("Digite o sexo (M/F): ");
    scanf(" %c", &listaAluno[qtdAluno].info.sexoAluno);

    printf("Digite o dia de nascimento: ");
    scanf("%d", &listaAluno[qtdAluno].info.dia_Nasc);

    printf("Digite o mes de nascimento: ");
    scanf("%d", &listaAluno[qtdAluno].info.mes_Nasc);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &listaAluno[qtdAluno].info.ano_Nasc);

    if (!validarData(listaAluno[qtdAluno].info.dia_Nasc, listaAluno[qtdAluno].info.mes_Nasc, listaAluno[qtdAluno].info.ano_Nasc)) {
        printf("Data de nascimento invalida!\n");
        return matricula_invalida;
    }

    return CAD_Aluno_sucesso;
}

void listar(Aluno listaAluno[], int qtdAluno) {
    printf("Listar Aluno\n");
    if (qtdAluno == 0) {
        printf("Lista de alunos vazia\n");
    } else {
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].info.ativo) {
                printf("Matricula: %d\n", listaAluno[i].info.matricula);
                printf("Nome: %s\n", listaAluno[i].info.nome);
                printf("Sexo: %c\n", listaAluno[i].info.sexoAluno);
                printf("Data de Nascimento: %02d/%02d/%04d\n", listaAluno[i].info.dia_Nasc, listaAluno[i].info.mes_Nasc, listaAluno[i].info.ano_Nasc);
                printf("-------------\n");
            }
        }
    }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Atualizar Aluno\n");
    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0) {
        return matricula_invalida;
    }

    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].info.matricula == matricula && listaAluno[i].info.ativo) {
            printf("Digite a nova matricula: ");
            int novaMatricula;
            scanf("%d", &novaMatricula);

            if (novaMatricula < 0) {
                return matricula_invalida;
            }

            listaAluno[i].info.matricula = novaMatricula;
            return atualizacao_aluno_sucesso;
        }
    }

    return matricula_inexistente;
}

int excluir_Aluno(Aluno listaAluno[], int qtdAluno) {
    printf("Excluir Aluno\n");
    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0) {
        return matricula_invalida;
    }

    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].info.matricula == matricula && listaAluno[i].info.ativo) {
            listaAluno[i].info.ativo = 0;
            return exclusao_Aluno;
        }
    }

    return matricula_inexistente;
}

void listarAlunosPorSexo(Aluno listaAluno[], int qtdAluno, char sexo) {
    printf("Listar Alunos por Sexo (%c)\n", sexo);
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].info.ativo && listaAluno[i].info.sexoAluno == sexo) {
            printf("Matricula: %d\n", listaAluno[i].info.matricula);
            printf("Nome: %s\n", listaAluno[i].info.nome);
            printf("Sexo: %c\n", listaAluno[i].info.sexoAluno);
            printf("Data de Nascimento: %02d/%02d/%04d\n", listaAluno[i].info.dia_Nasc, listaAluno[i].info.mes_Nasc, listaAluno[i].info.ano_Nasc);
            printf("-------------\n");
        }
    }
}

void listarAlunosOrdenadosPorNome(Aluno listaAluno[], int qtdAluno) {
    printf("Listar Alunos Ordenados por Nome\n");
    for (int i = 0; i < qtdAluno - 1; i++) {
        for (int j = 0; j < qtdAluno - i - 1; j++) {
            if (strcmp(listaAluno[j].info.nome, listaAluno[j + 1].info.nome) > 0) {
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
    listar(listaAluno, qtdAluno);
}

void listarAlunosOrdenadosPorDataNascimento(Aluno listaAluno[], int qtdAluno) {
    printf("Listar Alunos Ordenados por Data de Nascimento\n");
    for (int i = 0; i < qtdAluno - 1; i++) {
        for (int j = 0; j < qtdAluno - i - 1; j++) {
            if (listaAluno[j].info.ano_Nasc > listaAluno[j + 1].info.ano_Nasc ||
                (listaAluno[j].info.ano_Nasc == listaAluno[j + 1].info.ano_Nasc && listaAluno[j].info.mes_Nasc > listaAluno[j + 1].info.mes_Nasc) ||
                (listaAluno[j].info.ano_Nasc == listaAluno[j + 1].info.ano_Nasc && listaAluno[j].info.mes_Nasc == listaAluno[j + 1].info.mes_Nasc && listaAluno[j].info.dia_Nasc > listaAluno[j + 1].info.dia_Nasc)) {
                Aluno temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
    listar(listaAluno, qtdAluno);
}

