/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** my_realloc.c
*/

#include <stdlib.h>
#include "my.h"

void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr = malloc(new_size);

    if (new_ptr) {
        my_memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }
    return new_ptr;
}
