/*
** EPITECH PROJECT, 2023
** My_strcmp
** File description:
** Pool day 06 : Task 06
** Function that reproduce the behavior of the strcmp function
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int y = 0;

    while (s1[i] != '\0' && s1[i] == s2[y]) {
        i++;
        y++;
    }
    return s1[i] - s2[y];
}
