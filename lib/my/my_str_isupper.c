/*
** EPITECH PROJECT, 2023
** Pool day 6 : Task 15
** File description:
** A function that returns 1 if the string passed as
** parameter only contains uppercase alphabetical
** characters and 0 otherwise.
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 65 || str[i] > 90)
            return 0;
        i++;
    }
    return 1;
}
