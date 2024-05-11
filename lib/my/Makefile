##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile to build day12 cat program
##

CFLAGS = -Wall -Wextra -shared
SRC = ./my_compute_square_root.c \
	./my_isneg.c \
	./my_put_nbr.c \
	./my_showmem.c \
	./my_sort_int_array.c \
	./my_strcmp.c \
	./my_str_isalpha.c \
	./my_str_isprintable.c \
	./my_strlowcase.c \
	./my_strncpy.c \
	./my_strupcase.c \
	./my_find_prime_sup.c \
	./my_is_prime.c \
	./my_putstr.c \
	./my_showstr.c \
	./my_strcapitalize.c \
	./my_strcpy.c \
	./my_str_islower.c \
	./my_str_isupper.c \
	./my_strncat.c \
	./my_strstr.c \
	./my_swap.c \
	./my_compute_power_rec.c \
	./my_getnbr.c \
	./my_putchar.c \
	./my_revstr.c \
	./my_show_word_array.c \
	./my_strcat.c \
	./my_str_isnum.c \
	./my_strlen.c \
	./my_strncmp.c \
	./my_str_to_word_array.c \
	./my_put_errorstr.c \
	./int_to_str.c \
	./float_to_str.c \
	./my_round.c \
	./long_to_str.c \
	./my_memset.c \
	./my_char_memmove.c \
	./my_memcpy.c \
	./my_realloc.c \
	./my_printf/formatting.c \
	./my_printf/handle1.c \
	./my_printf/handle2.c \
	./my_printf/handle3.c \
	./my_printf/utils.c \
	./my_printf/my_printf.c \
	./my_strdup.c

OBJ	= $(SRC:.c=.o)
NAME	= libmy
CFLAGS 	= -Wall -Wextra -Werror -shared -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rc $(NAME).a $(OBJ)
	cp ./my.h ../../include/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
