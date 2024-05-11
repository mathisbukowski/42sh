/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_get_current_git_branch.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/utils.h"


Test(check_if_git_dir_exist, valid_git_dir_exists)
{
    char *result = check_if_git_dir_exist("./");
    cr_assert_not_null(result, "Valid git directory not detected.");
    free(result);
}

Test(check_if_git_dir_exist, invalid_git_dir)
{
    char *result = check_if_git_dir_exist("./invalid_dir");
    cr_assert_null(result, "Invalid git directory detected.");
}

Test(get_git_src_dir, valid_src_dir_found)
{
    char *result = get_git_src_dir("./");
    cr_assert_not_null(result, "Valid source directory not found.");
    free(result);
}

Test(get_git_src_dir, invalid_src_dir)
{
    char *result = get_git_src_dir("./invalid_dir");
    cr_assert_null(result, "Invalid source directory detected.");
}

Test(get_branch_name_from_file, valid_file_path)
{
    char *result = get_branch_name_from_file("./.git/HEAD");
    cr_assert_not_null(result, "Valid branch name not found.");
    free(result);
}

Test(get_branch_name_from_file, invalid_file_path)
{
    char *result = get_branch_name_from_file("./invalid");
    cr_assert_null(result, "Invalid file path detected.");
    free(result);
}

Test(get_dir_git_branch, valid_dir_git_branch)
{
    char *result = get_dir_git_branch("./");
    cr_assert_not_null(result, "Valid git branch not found.");
    free(result);
}
