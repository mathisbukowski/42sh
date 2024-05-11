/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** line_edition.c
*/

#include "minishell.h"
#include "exit.h"
#include "my.h"

static void handle_arrow_keys(int *position, char *buffer, const char c)
{
    if (c != '\033')
        return;
    getchar();
    switch (getchar()) {
        case 'C':
            if (*position < my_strlen(buffer))
                (*position)++;
            break;
        case 'D':
            if (*position > 0)
                (*position)--;
            break;
    }
}

static void handle_backspace(int *position, char *buffer)
{
    if (*position > 0) {
        memmove(&buffer[*position - 1], &buffer[*position],
            my_strlen(buffer) - *position + 1);
        (*position)--;
        if (*position == my_strlen(buffer))
            buffer[*position] = '\0';
        printf("\r%s╰─  %s ", CNRM, buffer);
        for (int i = 0; i < my_strlen(buffer) - *position; i++)
            printf("\b");
    }
}

static void handle_character_input(int *position, char *buffer, int c)
{
    if (c == 8 || c == 11 || c == 12 || c == 15 || c == 26)
        return;
    if (*position >= COMMAND_INPUT_SIZE)
        return;
    memmove(&buffer[*position + 1], &buffer[*position],
            my_strlen(buffer) - *position);
    buffer[*position] = c;
    (*position)++;
}

static void handle_ctrl_combination(int *position, char *buffer, int c,
    info_t *info)
{
    if (c == 4) {
        printf("exit\n");
        exit_main_process(info);
    }
    if (c == 3) {
        memset(buffer, 0, COMMAND_INPUT_SIZE);
        *position = 0;
    }
}

//TODO : handle TCSH tabulation instead of replacing by space
void handle_input(int *position, char *buffer, info_t *info)
{
    int c = getchar();

    while (c != '\n' && c != EOF && c != 3) {
        handle_ctrl_combination(position, buffer, c, info);
        handle_arrow_keys(position, buffer, c);
        if (c == 127 || c == 8)
            handle_backspace(position, buffer);
        if (c != '\033' && c != 127 && c != '\t')
            handle_character_input(position, buffer, c);
        if (c == '\t')
            handle_character_input(position, buffer, ' ');
        printf("\r%s╰─  %s", CNRM, buffer);
        for (int i = 0; i < my_strlen(buffer) - *position; i++)
            printf("\b");
        c = getchar();
    }
    if (c == EOF)
        exit_main_process(info);
}
