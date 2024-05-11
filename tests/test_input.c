/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** input.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../include/utils.h"

Test(format_dir, test_format_dir)
{
    info_t *info = malloc(sizeof(info_t));
    info->env = malloc(sizeof(char *) * 2);
    info->env[0] = strdup("HOME=/home/mathis");
    info->env[1] = NULL;
    char *dir = strdup("/home/mathis/42sh");
    char *result = format_dir(info, dir);
    cr_assert_str_eq(result, "/home/mathis/42sh");
    free(result);
    free(dir);
    free(info->env[0]);
    free(info->env);
    free(info);
}

void setup(void)
{
    cr_redirect_stdout();
}

Test(display_input, test_display_input, .init = setup)
{
    char *env[] = {"PWD=/home", "HOME=/home/rafaeldrouart", NULL};
    info_t *info = init_info(env);

    char *expected_output = "\n╭─ \x1B[34m~/delivery/Epitech-1ere_annee/PSU-200/42sh\n\x1B[0m╰─  ";
    display_input(info);
    fflush(stdout); // Ensure all output has been written to stdout

    FILE *actual_output_file = cr_get_redirected_stdout();
    char actual_output[1024];
    fread(actual_output, sizeof(char), 2048, actual_output_file);

    if (strcmp(actual_output, expected_output) != 0) {
        printf("Expected:\n%s\n", expected_output);
        printf("Actual:\n%s\n", actual_output);
        printf("Expected in hex:\n");
        for (int i = 0; expected_output[i]; i++)
            printf("%02x ", expected_output[i]);
        printf("\nActual in hex:\n");
        for (int i = 0; actual_output[i]; i++)
            printf("%02x ", actual_output[i]);
        printf("\n");
    }
    cr_assert_str_eq(actual_output, expected_output);

    // Free the info structure
    // free_info(info);
}