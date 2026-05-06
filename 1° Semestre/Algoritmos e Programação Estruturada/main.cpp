#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questions.h"
#include "Usuario.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ---------------- QUIZ ----------------
void jogar_quiz() {
    int total_perguntas = 5;
    int score = 0;

    for (int i = 0; i < total_perguntas; i++) {
        int idx = rand() % questions_count;
        Question q = questions[idx];

        printf("\n[Nivel %d]\n", q.nivel);
        printf("%s\n", q.pergunta);

        for (int j = 0; j < 4; j++) {
            printf("%d) %s\n", j, q.opcoes[j]);
        }

        int resposta;
        printf("Resposta: ");
        scanf("%d", &resposta);

        if (resposta == q.resposta_correta) {
            printf("? Correto!\n");
            score++;
        } else {
            printf("? Errado! Resposta correta: %s\n",
                   q.opcoes[q.resposta_correta]);
        }
    }

    printf("\nPontuação final: %d/%d\n", score, total_perguntas);

    // salvar usuário
    char nome[50];
    printf("Digite seu nome: ");
    scanf("%s", nome);

    criar_usuario(nome, (score >= 3 ? 2 : 1), score);
}

// ---------------- MENU ----------------
void menu() {
    printf("\n==== QUIZ MENU ====\n");
    printf("1. Jogar quiz\n");
    printf("2. Listar usuarios\n");
    printf("3. Buscar usuario por UUID\n");
    printf("4. Atualizar usuario\n");
    printf("5. Deletar usuario\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

// ---------------- MAIN ----------------
int main() {
    srand(time(NULL));

    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                jogar_quiz();
                break;

            case 2:
                listar_usuarios();
                break;

            case 3: {
                char uuid[37];
                Usuario u;

                printf("Digite UUID: ");
                scanf("%s", uuid);

                if (buscar_usuario(uuid, &u)) {
                    printf("Nome: %s | Nivel: %d | Pontos: %d\n",
                           u.nome, u.nivel, u.pontuacao);
                } else {
                    printf("Usuario nao encontrado.\n");
                }
                break;
            }

            case 4: {
                char uuid[37];
                int nivel, pontos;

                printf("UUID: ");
                scanf("%s", uuid);

                printf("Novo nivel: ");
                scanf("%d", &nivel);

                printf("Nova pontuacao: ");
                scanf("%d", &pontos);

                if (atualizar_usuario(uuid, nivel, pontos)) {
                    printf("Atualizado com sucesso!\n");
                } else {
                    printf("Erro ao atualizar.\n");
                }
                break;
            }

            case 5: {
                char uuid[37];

                printf("UUID: ");
                scanf("%s", uuid);

                if (deletar_usuario(uuid)) {
                    printf("Usuario deletado!\n");
                } else {
                    printf("Erro ao deletar.\n");
                }
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
