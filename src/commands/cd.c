/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** cd.c
*/

#include "minishell.h"
#include "commands.h"
#include "env.h"
#include "utils.h"
#include "my.h"

static void cond(char *home_path, info_t *info, int nb_args, int *status)
{
    if (home_path == NULL)
        home_path = my_strdup(info->home_var);
    if ((nb_args == 0 || my_strcmp(info->args[1], "~") == 0)
        && home_path != NULL)
        *status = chdir(home_path);
    if (nb_args == 1 && my_strcmp(info->args[1], "-") == 0)
        *status = chdir(info->previous_dir);
    if (*status == 404 && nb_args == 1)
        *status = chdir(info->args[1]);
    if (*status == -1){
        print_error_errno(info->args[1]);
        *status = 1;
    }
}

int command_cd(info_t *info)
{
    int status = 404;
    char *home_path = get_env_value(info, "HOME");
    int nb_args = get_str_array_len(info->args);
    char *previous_dir = info->current_dir;

    cond(home_path, info, nb_args, &status);
    if (status != -1 && previous_dir != NULL)
        strcpy(info->previous_dir, previous_dir);
    update_current_dir(info);
    free(home_path);
    return status;
}
