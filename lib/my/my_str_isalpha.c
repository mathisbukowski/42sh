/*
** EPITECH PROJECT, 2023
** Pool day 06 : Task 12
** File description:
** function that returns 1 if the string passed as parameter
** only contains alphabetical characters and 0 if the string
** contains another type of character.
*/

static int is_num(char c)
{
    return c >= 48 && c <= 57;
}

int my_str_isalpha(char const *str)
{
    int i = 0;
    char c;

    while (str[i] != '\0') {
        c = str[i];
        if (!(is_num(c)) && !(c >= 65 && c <= 90) && !(c >= 97 && c <= 122))
            return 0;
        i++;
    }
    return 1;
}
