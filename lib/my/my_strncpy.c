/*
** EPITECH PROJECT, 2023
** My_strncpy
** File description:
** Pool day 06 : Task 02
** A function that copies n characters from a string into another.
** The destination string will already have
** enough memory to contain n characters.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > i) {
        dest[i] = '\0';
    }
    return dest;
}
