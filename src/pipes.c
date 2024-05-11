/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** pipes.c
*/

#include <fcntl.h>
#include <sys/wait.h>
#include "minishell.h"
#include "exit.h"
#include "utils.h"
#include "my.h"

int handle_pipes(info_t *info)
{
    char *delim[] = {"|", NULL};
    char **pipe_splitted = my_str_to_word_array(info->input, delim, 1);
    int status = 0;

    if (pipe_splitted[0] == NULL || get_str_array_len(pipe_splitted) == 0) {
        free_str_array(pipe_splitted);
        return -1;
    }
    execute_piped_commands(info, pipe_splitted);
    free_str_array(pipe_splitted);
    return status;
}

int pipe_logic(info_t *info, pipe_info_t *pinfo, int fd[2])
{
    int status = 0;

    pinfo->pid = fork();
    if (pinfo->pid == -1) {
        perror("fork");
        return 1;
    }
    if (pinfo->pid == 0) {
        dup2(pinfo->fdb, 0);
        if (pinfo->commands[pinfo->i + 1] != NULL)
            dup2(fd[1], 1);
        close(fd[0]);
        status = execute_command(info, is_local_command(info->args));
        exit_fork_program(info, status);
    } else {
        close(fd[1]);
        pinfo->fdb = fd[0];
    }
    return status;
}

int loop_through_pipes(info_t *info, char *const *commands, pipe_info_t *pinfo,
    int *fd)
{
    int status;
    char *cleaned_args;
    char *delim[] = {" ", NULL};

    free_str_array(info->args);
    while (commands[pinfo->i] != NULL) {
        cleaned_args = clean_str(commands[pinfo->i]);
        info->args = my_str_to_word_array(cleaned_args, delim, 1);
        if (my_strlen(info->args[0]) == 0) {
            print_error_message("Invalid null command.\n");
            return 84;
        }
        pipe(fd);
        status = pipe_logic(info, pinfo, fd);
        pinfo->i++;
        free_str_array(info->args);
        free(cleaned_args);
    }
    info->args = NULL;
    return status;
}

int execute_piped_commands(info_t *info, char **commands)
{
    pipe_info_t *pinfo = malloc(sizeof(pipe_info_t));
    int status = 0;
    int fd[2];

    pinfo->fdb = 0;
    pinfo->i = 0;
    pinfo->commands = commands;
    status = loop_through_pipes(info, commands, pinfo, fd);
    if (status == 84) {
        free(pinfo);
        return 1;
    }
    while (wait(&status) != pinfo->pid);
    free(pinfo);
    return status;
}
