/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_error_utils.c
*/

#include <errno.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../include/utils.h"

Test(print_command_not_found_error, test_print_command_not_found_error)
{
    cr_redirect_stderr();
    print_command_not_found_error("ls");
    cr_assert_stderr_eq_str("ls: Command not found.\n");
}

Test(print_error_errno, test_print_error_errno)
{
    cr_redirect_stderr();
    errno = ENOENT;
    print_error_errno("ls");
    cr_assert_stderr_eq_str("ls: No such file or directory.\n");
}

Test(print_error, test_print_error)
{
    cr_redirect_stderr();
    print_error("ls", "error");
    cr_assert_stderr_eq_str("ls: error\n");
}

Test(print_error_message, test_print_error_message)
{
    cr_redirect_stderr();
    print_error_message("error");
    cr_assert_stderr_eq_str("error");
}