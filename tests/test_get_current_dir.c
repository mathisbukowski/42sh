/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_get_current_dir.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/utils.h"

Test(get_current_dir, should_return_current_dir)
{
    char *env[] = {"PWD=/home", NULL};
    info_t *info = init_info(env);
    init_current_dir(info);
    cr_assert_not_null(info->current_dir, "Expected a directory, but got NULL");
    char expected_dir[MAX_PATH_SIZE];
    getcwd(expected_dir, MAX_PATH_SIZE);
    cr_assert_str_eq(info->current_dir, expected_dir, "Expected directory was %s, but got %s", expected_dir, info->current_dir);
    free(info->current_dir);
    free(info);
}
