/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_pipes.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include "../include/utils.h"

void free_info(info_t *info)
{
    free(info->tmp_input);
    free(info->input);
    free_str_array(info->args);
    free_str_array(info->env);
    free(info->previous_dir);
    free_str_array(info->command_list);
    free(info->redirections);
    free(info->aliases);
    free(info->locale);
    free(info->home_var);
    free(info);
}

void free_pipe_info(pipe_info_t *pinfo)
{
    free_str_array(pinfo->commands);
    free(pinfo);
}

Test(handle_pipes, test_handle_pipes_success)
{
    char *env[] = {"PATH=/usr/bin", NULL};
    char *delimiter[] = {" ", NULL};
    info_t *info = init_info(env);
    info->input = strdup("ls | cat");
    info->args = my_str_to_word_array(info->input, delimiter, 1);
    info->input = strdup("ls | cat");
    int status = handle_pipes(info);
    cr_assert_eq(status, 0);
    //free_info(info);
}

Test(handle_pipes, test_handle_pipes_failure)
{
    char *env[] = {"PATH=/usr/bin", NULL};
    char *delimiter[] = {" ", NULL};
    info_t *info = init_info(env);
    info->input = strdup("ls | cat");
    info->args = my_str_to_word_array(info->input, delimiter, 1);
    info->input = strdup("");
    int status = handle_pipes(info);
    cr_assert_eq(status, -1);
    //free_info(info);
}

Test(pipe_logic, test_pipe_logic_success)
{
    char *env[] = {"PATH=/usr/bin", NULL};
    info_t *info = init_info(env);
    char *delimiter[] = {" ", NULL};
    info->input = strdup("ls | cat");
    info->args = my_str_to_word_array(info->input, delimiter, 1);
    pipe_info_t *pinfo = malloc(sizeof(pipe_info_t));
    int fd[2];
    pipe(fd);
    pinfo->fdb = fd[0];
    pinfo->i = 0;
    pinfo->commands = malloc(sizeof(char *) * 3);
    pinfo->commands[0] = strdup("ls");
    pinfo->commands[1] = strdup("cat");
    pinfo->commands[2] = NULL;
    int status = pipe_logic(info, pinfo, fd);
    cr_assert_eq(status, 0);
    //free_info(info);
    //free_pipe_info(pinfo);
}

Test(loop_through_pipes, test_loop_through_pipes_success)
{
    char *env[] = {"PATH=/usr/bin", NULL};
    info_t *info = init_info(env);
    char *delimiter[] = {" ", NULL};
    info->input = strdup("ls | cat");
    info->args = my_str_to_word_array(info->input, delimiter, 1);
    pipe_info_t *pinfo = malloc(sizeof(pipe_info_t));
    int fd[2];
    pipe(fd);
    pinfo->fdb = fd[0];
    pinfo->i = 0;
    pinfo->commands = malloc(sizeof(char *) * 3);
    pinfo->commands[0] = strdup("ls");
    pinfo->commands[1] = strdup("cat");
    pinfo->commands[2] = NULL;
    int status = loop_through_pipes(info, pinfo->commands, pinfo, fd);
    cr_assert_eq(status, 0);
    //free_info(info);
    //free_pipe_info(pinfo);
}

Test(execute_piped_commands, test_execute_piped_commands_success)
{
    char *env[] = {"PATH=/usr/bin", NULL};
    char *delimiter[] = {" ", NULL};
    info_t *info = init_info(env);
    info->input = strdup("ls | cat");
    info->args = my_str_to_word_array(info->input, delimiter, 1);
    char **commands = malloc(sizeof(char *) * 3);
    commands[0] = strdup("ls");
    commands[1] = strdup("cat");
    commands[2] = NULL;
    int status = execute_piped_commands(info, commands);
    cr_assert_eq(status, 1);
    //free_info(info);
    //free_str_array(commands);
}
