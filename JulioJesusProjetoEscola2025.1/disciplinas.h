#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <stdbool.h>
#include <string.h>

#define tam_Prof 3
#define tam_nome 255
#define CAD_Aluno_sucesso -1
#define disciplina_invalida -9
#define disciplina_inexistente -10
#define atualizacao_Disc_sucesso -11
#define exclusao_Disc -12

typedef struct disciplina {
    char nome[tam_nome];
    int semestre;
    int professor;
    int codigo;
    int ativo;
} Disc;

int menuDisciplina();
int cadastrar_disciplina(Disc listaDisc[], int qtdDisc, int qtdProf);
void listarDisc(Disc listaDisc[], int qtdDisc);
int atualizarDisc(Disc listaDisc[], int qtdDisc);
int excluir_disciplina(Disc listaDisc[], int qtdDisc);

#endif