#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARQUIVO_USUARIOS "usuarios.dat"

typedef struct {
    char uuid[37];      // formato: xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
    char nome[50];
    int nivel;
    int pontuacao;
    int ativo;          // 1 = ativo | 0 = deletado
} Usuario;


// ---------------- UUID SIMPLES ----------------
void gerar_uuid(char *uuid) {
    const char *chars = "abcdef0123456789";
    int i;

    for (i = 0; i < 36; i++) {
        if (i == 8 || i == 13 || i == 18 || i == 23) {
            uuid[i] = '-';
        } else {
            uuid[i] = chars[rand() % 16];
        }
    }
    uuid[36] = '\0';
}


// ---------------- CREATE ----------------
void criar_usuario(const char *nome, int nivel, int pontuacao) {
    FILE *file = fopen(ARQUIVO_USUARIOS, "ab");
    if (!file) return;

    Usuario u;
    gerar_uuid(u.uuid);
    strcpy(u.nome, nome);
    u.nivel = nivel;
    u.pontuacao = pontuacao;
    u.ativo = 1;

    fwrite(&u, sizeof(Usuario), 1, file);
    fclose(file);

    printf("Usuario criado! UUID: %s\n", u.uuid);
}


// ---------------- READ ALL ----------------
void listar_usuarios() {
    FILE *file = fopen(ARQUIVO_USUARIOS, "rb");
    if (!file) return;

    Usuario u;

    while (fread(&u, sizeof(Usuario), 1, file)) {
        if (u.ativo) {
            printf("UUID: %s | Nome: %s | Nivel: %d | Pontos: %d\n",
                   u.uuid, u.nome, u.nivel, u.pontuacao);
        }
    }

    fclose(file);
}


// ---------------- READ BY UUID ----------------
int buscar_usuario(const char *uuid, Usuario *resultado) {
    FILE *file = fopen(ARQUIVO_USUARIOS, "rb");
    if (!file) return 0;

    Usuario u;

    while (fread(&u, sizeof(Usuario), 1, file)) {
        if (u.ativo && strcmp(u.uuid, uuid) == 0) {
            *resultado = u;
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


// ---------------- UPDATE ----------------
int atualizar_usuario(const char *uuid, int novo_nivel, int nova_pontuacao) {
    FILE *file = fopen(ARQUIVO_USUARIOS, "rb+");
    if (!file) return 0;

    Usuario u;

    while (fread(&u, sizeof(Usuario), 1, file)) {
        if (u.ativo && strcmp(u.uuid, uuid) == 0) {
            u.nivel = novo_nivel;
            u.pontuacao = nova_pontuacao;

			fseek(file, ftell(file) - (long)sizeof(Usuario), SEEK_SET);
            fwrite(&u, sizeof(Usuario), 1, file);

            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


// ---------------- DELETE (lógico) ----------------
int deletar_usuario(const char *uuid) {
    FILE *file = fopen(ARQUIVO_USUARIOS, "rb+");
    if (!file) return 0;

    Usuario u;

    while (fread(&u, sizeof(Usuario), 1, file)) {
        if (u.ativo && strcmp(u.uuid, uuid) == 0) {
            u.ativo = 0;

			fseek(file, ftell(file) - (long)sizeof(Usuario), SEEK_SET);
            fwrite(&u, sizeof(Usuario), 1, file);

            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

#endif
