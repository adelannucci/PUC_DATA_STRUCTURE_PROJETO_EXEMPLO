#include "lista.h"

lista* cria_lista()
{
	lista *nova_lista;
	
	nova_lista = (lista*) malloc(sizeof(lista));
	
	if(nova_lista == NULL) 
	    exit(0);
	
	nova_lista->tamanho = 0;
	nova_lista->raiz = NULL;
	
	return (nova_lista);
	}

no* novo_no(aluno a)
{
	no* novo;
	novo = (no*)malloc(sizeof(no));
	
	if(novo == NULL)
		exit(0);
	
	novo->dados = a;
	novo->prox = NULL;
	
	return (novo);
}

void inserir_inicio(lista* l, aluno a)
{
	no* aux;
	no* novo;
	
	aux = l->raiz;
	novo = novo_no(a);
	
	l->raiz = novo;
	novo->prox = aux;
	l->tamanho++;
}

void inserir_fim(lista* l, aluno a)
{
	no* aux;
	no* novo;
	
	aux = l->raiz;
	novo = novo_no(a);
	
	if(aux == NULL)
	{
		l->raiz = novo;
	}
	else
	{
	
		while(aux->prox != NULL)
		{
		    aux = aux->prox;
		}
		aux->prox = novo;
	}
	l->tamanho++;
}

int inserir_ordenado(lista* l, aluno a)
{
	no* novo = novo_no(a);
	no* atual = l->raiz;
	no* anterior = NULL;
	int saida = 0;

	/*procura posicao para insercao*/
	while(atual != NULL && ( novo->dados.ra >= atual->dados.ra ))
    	{
		//nao add 2 ra's iguais
		if( novo->dados.ra == atual->dados.ra)
		{
			saida = -1;
			return saida;
		}
		
		anterior = atual;
		atual = atual->prox;
	}

	if(l->raiz == NULL)//lista vazia
	{
		l->raiz = novo;
		saida = 1;
	}
	else if(anterior == NULL)//pos ini
	{
		l->raiz = novo;
		novo->prox = atual;
		saida = 1;
	}
	else//pos meio
	{
		anterior->prox = novo;
		novo->prox = atual;
		saida = 1;
	}
	
	l->tamanho++;
	return saida;
}

aluno remover(lista* l, int ra)
{
	aluno aluno;
	aluno.ra = -1;
	no *autal, *anterior;
	anterior = NULL;

	for (autal = l->raiz; autal != NULL; anterior = autal, autal = autal->prox)
	{
		if (autal->dados.ra == ra)
		{
			if (anterior == NULL)
			{
				l->raiz = autal->prox;
			}
			else
			{
				anterior->prox = autal->prox;
			}
			l->tamanho--;    
			aluno = autal->dados;
			free(autal);
			return aluno;
		}
	}
	return aluno;
}

aluno remover_inicio(lista* l)
{
	no *aux;
	aluno a;
	a.ra = -1;
	
	if(l->raiz != NULL)
	{
		aux = l->raiz;
		l->raiz = aux->prox;
		a = aux->dados;
		l->tamanho--;
		free(aux);
	}
	
	return a;
}

void listar_(no* n, int tipo)
{
	time_t data_hora_atual;
	time( &data_hora_atual );

	if(n != NULL)
	{
		if(tipo == MATRICULADOS)
			printf("RA: %d - Nome: %s\n", n->dados.ra, n->dados.nome);
		else if(tipo == ESPERA)
			printf("RA: %d - Nome: %s - Tempo de espera de: %.0f segundos\n", n->dados.ra, n->dados.nome, 
				difftime(data_hora_atual, n->dados.time_espera));	
		listar_(n->prox, tipo);
	}
}

void listar_matriculados(lista* l)
{	 
	listar_(l->raiz, MATRICULADOS);
}

void listar_espera(lista* l)
{	 
	listar_(l->raiz, ESPERA);
}
