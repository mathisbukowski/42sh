/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** utils_env.c
*/

#include "minishell.h"
#include "env.h"
#include "my.h"

int init_env(info_t *info, char **env)
{
    info->env = copy_env(env);
    if (info->env == NULL)
        return 1;
    info->home_var = get_env_value(info, "HOME");
    if (info->home_var == NULL)
        return 1;
    return 0;
}

char **copy_env(char **env)
{
    char **env_copy;
    int i = 0;

    for (; env[i] != NULL; i++);
    env_copy = malloc(sizeof(char *) * (i + 1));
    if (env_copy == NULL)
        return NULL;
    for (i = 0; env[i] != NULL; i++) {
        env_copy[i] = calloc((my_strlen(env[i]) + 2), sizeof(char *));
        if (env_copy[i] == NULL) {
            free_str_array(env_copy);
            return NULL;
        }
        env_copy[i][0] = '\0';
        strcpy(env_copy[i], env[i]);
    }
    env_copy[i] = NULL;
    return env_copy;
}

char *get_env_value(info_t *info, char *key)
{
    char *value;
    char **line_tmp;
    char *delim[] = {"=", NULL};
    size_t key_len = strlen(key);

    for (int i = 0; info->env[i] != NULL; i++) {
        if (strncmp(info->env[i], key, key_len) == 0) {
            line_tmp = my_str_to_word_array(info->env[i], delim, 1);
            value = malloc(sizeof(char) * (my_strlen(line_tmp[1]) + 2));
            value[0] = '\0';
            strcpy(value, line_tmp[1]);
            free_str_array(line_tmp);
            return value;
        }
    }
    return NULL;
}
