/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** exit.c
*/

#include "minishell.h"
#include "exit.h"
#include "jobs.h"
#include "my.h"

static void destroy_list(info_t *info)
{
    destroy_aliases(info->aliases);
    destroy_jobs(info);
    destroy_locales(info->locale);
}

void exit_main_process(info_t *info)
{
    int status = info->status;

    printf("exit\n");
    free_str_array(info->env);
    free(info->redirections);
    if (info->history_fd != -1)
        close(info->history_fd);
    if (info->previous_dir != NULL)
        free(info->previous_dir);
    free(info->home_var);
    destroy_list(info);
    free(info->history_path);
    free(info->tmp_input);
    free(info->tmp_path);
    free(info->jobs);
    free(info->current_dir);
    free(info);
    exit(status);
}

void exit_fork_program(info_t *info, int status)
{
    if (info->redirections->fd != -1)
        close(info->redirections->fd);
    if (info->history_fd != -1)
        close(info->history_fd);
    free_str_array(info->args);
    free_str_array(info->env);
    free(info->input);
    free(info->tmp_input);
    free(info->redirections);
    free(info->previous_dir);
    destroy_list(info);
    free_str_array(info->command_list);
    free(info->home_var);
    free(info->history_path);
    free(info->tmp_path);
    free(info->jobs);
    free(info->current_dir);
    free(info);
    exit(status);
}

void exit_echo(info_t *info, int status)
{
    free_str_array(info->env);
    free(info->redirections);
    if (info->previous_dir != NULL)
        free(info->previous_dir);
    if (info->history_fd != -1)
        close(info->history_fd);
    free(info->home_var);
    destroy_list(info);
    free(info->jobs);
    free(info->history_path);
    free(info->tmp_path);
    free(info->current_dir);
    free(info);
    exit(status);
}
