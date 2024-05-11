/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** detect_ampersand.c
*/

#include "minishell.h"
#include "jobs.h"

int is_double_ampersand(char current, char next)
{
    return (current == '&' && next == '&');
}

void process_double_ampersand(char **dest, char current, char next)
{
    **dest = current;
    (*dest)++;
    **dest = next;
    (*dest)++;
}

void process_char(info_t *info, char **dest, char current)
{
    if (current != '&') {
        **dest = current;
        (*dest)++;
    } else {
        info->jobs->ampersand = 1;
    }
}

void detect_ampersand(info_t *info, char *line)
{
    char *dest = line;

    info->jobs->ampersand = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (is_double_ampersand(line[i], line[i + 1])) {
            process_double_ampersand(&dest, line[i], line[i + 1]);
            i++;
        } else
            process_char(info, &dest, line[i]);
    }
    *dest = '\0';
}
