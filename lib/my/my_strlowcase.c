/*
** EPITECH PROJECT, 2023
** My_strlowcase
** File description:
** Pool day 6 : Task 09
** A function that puts every letter of every word in it in lowercase.
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
        i++;
    }
    return str;
}
