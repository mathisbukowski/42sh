/*
** EPITECH PROJECT, 2023
** My_strcapitalize
** File description:
** Pool day 06 : Task 10
** A function that capitalizes the first letter of each word.
*/

static int is_low_letter(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

static int is_upper_letter(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

static int is_alpha(char c)
{
    if ((c >= '0' && c <= '9') || is_upper_letter(c) || is_low_letter(c))
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_low_letter(str[i]) && (i == 0 || !is_alpha(str[i - 1]))) {
            str[i] -= 32;
        }
        if (is_upper_letter(str[i]) && is_alpha(str[i - 1])) {
            str[i] += 32;
        }
        i++;
    }
    return str;
}
