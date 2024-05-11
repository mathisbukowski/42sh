/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *txt)
{
    int len = my_strlen(txt);
    char *str = malloc(sizeof(char) * (len + 1));

    my_memcpy(str, txt, len);
    str[len] = '\0';
    return str;
}
