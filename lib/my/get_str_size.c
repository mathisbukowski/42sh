/*
** EPITECH PROJECT, 2023
** Pool day 6
** File description:
** Function that return the length of an str
*/

int get_str_size(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
