#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "aluno.c"

#define MATRICULADOS 1
#define ESPERA 2

typedef struct nodo_aluno
{
	aluno dados;
	struct nodo_aluno* prox;
}no;

typedef struct lista
{
	int tamanho;
	no* raiz;
}lista;

lista* cria_lista();
no* novo_no(aluno a);
void inserir_inicio(lista* l, aluno a);
void inserir_fim(lista* l, aluno a);
int inserir_ordenado(lista* l, aluno a);
aluno remover(lista* l, int ra);
aluno remover_inicio(lista* l);
void listar_(no* n, int tipo);
void listar_matriculados(lista* l);
void listar_espera(lista* l);


#endif // LISTA_H_INCLUDED
