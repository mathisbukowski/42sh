/*
** EPITECH PROJECT, 2023
** my_roud
** File description:
** a function that takes as parameter a number to round
*/

int my_round(double nb)
{
    if (nb < 0.0) {
        return (int)(nb - 0.5);
    } else {
        return (int)(nb + 0.5);
    }
}
