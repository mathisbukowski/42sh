/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** a function that displays the number given as a parameter.
** It must be able to display all the possible values of an int
*/

#include <stdio.h>
#include "my.h"

int get_nb_length(int nb)
{
    int res = 0;

    while (nb != 0) {
        nb = nb / 10;
        res++;
    }
    return res;
}

int power(int nbo, int p)
{
    int nb = nbo;

    if (p == 0)
        return 1;
    for (int i = 0; i < p - 1; i++)
        nb = nb * nbo;
    return nb;
}

static void divisor_func(int nb)
{
    int length = get_nb_length(nb);
    int divisor = 1;
    int digit;

    for (int i = 1; i < length; i++)
        divisor *= 10;
    while (divisor != 0) {
        digit = nb / divisor;
        my_putchar('0' + digit);
        nb %= divisor;
        divisor /= 10;
    }
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        if (nb == -2147483648) {
            my_putchar('-');
            my_put_nbr(214748364);
            my_putchar('8');
            return;
        } else {
            my_putchar('-');
            nb = -nb;
        }
    }
    divisor_func(nb);
}
