/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_job.c
*/

#include "minishell.h"
#include "jobs.h"

static char *concatenate_command(char *command, info_t *info)
{
    int command_length = strlen(command);
    char *new_command = NULL;

    for (int i = 1; info->args[i] != NULL; i++)
        command_length += strlen(info->args[i]) + 1;
    new_command = malloc(command_length + 1);
    if (new_command == NULL)
        return NULL;
    strcpy(new_command, command);
    for (int i = 1; info->args[i] != NULL; i++) {
        strcat(new_command, " ");
        strcat(new_command, info->args[i]);
    }
    return new_command;
}

void add_job(pid_t pid, char *command, info_t *info, proc_type_t type)
{
    process_list_t *new_job = malloc(sizeof(process_list_t));
    char *new_command = NULL;

    if (new_job == NULL)
        return;
    new_command = concatenate_command(command, info);
    if (new_command == NULL) {
        free(new_job);
        return;
    }
    info->jobs->next_job_id += 1;
    new_job->id = info->jobs->next_job_id;
    new_job->pid = pid;
    new_job->command = new_command;
    new_job->type = type;
    new_job->next = info->jobs->list;
    info->jobs->list = new_job;
    if (new_job->type == AMPERSANDED)
        printf("[%d] %d", new_job->id, new_job->pid);
}
