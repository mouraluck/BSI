#ifndef QUESTIONS_H
#define QUESTIONS_H

#define MAX_OPTIONS 4
#define MAX_TEXT 256

typedef struct {
    int nivel;
    char pergunta[MAX_TEXT];
    char opcoes[MAX_OPTIONS][MAX_TEXT];
    int resposta_correta;
} Question;

extern Question questions[];
extern int questions_count;

#endif
