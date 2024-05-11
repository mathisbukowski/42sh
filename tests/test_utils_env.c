/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_utils_env.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include "../include/env.h"

Test(copy_env, test_copy_env)
{
    char *env[] = {"PATH=/usr/bin", "HOME=/home", "USER=alex", NULL};
    char **env_copy = copy_env(env);

    cr_assert_str_eq(env_copy[0], "PATH=/usr/bin");
    cr_assert_str_eq(env_copy[1], "HOME=/home");
    cr_assert_str_eq(env_copy[2], "USER=alex");
    cr_assert_null(env_copy[3]);
}

Test(get_env_value, should_return_value_for_existing_key)
{
    info_t info;
    char *env[] = {"PATH=/usr/bin", "HOME=/home", "USER=alex", NULL};
    char *key = "PATH";
    char *expected_value = "/usr/bin";

    info.env = copy_env(env);
    char *actual_value = get_env_value(&info, key);

    cr_assert_str_eq(actual_value, expected_value, "Expected value was %s, but got %s", expected_value, actual_value);

    free(actual_value);
    free_str_array(info.env);
}

Test(get_env_value, should_return_null_for_non_existing_key)
{
    info_t info;
    char *env[] = {"PATH=/usr/bin", "HOME=/home", "USER=alex", NULL};
    char *key = "NON_EXISTING_KEY";

    info.env = copy_env(env);
    char *actual_value = get_env_value(&info, key);

    cr_assert_null(actual_value, "Expected NULL, but got %s", actual_value);

    free(actual_value);
    free_str_array(info.env);
}