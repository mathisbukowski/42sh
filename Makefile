##
## EPITECH PROJECT, 2023
## B-MUL-100-LIL-1-1-myhunter-alexandre.detoeuf
## File description:
## Makefile
##

SRC = src/main.c src/command_runner.c src/commands/cd.c src/commands/env.c \
	src/commands/setenv.c src/utils/utils_env.c src/utils/clean_str.c \
	src/commands/unsetenv.c src/signals.c src/utils/error_utils.c \
	src/aliases/alias.c src/aliases/unalias.c \
	src/aliases/detect_aliases.c src/aliases/alias_replacer.c \
	src/aliases/destroy_aliases.c src/aliases/search_alias.c \
	src/local_variables/destroy_locales.c \
	src/local_variables/set.c src/local_variables/unset.c \
	src/local_variables/local_variable_replacer.c \
	src/utils/update_current_dir.c src/builtin_command_list.c \
	src/redirections.c src/utils/exit.c \
	src/historical/hist_command.c src/historical/write_hist.c \
	src/pipes.c \
	src/renderer/input.c \
	src/utils/get_current_git_branch.c \
	src/job_manager/detect_ampersand.c \
	src/job_manager/add_job.c \
	src/job_manager/bg_command.c \
	src/job_manager/fg_command.c \
	src/job_manager/find_job.c \
	src/job_manager/destroy_jobs.c \
	src/main_shell.c \
	src/utils/raw_mode.c \
	src/utils/init_info.c \
	src/input_manager/line_edition.c \
	src/globbings.c \
	src/handle_logical_operator.c \
	src/help.c

OBJ = $(SRC:.c=.o)
SRC_TESTS = src/command_runner.c src/commands/cd.c src/commands/env.c \
			src/commands/setenv.c src/utils/utils_env.c src/utils/clean_str.c \
			src/commands/unsetenv.c src/signals.c src/utils/error_utils.c \
			src/aliases/alias.c src/aliases/unalias.c \
			src/aliases/detect_aliases.c src/aliases/alias_replacer.c \
			src/aliases/destroy_aliases.c src/aliases/search_alias.c \
			src/local_variables/local_variable_replacer.c \
			src/local_variables/destroy_locales.c \
			src/local_variables/set.c src/local_variables/unset.c \
			src/utils/update_current_dir.c src/builtin_command_list.c \
			src/redirections.c src/utils/exit.c \
			src/historical/hist_command.c src/historical/write_hist.c \
			src/pipes.c \
			src/renderer/input.c \
			src/utils/get_current_git_branch.c \
			src/job_manager/detect_ampersand.c \
			src/job_manager/add_job.c \
			src/job_manager/bg_command.c \
			src/job_manager/fg_command.c \
			src/job_manager/find_job.c \
			src/job_manager/destroy_jobs.c \
			src/main_shell.c \
			src/utils/raw_mode.c \
			src/utils/init_info.c \
			src/input_manager/line_edition.c \
			src/globbings.c \
			src/help.c \
			src/handle_logical_operator.c \
			tests/test_redirections.c \
			tests/test_ampersand.c \
			tests/test_start_shell.c tests/test_pipes.c \
			tests/test_command_runner.c tests/test_utils_env.c \
			tests/test_exit.c tests/test_error_utils.c tests/test_clean_str.c \
			tests/test_get_current_dir.c tests/test_input.c \
			tests/test_get_current_git_branch.c
OBJ_TESTS = $(SRC_TESTS:.c=.o)
NAME = 42sh
CFLAGS = -Wall -Wextra -I./include
CLIB = -L./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	if [ ! -f './lib/my/libmy.a' ]; then make -C './lib/my/'; fi
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CLIB)
	make clean

dev: $(NAME)
	make clean

clean:
	make clean -C ./lib/my/
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

tests_run:
	if [ -f unit_tests ]; then rm unit_tests && rm *.gc*; fi
	gcc -o unit_tests $(SRC_TESTS) $(CLIB) --coverage -lcriterion -I./include
	./unit_tests --verbose --full-stats

gcovr_branches:
	gcovr --exclude tests/ --txt-metric branch

clean_tests:
	rm -f *.gc*
	rm -f unit_tests

documentation:
	doxygen
