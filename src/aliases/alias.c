/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias.c
*/

#include "minishell.h"
#include "commands.h"

aliases_t *create_new_alias(aliases_t **head, aliases_t *prev, info_t *info)
{
    aliases_t *new_node = malloc(sizeof(aliases_t));

    if (new_node == NULL)
        return NULL;
    new_node->alias = strdup(info->args[1]);
    new_node->command = strdup(info->args[2]);
    if (!new_node->alias || !new_node->command) {
        free(new_node->alias);
        free(new_node->command);
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

void display_aliases(info_t *info)
{
    aliases_t *current = info->aliases;

    if (current == NULL) {
        printf("None alias was provided.\n");
        return;
    }
    while (current != NULL) {
        printf("%s='%s'\n", current->alias, current->command);
        current = current->next;
    }
}

static int already_define(aliases_t *current, aliases_t **prev, info_t *info)
{
    while (current != NULL) {
        if (strcmp(current->alias, info->args[1]) == 0) {
            free(current->command);
            current->command = strdup(info->args[2]);
            return 0;
        }
        (*prev) = current;
        current = current->next;
    }
    return 1;
}

int command_alias(info_t *info)
{
    aliases_t *current = info->aliases;
    aliases_t *prev = NULL;
    aliases_t *new_node = NULL;

    if (info->args[1] == NULL) {
        display_aliases(info);
        return 0;
    }
    if (info->args[1] != NULL && !info->args[2])
        return 1;
    if (already_define(current, &prev, info) == 0)
        return 0;
    new_node = create_new_alias(&(info->aliases), prev, info);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new alias.\n");
        return 1;
    }
    return 0;
}
