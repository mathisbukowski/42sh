/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** bg_command.c
*/

#include "minishell.h"
#include "jobs.h"
#include <signal.h>
#include <ctype.h>

static int bg_with_command(info_t *info)
{
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(info->args[0], info->args) == -1)
            exit(1);
    } else if (pid > 0) {
        add_job(pid, info->args[0], info, BACKGROUNDED);
        kill(pid, SIGCONT);
    } else {
        perror("fork failed");
        return 1;
    }
    return 0;
}

int command_bg(info_t *info)
{
    process_list_t *job = NULL;

    if (info->args[1] && info->args[1][0] == '%') {
        job = (isdigit(info->args[1][1])) ?
        find_job_by_id(atoi(info->args[1] + 1), info) :
        find_job_by_name((info->args[1] + 1), info);
        if (job == NULL) {
            fprintf(stderr, "bg: No such job.");
            return 1;
        }
        job->type = BACKGROUNDED;
        if (kill(job->pid, SIGCONT) == -1)
            return 1;
        printf("[%d]\t%s", job->id, job->command);
    }
    return 0;
}
