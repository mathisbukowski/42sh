/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** redirections.c
*/

#include <fcntl.h>
#include "minishell.h"
#include "utils.h"
#include "my.h"

int read_until_delimiter(int fd, char *delim)
{
    char *buffer = NULL;
    size_t buffsize = 0;
    ssize_t bytes_read = 0;
    int delim_len = my_strlen(delim);
    int done = 0;

    while (!done) {
        bytes_read = getline(&buffer, &buffsize, stdin);
        if (bytes_read == -1) {
            free(buffer);
            return -1;
        }
        if (my_strncmp(buffer, delim, delim_len) == 0 &&
            buffer[delim_len] == '\n' && bytes_read == delim_len + 1)
            done = 1;
        else
            write(fd, buffer, bytes_read);
    }
    free(buffer);
    return 0;
}

static int heredoc(info_t *info, char *here)
{
    int tmp_fd = open(info->tmp_path, O_CREAT | O_RDWR | O_TRUNC, 0666);

    if (tmp_fd == -1) {
        perror("open");
        return -1;
    }
    if (read_until_delimiter(tmp_fd, here) == -1) {
        close(tmp_fd);
        return -1;
    }
    if (lseek(tmp_fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        close(tmp_fd);
        return -1;
    }
    return tmp_fd;
}

int open_file_for_redirect(info_t *info, char *filepath)
{
    int fd = -1;

    if (info->redirections->type == E_WRITE)
        fd = open(filepath, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (info->redirections->type == E_APPEND)
        fd = open(filepath, O_WRONLY | O_APPEND | O_CREAT, 0666);
    if (info->redirections->type == E_READ)
        fd = open(filepath, O_RDONLY);
    if (info->redirections->type == E_READ_UNTIL)
        fd = heredoc(info, info->args[info->redirections->redirect_index + 1]);
    if (access(filepath, W_OK) == -1 && (info->redirections->type == E_APPEND
    || info->redirections->type == E_WRITE)) {
        print_error(filepath, "Permission denied.");
        return -1;
    }
    if (fd == -1) {
        perror(filepath);
        return -1;
    }
    return fd;
}

void delete_args_after_redirection(info_t *info, int redirect_index)
{
    if (redirect_index == -1)
        return;
    for (int i = get_str_array_len(info->args); i >= redirect_index; i--) {
        free(info->args[i]);
        info->args[i] = NULL;
    }
}

static int get_the_return_indic(info_t *info,
    const redirection_type_t *redirect_types,
    const char *const *redirect_tokens, int i)
{
    for (int j = 0; redirect_tokens[j] != NULL; j++) {
        if (my_strcmp(info->args[i], redirect_tokens[j]) == 0) {
            info->redirections->type = redirect_types[j];
            info->redirections->redirect_index = i;
            return i;
        }
    }
    return -1;
}

int get_redirection_index(info_t *info)
{
    const char *redirect_tokens[] = {">>", ">", "<", "<<", NULL};
    redirection_type_t redirect_types[] =
    {E_APPEND, E_WRITE, E_READ, E_READ_UNTIL};
    int result;

    for (int i = 0; info->args[i] != NULL; i++) {
        result = get_the_return_indic(info, redirect_types, redirect_tokens,
    i);
        if (result != -1)
            return result;
    }
    return -1;
}

static int change_exit_redirect(int *fd, info_t *info, int redirect_index)
{
    *fd = open_file_for_redirect(info, info->args[redirect_index + 1]);
    if (*fd == -1)
        return 1;
    if (info->redirections->type == E_READ_UNTIL ||
    info->redirections->type == E_READ)
        dup2(*fd, STDIN_FILENO);
    else
        dup2(*fd, STDOUT_FILENO);
    return 0;
}

int handle_redirections(info_t *info)
{
    int fd = -1;
    int redirect_index = get_redirection_index(info);

    if (redirect_index == -1)
        return 0;
    if (info->args[redirect_index + 1] == NULL) {
        print_error_message("Missing name for redirect.");
        return 1;
    }
    if (change_exit_redirect(&fd, info, redirect_index) != 0)
        return 1;
    info->redirections->fd = fd;
    delete_args_after_redirection(info, redirect_index);
    return 0;
}
