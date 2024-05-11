/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** error_utils.c
*/

#include <errno.h>
#include "minishell.h"
#include "utils.h"
#include "my.h"

void print_command_not_found_error(char *command)
{
    char *error_str = malloc(sizeof(char) * (my_strlen(command) + 22));

    if (error_str == NULL)
        return;
    error_str[0] = '\0';
    my_strcat(error_str, command);
    my_strcat(error_str, ": Command not found.\n");
    write(2, error_str, my_strlen(error_str));
    free(error_str);
}

void print_error_errno(char *prefix)
{
    char *error_str;
    char *err = strerror(errno);

    error_str = malloc(sizeof(char) * (my_strlen(prefix) +
        my_strlen(err) + 5));
    if (error_str == NULL)
        return;
    error_str[0] = '\0';
    my_strcat(error_str, prefix);
    my_strcat(error_str, ": ");
    my_strcat(error_str, err);
    my_strcat(error_str, ".");
    my_strcat(error_str, "\n");
    write(2, error_str, my_strlen(error_str));
    free(error_str);
}

void print_error(char *prefix, char *msg)
{
    char *error_str;

    error_str = malloc(sizeof(char) * (my_strlen(prefix) +
        my_strlen(msg) + 4));
    if (error_str == NULL)
        return;
    error_str[0] = '\0';
    my_strcat(error_str, prefix);
    my_strcat(error_str, ": ");
    my_strcat(error_str, msg);
    my_strcat(error_str, "\n");
    write(2, error_str, my_strlen(error_str));
    free(error_str);
}

void print_error_message(char *msg)
{
    write(2, msg, my_strlen(msg));
}
