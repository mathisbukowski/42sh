/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** git_utils.c
*/

#include <sys/stat.h>
#include "minishell.h"
#include "utils.h"

char *check_if_git_dir_exist(char *dir)
{
    char path[strlen(dir) + 5];
    struct stat sb;

    path[0] = 0;
    strcat(path, dir);
    strcat(path, ".git");
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        return strdup(path);
    }
    return NULL;
}

char *get_git_src_dir(char *base_dir)
{
    char current_dir[MAX_PATH_SIZE];
    char *tmp = NULL;
    struct stat sb;

    strcpy(current_dir, base_dir);
    strcat(current_dir, "/");
    while (strcmp(current_dir, "/../") != 0) {
        if ((stat(current_dir, &sb) == 0 && S_ISDIR(sb.st_mode)))
            tmp = check_if_git_dir_exist(current_dir);
        else
            break;
        if (tmp != NULL)
            return tmp;
        strcat(current_dir, "../");
    }
    free(tmp);
    return NULL;
}

char *get_branch_name_from_file(char *file_path)
{
    FILE *fptr = fopen(file_path, "r");
    char buff[128];
    char *last;
    char *output;

    if (fptr == NULL)
        return NULL;
    fgets(buff, sizeof(buff), fptr);
    last = strrchr(buff, '/');
    if (last == NULL) {
        fclose(fptr);
        return NULL;
    }
    output = strdup(last + 1);
    fclose(fptr);
    return output;
}

char *get_dir_git_branch(char *dir)
{
    char *git_dir = get_git_src_dir(dir);
    char file_path[strlen(git_dir) + 6];
    char *tmp = NULL;

    if (git_dir == NULL)
        return NULL;
    file_path[0] = '\0';
    strcpy(file_path, git_dir);
    strcat(file_path, "/HEAD");
    if (access(file_path, R_OK) == 0)
        tmp = get_branch_name_from_file(file_path);
    free(git_dir);
    return tmp;
}
