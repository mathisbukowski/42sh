/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** main.c
*/

#include <fcntl.h>
#include "minishell.h"
#include "exit.h"
#include "utils.h"

int main(int argc, char **argv, char **env)
{
    info_t *info = init_info(env);
    int status = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            display_help_usage();
            return 0;
        }
    }
    info->history_fd = open(info->history_path, O_RDWR | O_APPEND | O_CREAT,
    0666);
    init_signals(info);
    if (!isatty(STDIN_FILENO)) {
        handle_stdin_input(info);
        status = info->status;
        exit_echo(info, status);
    } else {
        execute_minishell(info);
        exit_main_process(info);
    }
}
