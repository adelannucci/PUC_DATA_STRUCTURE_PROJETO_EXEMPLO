#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "lista.c"

typedef struct curso
{
    char nome[MAX];
    int vagas;
    lista* matriculados;
	lista* fila_espera;
}curso;

curso* novo_curso();

#endif// CURSO_H_INCLUDED