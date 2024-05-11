/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** handle_double_pipe.c
*/

#include "minishell.h"
#include "utils.h"
#include "my.h"

int execute_command_double(info_t *info, char **commands, int j)
{
    for (; commands[j] != NULL; j++) {
        free(info->input);
        info->input = strdup(commands[j]);
        pre_handle_command_check(info);
        if (info->status != 0)
            break;
    }
    return 0;
}

int handle_double_pipe_and(info_t *info)
{
    char *delim_pipe[] = {"||", NULL};
    char *delim_and[] = {"&&", NULL};
    char **sub_commands = my_str_to_word_array(info->input, delim_pipe, 1);
    char **commands = NULL;

    for (int i = 0; sub_commands[i] != NULL; i++) {
        commands = my_str_to_word_array(sub_commands[i], delim_and, 1);
        info->status = 0;
        execute_command_double(info, commands, i);
        free_str_array(commands);
        if (info->status == 0)
            break;
    }
    free_str_array(sub_commands);
    return 0;
}
