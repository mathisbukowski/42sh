/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main_shell.c
*/

#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"
#include "env.h"
#include "utils.h"
#include "my.h"

int run_commands(info_t *info)
{
    int exit = 0;
    char *delim[] = {";", NULL};

    info->command_list = my_str_to_word_array(info->tmp_input, delim, 1);
    for (int i = 0; info->command_list[i] != NULL; i++) {
        info->input = clean_str(info->command_list[i]);
        if (my_strcmp(info->input, "exit") == 0){
            exit = 1;
            free(info->input);
            continue;
        }
        if (handle_double_pipe_and(info)) {
            free(info->input);
            break;
        }
        free(info->input);
    }
    free_str_array(info->command_list);
    return exit;
}

static int get_command(char *buffer, info_t *info)
{
    if (info->tmp_input != NULL)
        free(info->tmp_input);
    info->tmp_input = malloc(strlen(buffer) + 1);
    strcpy(info->tmp_input, buffer);
    write(0, "\n", 1);
    return run_commands(info);
}

static void reset_input(char *buffer, int *position)
{
    memset(buffer, 0, my_strlen(buffer));
    *position = 0;
}

int execute_minishell(info_t *info)
{
    int position = 0;
    char buffer[COMMAND_INPUT_SIZE] = {0};

    enable_raw_mode();
    while (1) {
        display_input(info);
        handle_input(&position, buffer, info);
        if (read_input(info, buffer)) {
            reset_input(buffer, &position);
            continue;
        }
        if (get_command(buffer, info))
            break;
        reset_input(buffer, &position);
    }
    disable_raw_mode();
    return 0;
}

int handle_stdin_input(info_t *info)
{
    size_t size = COMMAND_INPUT_SIZE;

    info->tmp_input = malloc(sizeof(char *) * (size + 1));
    while (getline(&info->tmp_input, &size, stdin) != -1) {
        info->tmp_input[my_strlen(info->tmp_input) - 1] = '\0';
        run_commands(info);
        if (info->status != 0) {
            free(info->tmp_input);
            return 1;
        }
    }
    if (info->tmp_input != NULL)
        free(info->tmp_input);
    return 0;
}

info_t *init_info(char **env)
{
    info_t *info = malloc(sizeof(info_t));

    if (!info)
        return NULL;
    if (init_info_fields(info) || init_env(info, env)) {
        free_init(info);
        exit(84);
    }
    return info;
}
