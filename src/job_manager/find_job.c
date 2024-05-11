/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** find_job.c
*/

#include "minishell.h"
#include "jobs.h"

process_list_t *find_job_by_id(int id, info_t *info)
{
    process_list_t *job = info->jobs->list;

    for (; job != NULL; job = job->next) {
        if (job->id == id)
            return job;
    }
    return NULL;
}

process_list_t *find_job_by_name(char const *name, info_t *info)
{
    process_list_t *job = info->jobs->list;

    for (; job != NULL; job = job->next) {
        if (strcmp(job->command, name) == 0)
            return job;
    }
    return NULL;
}
