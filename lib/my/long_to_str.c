/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.detoeuf
** File description:
** long_to_str.c NE GERE PAS LES NOMBRES NEGATIFS
*/

#include <stdlib.h>
#include "my.h"

char *positive_int_to_str(int nb)
{
    int nb_digit = get_int_len(nb);
    char *buffer = malloc(sizeof(char) * nb_digit);
    int i = nb_digit - 1;

    while (nb > 0) {
        buffer[i] = nb % 10 + 48;
        nb /= 10;
        i--;
    }
    buffer[nb_digit] = '\0';
    return buffer;
}
