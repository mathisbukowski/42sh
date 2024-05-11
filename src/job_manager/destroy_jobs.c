/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** destroy_jobs.c
*/

#include "minishell.h"
#include "jobs.h"

void destroy_jobs(info_t *info)
{
    process_list_t *current = info->jobs->list;
    process_list_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->command);
        free(tmp);
    }
}
