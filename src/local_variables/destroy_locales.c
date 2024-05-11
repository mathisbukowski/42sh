/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** destroy_locales.c
*/

#include "minishell.h"

void destroy_locales(local_var_t *head)
{
    local_var_t *current = head;
    local_var_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
    }
}
