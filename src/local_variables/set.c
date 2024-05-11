/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set.c
*/

#include "minishell.h"
#include "commands.h"

local_var_t *create_new_var(local_var_t **head,
    local_var_t *prev, info_t *info)
{
    local_var_t *new_node = malloc(sizeof(local_var_t));

    if (new_node == NULL)
        return NULL;
    new_node->name = strdup(info->args[1]);
    new_node->value = strdup(info->args[2]);
    if (!new_node->name || !new_node->value) {
        free(new_node->name);
        free(new_node->value);
        free(new_node);
        return NULL;
    }
    new_node->next = NULL;
    if (prev != NULL)
        prev->next = new_node;
    else
        *head = new_node;
    return new_node;
}

void display_list_locales(info_t *info)
{
    local_var_t *current = info->locale;

    if (current == NULL) {
        printf("None variable was provided.\n");
        return;
    }
    while (current != NULL) {
        printf("%s='%s'\n", current->name, current->value);
        current = current->next;
    }
}

static int is_already_in(local_var_t *current,
    local_var_t **prev, info_t *info)
{
    while (current != NULL) {
        if (strcmp(current->name, info->args[1]) == 0) {
            free(current->value);
            current->value = strdup(info->args[2]);
            return 0;
        }
        (*prev) = current;
        current = current->next;
    }
    return 1;
}

int command_set(info_t *info)
{
    local_var_t *current = info->locale;
    local_var_t *prev = NULL;
    local_var_t *new_node = NULL;

    if (info->args[1] == NULL) {
        display_list_locales(info);
        return 0;
    }
    if (info->args[1] != NULL && !info->args[2])
        return 1;
    if (is_already_in(current, &prev, info) == 0)
        return 0;
    new_node = create_new_var(&(info->locale), prev, info);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new local.\n");
        return 1;
    }
    return 0;
}
