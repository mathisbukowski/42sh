/*
** EPITECH PROJECT, 2023
** My_strstr
** File description:
** Pool day 06 :
** Task Reproduce the behavior of the strstr function.
*/

#include "my.h"

static int in_range(int i, int x, int s1, int s2)
{
    return i <= s1 && x + i < s2;
}

static int check_find(char *str, char const *to_find, int index)
{
    int i = 0;
    int s_size = get_str_size(str);
    int f_size = get_str_size(to_find);

    while (in_range(i, index, f_size, s_size) &&
        str[index + i] == to_find[i]) {
        if (i == f_size - 1)
            return 1;
        i++;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int str_len = get_str_size(str);
    int to_find_size = get_str_size(to_find);

    if (*to_find == '\0')
        return str;
    for (int i = 0; i <= str_len - to_find_size; i++) {
        if (check_find(str, to_find, i)) {
            return &str[i];
        }
    }
    return 0;
}
