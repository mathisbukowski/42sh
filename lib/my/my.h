/*
** EPITECH PROJECT, 2023
** Pool day 09 : Task 02
** File description:
** Header for libmy
*/

#ifndef MY_H
    #define MY_H
// STWA STRUCTURE
typedef struct stwa_s {
    char const *str;
    char **delimiters;
    int delim_index;
    char **words;
    int *word_index;
}stwa_t;

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime_sub(int nb);
int get_int_len(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *txt);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_memset(char *pointer, int value, int count);
void my_char_memmove(char *dest, const char *src);
char **my_str_to_word_array(char *str, char **delimiters, int num_delimiters);
void free_str_array(char **arr);
int get_str_array_len(char **arr);
int my_show_word_array(char const **tab);
int get_str_size(char const *str);
int my_getnbr(char const *str);
void prepare_word_alloc(int *, int *, int *, const char *);
int my_put_errorstr(char const *str);
void int_to_str(int n, char *str);
char *positive_int_to_str(int nb);
void float_to_str(double nb, char *str, int precision);
int my_round(double nb);
void *my_memcpy(void *dest, void *src, int len);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int my_printf(const char *str, ...);

#endif
