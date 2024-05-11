/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_start_shell.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include "../include/utils.h"

Test(handle_stdin_input, should_handle_stdin_input)
{
    char *env[] = {"PWD=/home", NULL};
    info_t *info = init_info(env);
    char *command = "ls; ls -l; ls -la\n";
    int pipefd[2];

    pipe(pipefd);
    write(pipefd[1], command, my_strlen(command));
    close(pipefd[1]);

    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);

    int exit = handle_stdin_input(info);

    cr_assert_eq(exit, 0);
}