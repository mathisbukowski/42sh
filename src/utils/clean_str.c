/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** clean_str.c
*/

#include "minishell.h"
#include "utils.h"
#include "my.h"

int is_there_word_after(char *str, int index)
{
    char c;

    while (str[index] != '\0') {
        c = str[index];
        if (c != ' ' && c != '\t')
            return 1;
        index++;
    }
    return 0;
}

void append(char *str, char c)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    str[i] = c;
    str[i + 1] = '\0';
}

void add_letter(char *cleaned_str, char c, int *has_word,
    int is_word_after)
{
    if (c != ' ' && c != '\t') {
        append(cleaned_str, c);
        *has_word = 1;
        return;
    }
    if ((c == ' ' || c == '\t') && *has_word && is_word_after) {
        append(cleaned_str, ' ');
        *has_word = 0;
    }
}

char *clean_str(char *str)
{
    char *cleaned_str = malloc(my_strlen(str) + 1);
    int i = 0;
    int has_word = 0;

    cleaned_str[0] = '\0';
    while (str[i] != '\0') {
        add_letter(cleaned_str, str[i], &has_word,
            is_there_word_after(str, i));
        i++;
    }
    return cleaned_str;
}
