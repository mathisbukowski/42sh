/*
** EPITECH PROJECT, 2023
** My_revstr
** File description:
** Pool day 06 : Task 03
** A function that reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int y = get_str_size(str) - 1;
    char temp;

    while (i < y) {
        temp = str[i];
        str[i] = str[y];
        str[y] = temp;
        i++;
        y--;
    }
    return str;
}
