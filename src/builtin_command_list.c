/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** builtin_command_list.c
*/

#include "minishell.h"
#include "commands.h"
#include "jobs.h"

int (* const custom_commands[NB_CUSTOM_COMMANDS]) (info_t *) =
{ command_cd, command_env, command_setenv, command_unsetenv, command_alias,
    command_unalias, search_alias_command, command_set, command_unset,
    command_history, command_bg, command_fg, command_help};
char const *custom_commands_prefix[NB_CUSTOM_COMMANDS] =
{ "cd", "env", "setenv", "unsetenv", "alias", "unalias", "searchalias",
    "set", "unset", "history", "bg", "fg", "help"};
