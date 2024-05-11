/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** command_runner.c
*/

#include <sys/wait.h>
#include "minishell.h"
#include "exit.h"
#include "jobs.h"
#include "utils.h"
#include "my.h"

int execute_local_command(info_t *info)
{
    if (access(info->args[0], X_OK)) {
        print_error_errno(info->args[0]);
        return 0;
    }
    if (execve(info->args[0], info->args, info->env) == -1){
        print_command_not_found_error(info->args[0]);
        return 1;
    }
    return 0;
}

int execute_command(info_t *info, int is_local_command)
{
    replace_alias_in_command(info);
    if (handle_redirections(info) == 1)
        exit_fork_program(info, 1);
    if (is_local_command)
        return execute_local_command(info);
    if (execvp(info->args[0], info->args) != -1)
        return 0;
    print_command_not_found_error(info->args[0]);
    return 1;
}

static void handle_process_execution(info_t *info, pid_t pid_fork)
{
    if (!info->jobs->ampersand) {
        waitpid(pid_fork, &info->status, 0);
        info->status = WEXITSTATUS(info->status);
    } else
        add_job(pid_fork, info->args[0], info, AMPERSANDED);
}

static int create_fork_command(info_t *info)
{
    pid_t pid_fork;
    int status;

    status = handle_pipes(info);
    if (status != -1)
        return status;
    pid_fork = fork();
    if (pid_fork == -1) {
        perror("Error, cannot fork.");
        return 84;
    }
    if (pid_fork == 0) {
        status = execute_command(info, is_local_command(info->args));
        exit_fork_program(info, status);
    } else
        handle_process_execution(info, pid_fork);
    return 0;
}

int is_local_command(char **command)
{
    return my_strncmp(command[0], "./", 2) == 0 ||
        my_strncmp(command[0], "~/", 2) == 0 || command[0][0] == '/';
}

void pre_handle_command_check(info_t *info)
{
    handle_command(info);
}

int handle_command(info_t *info)
{
    int is_builtin_executed = 0;
    char *delim[] = {" ", NULL};

    detect_ampersand(info, info->input);
    info->args = my_str_to_word_array(info->input, delim, 1);
    replace_local_variable(info);
    if (handle_globbings(info) != 0)
        return 1;
    for (int i = 0; i < NB_CUSTOM_COMMANDS; i++) {
        if (my_strcmp(info->args[0], custom_commands_prefix[i]) == 0) {
            info->status = custom_commands[i](info);
            is_builtin_executed = 1;
            break;
        }
    }
    if (!is_builtin_executed)
        create_fork_command(info);
    if (info->args != NULL)
        free_str_array(info->args);
    return 0;
}
