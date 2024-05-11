/*
** EPITECH PROJECT, 2023
** Pool day 08 : Task 03
** File description:
** A function that displays the content of an array of words.
** There must be one word per line, and each word must end
** with ‘\n’, including the last one.
*/

#include "my.h"

int my_show_word_array(char const **tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
