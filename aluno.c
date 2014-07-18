#include "aluno.h"

aluno novo_aluno()
{
	aluno novo;
	novo.ra = ler_int("Digite o RA: ");
	strcpy(novo.nome     , ler_str("Digite o nome: "    ));
	strcpy(novo.curso    , ler_str("Digite o curso: "   ));
	strcpy(novo.telefone , ler_str("Digite o telefone: "));
	strcpy(novo.email    , ler_str("Digite o email: "   ));
	novo.cp = ler_int("Digite o coeficiente de progressao: ");
	novo.time_matricula = 0;
	novo.time_espera = 0;

	return novo;
}