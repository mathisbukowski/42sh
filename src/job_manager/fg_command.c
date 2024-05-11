/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** fg_command.c
*/

#include "minishell.h"
#include "jobs.h"
#include <signal.h>
#include <ctype.h>
#include <sys/wait.h>

int command_fg(info_t *info)
{
    process_list_t *job = NULL;
    int status;

    if (info->args[1] && info->args[1][0] == '%') {
        job = (isdigit(info->args[1][1])) ?
                find_job_by_id(atoi(info->args[1] + 1), info) :
                find_job_by_name((info->args[1] + 1), info);
        if (job == NULL) {
            fprintf(stderr, "fg: No such job.");
            return 1;
        }
        job->type = FOREGROUNDED;
        printf("%s", job->command);
        if (kill(job->pid, SIGCONT) == -1)
            return 1;
        if (waitpid(job->pid, &status, WUNTRACED) == -1)
            return 1;
    }
    return 0;
}
