#include <stdio.h>
#include "aluno.h"
#include "professores.h"
#include "disciplinas.h"
#include "predefinicoes.h"

int main(void) {
    int opcao, qtdAluno = 0, qtdProf = 0, qtdDisc = 0, sair = 0;
    char sexo;
    Aluno listaAluno[tam_aluno];
    professor listaProf[tam_Prof];
    Disc listaDisc[tam_Prof];

    while (!sair) {
        opcao = menuGeral();

        switch (opcao) {
            case 0:
                sair = 1;
                break;

            case 1:
                printf("Modulo aluno\n");
                int sairAluno = 0;
                int opcaoAluno;
                while (!sairAluno) {
                    opcaoAluno = menuAluno();
                    switch (opcaoAluno) {
                        case 0:
                            sairAluno = 1;
                            break;

                        case 1: {
                            int retorno = cadastrarAluno(listaAluno, qtdAluno);
                            if (retorno == lista_Cheia) {
                                printf("Lista cheia\n");
                            } else if (retorno == matricula_invalida) {
                                printf("Matricula invalida\n");
                            } else {
                                printf("Cadastrado com sucesso\n");
                                qtdAluno++;
                            }
                            break;
                        }

                        case 2: {
                            listar(listaAluno, qtdAluno);
                            char opcaolistar;
                            printf("Pressione 'e' para escolher como listar os alunos ou 'v' para voltar: ");
                            scanf(" %c", &opcaolistar);
                            int sairLista = 0;
                            if (opcaolistar == 'e') {
                                
                                char opcaoLista;
                                while (!sairLista) {
                                    printf("\nE - Para sair\nS - Lista por sexo\nN - Lista por nome\nD - Lista por data de nascimento\n");
                                    printf("Escolha uma opcao: ");
                                    scanf(" %c", &opcaoLista);

                                    switch (opcaoLista) {
                                        case 'E':
                                        case 'e':
                                            sairLista = 1;
                                            break;
                                        case 'S':
                                        case 's': {
                                            char sexo;
                                            printf("Digite o sexo (M/F): ");
                                            scanf(" %c", &sexo);
                                            listarAlunosPorSexo(listaAluno, qtdAluno, sexo);
                                            break;
                                        }
                                        case 'N':
                                        case 'n':
                                            listarAlunosOrdenadosPorNome(listaAluno, qtdAluno);
                                            break;
                                        case 'D':
                                        case 'd':
                                            listarAlunosOrdenadosPorDataNascimento(listaAluno, qtdAluno);
                                            break;
                                        default:
                                            printf("Opcao invalida!\n");
                                            break;
                                    }
                                }
                            } else {
                                sairLista=1;
                            }
                            break;
                        }

                        case 3: {
                            int retorno = atualizarAluno(listaAluno, qtdAluno);
                            if (retorno == matricula_invalida) {
                                printf("Matricula invalida\n");
                            } else if (retorno == matricula_inexistente) {
                                printf("Matricula inexistente\n");
                            } else if (retorno == atualizacao_aluno_sucesso) {
                                printf("Aluno atualizado com sucesso\n");
                            }
                            break;
                        }

                        case 4: {
                            int retorno = excluir_Aluno(listaAluno, qtdAluno);
                            if (retorno == matricula_invalida) {
                                printf("Matricula invalida\n");
                            } else if (retorno == matricula_inexistente) {
                                printf("Matricula inexistente\n");
                            } else if (retorno == exclusao_Aluno) {
                                printf("Aluno excluido com sucesso\n");
                                qtdAluno--;
                            }
                            break;
                        }

                        default:
                            printf("Escolha invalida\n");
                            break;
                    }
                }
                break;

            case 2:
                printf("Modulo professor\n");
                int sairProf = 0;
                int opcaoProf;
                while (!sairProf) {
                    opcaoProf = menuProf();
                    switch (opcaoProf) {
                        case 0:
                            sairProf = 1;
                            break;

                        case 1: {
                            int retornoProf = cadastrarProf(listaProf, qtdProf);
                            if (retornoProf == lista_Cheia) {
                                printf("Lista cheia\n");
                            } else if (retornoProf == matricula_invalida) {
                                printf("Matricula invalida\n");
                            } else {
                                printf("Cadastrado com sucesso\n");
                                qtdProf++;
                            }
                            break;
                        }

                        case 2:
                            lista_de_Prof(listaProf, qtdProf);
                            break;

                        case 3: {
                            int retornoProf = atualizarProf(listaProf, qtdProf);
                            if (retornoProf == matricula_invalida) {
                                printf("Matricula invalida\n");
                            } else if (retornoProf == matricula_inexistente) {
                                printf("Matricula inexistente\n");
                            } else if (retornoProf == atualizacao_aluno_sucesso) {
                                printf("Professor atualizado com sucesso\n");
                            }
                            break;
                        }

                        case 4: {
                            int retornoProf = excluir_Prof(listaProf, qtdProf);
                            if (retornoProf == matricula_invalida) {
                                printf("Matricula invalida\n");
                            } else if (retornoProf == matricula_inexistente) {
                                printf("Matricula inexistente\n");
                            } else if (retornoProf == exclusao_Prof) {
                                printf("Professor excluido com sucesso\n");
                                qtdProf--;
                            }
                            break;
                        }

                        default:
                            printf("Escolha invalida\n");
                            break;
                    }
                }
                break;

            case 3:
                printf("Modulo disciplina\n");
                int sairDisc = 0;
                int opcaoDisc;
                while (!sairDisc) {
                    opcaoDisc = menuDisciplina();
                    switch (opcaoDisc) {
                        case 0:
                            sairDisc = 1;
                            break;

                        case 1: {
                            int retornoDisc = cadastrar_disciplina(listaDisc, qtdDisc, qtdProf);
                            if (retornoDisc == lista_Cheia) {
                                printf("Lista cheia\n");
                            } else if (retornoDisc == disciplina_invalida) {
                                printf("Codigo invalido\n");
                            } else {
                                printf("Cadastrado com sucesso\n");
                                qtdDisc++;
                            }
                            break;
                        }

                        case 2:
                            listarDisc(listaDisc, qtdDisc);
                            break;

                        case 3: {
                            int retornoDisc = atualizarDisc(listaDisc, qtdDisc);
                            if (retornoDisc == disciplina_invalida) {
                                printf("Codigo invalido\n");
                            } else if (retornoDisc == disciplina_inexistente) {
                                printf("Disciplina inexistente\n");
                            } else if (retornoDisc == atualizacao_Disc_sucesso) {
                                printf("Disciplina atualizada com sucesso\n");
                            }
                            break;
                        }

                        case 4: {
                            int retornoDisc = excluir_disciplina(listaDisc, qtdDisc);
                            if (retornoDisc == disciplina_invalida) {
                                printf("Codigo invalido\n");
                            } else if (retornoDisc == disciplina_inexistente) {
                                printf("Disciplina inexistente\n");
                            } else if (retornoDisc == exclusao_Disc) {
                                printf("Disciplina excluida com sucesso\n");
                                qtdDisc--;
                            }
                            break;
                        }

                        default:
                            printf("Escolha invalida\n");
                            break;
                    }
                }
                break;

            default:
                printf("Escolha invalida\n");
                break;
        }
    }

    return 0;
}