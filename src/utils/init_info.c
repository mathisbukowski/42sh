/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_info.c
*/

#include "minishell.h"
#include "utils.h"

redirections_t *init_redirection(void)
{
    redirections_t *redirections = malloc(sizeof(redirections_t));

    if (redirections == NULL)
        return NULL;
    redirections->fd = -1;
    redirections->redirect_index = -1;
    redirections->type = -1;
    return redirections;
}

job_manager_t *init_jobs(void)
{
    job_manager_t *jobs = malloc(sizeof(job_manager_t));

    if (jobs == NULL)
        return NULL;
    jobs->ampersand = 0;
    jobs->list = NULL;
    jobs->next_job_id = 0;
    return jobs;
}

char *get_full_path(info_t *info, const char *subdir, const char *filename)
{
    char *dir = info->current_dir;
    size_t len;
    char *path;

    if (dir == NULL)
        return NULL;
    len = strlen(dir) + strlen(subdir) + strlen(filename) + 3;
    path = malloc(len);
    if (!path)
        return NULL;
    sprintf(path, "%s/%s/%s", dir, subdir, filename);
    return path;
}

int init_info_fields(info_t *info)
{
    memset(info, 0, sizeof(info_t));
    if (init_current_dir(info))
        return 1;
    info->redirections = init_redirection();
    if (!info->redirections)
        return 1;
    info->jobs = init_jobs();
    if (!info->jobs)
        return 1;
    info->history_path = get_full_path(info, "tmp", "history.txt");
    if (!info->history_path)
        return 1;
    info->tmp_path = get_full_path(info, "tmp", "tmp.txt");
    if (!info->tmp_path)
        return 1;
    info->previous_dir = calloc(MAX_PATH_SIZE, sizeof(char));
    if (!info->previous_dir)
        return 1;
    return 0;
}

void free_init(info_t *info)
{
    free(info->redirections);
    free(info->jobs);
    free(info->history_path);
    free(info->tmp_path);
    free(info->current_dir);
    free(info->previous_dir);
    free(info);
}
