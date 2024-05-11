/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Pool day 4 : Task 01
** A function that swaps the content of two integers,
** whose addresses are given as a parameter.
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
