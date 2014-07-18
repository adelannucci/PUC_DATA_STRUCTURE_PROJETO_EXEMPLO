#include "basico.h"

char* ler_str(char* msg)
{
    char *aux;
    aux =(char*)malloc(MAX);

    system("clear");
    fflush(stdout);
    printf("%s\n", msg);
    ler_string(aux,MAX);
    fflush(stdin);
    printf("\n");
    fflush(stdout);

    return aux;
}

int ler_int(char* msg)
{
    int aux = 0;

    system("clear");
    fflush(stdout);
    printf("%s\n", msg);
    scanf("%d", &aux);
    fflush(stdin);
    printf("\n");
    fflush(stdout);

    return aux;
}

int ler_string(char s[], int max)
{
    int i = 0;
    char letra;

    /* No caso o max é o tamanho que s pode receber. Deve ser passado o tamanho
     * mesmo, ou seja, se for passado 100 a função já se encarrega de não deixar
     * passar de 99 cars (+1 do finalizador)
     */
    for (i = 0; i < (max - 1); i++)
    {
        letra = fgetc(stdin);

        /* Veja que se encontrou um ENTER (\n) mas não leu nenhum caractere válido,
         * não aceita. Precisa ler algo. Decrementa o i para anular o efeito do i++
         * do laço e volta no laço com continue
         */
        if ((letra == '\n') && (i == 0))
        {
            i = i - 1;
            continue;
        }
        /* Agora se leu um enter já tendo lido caracteres válidos, então
         * o usuário terminou de digitar sua string e ela possui ao menos
         * um caractere válido
         */
         if (letra == '\n')
            break;
         s[i] = letra;
    }

    /* Finaliza a string */
    s[i] = 0;

    /* retorna a quantidade de cars lidos (pode ser útil). Então, esta função
     * lê uma string e retorna o seu tamanho
     */

     return (i);
}

int confirmar(char* texto)
{

    int c;
    printf("%s", texto);
    printf("\nDigite 1 para confirmar ou 0 para cancelar.\n");
    fflush(stdout);
    scanf("%d", &c);
    fflush(stdin);
    printf("\n");
    fflush(stdout);

    if(c!=0 && c!=1)
        c = confirmar(texto);

    return c;
}