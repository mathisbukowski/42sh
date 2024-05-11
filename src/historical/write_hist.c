/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** write_hist.c
*/

#include <time.h>
#include "minishell.h"

void write_command_to_file(info_t *info)
{
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buffer[200];

    snprintf(buffer, sizeof(buffer), "%d %02d:%02d:%02d %s\n",
    info->command_count, tm_info->tm_hour, tm_info->tm_min,
    tm_info->tm_sec, info->input);
    if (info->history_fd != -1) {
        write(info->history_fd, buffer, strlen(buffer));
        info->command_count += 1;
    } else {
        perror("Erreur lors de l'ouverture du fichier d'historique");
        return;
    }
}
