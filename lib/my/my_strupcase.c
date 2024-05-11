/*
** EPITECH PROJECT, 2023
** My_strupcase
** File description:
** Pool day 06 : Task 08
** A function that puts every letter of every word in it in uppercase.
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}
