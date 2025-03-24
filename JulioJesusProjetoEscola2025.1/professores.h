#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdbool.h>
#include <string.h>

#define tam_Prof 3
#define tam_nome 255
#define CAD_Prof_sucesso -7
#define matricula_invalida -2
#define lista_Cheia -3
#define atualizacao_aluno_sucesso -4
#define matricula_inexistente -5
#define exclusao_Prof -8

typedef struct dataProf {
    int dia_NascProf;
    int mes_NascProf;
    int ano_NascProf;
    int matriculaProf;
    char sexoProf;
    int ativoProf;
    char nomeProf[tam_nome];
} dadosProf;

typedef struct prof {
    dadosProf infoProf;
} professor;

int menuProf();
int cadastrarProf(professor listaProf[], int qtdProf);
void lista_de_Prof(professor listaProf[], int qtdProf);
int atualizarProf(professor listaProf[], int qtdProf);
int excluir_Prof(professor listaProf[], int qtdProf);
void listarProfessoresPorSexo(professor listaProf[], int qtdProf, char sexo);
void listarProfessoresOrdenadosPorNome(professor listaProf[], int qtdProf);
void listarProfessoresOrdenadosPorDataNascimento(professor listaProf[], int qtdProf);

#endif