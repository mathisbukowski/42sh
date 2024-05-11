/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** a function that displays, one-by-one, the characters of a string.
** The address of the string’s first character will be found in the pointer
** passed as a parameter to the function.
*/

#include <unistd.h>

void my_put_errorstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}
