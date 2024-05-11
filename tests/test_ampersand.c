/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_ampersand.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include "../include/jobs.h"

Test(detect_ampersand, test_ampersand)
{
    info_t *info = malloc(sizeof(info_t));
    info->jobs = malloc(sizeof(job_manager_t));
    info->jobs->ampersand = 0;
    char *line = my_strdup("ls -l &");

    detect_ampersand(info, line);
    cr_assert_eq(info->jobs->ampersand, 1);
    free(info->jobs);
    free(info);
    free(line);
}

Test(detect_ampersand, test_no_ampersand)
{
    info_t *info = malloc(sizeof(info_t));
    info->jobs = malloc(sizeof(job_manager_t));
    info->jobs->ampersand = 0;
    char *line = my_strdup("ls -l");

    detect_ampersand(info, line);
    cr_assert_eq(info->jobs->ampersand, 0);
    free(info->jobs);
    free(info);
    free(line);
}