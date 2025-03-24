#ifndef ALUNO_H
#define ALUNO_H

#include <stdbool.h>
#include <string.h>

#define tam_aluno 5
#define tam_nome 255
#define CAD_Aluno_sucesso -1
#define matricula_invalida -2
#define lista_Cheia -3
#define atualizacao_aluno_sucesso -4
#define matricula_inexistente -5
#define exclusao_Aluno -6

typedef struct data {
    int dia_Nasc;
    int mes_Nasc;
    int ano_Nasc;
    int matricula;
    char sexoAluno;
    int ativo;
    char nome[tam_nome];
} dados;

typedef struct alu {
    dados info;
} Aluno;

int menuAluno();
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listar(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluir_Aluno(Aluno listaAluno[], int qtdAluno);
void listarAlunosPorSexo(Aluno listaAluno[], int qtdAluno, char sexoAluno);
void listarAlunosOrdenadosPorNome(Aluno listaAluno[], int qtdAluno);
void listarAlunosOrdenadosPorDataNascimento(Aluno listaAluno[], int qtdAluno);
#endif