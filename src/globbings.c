/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** globbings.c
*/

#include <glob.h>
#include "minishell.h"
#include "my.h"

static int is_valid_merge_strdup(char **result_arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (result_arr[i] == NULL)
            return 0;
    }
    return 1;
}

static char **get_file_from_glob(glob_t globbuf)
{
    char **match = NULL;
    int i;

    match = malloc(sizeof(char *) * (get_str_array_len(globbuf.gl_pathv) + 2));
    if (match == NULL)
        return NULL;
    for (i = 0; globbuf.gl_pathv[i] != NULL; i++) {
        match[i] = strdup(globbuf.gl_pathv[i]);
        if (match[i] == NULL) {
            match[i] = NULL;
            free_str_array(match);
            return NULL;
        }
    }
    match[i] = NULL;
    return match;
}

char **get_globbings_by_pattern(char *pattern)
{
    glob_t globbuf;
    int err = 0;
    char **files;

    globbuf.gl_offs = 2;
    err = glob(pattern, GLOB_ERR, NULL, &globbuf);
    if (err != 0 && err != GLOB_NOMATCH) {
        fprintf(stderr, "Glob error.");
        exit(84);
    }
    if (err == GLOB_NOMATCH)
        return NULL;
    files = get_file_from_glob(globbuf);
    globfree(&globbuf);
    return files;
}

static void merge_args_and_globs(info_t *info, char **paths, int index)
{
    int nb_args = get_str_array_len(info->args);
    int nb_path = get_str_array_len(paths);
    char **result_arr = malloc(sizeof(char *) * (nb_args + nb_path + 1));
    int i;

    for (i = 0; i < index; i++)
        result_arr[i] = strdup(info->args[i]);
    for (; i < index + nb_path; i++)
        result_arr[i] = strdup(paths[i - index]);
    for (; i < nb_path + nb_args; i++)
        result_arr[i] = strdup(info->args[i - nb_path]);
    result_arr[i] = NULL;
    if (!is_valid_merge_strdup(result_arr, (nb_args + nb_path + 1))) {
        free_str_array(result_arr);
        return;
    }
    free_str_array(info->args);
    info->args = result_arr;
}

int handle_globbings(info_t *info)
{
    char **paths;

    for (int i = 0; info->args[i] != NULL; i++) {
        paths = get_globbings_by_pattern(info->args[i]);
        if (paths == NULL)
            continue;
        if (strcmp(paths[0], info->args[i]) != 0) {
            merge_args_and_globs(info, paths, i);
            i += get_str_array_len(paths) - 1;
        }
        free_str_array(paths);
    }
    return 0;
}
