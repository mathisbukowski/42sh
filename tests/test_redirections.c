/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_redirections.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include "../include/utils.h"

Test(open_file_write, should_open_file)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->redirections->type = E_WRITE;
    int fd = open_file_for_redirect(info, "test.txt");

    cr_assert_neq(fd, -1);
    close(fd);
}

Test(open_file_append, should_open_file)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->redirections->type = E_APPEND;
    int fd = open_file_for_redirect(info, "test.txt");

    cr_assert_neq(fd, -1);
    close(fd);
}

Test(open_file_error, should_print_error)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->redirections->type = E_WRITE;
    int fd = open_file_for_redirect(info, "/root/test.txt");

    cr_assert_eq(fd, -1);
}

Test(delete_args_after_redirection, should_delete_args)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info = init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">");
    info->args[2] = my_strdup("test.txt");
    info->args[3] = NULL;

    delete_args_after_redirection(info, 0);
    cr_assert_null(info->args[1]);
    cr_assert_null(info->args[2]);
}

Test(get_redirection_index, should_get_redirection_index)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">");
    info->args[2] = my_strdup("test.txt");
    info->args[3] = NULL;

    get_redirection_index(info);

    cr_assert_eq(info->redirections->redirect_index, 1);
    cr_assert_eq(info->redirections->type, E_WRITE);
}

Test(get_redirection_index_append, should_get_redirection_index)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">>");
    info->args[2] = my_strdup("test.txt");
    info->args[3] = NULL;

    get_redirection_index(info);

    cr_assert_eq(info->redirections->redirect_index, 1);
    cr_assert_eq(info->redirections->type, E_APPEND);
}

Test(get_redirection_index_no_redirection, should_not_get_redirection_index)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 3);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup("-l");
    info->args[2] = NULL;

    get_redirection_index(info);

    cr_assert_eq(info->redirections->redirect_index, -1);
}

Test(handle_redirections, should_handle_redirections)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">");
    info->args[2] = my_strdup("test.txt");
    info->args[3] = NULL;

    handle_redirections(info);

    cr_assert_eq(info->redirections->fd, 9);
    cr_assert_null(info->args[1]);
    cr_assert_null(info->args[2]);
}

Test(handle_redirections_no_redirection, should_not_handle_redirections)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 3);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup("-l");
    info->args[2] = NULL;

    int ret = handle_redirections(info);

    cr_assert_eq(ret, 0);
}

Test(handle_redirections_no_filename, should_print_error)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 3);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">");
    info->args[2] = NULL;

    int ret = handle_redirections(info);

    cr_assert_eq(ret, 1);
}

Test(handle_redirections_error, should_print_error)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">");
    info->args[2] = my_strdup("/root/test.txt");
    info->args[3] = NULL;

    int ret = handle_redirections(info);

    cr_assert_eq(ret, 1);
}

Test(handle_redirections_append, should_handle_redirections)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">>");
    info->args[2] = my_strdup("test.txt");
    info->args[3] = NULL;

    handle_redirections(info);

    cr_assert_eq(info->redirections->fd, 9);
    cr_assert_null(info->args[1]);
    cr_assert_null(info->args[2]);
}

Test(handle_redirections_error_append, should_print_error)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 4);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">>");
    info->args[2] = my_strdup("/root/test.txt");
    info->args[3] = NULL;

    int ret = handle_redirections(info);

    cr_assert_eq(ret, 1);
}

Test(handle_redirections_no_filename_append, should_print_error)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 3);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup(">>");
    info->args[2] = NULL;

    int ret = handle_redirections(info);

    cr_assert_eq(ret, 1);
}

Test(handle_redirections_no_redirection_append, should_not_handle_redirections)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/usr/bin");
    env[1] = NULL;
    info_t *info= init_info(env);
    info->args = malloc(sizeof(char *) * 3);
    info->args[0] = my_strdup("ls");
    info->args[1] = my_strdup("-l");
    info->args[2] = NULL;

    int ret = handle_redirections(info);

    cr_assert_eq(ret, 0);
}