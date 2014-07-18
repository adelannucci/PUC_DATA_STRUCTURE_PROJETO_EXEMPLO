#ifndef BASICO_H_INCLUDED
#define BASICO_H_INCLUDED

#define MAX 255

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* ler_str(char* msg);
int ler_int(char* msg);
int ler_string(char s[], int max);
int confirmar(char* texto);

#endif // BASICO_H_INCLUDED