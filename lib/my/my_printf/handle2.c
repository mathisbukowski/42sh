/*
** EPITECH PROJECT, 2023
** handle2
** File description:
** 2nd part off all the handle function used in my implementation
** of my self-made printf function
*/

#include <stdarg.h>
#include "../my.h"
#include "./my_printf.h"

void handle_octal(handle_params_t *h_params)
{
    int nb = va_arg(*(h_params->params), int);
    int octal_nb[100];
    int i = 0;

    while (nb != 0) {
        octal_nb[i] = nb % 8;
        nb = nb / 8;
        i++;
    }
    display_flags_formatting(h_params, i, 1);
    for (int j = i - 1; j >= 0; j--) {
        my_put_nbr(octal_nb[j]);
        (h_params->nb_char)++;
    }
}

void handle_hexa(handle_params_t *h_params)
{
    int ch = (h_params->flag >= 97 && h_params->flag <= 122) ? 87 : 55;
    int nb = va_arg(*(h_params->params), int);
    int i = 1;
    int j;
    int tmp;
    char out[100];

    while (nb != 0) {
        tmp = nb % 16;
        tmp += (tmp < 10) ? 48 : ch;
        i++;
        out[i] = tmp;
        nb /= 16;
    }
    display_flags_formatting(h_params, i - 1, 1);
    for (j = i - 1; j > 0; j--) {
        my_putchar(out[j]);
        (h_params->nb_char)++;
    }
}

void handle_binary(handle_params_t *h_params)
{
    int nb = (va_arg(*(h_params->params), int));
    int binary_nb[100];
    int i = 0;

    while (nb != 0) {
        binary_nb[i] = nb % 2;
        nb = nb / 2;
        i++;
    }
    display_flags_formatting(h_params, i, 1);
    for (int j = i - 1; j >= 0; j--) {
        my_put_nbr(binary_nb[j]);
        (h_params->nb_char)++;
    }
}

void handle_float(handle_params_t *h_params)
{
    double nb = va_arg(*(h_params->params), double);
    char str[50];

    if (h_params->precision == -1)
        h_params->precision = 6;
    float_to_str(nb, str, h_params->precision);
    h_params->nb_char += my_strlen(str);
    display_flags_formatting(h_params, my_strlen(str), 0);
    my_putstr(str);
}

void handle_unsigned(handle_params_t *h_params)
{
    unsigned int nb = va_arg(*(h_params->params), unsigned int);
    char nb_str[50];
    int i = 0;
    int digit;

    while (nb != 0) {
        digit = nb % 10;
        nb /= 10;
        nb_str[i] = digit + 48;
        i++;
    }
    nb_str[i] = '\0';
    my_revstr(nb_str);
    h_params->nb_char += my_strlen(nb_str);
    display_flags_formatting(h_params, my_strlen(nb_str), 1);
    my_putstr(nb_str);
}
