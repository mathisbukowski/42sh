/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Pool day 5 : Task 07
** A function that returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    const int INT_MAX = 2147483647;

    for (int i = nb; i <= INT_MAX; i++) {
        if (my_is_prime_sub(i)) {
            return i;
        }
    }
    return 0;
}
