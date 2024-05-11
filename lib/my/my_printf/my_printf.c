/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** a self_made implementation of printf function
*/

#include "../my.h"
#include "./my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

struct {
    char flag;
    void (*func)(handle_params_t *);
} const FLAGS[] = {
    {'s', &handle_str}, {'c', &handle_char}, {'d', &handle_int},
    {'i', &handle_int}, {'%', &handle_percent}, {'o', &handle_octal},
    {'x', &handle_hexa}, {'X', &handle_hexa}, {'b', &handle_binary},
    {'f', &handle_float}, {'F', &handle_float}, {'u', &handle_unsigned},
    {'p', &handle_ptr},
    {'\0', &handle_nothing},
};

int handle_types(handle_params_t *h_params)
{
    for (int j = 0; FLAGS[j].flag != 0; j++) {
        if (FLAGS[j].flag == h_params->flag) {
            FLAGS[j].func(h_params);
        }
    }
    h_params->i += 1;
    return 0;
}

static void init_struct_params(handle_params_t *h_params, va_list *params,
    const char *str)
{
    h_params->nb_char = 0;
    h_params->params = params;
    h_params->str = malloc(sizeof(char) * my_strlen(str));
    my_strcpy(h_params->str, str);
    h_params->flag = 0;
    h_params->i = 0;
}

int my_printf(const char *str, ...)
{
    va_list params;
    handle_params_t test;
    handle_params_t *h_params = &test;

    va_start(params, str);
    init_struct_params(h_params, &params, str);
    for (h_params->i = 0; h_params->str[h_params->i] != '\0';
    h_params->i += 1) {
        if (h_params->str[h_params->i] != '%') {
            my_putchar(h_params->str[h_params->i]);
            (h_params->nb_char)++;
            continue;
        }
        set_formatting_specifier(str, h_params);
        handle_types(h_params);
    }
    return h_params->nb_char;
}
