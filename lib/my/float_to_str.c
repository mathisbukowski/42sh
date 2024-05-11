/*
** EPITECH PROJECT, 2023
** int_to_str
** File description:
** a function that takes as parameters a char* with a float and convert the int
** into the char*
*/

#include "my.h"

static int round_int_part(double *dec_part, int power, int *int_part)
{
    *dec_part = my_round(*dec_part * power);
    if (*dec_part >= power) {
        (*int_part)++;
        *dec_part = 0;
    }
    return *dec_part;
}

void float_to_str(double nb, char *str, int precision)
{
    int int_part = (int) nb;
    double dec_part = nb - int_part;
    double power = my_compute_power_rec(10, precision);
    int i = 0;
    int int_dec;

    round_int_part(&dec_part, power, &int_part);
    int_to_str(int_part, str);
    if (precision > 0) {
        while (str[i] != '\0')
            i++;
        str[i] = '.';
        int_dec = (int)dec_part;
        for (int j = i; j < precision + i - get_int_len(int_dec); j++)
            str[j + 1] = '0';
        int_to_str(int_dec, &str[i + precision - get_int_len(int_dec) + 1]);
    }
}
