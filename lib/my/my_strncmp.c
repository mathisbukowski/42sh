/*
** EPITECH PROJECT, 2023
** My_strncmp
** File description:
** Pool day 06 : Task 07
** Function that reproduce the behavior of the strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    char u1;
    char u2;

    while (n > 0) {
        u1 = *s1;
        u2 = *s2;
        s1++;
        s2++;
        n--;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }
    return 0;
}
