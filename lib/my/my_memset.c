/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.detoeuf
** File description:
** memset.c
*/

void my_memset(char *pointer, char value, int count)
{
    int i = 0;

    while (i < count) {
        pointer[i] = value;
        i++;
    }
}
