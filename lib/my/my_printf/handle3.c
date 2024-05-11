/*
** EPITECH PROJECT, 2023
** handle3
** File description:
** 3rd part off all the handle function used in my implementation
** of my self-made printf function
*/

#include "../my.h"
#include "./my_printf.h"

void handle_ptr(handle_params_t *h_params)
{
    unsigned long ptr = (unsigned long)va_arg(*(h_params->params), void *);
    char ptr_str[50];
    int i = 0;
    int nb;

    while (ptr != 0) {
        nb = ptr % 16;
        ptr = ptr / 16;
        if (nb < 10) {
            ptr_str[i] = nb + 48;
        } else {
            ptr_str[i] = nb + 97 - 10;
        }
        i++;
    }
    ptr_str[i] = '\0';
    my_revstr(ptr_str);
    h_params->nb_char += my_strlen(ptr_str) + 2;
    my_putstr("0x");
    my_putstr(ptr_str);
}
