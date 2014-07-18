#include "main.h"

int main()
{

	curso* c = novo_curso();
	int opcao;
	do
	{
		menu();
		printf("\nDigite uma opcao: ");
		fflush(stdout);
		scanf("%d",&opcao);
		fflush(stdin);
		executaOpcao(opcao, c);
	}while(opcao != -1);

    return 0;
}

void menu()
{
	system("clear");
	printf("\n1  - Matricular Aluno no Curso");
	printf("\n2  - Remover Aluno da lista de matriculados");
	printf("\n3  - Remover Aluno da fila de espera");
    printf("\n4  - Listar Alunos matriculados");
    printf("\n5  - Listar Alunos da fila de espera");
    printf("\n6  - Opcional 1");
    printf("\n7  - Opcional 2");
	printf("\n-1 - Sair");
}

void matricular_aluno(curso *c, aluno a)
{
	time(&a.time_matricula);
	switch (inserir_ordenado(c->matriculados, a))
	{
		case 1:
			printf("Aluno: %s RA: %d adicionado no Curso: %s\n", a.nome, a.ra, c->nome);
			break;
		case -1:
			printf("RA: %d ja existe nao adicionado no Curso: %s\n", a.ra, c->nome);
			break;
		default:
			printf("erro\n");
			break;
	}
}

void executaOpcao(int opcao, curso *c)
{
	aluno a;
	int ra;
	time_t data_atual;

	switch (opcao)
	{
		case 1:
			if(c->matriculados->tamanho < c->vagas)
			{
				a = novo_aluno();
				matricular_aluno(c, a);
			}
			else if(c->fila_espera->tamanho < c->vagas)
			{
				a = novo_aluno();
				time(&a.time_espera);
				inserir_fim(c->fila_espera, a);
				printf("Aluno: %s RA: %d adicionado na fila de espera do Curso: %s\n", a.nome, a.ra, c->nome);

			}
			else
			{
				printf("Nao tem mais vagas no curso: %s\n", c->nome);
			}
			break;
		case 2:
			ra = ler_int("Digite o RA do aluno a ser removido da lista de matriculados: ");
			a = remover(c->matriculados, ra);
			if(a.ra == -1)
			{
				printf("Aluno nao encontrado\n");
			}
			else
			{
				printf("Aluno: %s - RA: %d removido do Curso: %s\n", a.nome, a.ra, c->nome);
				a = remover_inicio(c->fila_espera);
				if(a.ra != -1)
				{
					printf("Aluno: %s - RA: %d removido do Lista de Espera: %s\n", a.nome, a.ra, c->nome);
					matricular_aluno(c, a);
				}
			}
			break;
		case 3:
			ra = ler_int("Digite o RA do aluno a ser removido da lista de matriculados: ");
			a = remover(c->fila_espera, ra);
			if(a.ra == -1)
			{
				printf("Aluno nao encontrado\n");
			}
			else
			{
				printf("Aluno: %s - RA: %d removido do Curso: %s\n", a.nome, a.ra, c->nome);
			}
			break;
    	case 4: 
	  		time (&data_atual);
	  		printf ( "Data e Hora Atual: %s", asctime (localtime(&data_atual)) );
			printf("Alunos Matriculados:\n");
			listar_matriculados(c->matriculados);
			break;
		case 5: 
	  		time (&data_atual);
	  		printf ( "Data e Hora Atual: %s", asctime (localtime(&data_atual)) );
			printf("Alunos Na Fila de Espera:\n");
			listar_espera(c->fila_espera);
			break;
		case 6:
			 opc_01(c);
			 break;
		case 7:
			 opc_02(c);
			 break;
    	case -1:
    			printf("Saindo\n");
    			break;
		default:
    			printf("erro\n");
	}	

	
	system("read -p \"Pressione enter para continuar\" continuar");
}

void opc_01(curso* c)
{
	time_t data_atual;
	time (&data_atual);
	int i, tamanho, vagas;
	double diff;
	double soma;
	double *tempos;
	no* aux;

	soma = 0;
	tamanho = (c->fila_espera->tamanho);
	vagas = c->vagas;
	tempos = (double*)calloc(tamanho, sizeof(double));
	aux = c->fila_espera->raiz;

	if(tamanho == 0)
	{
		printf("Fila de Espera esta vazia, sem dados para gerar o relatorio\n");
		
	}
	else
	{
		for(i = 0; aux != NULL ; i++)
		{	
			diff = difftime(data_atual, aux->dados.time_espera);
			tempos[i] = diff;
			soma += diff;
			aux = aux->prox;	
		}


		printf("Alunos Na Fila de Espera:\n");
		listar_espera(c->fila_espera);
		printf(" _______________________________________________________________\n");
		printf("|              RELATORIO TEMPO DE ESPERA NA FILA                \n");
		printf("|_______________________________________________________________\n");
		printf("|Data e Hora Atual: %s", asctime (localtime(&data_atual)) );
		printf("|_______________________________________________________________\n");
		printf("|Tempo maximo de espera: %.0f segundos\n", tempos[0]);
		printf("|Tempo medio  de espera: %.0f segundos\n", soma/tamanho);
		printf("|Tempo minimo de espera: %.0f segundos\n", tempos[i-1]);
		printf("|_______________________________________________________________\n");

		printf(" _______________________________________________________________\n");
		printf("|                    RELATORIO TAMANHO DA FILA                  \n");
		printf("|_______________________________________________________________\n");
		printf("|                                                               \n");
		printf("|Tamanho maximo da fila: %d\n", vagas);
		printf("|Tamanho medio  da fila: %.0f\n", (double)tamanho/vagas);
		printf("|Tamanho minimo da fila: 0\n");
		printf("|_______________________________________________________________\n");
	}
}

//Opcionais
void opc_02(curso* c)
{
	int size = c->matriculados->tamanho + c->fila_espera->tamanho;
	
    //vetor de alunos
	aluno* a = (aluno*) calloc(size, sizeof(aluno));
	aluno aluno_aux;

	int i;
	int j;
	int k = size - 1;

    //adiciona todos os alunos matriculados no vetor
	no* aux;
	aux = c->matriculados->raiz;	
	for(i=0; aux != NULL ; i++)
	{	
		//printf("Nome: %s - RA: %d\n", list_aux->value->nome, list_aux->value->ra);
		a[i] = aux->dados;
		aux = aux->prox;	
	}

    //adiciona todos os alunos na fila de espera no vetor
	aux = c->fila_espera->raiz;
	for(i = i; aux != NULL ; i++)
	{	
		a[i] = aux->dados;
		aux = aux->prox;	
	}

    //ordena o vetor utilizando bubble sort
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < k; j++)
		{
			if(strcmp(a[j].nome, a[j+1].nome) >= 0 )
			{
				aluno_aux    = a[j];
				a[j]   = a[j+1];
				a[j+1] = aluno_aux;
			}
		}
		k--;
	}
	
	printf("Ordenado por nome\n");	
	for(i = 0; i < size; i++)
	{	
		printf("Nome: %s - RA: %d\n", a[i].nome, a[i].ra);	
	}
}