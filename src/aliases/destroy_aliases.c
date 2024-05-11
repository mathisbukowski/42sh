/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** destroy_aliases.c
*/

#include "minishell.h"

void destroy_aliases(aliases_t *head)
{
    aliases_t *current = head;
    aliases_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->alias);
        free(tmp->command);
        free(tmp);
    }
}
