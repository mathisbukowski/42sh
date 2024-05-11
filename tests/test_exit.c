/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_exit.c
*/

#include <criterion/criterion.h>
#include <sys/wait.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include "../include/exit.h"
#include "../include/utils.h"

info_t *init_info_test()
{
    char *env[] = {"PATH=/usr/bin", NULL};
    char *delimiter[] = {" ", NULL};
    info_t *info = init_info(env);
    info->status = 0;
    info->tmp_input = strdup("exit");
    info->input = strdup("exit");
    info->args = my_str_to_word_array("exit", delimiter, 1);
    info->env = my_str_to_word_array("exit", delimiter, 1);
    info->previous_dir = strdup("some_directory");
    info->command_list = my_str_to_word_array("exit", delimiter, 1);
    info->redirections = malloc(sizeof(redirections_t));
    info->redirections->fd = 0;
    info->redirections->redirect_index = 0;
    info->redirections->type = E_NONE;
    info->aliases = malloc(sizeof(aliases_t));
    info->aliases->alias = strdup("alias");
    info->aliases->command = strdup("command");
    info->aliases->next = NULL;
    info->locale = malloc(sizeof(local_var_t));
    info->locale->name = strdup("name");
    info->locale->value = strdup("value");
    info->locale->next = NULL;
    info->home_var = strdup("home_var");
    info->command_count = 0;
}

Test(exit_main_process, should_free_previous_dir_when_not_null)
{
    pid_t pid = fork();
    if (pid == 0) {
        info_t *info = init_info_test();
        exit_main_process(info);
    } else {
        int status;
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Expected exit_main_process to call exit, but it didn't");
    }
}

Test(exit_main_process, should_not_free_previous_dir_when_null)
{
    pid_t pid = fork();
    if (pid == 0) {
        info_t *info = init_info_test();
        info->previous_dir = NULL;
        exit_main_process(info);
    } else {
        int status;
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Expected exit_main_process to call exit, but it didn't");
    }
}

Test(exit_fork_program, should_free_previous_dir_when_not_null)
{
    pid_t pid = fork();
    if (pid == 0) {
        info_t *info = init_info_test();
        info->previous_dir = strdup("some_directory");
        exit_fork_program(info, 0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Expected exit_fork_program to call exit, but it didn't");
    }
}

Test(exit_fork_program, should_not_free_previous_dir_when_null)
{
    pid_t pid = fork();
    if (pid == 0) {
        info_t *info = init_info_test();
        info->previous_dir = NULL;
        exit_fork_program(info, 0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Expected exit_fork_program to call exit, but it didn't");
    }
}

Test(exit_fork_program, should_close_fd_when_not_minus_one)
{
    pid_t pid = fork();
    if (pid == 0) {
        info_t *info = init_info_test();
        info->redirections->fd = 1;
        exit_fork_program(info, 0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Expected exit_fork_program to call exit, but it didn't");
    }
}

Test(exit_fork_program, should_not_close_fd_when_minus_one)
{
    pid_t pid = fork();
    if (pid == 0) {
        info_t *info = init_info_test();
        info->redirections->fd = -1;
        exit_fork_program(info, 0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Expected exit_fork_program to call exit, but it didn't");
    }
}