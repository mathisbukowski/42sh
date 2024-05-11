/*
** EPITECH PROJECT, 2023
** My_strcpy
** File description:
** Pool day 6 : Task 01  a function that copies a string into another.
** The destination string will already have enough memory
** to copy the source string
*/

char *my_strcpy(char *dest, char const *src)
{
    char *save = dest;

    *dest = *src;
    while (*src != '\0') {
        ++src;
        ++dest;
        *dest = *src;
    }
    ++dest;
    *dest = '\0';
    return save;
}
