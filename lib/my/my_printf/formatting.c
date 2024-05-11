/*
** EPITECH PROJECT, 2023
** My_printf
** File description:
** File that control the padding and precision
*/

#include <stdlib.h>
#include "../my.h"
#include "./my_printf.h"

static int is_valid_middle_char(char c)
{
    return my_isnum(c) || is_valid_flag(c) || c == ' ' || c == '*' || c == '.';
}

char get_flag(char const *str, int i)
{
    if (str[i] != '%')
        return 0;
    while (is_valid_middle_char(str[i])) {
        i += 1;
        if (is_valid_flag(str[i]))
            return str[i];
    }
    return 0;
}

int get_precision(char const *str, int i, char flag)
{
    char *precision = malloc(sizeof(char) * my_strlen(str));
    int getPrecision = 0;
    int precisionIndex = 0;

    if (str[i] != '%')
        return 0;
    while (str[i] != flag) {
        i++;
        if (getPrecision && my_isnum(str[i])) {
            precision[precisionIndex] = str[i];
            precisionIndex++;
        }
        if (getPrecision && !my_isnum(str[i]) && str[i] != flag)
            return -1;
        if (str[i] == '.')
            getPrecision = 1;
    }
    precision[precisionIndex] = '\0';
    return my_strlen(precision) == 0 ? -1 : my_getnbr(precision);
}

int get_width(const char *str, handle_params_t *h_params)
{
    char *width = malloc(sizeof(char) * my_strlen(str));
    int widthIndex = 0;
    int get_width = 0;
    int i = h_params->i;

    if (str[i] != '%')
        return 0;
    while (str[i] != h_params->flag) {
        i++;
        if ((get_width && !my_isnum(str[i])) ||
        (is_valid_middle_char(str[i]) && str[i] != ' ' && !my_isnum(str[i])))
            break;
        if (my_isnum(str[i])) {
            get_width = 1;
            width[widthIndex] = str[i];
            widthIndex++;
        }
    }
    width[widthIndex] = '\0';
    return my_getnbr(width);
}

void set_formatting_specifier(const char *str, handle_params_t *h_params)
{
    h_params->flag = get_flag(str, h_params->i);
    h_params->precision = get_precision(str, h_params->i, h_params->flag);
    h_params->width = get_width(str, h_params);
    move_index_to_flag(str, h_params);
}

void display_flags_formatting(handle_params_t *h_params, int displaySize,
    int displayPrecision)
{
    int precision = h_params->precision;
    int nbSpaceForPadding = h_params->width - displaySize;

    if (precision == -1 || !displayPrecision)
        precision = 0;
    if (precision > displaySize)
        nbSpaceForPadding -= precision - displaySize;
    print_n_char(nbSpaceForPadding, ' ', h_params);
    if (displayPrecision)
        print_n_char(precision - displaySize, '0', h_params);
}
