/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Pool day 3 : Task 04
** A function that displays either N if the integer passed as
** parameter is negative or P, if positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
