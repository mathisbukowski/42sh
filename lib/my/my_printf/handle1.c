/*
** EPITECH PROJECT, 2023
** handle1
** File description:
** 1st part off all the handle functions used in my implementation
** of my self-made printf function
*/

#include <stdarg.h>
#include "../my.h"
#include "./my_printf.h"

void handle_int(handle_params_t *h_params)
{
    int nb = va_arg(*(h_params->params), int);

    display_flags_formatting(h_params, get_int_len(nb), 1);
    my_put_nbr(nb);
    h_params->nb_char += get_int_len(nb);
}

void handle_str(handle_params_t *h_params)
{
    char *str = va_arg(*(h_params->params), char *);
    int strLen = my_strlen(str);

    for (int i = 0; i < strLen; i++)
        my_putchar(str[i]);
    h_params->nb_char += strLen;
}

void handle_char(handle_params_t *h_params)
{
    char ch = va_arg(*(h_params->params), int);

    display_flags_formatting(h_params, 1, 0);
    my_putchar(ch);
    h_params->nb_char += 1;
}

void handle_percent(handle_params_t *h_params)
{
    my_putchar('%');
    h_params->nb_char += 1;
}

void handle_nothing(handle_params_t *h_params)
{
    if (h_params) {
        return;
    }
}
