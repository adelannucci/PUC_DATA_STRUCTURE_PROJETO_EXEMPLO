#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

#include "basico.c"

typedef struct aluno
{
	int ra;
	int cp;
	
	char nome[MAX];
	char curso[MAX];
	char telefone[MAX];
	char email[MAX];
	
	time_t time_matricula;
	time_t time_espera;
}aluno;

aluno novo_aluno();

#endif // ALUNO_H_INCLUDED
