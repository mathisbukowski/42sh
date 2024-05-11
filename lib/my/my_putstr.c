/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Pool day 4 : Task02
** A function that displays, one-by-one, the characters of a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
