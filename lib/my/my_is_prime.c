/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Pool day 5 : Task 06
** A function that returns 1 if the number is prime and 0 if not.
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return 0;
    for (int i = 2; i < nb / 2 + 1; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
