/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** input.c
*/

#include "minishell.h"
#include "utils.h"

char *format_dir(info_t *info, char *dir)
{
    char *new_dir;
    char *home_path = info->home_var;

    if (home_path == NULL)
        return strdup(dir);
    new_dir = calloc(strlen(dir), sizeof(char));
    if (new_dir == NULL)
        return strdup(dir);
    if (strncmp(home_path, dir, strlen(home_path)) == 0) {
        strcat(new_dir, "~");
        strcat(new_dir, dir + strlen(home_path));
    } else {
        free(new_dir);
        return strdup(dir);
    }
    return new_dir;
}

void display_input(info_t *info)
{
    char *formatted_dir = format_dir(info, info->current_dir);
    char *git_branch_name = NULL;

    if (git_branch_name == NULL)
        printf("\n╭─ %s%s\n", CBLU, formatted_dir);
    else
        printf("\n╭─ %s%s \uE0B1 %s", CBLU, formatted_dir,
            git_branch_name);
    printf("%s╰─  ", CNRM);
    free(formatted_dir);
    free(git_branch_name);
}
