/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** hist_command.c
*/

#include <time.h>
#include "minishell.h"
#include "commands.h"

int command_history(info_t *info)
{
    char line[1024];
    FILE *file = fopen(info->history_path, "r");

    if (file != NULL) {
        while (fgets(line, sizeof(line), file))
            fputs(line, stdout);
        fclose(file);
        return 0;
    } else {
        fclose(file);
        return 1;
    }
}

int process_command(info_t *info)
{
    info->input[strcspn(info->input, "\n")] = 0;
    write_command_to_file(info);
    return 0;
}

int read_input(info_t *info, char *command)
{
    if (strlen(command) == 0)
        return 1;
    info->input = strdup(command);
    process_command(info);
    free(info->input);
    return 0;
}
