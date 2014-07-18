#include "curso.h"

curso* novo_curso()
{
	curso* novo_curso;
 
    novo_curso = (curso*) malloc(sizeof(curso));
 
    if(novo_curso == NULL) 
    	exit(0);

    strcpy(novo_curso->nome, ler_str("Digite o nome do curso: "));
    novo_curso->vagas = ler_int("Digite a quantidade de vagas: ");
    novo_curso->matriculados = cria_lista();
    novo_curso->fila_espera = cria_lista();

    return (novo_curso);
}