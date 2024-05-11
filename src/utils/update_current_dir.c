/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** get_current_dir.c
*/

#include "minishell.h"
#include "utils.h"

int init_current_dir(info_t *info)
{
    info->current_dir = calloc(MAX_PATH_SIZE, sizeof(char));
    if (info->current_dir == NULL)
        return 1;
    return update_current_dir(info);
}

int update_current_dir(info_t *info)
{
    if (info->current_dir == NULL)
        return 1;
    if (getcwd(info->current_dir, MAX_PATH_SIZE) == NULL) {
        info->current_dir = NULL;
        return 1;
    }
    return 0;
}
