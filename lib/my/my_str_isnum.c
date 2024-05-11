/*
** EPITECH PROJECT, 2023
** Pool day 6 : Task 13
** File description:
** A function that returns 1 if the string passed as
** parameter only contains digits and 0 otherwise.
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            return 0;
        i++;
    }
    return 1;
}
