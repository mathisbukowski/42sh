/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_command_runner.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"

Test(execute_local_command, test_execute_local_command)
{
    info_t *info = malloc(sizeof(info_t));
    info->args = malloc(sizeof(char *) * 2);
    info->args[0] = "ls";
    info->args[1] = NULL;
    int status = execute_local_command(info);
    cr_assert_eq(status, 0);
}

Test(execute_command, test_execute_command)
{
    info_t *info = malloc(sizeof(info_t));
    info->args = malloc(sizeof(char *) * 2);
    info->args[0] = "ls";
    info->args[1] = NULL;
    int status = execute_command(info, is_local_command(info->args));
    cr_assert_eq(status, 0);
}

Test(is_local_command, test_is_local_command)
{
    char *command[2] = {"ls", NULL};
    int status = is_local_command(command);
    cr_assert_eq(status, 0);
}
