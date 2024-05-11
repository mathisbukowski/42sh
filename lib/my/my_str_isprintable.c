/*
** EPITECH PROJECT, 2023
** Pool day 06 : Task 16
** File description:
** A function that returns 1 if the string passed as
** parameter only contains printable characters and 0 otherwise
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    char c;

    while (str[i] != '\0') {
        c = str[i];
        if (c < 32 || c > 126)
            return 0;
        i++;
    }
    return 1;
}
