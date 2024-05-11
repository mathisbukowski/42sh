/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** signals.c
*/

#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include "minishell.h"

static info_t *static_info_ptr;

void init_static_info(info_t *info)
{
    static_info_ptr = NULL;
    static_info_ptr = info;
}

int init_signals(info_t *info)
{
    init_static_info(info);
    signal(SIGCHLD, &handle_sigchld);
    return 0;
}

static void for_in_list(pid_t pid, process_list_t **job_ptr)
{
    process_list_t *current_job = NULL;

    while (*job_ptr) {
        current_job = (*job_ptr);
        static_info_ptr->jobs->next_job_id = 0;
        if (current_job->type == AMPERSANDED)
            printf("\n[%d]  + Done%26s%s", current_job->id, "",
            current_job->command);
        else
            printf("\n[%d]    Done%26s%s", current_job->id, "",
            current_job->command);
        if (current_job->pid == pid) {
            *job_ptr = current_job->next;
            free(current_job->command);
            free(current_job);
            break;
        }
        job_ptr = &(*job_ptr)->next;
    }
}

void handle_sigchld(int sig)
{
    int saved_errno = errno;
    int status;
    pid_t pid;
    process_list_t **job_ptr = NULL;

    pid = waitpid(-1, &status, WNOHANG);
    while (pid > 0) {
        job_ptr = &(static_info_ptr->jobs->list);
        for_in_list(pid, job_ptr);
        pid = waitpid(-1, &status, WNOHANG);
    }
    if (pid == -1 && errno != ECHILD)
        perror("waitpid failed");
    errno = saved_errno;
}
