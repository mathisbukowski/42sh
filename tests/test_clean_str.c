/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** test_clean_str.c
*/

#include <criterion/criterion.h>
#include "../include/minishell.h"
#include "../include/utils.h"


Test(is_there_word_after, test_is_there_word_after)
{
    char *str = "  hello   world  ";
    int status = is_there_word_after(str, 0);
    cr_assert_eq(status, 1);
}

Test(append, test_append)
{
    char *str = malloc(100);
    str[0] = '\0';
    append(str, 'h');
    append(str, 'e');
    append(str, 'l');
    append(str, 'l');
    append(str, 'o');
    cr_assert_str_eq(str, "hello");
}

Test(add_letter, test_add_letter)
{
    char *cleanedStr = malloc(100);
    cleanedStr[0] = '\0';
    int has_word = 0;
    add_letter(cleanedStr, 'h', &has_word, 1);
    add_letter(cleanedStr, 'e', &has_word, 1);
    add_letter(cleanedStr, 'l', &has_word, 1);
    add_letter(cleanedStr, 'l', &has_word, 1);
    add_letter(cleanedStr, 'o', &has_word, 0);
    add_letter(cleanedStr, ' ', &has_word, 1);
    cr_assert_str_eq(cleanedStr, "hello ");
}

Test(add_letter, test_add_letter2)
{
    char *cleanedStr = malloc(100);
    cleanedStr[0] = '\0';
    int has_word = 0;
    add_letter(cleanedStr, 'h', &has_word, 1);
    add_letter(cleanedStr, 'e', &has_word, 1);
    add_letter(cleanedStr, 'l', &has_word, 1);
    add_letter(cleanedStr, 'l', &has_word, 1);
    add_letter(cleanedStr, 'o', &has_word, 0);
    add_letter(cleanedStr, ' ', &has_word, 1);
    cr_assert_str_eq(cleanedStr, "hello ");
}

Test(add_letter, test_add_letter3)
{
    char *cleanedStr = malloc(100);
    cleanedStr[0] = '\0';
    int has_word = 0;
    add_letter(cleanedStr, 'h', &has_word, 1);
    add_letter(cleanedStr, 'e', &has_word, 1);
    add_letter(cleanedStr, 'l', &has_word, 1);
    add_letter(cleanedStr, 'l', &has_word, 1);
    add_letter(cleanedStr, 'o', &has_word, 0);
    cr_assert_str_eq(cleanedStr, "hello");
}

Test(clean_str, test_clean_str)
{
    char *str = "  hello   world  ";
    char *cleanedStr = clean_str(str);
    cr_assert_str_eq(cleanedStr, "hello world");
}

Test(is_there_word_after, test_non_space_character_after)
{
    char *str = "hello world";
    int status = is_there_word_after(str, 5);
    cr_assert_eq(status, 1);
}

Test(add_letter, test_add_non_space_character)
{
    char *cleanedStr = malloc(100);
    cleanedStr[0] = '\0';
    int has_word = 0;
    add_letter(cleanedStr, 'h', &has_word, 1);
    cr_assert_str_eq(cleanedStr, "h");
}

Test(add_letter, test_add_space_with_word_after)
{
    char *cleanedStr = malloc(100);
    cleanedStr[0] = '\0';
    int has_word = 1;
    add_letter(cleanedStr, ' ', &has_word, 1);
    cr_assert_str_eq(cleanedStr, " ");
}