/*
** EPITECH PROJECT, 2023
** Pool day 08 : Task 04
** File description:
** A function that splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell
** contains the address of a string (representing a word).
** The last cell must be null to terminate the array.
*/

#include <stdlib.h>
#include "my.h"

static int is_delimiter(const char *str, char **delimiters,
    int delim_index)
{
    int delimiter_length;

    if (!str || !delimiters)
        return 0;
    for (int i = 0; i < delim_index; i++) {
        delimiter_length = my_strlen(delimiters[i]);
        if (my_strncmp(str, delimiters[i], delimiter_length) == 0)
            return delimiter_length;
    }
    return 0;
}

static const char *find_word_end(const char *str, char **delimiters,
    int delim_index)
{
    while (*str != '\0' && !is_delimiter(str, delimiters, delim_index)) {
        str++;
    }
    return str;
}

static int count_words_in_array(const char *str, char **delimiters,
    int delim_index)
{
    int count = 0;
    int i = 0;
    int del_len = 0;
    char const *word_end = NULL;

    if (!str)
        return 0;
    while (str[i] != '\0') {
        del_len = is_delimiter(&str[i], delimiters, delim_index);
        while (del_len > 0) {
            i += del_len;
            del_len = is_delimiter(&str[i], delimiters, delim_index);
        }
        if (str[i] != '\0') {
            count++;
            word_end = find_word_end(&str[i], delimiters, delim_index);
            i = word_end - str;
        }
    }
    return count;
}

static void process_word(stwa_t *params, int *i)
{
    char const *end_word = find_word_end(&(params->str[*i]),
    params->delimiters, params->delim_index);
    int start = *i;
    int word_length = end_word - &(params->str[start]);

    params->words[*(params->word_index)] = malloc(word_length + 1);
    my_strncpy(params->words[*(params->word_index)], &(params->str[start]),
    word_length);
    params->words[*(params->word_index)][word_length] = '\0';
    (*(params->word_index))++;
    *i = end_word - params->str;
}

char **my_str_to_word_array(char *str, char **delims, int delim_index)
{
    int num_words = count_words_in_array(str, delims, delim_index);
    char **words = malloc((num_words + 1) * sizeof(char *));
    int word_index = 0;
    int del_len;
    stwa_t params = {str, delims, delim_index, words, &word_index};
    int j = 0;

    for (int i = 0; str != NULL && str[i] != '\0';) {
        del_len = is_delimiter(&str[i], delims, delim_index);
        for (; del_len > 0; i += del_len)
            del_len = is_delimiter(&str[i], delims, delim_index);
        if (str[i] != '\0') {
            j = i;
            process_word(&params, &j);
            i += my_strlen(words[word_index - 1]);
        }
    }
    words[num_words] = NULL;
    return words;
}

void free_str_array(char **arr)
{
    int i = 0;

    while (arr[i]) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int get_str_array_len(char **arr)
{
    int i = 0;

    while (arr[i]) {
        i++;
    }
    return i - 1;
}
