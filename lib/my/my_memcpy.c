/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** my_memcpy.c
*/

void *my_memcpy(void *dest, void *src, int len)
{
    char *d = dest;
    char *s = src;
    int i = len;

    while (i > 0) {
        *d = *s;
        d++;
        s++;
        i--;
    }
    return dest;
}
