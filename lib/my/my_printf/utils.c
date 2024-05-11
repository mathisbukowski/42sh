/*
** EPITECH PROJECT, 2023
** utils
** File description:
** utils function used in my_printf project
*/

#include <stdarg.h>
#include "./my_printf.h"
#include "../my.h"

int get_int_len(int integer)
{
    int len = !integer;

    while (integer) {
        len++;
        integer /= 10;
    }
    return len;
}

void print_n_char(int nbSpace, char c, handle_params_t *h_params)
{
    for (int i = 0; i < nbSpace; i++) {
        my_putchar(c);
        h_params->nb_char += 1;
    }
}

int my_isnum(char c)
{
    return (c >= '0' && c <= '9');
}

int is_valid_flag(char letter)
{
    char validFlags[] = {'d', 'i', 's', 'c', '%', 'o', 'u', 'x', 'X', 'e', 'E',
        'f', 'F', 'g', 'G', 'p', 'n', 'b', 'S', '0'};
    int i = 0;

    while (validFlags[i] != '0') {
        if (letter == validFlags[i])
            return 1;
        i++;
    }
    return 0;
}

void move_index_to_flag(const char *str, handle_params_t *h_params)
{
    while (str[h_params->i + 1] != h_params->flag) {
        h_params->i += 1;
    }
}
