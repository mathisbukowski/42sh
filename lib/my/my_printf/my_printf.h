/*
** EPITECH PROJECT, 2023
** my_printf_h
** File description:
** header file with all the necessary prototypes for myprintf project
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

int my_printf(const char *str, ...);
int get_int_len(int integer);
void print_space_before_flags(const char *str, int *indexPosition, char flag);
int is_valid_flag(char letter);
typedef struct handle_params_t {
    int nb_char;
    va_list *params;
    char *str;
    char flag;
    int i;
    int precision;
    int width;
} handle_params_t;
int my_isnum(char c);
void print_n_char(int nbSpace, char c, handle_params_t *h_params);
char get_flag(char const *str, int i);
int get_precision(const char *str, int i, char flag);
int get_width(const char *str, handle_params_t *h_params);
void move_index_to_flag(const char *str, handle_params_t *h_params);
void set_formatting_specifier(const char *str, handle_params_t *h_params);
void display_flags_formatting(handle_params_t *h_params, int displaySize,
    int displayPrecision);
int handle_types(handle_params_t *h_params);
void handle_int(handle_params_t *h_params);
void handle_str(handle_params_t *h_params);
void handle_char(handle_params_t *h_params);
void handle_percent(handle_params_t *h_params);
void handle_nothing(handle_params_t *h_params);
void handle_octal(handle_params_t *h_params);
void handle_hexa(handle_params_t *h_params);
void handle_binary(handle_params_t *h_params);
void handle_float(handle_params_t *h_params);
//void handle_scientific(handle_params_t *h_params);
void handle_unsigned(handle_params_t *h_params);
void handle_ptr(handle_params_t *h_params);
#endif
