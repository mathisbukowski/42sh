/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** Pool day 4 : Task 05
** A function that returns a number, sent to the function as a string.
*/

#include "my.h"

static int is_digit(char c)
{
    if (c >= 48 && c <= 57) {
        return 1;
    }
    return 0;
}

static int is_valid(char const *str, int i)
{
    if (is_digit(str[i])) {
        return 1;
    }
    if (str[i] == '-' && is_digit(str[i + 1]))
        return 1;
    return 0;
}

static long long string_to_long_long(char *str)
{
    long long result = 0;
    int i = 0;
    int minus = 0;

    if (my_strlen(str) == 12)
        str[11] = ' ';
    if (str[0] == '-') {
        i++;
        minus = 1;
    }
    while (str[i] && str[i] != ' ' && i < my_strlen(str)) {
        result = result * 10 + str[i] - '0';
        i++;
    }
    if (minus)
        result *= (-1);
    return result;
}

static int is_overflow(char *number)
{
    long long t = string_to_long_long(number);

    if (t >= -2147483648 && t <= 2147483647) {
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int strlen = my_strlen(str);
    char result[11];
    int result_index = 0;
    int in_a_number = 0;
    int char_is_valid = 0;

    for (int i = 0; i < strlen; i++) {
        char_is_valid = is_valid(str, i);
        if (!is_digit(str[i]) && in_a_number == 1)
            break;
        if (char_is_valid) {
            result[result_index] = str[i];
            result_index++;
            in_a_number = 1;
        }
        if (is_overflow(result) == 0 || result_index > 11)
            return 0;
    }
    return (int)string_to_long_long(result);
}
