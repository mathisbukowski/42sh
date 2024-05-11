/*
** EPITECH PROJECT, 2023
** Pool day 07 : Task 02
** File description:
** A function that concatenates two strings.
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_size = 0;

    while (dest[dest_size] != '\0') {
        dest_size++;
    }
    while (src[i] != '\0') {
        dest[dest_size + i] = src[i];
        i++;
    }
    dest[dest_size + i] = '\0';
    return dest;
}
