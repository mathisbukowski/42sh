/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** Pool day 5 : Task 05
** A function that returns the square root (if it is a whole number)
** of the number given as argument.
** If the square root is not a whole number, the function should return 0.
*/

int my_compute_square_root(int nb)
{
    const int INT_MAX = 2147483647;
    int test;

    for (int i = 0; i < INT_MAX / 2; i++) {
        test = i * i;
        if (test > nb) {
            return 0;
        }
        if (test == nb) {
            return i;
        }
    }
    return 0;
}
