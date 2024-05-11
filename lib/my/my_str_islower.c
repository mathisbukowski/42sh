/*
** EPITECH PROJECT, 2023
** Pool day 6 : Task 14
** File description:
** A function that returns 1 if the string passed as
** parameter only contains lowercase alphabetical
** characters and 0 otherwise.
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 97 || str[i] > 122)
            return 0;
        i++;
    }
    return 1;
}
